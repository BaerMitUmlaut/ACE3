#include "script_component.hpp"
private ["_listBox", "_indexSelected", "_connectedExplorers"];

_listBox = _this select 0;
_indexSelected = _this select 1;

_listBox ctrlShow false;

_connectedExplorers = ACE_player getVariable [QGVAR(connectedExplorers), []];
[_connectedExplorers select _indexSelected] call FUNC(initCamera);