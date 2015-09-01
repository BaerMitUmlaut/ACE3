#define TOUCHSCREEN_W (safeZoneW / 6 * 4)
#define TOUCHSCREEN_H (TOUCHSCREEN_W * 4 / 3 / 16 * 9)
#define TOUCHSCREEN_X ((safeZoneW - TOUCHSCREEN_W) / 2 + safeZoneX)
#define TOUCHSCREEN_Y ((safeZoneH - TOUCHSCREEN_H) / 2 + safeZoneY)

class RscPicture;
class RscButton;
class RscListbox;

class GVAR(ctrlBlocker) {
    type = 0;
    style = 0;
    font = "PuristaMedium";
    sizeEx = 0;
    colorText[] = {0, 0, 0, 0};
    colorBackground[] = {0, 0, 0, 1};
    text = "";
};

class GVAR(ctrlBorderTiled) {
    idc = -1;
    type = 0;
    style = 144;
    font = "PuristaMedium";
    sizeEx = 0;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 1};
    tileH = 1;
    tileW = 20;
};

class GVAR(ctrlBorderBasic) {
    idc = -1;
    type = 0;
    style = 48;
    font = "PuristaMedium";
    sizeEx = 0;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 0};
};

class GVAR(dlgPhone) {
    idd = -1;
    movingEnable = false;
    enableSimulation = 1;

    onLoad = _this call FUNC(dialogInit);
    onUnload = _this call FUNC(dialogExit);

    controlsBackground[] = {blockerTop, blockerBottom, blockerLeft, blockerRight, blockerScreen, noSignal, statusBar, borderTop, borderBottom, borderLeft, borderRight};
    controls[] = {deviceList, btnClose, btnList, touchScreen};

    class blockerTop: GVAR(ctrlBlocker) {
        idc = -1;
        x = safeZoneX;
        y = safeZoneY;
        w = safeZoneW;
        h = TOUCHSCREEN_Y - safeZoneY;
    };

    class blockerBottom: GVAR(ctrlBlocker) {
        idc = -1;
        x = safeZoneX;
        y = TOUCHSCREEN_Y + TOUCHSCREEN_H;
        w = safeZoneW;
        h = TOUCHSCREEN_Y - safeZoneY;
    };

    class blockerLeft: GVAR(ctrlBlocker) {
        idc = -1;
        x = safeZoneX;
        y = safeZoneY;
        w = TOUCHSCREEN_X - safeZoneX;
        h = safeZoneH;
    };

    class blockerRight: GVAR(ctrlBlocker) {
        idc = -1;
        x = TOUCHSCREEN_X + TOUCHSCREEN_W;
        y = safeZoneY;
        w = TOUCHSCREEN_X - safeZoneX;
        h = safeZoneH;
    };

    class blockerScreen: GVAR(ctrlBlocker) {
        idc = 5;
        x = TOUCHSCREEN_X;
        y = TOUCHSCREEN_Y;
        w = TOUCHSCREEN_W;
        h = TOUCHSCREEN_H;
        colorBackground[] = {1,1,1,1};
    };

    class borderTop: GVAR(ctrlBorderTiled) {
        text = PATHTOF(UI\dlgBorderTop.paa);
        x = TOUCHSCREEN_X;
        y = TOUCHSCREEN_Y - 0.13;
        w = TOUCHSCREEN_W;
        h = 0.13;
    };

    class borderBottom: GVAR(ctrlBorderTiled) {
        text = PATHTOF(UI\dlgBorderBottom.paa);
        x = TOUCHSCREEN_X;
        y = TOUCHSCREEN_Y + TOUCHSCREEN_H;
        w = TOUCHSCREEN_W;
        h = 0.13;
    };

    class borderLeft: GVAR(ctrlBorderBasic) {
        text = PATHTOF(UI\dlgBorderLeft.paa);
        x = TOUCHSCREEN_X - ((TOUCHSCREEN_H + 0.1463) / 8 * 3/4);
        y = TOUCHSCREEN_Y - 0.0731;
        w = (TOUCHSCREEN_H + 0.1463) / 8 * 3/4;
        h = TOUCHSCREEN_H + 0.1463;
    };

    class borderRight: GVAR(ctrlBorderBasic) {
        text = PATHTOF(UI\dlgBorderRight.paa);
        x = TOUCHSCREEN_X + TOUCHSCREEN_W;
        y = TOUCHSCREEN_Y - 0.0731;
        w = (TOUCHSCREEN_H + 0.1463) / 8 * 3/4;
        h = TOUCHSCREEN_H + 0.1463;
    };

    class statusBar {
        idc = -1;
        type = 0;
        style = 2;
        font = "PuristaLight";
        sizeEx = 0.05;
        colorText[] = {1, 1, 1, 1};
        colorBackground[] = {0.07, 0.07, 0.07, 0.95};
        text = "BOUNCE VIEWER";
        x = TOUCHSCREEN_X - 0.05;
        y = TOUCHSCREEN_Y;
        w = TOUCHSCREEN_W + 0.1;
        h = 0.1;
    };

    class btnClose: RscButton {
        idc = -1;
        style = 48;
        x = TOUCHSCREEN_X + TOUCHSCREEN_W - 0.075 * 3/4;
        y = TOUCHSCREEN_Y + 0.025;
        w = 0.05 * 3/4;
        h = 0.05;
        text = PATHTOF(UI\iconClose.paa);
        font = "PuristaBold";
        sizeEx = 0;
        colorText[] = {1,1,1,1};
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
        onMouseButtonClick = closeDialog 0;
    };

    class btnList: RscButton {
        idc = 4;
        style = 48;
        x = TOUCHSCREEN_X + 0.025 * 3/4;
        y = TOUCHSCREEN_Y + 0.025;
        w = 0.05 * 3/4;
        h = 0.05;
        text = PATHTOF(UI\iconList.paa);
        font = "PuristaBold";
        sizeEx = 0;
        colorText[] = {1,1,1,1};
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
        onMouseButtonClick = _this call FUNC(onBtnBack);
    };

    class touchScreen {
        idc = 6;
        style = 0;
        type = 1;
        x = TOUCHSCREEN_X;
        y = TOUCHSCREEN_Y + 0.1;
        w = TOUCHSCREEN_W;
        h = TOUCHSCREEN_H - 0.1;
        text = "";
        font = "PuristaMedium";
        sizeEx = 0;
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
        onMouseButtonDown = _this call FUNC(onMouseDown);
        onMouseButtonUp = _this call FUNC(onMouseUp);
        onMouseMoving = _this call FUNC(onMouseMove);
    };

    class deviceList: RscListbox {
        idc = 3;
        x = TOUCHSCREEN_X;
        y = TOUCHSCREEN_Y + 0.1;
        w = TOUCHSCREEN_W;
        h = TOUCHSCREEN_H - 0.1;
        sizeEx = 0.075;
        blinkingPeriod = 0;
        period = 0;
        canDrag = 0;
        colorText[] = {0.6, 0.6, 0.6, 1};
        colorSelect[] = {0.6, 0.6, 0.6, 1};
        pictureColor[] = {1,1,1,1};
        pictureColorSelect[] = {1,1,1,1};
        colorBackground[] = {1,1,1,1};
        colorSelectBackground[] = {1,1,1,1};
        colorSelectBackground2[] = {1,1,1,1};
        rowHeight = 0.15;
        onLBSelChanged = _this call FUNC(onListSelect);
    };

    class noSignal {
        idc = 7;
        type = 0;
        style = 2;
        font = "PuristaMedium";
        sizeEx = 0.05;
        colorText[] = {0.73, 0.15, 0.1, 1};
        colorBackground[] = {1,1,1,1};
        text = "[NO SIGNAL]";
        x = TOUCHSCREEN_X;
        y = TOUCHSCREEN_Y;
        w = TOUCHSCREEN_W;
        h = TOUCHSCREEN_H;
    };
};