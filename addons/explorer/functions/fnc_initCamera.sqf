#include "script_component.hpp"
private ["_explorer"];

_explorer = _this select 0;


hideObject _explorer; //hide explorer so it doesn't interfere with the camera

GVAR(cam) = "Camera" camCreate [0,0,0];
GVAR(cam) setPosATL (getPosATL _explorer);

GVAR(camDir) = random 360;
GVAR(camPitch) = random 360;
GVAR(camBank) = random 360;

GVAR(cam) setDir GVAR(camDir);
[GVAR(cam), GVAR(camPitch), GVAR(camBank)] call BIS_fnc_setPitchBank;

GVAR(cam) camSetFov 1;
GVAR(cam) cameraEffect ["External", "BACK"];
GVAR(cam) camCommit 0;