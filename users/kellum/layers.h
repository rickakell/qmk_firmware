#pragma once

#define TO_DEF TO(DEF)
#define TO_CAN TO(CAN)
#define TO_COL TO(COL)
#define TO_QWE TO(QWE)
#define TO_HDN TO(HDN)
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define TO_GME TO(GME)
#define TO_MSE TO(MSE)
#define LA_SPL MO(SPD)
#define TO_ART TO(ART)

enum layers {
    DEF, // Default
    CAN, // Canary
    COL, // Colemak
    QWE, // Qwerty
    HDN, // Hands Down Nue
    SYM, // Symbols
    NAV, // Navigation
    NUM, // Numbers and Function
    GME, // Game
    MSE, // Mouse
    ART,
    SPD, // Special
};
