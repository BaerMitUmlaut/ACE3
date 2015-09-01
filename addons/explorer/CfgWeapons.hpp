class CfgWeapons {
    class GrenadeLauncher;
    class Throw: GrenadeLauncher {
        muzzles[] += {"ACE_Explorer_Muzzle"};
        class ThrowMuzzle;
        class ACE_Explorer_Muzzle: ThrowMuzzle {
            magazines[] = {"ACE_Explorer"};
        };
    };

    class ACE_ItemCore;
    class InventoryItem_Base_F;    
    class ACE_Explorer_Device: ACE_ItemCore {
        scope = 2;
        displayName = "Bounce Viewer";
        picture = PATHTOF(UI\iconDevice.paa);
        descriptionShort = "Bounce Viewer";
        model = "\A3\Structures_F\Items\Electronics\MobilePhone_smart_F.p3d";
        class ItemInfo: InventoryItem_Base_F {
            mass = 5;
        };
    };
};