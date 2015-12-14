#include "script_component.hpp"

if (isNil QGVAR(log)) then {
    GVAR(log) = "";
};

GVAR(log) = GVAR(log) + str(round time) + ","
    + str((ACE_player getVariable [QGVAR(ae1Reserve), 4000000])/4000000) + ","
    + str((ACE_player getVariable [QGVAR(ae2Reserve), 84000])/84000) + ","
    + str((ACE_player getVariable [QGVAR(anReserve), 2300])/2300) + ","
    + str(ACE_player getVariable [QGVAR(anFatigue), 0]) + ","
    + str(ACE_player getVariable [QGVAR(muscleDamage), 0]) + "
";
