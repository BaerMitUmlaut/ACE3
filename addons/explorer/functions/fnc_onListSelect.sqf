#include "script_component.hpp"
private ["_listBox", "_indexSelected", "_connectedExplorers"];

_listBox = _this select 0;
_indexSelected = _this select 1;

_connectedExplorers = ACE_player getVariable [QGVAR(connectedExplorers), []];
[_connectedExplorers select _indexSelected] call FUNC(initCamera);

((ctrlParent _listBox) displayCtrl 4) ctrlShow true;
((ctrlParent _listBox) displayCtrl 5) ctrlShow false;
((ctrlParent _listBox) displayCtrl 6) ctrlShow true;
_listBox ctrlShow false;