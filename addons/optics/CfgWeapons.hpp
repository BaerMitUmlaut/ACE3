
class CfgWeapons {
    class ItemCore;
    class InventoryOpticsItem_Base_F;

    // zooming reticle scopes
    class optic_DMS: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class Snip;
                class Iron;
            };
        };
    };

    class ACE_optic_DMS: optic_DMS {
        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_DMS";
        scope = 1;
        displayName = "LOCALIZE ACE DMS";
        //descriptionShort = "$STR_A3_CFGWEAPONS_ACC_DMS1";
        weaponInfoType = "ACE_RscWeaponZeroing";

        class ItemInfo: ItemInfo {
            modelOptics = QUOTE(PATHTOF(models\ace_shortdot_optics.p3d));

            class OpticsModes: OpticsModes {
                class Snip: Snip {
                    opticsZoomMin = 0.05;
                    opticsZoomMax = 0.3;
                    opticsZoomInit = 0.3;
                    discretefov[] = {};
                    modelOptics[] = {};
                };

                class Iron: Iron {};
            };
        };
    };

    // PIP scopes
    class optic_Hamr: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class Hamr2Collimator;
                class Hamr2Scope;
            };
        };
    };

    class ACE_optic_Hamr_2D: optic_Hamr {
        GVAR(BodyDay) = QUOTE(PATHTOF(reticles\hamr-body_ca.paa));
        GVAR(BodyNight) = QUOTE(PATHTOF(reticles\hamr-bodyNight_ca.paa));
        GVAR(ReticleDay) = QUOTE(PATHTOF(reticles\hamr-reticle65_ca.paa));
        GVAR(ReticleNight) = QUOTE(PATHTOF(reticles\hamr-reticle65Illum_ca.paa));

        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_Hamr_2D";
        displayName = "$STR_ACE_optic_hamr";
        weaponInfoType = "ACE_RscWeapon_Hamr";

        class ItemInfo: ItemInfo {
            modelOptics = QUOTE(PATHTOF(models\ace_optics_reticle90.p3d));

            class OpticsModes: OpticsModes {
                class Hamr2Collimator: Hamr2Collimator {};

                class Hamr2Scope: Hamr2Scope {
                    useModelOptics = 1;
                    opticsZoomInit = 0.0872664626;
                    opticsZoomMax = 0.0872664626;
                    opticsZoomMin = 0.0872664626;
                    opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5","ACE_OpticsRadBlur1"};
                    opticsDisablePeripherialVision = 0;
                    visionMode[] = {"Normal","NVG"};
                };
            };
        };
    };

    class ACE_optic_Hamr_PIP: ACE_optic_Hamr_2D {
        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_Hamr_PIP";
        scopeArsenal = 1;
        displayName = "$STR_ACE_optic_hamr_pip";

        class ItemInfo: ItemInfo {
            modelOptics = QUOTE(PATHTOF(models\ace_optics_pip.p3d));
        };
    };

    class optic_Arco: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class ARCO2collimator;
                class ARCO2scope: ARCO2collimator {};
            };
        };
    };

    class ACE_optic_Arco_2D: optic_Arco {
        GVAR(BodyDay) = QUOTE(PATHTOF(reticles\arco-body_ca.paa));
        GVAR(BodyNight) = QUOTE(PATHTOF(reticles\arco-bodyNight_ca.paa));
        GVAR(ReticleDay) = QUOTE(PATHTOF(reticles\arco-reticle65_ca.paa));
        GVAR(ReticleNight) = QUOTE(PATHTOF(reticles\arco-reticle65Illum_ca.paa));

        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_Arco_2D";
        displayName = "$STR_ACE_optic_arco";
        weaponInfoType = "ACE_RscWeapon_Arco";

        class ItemInfo: ItemInfo {
            modelOptics = QUOTE(PATHTOF(models\ace_optics_reticle90.p3d));

            class OpticsModes: OpticsModes {
                class ARCO2collimator: ARCO2collimator {};
                class ARCO2scope: ARCO2scope {
                    useModelOptics = 1;
                    opticsZoomInit = 0.0872664626;
                    opticsZoomMax = 0.0872664626;
                    opticsZoomMin = 0.0872664626;
                    opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5","ACE_OpticsRadBlur1"};
                    opticsDisablePeripherialVision = 0;
                    visionMode[] = {"Normal"};
                };
            };
        };
    };

    class ACE_optic_Arco_PIP: ACE_optic_Arco_2D {
        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_Arco_PIP";
        scopeArsenal = 1;
        displayName = "$STR_ACE_optic_arco_pip";

        class ItemInfo: ItemInfo {
            modelOptics = QUOTE(PATHTOF(models\ace_optics_pip.p3d));
        };
    };

    class optic_MRCO: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class MRCOcq;
                class MRCOscope;
            };
        };
    };

    class ACE_optic_MRCO_2D: optic_MRCO {
        GVAR(BodyDay) = QUOTE(PATHTOF(reticles\mrco-body_ca.paa));
        GVAR(BodyNight) = QUOTE(PATHTOF(reticles\mrco-bodyNight_ca.paa));
        GVAR(ReticleDay) = QUOTE(PATHTOF(reticles\mrco-reticle556_ca.paa));
        GVAR(ReticleNight) = QUOTE(PATHTOF(reticles\mrco-reticle556Illum_ca.paa));

        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_MRCO_2D";
        displayName = "$STR_ACE_optic_valdada";
        weaponInfoType = "ACE_RscWeapon_MRCO";

        class ItemInfo: ItemInfo {
            modelOptics = QUOTE(PATHTOF(models\ace_optics_reticle90.p3d));

            class OpticsModes: OpticsModes {
                class MRCOcq: MRCOcq {};
                class MRCOscope: MRCOscope {
                    useModelOptics = 1;
                    opticsZoomInit = 0.0872664626;
                    opticsZoomMax = 0.0872664626;
                    opticsZoomMin = 0.0872664626;
                    opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5","ACE_OpticsRadBlur1"};
                    opticsDisablePeripherialVision = 0;
                    visionMode[] = {"Normal"};
                };
            };
        };
    };

    class ACE_optic_MRCO_PIP: ACE_optic_MRCO_2D {
        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_MRCO_PIP";
        scope = 1;
        scopeArsenal = 1;
        displayName = "$STR_ACE_optic_valdada_pip";

        class ItemInfo: ItemInfo {
            modelOptics = QUOTE(PATHTOF(models\ace_optics_pip.p3d));
        };
    };

    class optic_SOS: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class Snip;
                class Iron;
            };
        };
    };

    class ACE_optic_SOS_2D: optic_SOS {
        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_SOS_2D";
        displayName = "$STR_ACE_optic_sos";
        weaponInfoType = "ACE_RscWeapon_SOS";

        class ItemInfo: ItemInfo {
            class OpticsModes: OpticsModes {
                class Snip: Snip {
                    modelOptics[] = {QUOTE(PATHTOF(models\ace_optics_reticle90.p3d)),QUOTE(PATHTOF(models\ace_optics_reticle90.p3d))};
                    opticsDisablePeripherialVision = 0;
                };
                class Iron: Iron {};
            };
        };
    };

    class ACE_optic_SOS_PIP: ACE_optic_SOS_2D {
        GVAR(BodyDay) = QUOTE(PATHTOF(reticles\sos-body_ca.paa));
        GVAR(BodyNight) = QUOTE(PATHTOF(reticles\sos-bodyNight_ca.paa));
        GVAR(ReticleDay) = QUOTE(PATHTOF(reticles\sos-reticleMLR_ca.paa));
        GVAR(ReticleNight) = QUOTE(PATHTOF(reticles\sos-reticleMLRIllum_ca.paa));

        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_SOS_PIP";
        scopeArsenal = 1;
        displayName = "$STR_ACE_optic_sos_pip";

        class ItemInfo: ItemInfo {
            class OpticsModes: OpticsModes {
                class Snip: Snip {
                    modelOptics[] = {QUOTE(PATHTOF(models\ace_optics_pip.p3d)),QUOTE(PATHTOF(models\ace_optics_pip.p3d))};
                };
            };
        };
    };

    class optic_LRPS: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class Snip;
            };
        };
    };

    class ACE_optic_LRPS_2D: optic_LRPS {
        GVAR(BodyDay) = QUOTE(PATHTOF(reticles\sos-body_ca.paa));
        GVAR(BodyNight) = QUOTE(PATHTOF(reticles\sos-bodyNight_ca.paa));
        GVAR(ReticleDay) = QUOTE(PATHTOF(reticles\sos-reticleMLR_ca.paa));
        GVAR(ReticleNight) = QUOTE(PATHTOF(reticles\sos-reticleMLRIllum_ca.paa));

        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_LRPS_2D";
        displayName = "$STR_ACE_optic_lrps";
        weaponInfoType = "ACE_RscWeapon_SOS";

        class ItemInfo: ItemInfo {
            class OpticsModes: OpticsModes {
                class Snip: Snip {
                    modelOptics[] = {QUOTE(PATHTOF(models\ace_optics_reticle90.p3d)),QUOTE(PATHTOF(models\ace_optics_reticle90.p3d))};
                    useModelOptics = 1;
                    opticsZoomInit = 0.01234;
                    opticsZoomMax = 0.04673;
                    opticsZoomMin = 0.01234;
                    discreteFOV[] = {};
                    opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1","ACE_OpticsRadBlur1"};
                    opticsDisablePeripherialVision = 0;
                };
            };
        };
    };

    class ACE_optic_LRPS_PIP: ACE_optic_LRPS_2D {
        author = "$STR_ACE_Common_ACETeam";
        _generalMacro = "ACE_optic_LRPS_PIP";
        scopeArsenal = 1;
        displayName = "$STR_ACE_optic_lrps_pip";

        class ItemInfo: ItemInfo {
            class OpticsModes: OpticsModes {
                class Snip: Snip {
                    modelOptics[] = {QUOTE(PATHTOF(models\ace_optics_pip.p3d)),QUOTE(PATHTOF(models\ace_optics_pip.p3d))};
                };
            };
        };
    };
};

class SlotInfo;
class CowsSlot: SlotInfo {
    compatibleItems[] += {
        "ACE_optic_Hamr_2D",
        "ACE_optic_Hamr_PIP",
        "ACE_optic_Arco_2D",
        "ACE_optic_Arco_PIP",
        "ACE_optic_MRCO_2D",
        "ACE_optic_MRCO_PIP",
        "ACE_optic_SOS_2D",
        "ACE_optic_SOS_PIP",
        "ACE_optic_LRPS_2D",
        "ACE_optic_LRPS_PIP",
        "ACE_optic_DMS"
    };
};
