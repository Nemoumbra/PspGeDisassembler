//
// Created by Nemoumbra on 19.12.2023.
//

#pragma once

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using s8 = signed char;
using s16 = signed short;
using s32 = signed int;
using s64 = signed long long;



enum SignalBehavior {
    PSP_GE_SIGNAL_NONE             = 0x00,
    PSP_GE_SIGNAL_HANDLER_SUSPEND  = 0x01,
    PSP_GE_SIGNAL_HANDLER_CONTINUE = 0x02,
    PSP_GE_SIGNAL_HANDLER_PAUSE    = 0x03,
    PSP_GE_SIGNAL_SYNC             = 0x08,
    PSP_GE_SIGNAL_JUMP             = 0x10,
    PSP_GE_SIGNAL_CALL             = 0x11,
    PSP_GE_SIGNAL_RET              = 0x12,
    PSP_GE_SIGNAL_RJUMP            = 0x13,
    PSP_GE_SIGNAL_RCALL            = 0x14,
    PSP_GE_SIGNAL_OJUMP            = 0x15,
    PSP_GE_SIGNAL_OCALL            = 0x16,

    PSP_GE_SIGNAL_RTBP0            = 0x20,
    PSP_GE_SIGNAL_RTBP1            = 0x21,
    PSP_GE_SIGNAL_RTBP2            = 0x22,
    PSP_GE_SIGNAL_RTBP3            = 0x23,
    PSP_GE_SIGNAL_RTBP4            = 0x24,
    PSP_GE_SIGNAL_RTBP5            = 0x25,
    PSP_GE_SIGNAL_RTBP6            = 0x26,
    PSP_GE_SIGNAL_RTBP7            = 0x27,
    PSP_GE_SIGNAL_OTBP0            = 0x28,
    PSP_GE_SIGNAL_OTBP1            = 0x29,
    PSP_GE_SIGNAL_OTBP2            = 0x2A,
    PSP_GE_SIGNAL_OTBP3            = 0x2B,
    PSP_GE_SIGNAL_OTBP4            = 0x2C,
    PSP_GE_SIGNAL_OTBP5            = 0x2D,
    PSP_GE_SIGNAL_OTBP6            = 0x2E,
    PSP_GE_SIGNAL_OTBP7            = 0x2F,
    PSP_GE_SIGNAL_RCBP             = 0x30,
    PSP_GE_SIGNAL_OCBP             = 0x38,
    PSP_GE_SIGNAL_BREAK1           = 0xF0,
    PSP_GE_SIGNAL_BREAK2           = 0xFF,
};

