class GVAR(ctrlBlocker) {
    type = 0;
    style = 0;
    font = "PuristaMedium";
    SizeEx = 0;
    colorText[] = {0, 0, 0, 0};
    colorBackground[] = {0, 0, 0, 1};
    text = "";
};

class RscPicture;
class RscButton;
class RscListbox;
class GVAR(dlgPhone) {
    idd = -1;
    movingEnable = false;
    enableSimulation = 1;

    onLoad = QUOTE(_this call FUNC(dialogInit));
    onUnload = QUOTE(_this call FUNC(dialogExit));

    controlsBackground[] = {blockerTop, blockerBottom, blockerLeft, blockerRight, overlay};
    controls[] = {deviceList, touchScreen};

    class blockerTop: GVAR(ctrlBlocker) {
        idc = -1;
        x = safeZoneX;
        y = safeZoneY;
        w = safeZoneW;
        h = safeZoneH / 6;
    };

    class blockerBottom: GVAR(ctrlBlocker) {
        idc = -2;
        x = safeZoneX;
        y = safeZoneY + safeZoneH - safeZoneH / 6;
        w = safeZoneW;
        h = safeZoneH / 6;
    };

    class blockerLeft: GVAR(ctrlBlocker) {
        idc = -3;
        x = safeZoneX;
        y = safeZoneY;
        w = safeZoneW / 6;
        h = safeZoneH;
    };

    class blockerRight: GVAR(ctrlBlocker) {
        idc = -4;
        x = safeZoneX + safeZoneW - safeZoneW / 6;
        y = safeZoneY;
        w = safeZoneW / 6;
        h = safeZoneH;
    };

    class overlay: RscPicture {
        idc = -5;
        x = 0;
        y = 0;
        w = 1;
        h = 1;
        text = "";
    };

    class touchScreen: RscButton {
        idc = 1;
        x = safeZoneX + safeZoneW / 6;
        y = safeZoneY + safeZoneH / 6;
        w = safeZoneW / 6 * 4;
        h = safeZoneH / 6 * 4;
        text = "";
        colorText[] = {0,0,0,0};
        colorDisabled[] = {0,0,0,0};
        colorBackground[] = {0,0,0,0};
        colorBackgroundDisabled[] = {0,0,0,0};
        colorBackgroundActive[] = {0,0,0,0};
        offsetX = 0;
        offsetY = 0;
        offsetPressedX = 0;
        offsetPressedY = 0;
        colorFocused[] = {0,0,0,0};
        colorShadow[] = {0,0,0,0};
        shadow = 0;
        colorBorder[] = {0,0,0,0};
        borderSize = 0;
        soundEnter[] = {"",0.1,1};
        soundPush[] = {"",0.1,1};
        soundClick[] = {"",0.1,1};
        soundEscape[] = {"",0.1,1};
        onMouseButtonDown = QUOTE(_this call FUNC(onMouseDown));
        onMouseButtonUp = QUOTE(_this call FUNC(onMouseUp));
        onMouseMoving = QUOTE(_this call FUNC(onMouseMove));
    };

    class deviceList: RscListbox {
        idc = 2;
        x = safeZoneX + safeZoneW / 6;
        y = safeZoneY + safeZoneH / 6;
        w = safeZoneW / 6 * 4;
        h = safeZoneH / 6 * 4;
        colorBackground[] = {0, 0, 0, 1};
        onLBSelChanged = QUOTE(_this call FUNC(onListSelect));
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2)";
    };
};