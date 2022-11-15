cmake_minimum_required(VERSION 3.20)
project(ece-city-3a C)

set(CMAKE_C_STANDARD 99)

add_executable(ece-city-3a main.c Structures/structures.c Structures/structures.h Map/map.c Map/map.h Bitmaps/bitmaps.c Bitmaps/bitmaps.h Pages/MenuPrincipal/menuPrincipal.c Pages/MenuPrincipal/menuPrincipal.h Banque/banque.c Banque/banque.h Graphe/graphe.c Graphe/graphe.h Timers/timers.c Timers/timers.h Batiments/batiments.c Batiments/batiments.h ToolBox/toolbox.c ToolBox/toolbox.h)

target_link_libraries(ece-city-3a -lmingw32 -lallegro-5.0.10-monolith-md-debug)

