#include "script_component.hpp"
private ["_mouseX", "_mouseY", "_deltaX", "_deltaY", "_dirPitchBank"];

_mouseX = _this select 1;
_mouseY = _this select 2;

_dirPitchBank = GVAR(activeExplorer) getVariable [QGVAR(cameraDirPitchBank), [0,0,0]];

if (GVAR(mouseDown)) then {
	_deltaX = _mouseX - GVAR(prevMouseX);
	_dirPitchBank set [0, ((_dirPitchBank select 0) + _deltaX * -100)];

	_deltaY = _mouseY - GVAR(prevMouseY);
	_dirPitchBank set [1, ((_dirPitchBank select 1) + _deltaY * 100) max -89 min 89];
};

GVAR(activeCamera) setDir (_dirPitchBank select 0);
[GVAR(activeCamera), _dirPitchBank select 1, _dirPitchBank select 2] call BIS_fnc_setPitchBank;

GVAR(activeExplorer) setVariable [QGVAR(cameraDirPitchBank), _dirPitchBank];

GVAR(prevMouseX) = _mouseX;
GVAR(prevMouseY) = _mouseY;

true