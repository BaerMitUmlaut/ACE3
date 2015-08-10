class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class ACE_Explorer {
                    displayName = "Open Explorer";
                    condition = "true";
                    statement = "createDialog 'ace_explorer_dlgPhone'";
                    exceptions[] = {};
                    showDisabled = 0;
                    priority = 4;
                };
            };
        };
    };

    class Items_base_F;
    class ACE_Explorer_Ground: Items_base_F {
        XEH_ENABLED;
        scope = 1;
        displayName = "Explorer";
        model = "\A3\Weapons_f\ammo\Handgrenade";
        class ACE_Actions {
            class ACE_PickUp {
                selection = "";
                displayName = "Pick up";
                distance = 4;
                condition = QUOTE(true);
                statement = QUOTE(_this call FUNC(pickupExplorer));
                showDisabled = 0;
                exceptions[] = {};
                priority = 1;
            };
        };
    };
};