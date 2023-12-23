cmake_minimum_required(VERSION 3.26)

project(PSPGEDisasm_Library)


add_library(
        PSPGEDisasm
        SHARED
        GE_Disasm.cpp
)
add_library(
        PSPGEDisasmStatic
        STATIC
        GE_Disasm.cpp
)