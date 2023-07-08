cmake_minimum_required(VERSION 3.23)

project(
        PLSCDemo
        VERSION 0.1
        LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set(CMAKE_CXX_STANDARD 20)
endif ()

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

add_subdirectory(src)

if (WIN32 OR MSYS OR MINGW)
    target_compile_definitions(PLSCDemo PRIVATE SDL_MAIN_HANDLED)
endif ()

add_subdirectory(parlitesc)

target_link_libraries(PLSCDemo
        PRIVATE
        PLSC
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2MAIN>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>

        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        )