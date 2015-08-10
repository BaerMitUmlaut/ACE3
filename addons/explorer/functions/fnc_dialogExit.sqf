#include "script_component.hpp"

if (!isNil QGVAR(activeExplorer)) then {
	GVAR(activeExplorer) hideObject false;
	GVAR(activeExplorer) = nil;

	GVAR(activeCamera) cameraEffect ["Terminate", "BACK"];
	GVAR(activeCamera) camCommit 0;
	GVAR(activeCamera) = nil;

	GVAR(handlePPColor) ppEffectEnable false;
	GVAR(handlePPColor) ppEffectCommit 0;
};