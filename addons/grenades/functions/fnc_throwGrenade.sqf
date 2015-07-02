/*
 * Author: commy2
 * Adjust the grenades throwing direction and speed to the selected throwing mode.
 *
 * Arguments:
 * 0: unit - Object the event handler is assigned to <OBJECT>
 * 1: weapon - Fired weapon <STRING>
 * 2: muzzle - Muzzle that was used <STRING>
 * 3: mode - Current mode of the fired weapon <STRING>
 * 4: ammo - Ammo used <STRING>
 * 5: magazine - magazine name which was used <STRING>
 * 6: projectile - Object of the projectile that was shot <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [clientFiredBIS-XEH] call ace_grenades_fnc_throwGrenade
 *
 * Public: No
 */
#include "script_component.hpp"

private ["_unit", "_weapon", "_projectile", "_mode", "_velocity", "_fuzeTime"];

_unit = _this select 0;
_weapon = _this select 1;
_projectile = _this select 6;

if (_unit != ACE_player) exitWith {};
if (_weapon != "Throw") exitWith {};

_mode = missionNamespace getVariable [QGVAR(currentThrowMode), 4];

_velocity = velocity _projectile;

_velocity = _velocity vectorMultiply ((_mode * 0.25) max 0.1);

_projectile setVelocity _velocity;

if (typeOf _projectile == "ACE_G_M84") then {
    _fuzeTime = getNumber (configFile >> "CfgAmmo" >> typeOf _projectile >> "fuseDistance");
    // _fuzeTime = getNumber (configFile >> "CfgAmmo" >> typeOf _projectile >> "explosionTime");  //@toDo pretty sure this should be explosionTime not fuseDistance
    [FUNC(flashbangThrownFuze), [_projectile], _fuzeTime, 0] call EFUNC(common,waitAndExecute);
};
