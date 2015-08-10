#include "script_component.hpp"
private ["_explorer", "_dirPitchBank"];

_explorer = _this select 0;
_explorer hideObject true;
GVAR(activeExplorer) = _explorer;

_dirPitchBank = _explorer getVariable [QGVAR(cameraDirPitchBank), []];
if (count (_dirPitchBank) != 3) then {
	_dirPitchBank = _explorer setVariable [QGVAR(cameraDirPitchBank), [direction _explorer, 45, 0]];
};

GVAR(activeCamera) = "Camera" camCreate [0,0,0];
GVAR(activeCamera) setPosASL (getPosASL _explorer);

GVAR(activeCamera) camSetFov 2;
GVAR(activeCamera) cameraEffect ["Internal", "BACK"];
GVAR(activeCamera) camCommit 0;

showCinemaBorder false;
cameraEffectEnableHUD true;

GVAR(handlePPColor) = ppEffectCreate ["colorCorrections", 1501];
GVAR(handlePPColor) ppEffectEnable true;
GVAR(handlePPColor) ppEffectAdjust [1,0.5,0,[0,0,0,0],[1,1,1,0],[1,1,1,1]];
GVAR(handlePPColor) ppEffectCommit 0;

GVAR(activeCamera) setDir (_dirPitchBank select 0);
[GVAR(activeCamera), _dirPitchBank select 1, _dirPitchBank select 2] call BIS_fnc_setPitchBank;