//
// Created by Nemoumbra on 19.12.2023.
//

#pragma once
#include "simplified/State.h"
#include "simplified/StateCache.h"

#include <vector>
#include <string>
#include <cstdint>

struct GPUDebugOp {
    u32 pc;
    u8 cmd;
    u32 op;
    std::string desc;
};

class GE_Disasm {
private:
    State gstate{};
    StateCache gstate_c{};

    [[nodiscard]] inline u32 getRelativeAddress(u32 data) const {
        u32 baseExtended = ((gstate.base & 0x000F0000) << 8) | data;
        return (gstate_c.offsetAddr + baseExtended) & 0x0FFFFFFF;
    }

    // PSP uses a curious 24-bit float - it's the top 24 bits of a regular IEEE754 32-bit float.
    // This is used for light positions, transform matrices, you name it.
    static float getFloat24(unsigned int data);

    static void GeDescribeVertexType(u32 op, char *buffer, int len);

    static constexpr const char *colorNames[] = {
            nullptr,
            "unsupported1",
            "unsupported2",
            "unsupported3",
            "BGR 565",
            "ABGR 1555",
            "ABGR 4444",
            "ABGR 8888",
    };
    static constexpr const char *typeNames[] = {
            nullptr,
            "u8",
            "u16",
            "float",
    };

    static constexpr const char *typeNamesI[] = {
            nullptr,
            "u8",
            "u16",
            "u32",
    };
    static constexpr const char *typeNamesS[] = {
            nullptr,
            "s8",
            "s16",
            "float",
    };

    static constexpr const char * const primTypes[8] = {
            "POINTS",
            "LINES",
            "LINE_STRIP",
            "TRIANGLES",
            "TRIANGLE_STRIP",
            "TRIANGLE_FAN",
            "RECTANGLES",
            "CONTINUE_PREVIOUS",
    };

public:
    GE_Disasm() = default;

    void GeDisassembleOp(u32 pc, u32 op, u32 prev, char *buffer, int bufsize);
    [[nodiscard]] std::vector<GPUDebugOp> DisassembleOpcodeRange(const std::vector<uint8_t>& data);
    GPUDebugOp DisassembleOpcode(u32 op, u32 pc);
};