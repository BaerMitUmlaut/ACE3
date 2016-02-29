/*
 * Author: BaerMitUmlaut
 * Switches the anti collision lights of any aircraft on or off.
 *
 * Arguments:
 * 0: Aircraft <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_helo] call ace_cockpit_interaction_fnc_switchCollisionLight
 *
 * Public: No
 */

#include "script_component.hpp"
params ["_vehicle"];

private _collisionLightsOn = _vehicle getVariable [QGVAR(collisionLightsOn), false];
_vehicle setVariable [QGVAR(collisionLightsOn), !_collisionLightsOn, true];
if (_vehicle getVariable [QGVAR(hasElectricalPower), false]) then {
    [QGVAR(setCollisionLight), _vehicle, [_vehicle, !_collisionLightsOn]] call EFUNC(common,objectEvent);
};
