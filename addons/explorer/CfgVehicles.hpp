class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class ACE_Explorer {
                    displayName = CSTRING(openDevice);
                    condition = ("ACE_Explorer_Device" in (items ACE_player));
                    statement = createDialog QGVAR(dlgPhone);
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
                displayName = CSTRING(pickUp);
                distance = 2;
                condition = QUOTE(true);
                statement = QUOTE(_this call FUNC(pickupExplorer));
                showDisabled = 0;
                exceptions[] = {};
                priority = 1;
            };
        };
    };

    class Box_NATO_Support_F;
    class ACE_Box_Misc: Box_NATO_Support_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_Explorer_Device,5);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(ACE_Explorer,20);
        };
    };
};