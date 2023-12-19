cmake_minimum_required(VERSION 3.26)

project(MAIN_EXECUTABLE)

add_executable(
        MainExecutable

        from_ppsspp/GeConstants.cpp
        from_ppsspp/GPU.cpp
        from_ppsspp/GPUState.cpp
        from_ppsspp/GeDisasm.cpp
        main.cpp
)