#include "script_component.hpp"
private ["_dialog"];

_dialog = ctrlParent (_this select 0);

(_dialog displayCtrl 3) ctrlShow true;
(_dialog displayCtrl 4) ctrlShow false;
(_dialog displayCtrl 5) ctrlShow true;
(_dialog displayCtrl 6) ctrlShow false;

if (!isNil QGVAR(activeExplorer)) then {
	GVAR(activeExplorer) hideObject false;
	GVAR(activeExplorer) = nil;

	GVAR(activeCamera) cameraEffect ["Terminate", "BACK"];
	GVAR(activeCamera) camCommit 0;
	GVAR(activeCamera) = nil;

	GVAR(handlePPColor) ppEffectEnable false;
	GVAR(handlePPColor) ppEffectCommit 0;
};