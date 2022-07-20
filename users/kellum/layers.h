#pragma once

#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define TO_GME TO(GME)
#define TO_DEF TO(DEF)
#define TO_MSE TO(MSE)
#define LA_SPL MO(SPD)
#define TO_ART TO(ART)

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    GME,
    MSE,
    ART,
    SPD,
};
