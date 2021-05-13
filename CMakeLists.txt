cmake_minimum_required(VERSION 3.19)
project(systemProgram C)

set(CMAKE_C_STANDARD 11)

link_directories( /usr/lib/x86_64-linux-gnu/libpthread.so )
include_directories( /usr/lib/x86_64-linux-gnu/libpthread.a )

link_directories( /usr/lib/x86_64-linux-gnu/librt.so )
include_directories( /usr/lib/x86_64-linux-gnu/librt.a )

add_executable(systemProgram
        all.h semphore/sem_open.c semphore/sem_wait.c semphore/sem_trywait.c
        MessageQueue/mq_open.c MessageQueue/mq_send.c MessageQueue/mq_receive.c
        MessageQueue/mq_send_attr.c
        ShareMemory/shm_open.c ShareMemory/shm_write_map.c ShareMemory/shm_read_map.c
        Daemon/setDaemon.c)

target_link_libraries(systemProgram pthread rt)
