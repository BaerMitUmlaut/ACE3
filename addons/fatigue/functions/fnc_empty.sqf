/*
 * Author: BaerMitUmlaut
 * Checks if the unit can prepare the helicopters FRIES.
 *
 * Arguments:
 * 0: The helicopter itself <OBJECT>
 *
 * Return Value:
 * Able to prepare FRIES <BOOL>
 *
 * Example:
 * [_vehicle] call ace_fatigue_fnc_canPrepareFRIES
 *
 * Public: No
 */

#include "script_component.hpp"
params ["_vehicle"];
private ["_deployedRopes", "_config"];
