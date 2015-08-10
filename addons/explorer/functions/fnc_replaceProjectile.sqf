#include "script_component.hpp"

if (isNil QGVAR(projectilesToReplace)) then {
	GVAR(projectilesToReplace) = []
};
GVAR(projectilesToReplace) pushBack (_this select 0);

if (isNil QGVAR(replaceProjectilePFH)) then {
	GVAR(replaceProjectilePFH) = [FUNC(replaceProjectilePFH), 0, []] call CBA_fnc_addPerFrameHandler;
};