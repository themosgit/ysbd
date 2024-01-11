cmake_minimum_required(VERSION 3.16)
project(untitled C)
set(CMAKE_C_STANDARD 99)
include_directories(./examples ./include ./lib ./src)
link_directories(lib)

add_executable(sort  ./lib/libbf.so ./lib/libhp_file.so ./examples/sort_main.c
        ./src/record.c ./src/chunk.c ./src/merge.c ./src/sort.c
        ./include/record.h include/hp_file.h ./include/bf.h ./include/chunk.h ./include/merge.h ./include/sort.h)

add_executable(test  ./lib/libbf.so ./lib/libhp_file.so ./examples/test.c
        ./src/record.c ./src/chunk.c ./src/merge.c ./src/sort.c
        ./include/record.h include/hp_file.h ./include/bf.h ./include/chunk.h ./include/merge.h ./include/sort.h)


target_link_libraries(sort libbf.so libhp_file.so)

target_link_libraries(test libbf.so libhp_file.so)

