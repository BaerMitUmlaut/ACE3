#include "script_component.hpp"
private ["_unit", "_weapon", "_projectile", "_connectedExplorers"];

_unit = _this select 0;
_weapon = _this select 1;
_projectile = _this select 6;

if (_unit != ACE_player) exitWith {};
if (_weapon != "Throw") exitWith {};
if (typeOf _projectile != "ACE_Explorer_Ammo") exitWith {};

[_projectile] call FUNC(replaceProjectile);