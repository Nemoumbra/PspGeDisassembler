cmake_minimum_required(VERSION 3.26)
project(PSPGEDisasm_Sample)

add_executable(
        PSPGEDisassembler
        main.cpp
)

add_executable(
        PSPGEDisassemblerStatic
        main.cpp
)

target_link_libraries(PSPGEDisassembler PSPGEDisasm)
target_link_libraries(PSPGEDisassemblerStatic PSPGEDisasmStatic)
