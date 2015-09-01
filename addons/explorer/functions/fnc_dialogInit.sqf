#include "script_component.hpp"
private ["_dialog", "_index", "_signal", "_img"];

_dialog = _this select 0;

{
    _index = (_dialog displayCtrl 3) lbAdd ("ID #" + str (_forEachIndex + 1));
    _signal = [_x] call FUNC(calculateSignalStrength);
    _img = switch (true) do {
        case (_signal < 1):   {QUOTE(PATHTOF(UI\iconSignal0.paa))};
        case (_signal < 1.8): {QUOTE(PATHTOF(UI\iconSignal1.paa))};
        case (_signal < 4):   {QUOTE(PATHTOF(UI\iconSignal2.paa))};
        case (_signal < 16):  {QUOTE(PATHTOF(UI\iconSignal3.paa))};
        case (_signal >= 16): {QUOTE(PATHTOF(UI\iconSignal4.paa))};
        default               {QUOTE(PATHTOF(UI\iconSignal0.paa))};
    };
    (_dialog displayCtrl 3) lbSetPicture [_index, _img];
} foreach (ACE_player getVariable [QGVAR(connectedExplorers), []]);

(_dialog displayCtrl 4) ctrlShow false;
(_dialog displayCtrl 7) ctrlShow false;

GVAR(dialogPFH) = [FUNC(dialogPFH), 0, [_dialog]] call CBA_fnc_addPerFrameHandler;