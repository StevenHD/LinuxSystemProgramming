//
// Created by hlhd on 2021/5/12.
//

#include "../all.h"

const char* shareMemName = "/myshm";

int mainOPEn(int argc, char** argv)
{
    int fd = shm_open(shareMemName, O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    printf("shm_open success\n");
    ftruncate(fd, 4096);

    return 0;
}