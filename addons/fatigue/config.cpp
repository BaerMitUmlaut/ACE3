#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_common"};
        author[] = {"BaerMitUmlaut"};
        authorUrl = "";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"