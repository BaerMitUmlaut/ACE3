#include "script_component.hpp"
private ["_explorer", "_distance"];

_explorer = _this select 0;

_distanceSqr = (ACE_player distanceSqr _explorer) max 1;
_countInteresect = count (lineIntersectsWith [getPosASL _explorer, eyePos ACE_player, _explorer, ACE_player, false]);

(3600 / _distanceSqr) * (1 / ((1 + _countInteresect) ^ 3))