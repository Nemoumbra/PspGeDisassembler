//
// Created by Nemoumbra on 19.12.2023.
//
#pragma once

#include "types.h"

struct State {
    union {
        u32 cmdmem[256];
        struct {
            u32 clutaddr,
                clutaddrupper,
                base,
                transfersrc,
                transferdst,
                vertType; // 0x6
            u32 pad05[0xFF- 0x6];
        };
    };

    State() = default;

    [[nodiscard]] u32 getClutAddress() const {
        return
        (clutaddr & 0x00FFFFF0)
        |
        ((clutaddrupper << 8) & 0x0F00000);
    }
};
