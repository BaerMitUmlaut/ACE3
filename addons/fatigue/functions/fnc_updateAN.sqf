/*
 * Author: BaerMitUmlaut
 * Updates the anaerobic pathway.
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

_reserve = _unit getVariable [QGVAR(reserveAN), 2300];
_reserve = 2300 max (_reserve + 58.7);

if (_workload > 0) then {
    _VO2maxPower = VO2MAX * 5.608;
    _peakPower = 4.1 * _VO2maxPower;
    _powerOutput = _peakPower / (13.3 + 16.7 + 113.3) * 113.3 * ANT^1.28 * 1.362;
    _reserve = _reserve - (_powerOutput / 29);
    systemChat ("AN  " + str _reserve + " | " + str _powerOutput);
    _unit setVariable [QGVAR(reserveAN), _reserve];
    _workload - _powerOutput
} else {
    0
};
