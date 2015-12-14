/*
 * Author: BaerMitUmlaut
 * Main perFrameHandler that updates fatigue values.
 *
 * Arguments:
 * 0: PFH arguments <ARRAY>
 * 1: PFH handler <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [[_unit], 0] call ace_fatigue_fnc_pfhMain
 *
 * Public: No
 */

#include "script_component.hpp"
params ["_args", "_pfhHandle"];
private ["_currentWork", "_oxygen", "_wattsPerATP", "_ae1Reserve", "_ae2Reserve", "_anReserve", "_anFatigue", "_ae1PathwayPower", "_ae2PathwayPower",
         "_VO2maxPower", "_peakPower", "_muscleDamage", "_muscleIntegrity", "_ae1PathwayPowerFatigued", "_ae2PathwayPowerFatigued",
         "_ae1Power", "_ae2Power", "_anPower", "_ae1Dwork", "_ae2Dwork", "_anDwork"];

_currentWork = [ACE_player, vectorMagnitude (velocity ACE_player)] call FUNC(getMetabolicCosts);
_currentWork = _currentWork max REE;

//No need to go overboard, so we set oxygen percentage to a constant
_oxygen = 0.9;
_wattsPerATP = 29;

_ae1Reserve = ACE_player getVariable [QGVAR(ae1Reserve), 4000000];
_ae2Reserve = ACE_player getVariable [QGVAR(ae2Reserve), 84000];
_anReserve  = ACE_player getVariable [QGVAR(anReserve), 2300];
_anFatigue  = ACE_player getVariable [QGVAR(anFatigue), 0];
_muscleDamage  = ACE_player getVariable [QGVAR(muscleDamage), 0];

_VO2maxPower = VO2MAX * 5.608;
_peakPower = 4.1 * _VO2maxPower;

_ae1PathwayPower = ACE_player getVariable [QGVAR(ae1PathwayPower), 0];
_ae2PathwayPower = ACE_player getVariable [QGVAR(ae2PathwayPower), 0];

if (_ae1PathwayPower == 0) then {
    _ae1PathwayPower = _peakPower / (13.3 + 16.7 + 113.3) *  13.3 * ANT^1.28 * 1.362;
    _ae2PathwayPower = _peakPower / (13.3 + 16.7 + 113.3) *  16.7 * ANT^1.28 * 1.362;
    ACE_player setVariable [QGVAR(ae1PathwayPower), _ae1PathwayPower];
    ACE_player setVariable [QGVAR(ae2PathwayPower), _ae2PathwayPower];
};

_muscleDamage = _muscleDamage + (_currentWork/_peakPower)^3.2 * 0.00004;
_muscleIntegrity = 1 - _muscleDamage;

_ae1PathwayPowerFatigued = _ae1PathwayPower * sqrt (_ae1Reserve/4000000) * _oxygen * sqrt _muscleIntegrity;
_ae2PathwayPowerFatigued = _ae2PathwayPower * sqrt (_ae2Reserve/84000) * _oxygen * sqrt _muscleIntegrity;

_ae1Power = _currentWork;
_ae1Power = _ae1Power min _ae1PathwayPowerFatigued;
_ae2Power = _currentWork - _ae1Power;
_ae2Power = _ae2Power min _ae2PathwayPowerFatigued;
_anPower = (_peakPower - _ae1PathwayPower - _ae2PathwayPower) * (1 - _anFatigue^2);

_ae1Dwork = _ae1Power;
_ae2Dwork = _ae2Power;
_anDwork = _anPower;

//Anearobic fatigue increase and ATP reserve decrease
_ae1Reserve = _ae1Reserve - _ae1Dwork/_wattsPerATP;
_ae2Reserve = _ae2Reserve - _ae2Dwork/_wattsPerATP;
_anReserve = _anReserve - _anDwork/_wattsPerATP;
_anFatigue = _anFatigue + _anDwork * (0.057/_peakPower) * 1.1;

//Anearobic fatigue and ATP reserve recovery
_ae1Reserve = (_ae1Reserve + _oxygen * 6.6 * (_ae1PathwayPower - _ae1Dwork) / _ae1PathwayPower) min 4000000;
_ae2Reserve = (_ae2Reserve + _oxygen * 5.83 * (_ae2PathwayPower - _ae2Dwork) / _ae2PathwayPower) min 84000;
_anReserve = (_anReserve + (_ae1PathwayPowerFatigued + _ae2PathwayPowerFatigued - _ae1Dwork - _ae2Dwork) / _VO2maxPower * 56.7 * 1 * _anFatigue^2) min 2300;
_anFatigue = (_anFatigue - (_ae1PathwayPowerFatigued + _ae2PathwayPowerFatigued - _ae1Dwork - _ae2Dwork) * (0.057/_peakPower) * _anFatigue^2) max 0;

systemChat ((str _ae1Reserve) +" | "+ str (_ae2Reserve) +" | "+ (str _anReserve) +" | "+ (str _anFatigue));

ACE_player setVariable [QGVAR(ae1Reserve), _ae1Reserve];
ACE_player setVariable [QGVAR(ae2Reserve), _ae2Reserve];
ACE_player setVariable [QGVAR(anReserve), _anReserve];
ACE_player setVariable [QGVAR(anFatigue), _anFatigue];
ACE_player setVariable [QGVAR(muscleDamage), _muscleDamage];
