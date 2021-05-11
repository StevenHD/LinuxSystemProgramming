//
// Created by hlhd on 2021/5/11.
//

#include "../all.h"

int mainTrywait(int argc, char** argv)
{
    sem_t* sem_ptr = sem_open("/mysem", O_CREAT, 0666, 1);
    if (sem_ptr == SEM_FAILED)
    {
        perror("sem_open");
        exit(1);
    }

    printf("sem_open success\n");

    while (1)
    {
        // Non-blocking just means that Round-Robin
        if (sem_trywait(sem_ptr) == -1)
        {
            if (errno == EAGAIN)
            {
                printf("try wait again\n");
                sleep(1);
                continue;
            }

            perror("sem_trywait");
            exit(1);
        }

        printf("get sem\n");
        sleep(5);
        sem_post(sem_ptr);
        printf("post sem\n");
        sleep(1);
    }

    sem_close(sem_ptr);
    sem_unlink("/mysem");

    return 0;
}