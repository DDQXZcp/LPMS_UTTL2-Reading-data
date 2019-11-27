#include "mbed.h"
#ifndef I
#define I
union {
            uint8_t data[56];
            float valF[14];
        } posture;
#endif 