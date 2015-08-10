#include "script_component.hpp";
private ["_explorer", "_connectedExplorers"];

_explorer = _this select 0;

_connectedExplorers = ACE_player getVariable [QGVAR(connectedExplorers), []];
_connectedExplorers deleteAt (_connectedExplorers find _explorer);
ACE_player setVariable [QGVAR(connectedExplorers), _connectedExplorers];

deleteVehicle _explorer;
ACE_player addMagazine "ACE_Explorer";