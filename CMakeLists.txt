cmake_minimum_required(VERSION 3.19)
project(systemProgram C)

set(CMAKE_C_STANDARD 11)

link_directories( /usr/lib/x86_64-linux-gnu/libpthread.so )
include_directories( /usr/lib/x86_64-linux-gnu/libpthread.a )

add_executable(systemProgram
        all.h semphore/sem_open.c semphore/sem_wait.c semphore/sem_trywait.c)

target_link_libraries(systemProgram pthread)
