class CfgWeapons {
    class GrenadeLauncher;
    class Throw: GrenadeLauncher {
        muzzles[] += {"ACE_Explorer_Muzzle"};
        class ThrowMuzzle;
        class ACE_Explorer_Muzzle: ThrowMuzzle {
            magazines[] = {"ACE_Explorer"};
        };
    };
};