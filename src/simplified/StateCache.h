//
// Created by Nemoumbra on 19.12.2023.
//

#pragma once
#include "types.h"

struct StateCache {
    u32 vertexAddr;
    u32 indexAddr;
    u32 offsetAddr;

    StateCache(): vertexAddr(0), indexAddr(0), offsetAddr(0) {}
};
