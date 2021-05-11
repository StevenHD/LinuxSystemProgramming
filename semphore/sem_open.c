//
// Created by hlhd on 2021/5/11.
//

#include "../all.h"

int mainOpen(int argc, char** argv)
{
    sem_t* sem_ptr = sem_open("/mysem", O_CREAT, 0666, 1);
    if (sem_ptr == SEM_FAILED)
    {
        perror("sem_open");
        exit(1);
    }

    printf("sem_open success\n"); // if success, check "ls -l /dev/shm"

    sem_close(sem_ptr);
    sem_unlink("/mysem");    // RefCnt --

    // "/mysem" is better than "mysem" when cross-platform

    return 0;
}