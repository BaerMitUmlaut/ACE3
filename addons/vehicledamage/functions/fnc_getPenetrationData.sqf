#include "script_component.hpp"
private["_penArray", "_penClass"];
PARAMS_1(_surfaceName);

_surfaceName = [_surfaceName, "A3\data_f\Penetration\", ""] call CBA_fnc_replace;
_surfaceName = [_surfaceName, ".bisurf", ""] call CBA_fnc_replace;

if(!isClass (configFile >> "ACE_Penetration" >> _surfaceName)) exitWith { nil };

_penArray = [
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "thickness"),
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "density"),
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "rough"),
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "dust"),
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "bulletPenetrability"),
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "friction"),
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "restitution"),
    getNumber (configFile >> "ACE_Penetration" >> _surfaceName >> "deflection")
];

_penArray