#include "script_component.hpp"
private ["_VO2maxPower", "_peakPower, ""_ae1PathwayPower", "_ae1PathwayPower"];

if (!hasInterface) exitWith {};

_VO2maxPower = VO2MAX * 5.608;
_peakPower = 4.1 * _VO2maxPower;
_ae1PathwayPower = _peakPower / (13.3 + 16.7 + 113.3) *  13.3 * ANT^1.28 * 1.362;
_ae2PathwayPower = _peakPower / (13.3 + 16.7 + 113.3) *  16.7 * ANT^1.28 * 1.362;

//GVAR() = (0.5617 * 70 + 42.57) * 0.23;

ACE_player setVariable [QGVAR(ae1PathwayPower), _ae1PathwayPower];
ACE_player setVariable [QGVAR(ae2PathwayPower), _ae1PathwayPower];

[FUNC(pfhMain), 1, []] call CBA_fnc_addPerFrameHandler;
[FUNC(logData), 10, []] call CBA_fnc_addPerFrameHandler;
