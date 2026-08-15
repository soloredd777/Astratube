cmake_minimum_required(VERSION 3.16)

include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

project(Astratube)

set(VITA_APP_NAME "Astratube")
set(VITA_TITLEID "ASTR00001")
set(VITA_VERSION "01.00")

add_executable(Astratube
    src/main.c
)

target_link_libraries(Astratube
    vita2d
    SceCtrl_stub
    SceTouch_stub
)

vita_create_self(Astratube.self Astratube)

vita_create_vpk(Astratube.vpk ${VITA_TITLEID} Astratube.self
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
)
