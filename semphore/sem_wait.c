//
// Created by hlhd on 2021/5/11.
//

#include "../all.h"

int mainWait(int argc, char** argv)
{
    // when sem_open() last para is M, which means "N processes compete M resources"
    sem_t* sem_ptr = sem_open("/mysem", O_CREAT, 0666, 1);
    if (sem_ptr == SEM_FAILED)
    {
        perror("sem_open");
        exit(1);
    }

    printf("sem_open success\n");

    // use while(1) to "continually" get semphore
    while (1)
    {
        sem_wait(sem_ptr);
        printf("get sem\n");
        sleep(5);
        sem_post(sem_ptr);
        printf("post sem\n");
        sleep(1);
    }

    // if we launch two processes, when "process A" get sem, we ctrl + c "process A",
    // then "process B" will stay in "post sem" state forever
    // since the "val" of sem don't ++

    sem_close(sem_ptr);
    sem_unlink("/mysem");

    return 0;
}