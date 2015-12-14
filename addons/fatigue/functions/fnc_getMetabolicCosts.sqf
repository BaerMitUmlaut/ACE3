/*
 * Author: BaerMitUmlaut
 * Calculates the current metabolic costs for a unit.
 * Calculation is done according to the Pandolf/Wojtowicz formulas.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Metabolic cost <NUMBER>
 *
 * Example:
 * [_player, true] call ace_fatigue_fnc_getMetabolicCosts
 *
 * Public: No
 */

#include "script_component.hpp"
params ["_unit", "_velocity"];
private ["_m", "_l", "_t", "_g", "_v", "_postureWeight", "_duty"];

_m = 70;                                //unit weight
//_l = loadAbs _unit * 0.1 * 1/2.2046;    //gear weight
_l = 0;
_t = 1;                                 //terrain factor - TODO
_g = 0;                                 //slope angle - TODO
_v = _velocity; //vectorMagnitude (velocity _unit);  //velocity
_postureWeight = 1;
/*_postureWeight = switch (unitPos _unit) do {
    case "UP": {1};
    case "MIDDLE": {
        if (_g > 1) then {
            1 max (1.5 - 0.5 * _g * 0.01667);
        } else {
            1.5
        };
    };
    case "DOWN": {
        if (_g > 1) then {
            1 max (7.0 - 6.0 * _g * 0.01667)
        } else {
            7
        };
    };
};*/
_duty = 1;                              //duty - TODO

if (_v > 2) then {
    2.10*_m + 4*(_m+_l)*((_l/_m)^2) + _t*(_m+_l)*(0.90*(_v^2)+0.66*_v*_g) * 0.23 * _postureWeight * _duty
} else {
    1.05*_m + 2*(_m+_l)*((_l/_m)^2) + _t*(_m+_l)*(1.15*(_v^2)+0.66*_v*_g) * 0.23 * _postureWeight * _duty
};
