#include "script_component.hpp"
private ["_replacement", "_pos", "_connectedExplorers"];

{
	if (vectorMagnitude (velocity _x) == 0) then {
		_replacement = "ACE_Explorer_Ground" createVehicle [0,0,0];
		_replacement setVectorDirAndUp [vectorDir _x, vectorUp _x];
		_pos = getPosASL _x;
		deleteVehicle _x;
		_replacement setPosASL _pos;

		GVAR(projectilesToReplace) deleteAt (GVAR(projectilesToReplace) find _x);

		_connectedExplorers = ACE_player getVariable [QGVAR(connectedExplorers), []];
		_connectedExplorers pushBack _replacement;
		ACE_player setVariable [QGVAR(connectedExplorers), _connectedExplorers];
	};
	nil
} count GVAR(projectilesToReplace);

if (count GVAR(projectilesToReplace) == 0) then {
	[GVAR(replaceProjectilePFH)] call CBA_fnc_removePerFrameHandler;
	GVAR(replaceProjectilePFH) = nil;
};