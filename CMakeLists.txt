cmake_minimum_required(VERSION 3.27)
project(chk_lib_core C)

add_subdirectory("external")

set(src "arena.c" "color.c" "log.c" "mem.c" "print.c" "rect.c"
    "vec/v2.c" "vec/v3.c" "vec/v4.c" 
)
set(hdr "arena.h" "color.h" "log.h" "mem.h" "print.h" "rect.h" "types.h" 
    "vec/fwd.h" "vec/v2.h" "vec/v3.h" "vec/v4.h"
)

list(TRANSFORM src PREPEND "src/")
list(TRANSFORM hdr PREPEND "include/chk/core/")

add_library(chk_core ${src} ${hdr})
add_library(chk::core ALIAS chk_core)

target_compile_features(chk_core PUBLIC c_std_11)
target_include_directories(chk_core PUBLIC "include")

target_link_libraries(chk_core PRIVATE cwalk::cwalk)
