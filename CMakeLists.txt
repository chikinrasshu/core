cmake_minimum_required(VERSION 3.27)
project(chk_lib_core C)

set(src "mem.c" "arena.c")
set(hdr "mem.h" "arena.h" "types.h")

list(TRANSFORM src PREPEND "src/")
list(TRANSFORM hdr PREPEND "include/chk/core/")

add_library(chk_core ${src} ${hdr})
add_library(chk::core ALIAS chk_core)

target_compile_features(chk_core PUBLIC c_std_11)
target_include_directories(chk_core PUBLIC "include")
