
class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_FiredBIS_EventHandlers {
    class CAManBase {
        class ADDON {
            clientFiredBIS = QUOTE(_this call FUNC(onThrow));
        };
    };
};
