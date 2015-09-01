#include "script_component.hpp"
private ["_dialog"];

_dialog = (_this select 0) select 0;

if (!isNil QGVAR(activeExplorer)) then {
	if (alive GVAR(activeExplorer)) then {
		GVAR(activeCamera) setPosASL (getPosASL GVAR(activeExplorer));
		(_dialog displayCtrl 7) ctrlShow false;
	} else {
		(_dialog displayCtrl 7) ctrlShow true;
	};
} else {
	(_dialog displayCtrl 7) ctrlShow true;
};