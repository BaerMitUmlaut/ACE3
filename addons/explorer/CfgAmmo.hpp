class CfgAmmo {
    class GrenadeHand;
    class ACE_Explorer_Ammo: GrenadeHand {
        hit = 0;
        indirectHit = 0;
        indirectHitRange = 0;
        dangerRadiusHit = 0;
        suppressionRadiusHit = -1;
        CraterEffects = "NoCrater";
        explosionEffects = "NoExplosion";
        explosive = 0;
        soundHit[] = {"",1,1};
        cost = 1;
        whistleDist = 0;
        explosionTime = 10e10;
        timeToLive = 10e10;
        deflecting = 60;
        deflectionSlowDown = 0.5;
        class CamShakeExplode {
            power = 0;
            duration = 0;
            frequency = 0;
            distance = 0;
        };
        class CamShakeHit {
            power = 0;
            duration = 0;
            frequency = 0;
            distance = 0;
        };
    };
};