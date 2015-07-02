/*
 * Author: commy2
 * Select the next throwing mode and display message.
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Handeled <BOOL>
 *
 * Example:
 * [] call ace_grenades_fnc_nextMode
 *
 * Public: No
 */
#include "script_component.hpp"

private ["_mode", "_hint"];

_mode = missionNamespace getVariable [QGVAR(currentThrowMode), 4];

if (_mode == 4) then {
    _mode = 0;
} else {
    _mode = _mode + 1;
};

[(str _mode), ("\z\ace\addons\grenades\UI\grenadeIndicator" + (str _mode) + ".paa")] call EFUNC(common,displayTextPicture);

GVAR(currentThrowMode) = _mode;

true