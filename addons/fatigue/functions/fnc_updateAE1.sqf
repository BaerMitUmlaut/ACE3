/*
 * Author: BaerMitUmlaut
 * Updates the first aerobic pathway.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Workload of unit (in watts) <NUMBER>
 *
 * Return Value:
 * Workload left after pathway <NUMBER>
 *
 * Public: No
 */

#include "script_component.hpp"
params ["_unit", "_workload"];
private ["_reserve", "_VO2maxPower", "_peakPower", "_powerOutput"];

_reserve = _unit getVariable [QGVAR(reserveAE1), 4000000];
_reserve = 4000000 max (_reserve + 6.6);

if (_workload > 0) then {
    _VO2maxPower = VO2MAX * 5.608;
    _peakPower = 4.1 * _VO2maxPower;
    _powerOutput = _peakPower / (13.3 + 16.7 + 113.3) * 13.3 * ANT^1.28 * 1.362;
    _reserve = _reserve - (_powerOutput / 29);
    systemChat ("AE1 " + str _reserve + " | " + str (_powerOutput);
    _unit setVariable [QGVAR(reserveAE1), _reserve];
    _workload - _powerOutput
} else {
    0
};
