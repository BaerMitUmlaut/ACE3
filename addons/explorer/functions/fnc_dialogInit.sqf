#include "script_component.hpp"

_dialog = _this select 0;

{
	(_dialog displayCtrl 2) lbAdd ("ID #" + str (_forEachIndex + 1));
} foreach (ACE_player getVariable [QGVAR(connectedExplorers), []]);