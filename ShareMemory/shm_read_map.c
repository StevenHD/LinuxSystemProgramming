//
// Created by hlhd on 2021/5/12.
//

#include "../all.h"

const char* shareReadMemName = "/myshm";
int mapRdLen = 4096;

int mainSRM(int argc, char** argv)
{
    int fd = shm_open(shareReadMemName, O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    printf("shm_open success\n");
    ftruncate(fd, 4096);

    // mmap
    void* ptr = mmap(0, mapRdLen, PROT_READ, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap");

        exit(1);
    }
    printf("mmap success\n");

    int i = 0;
    while (i ++ < 10)
    {
        printf("read share memory %s\n", (char*)ptr);
        sleep(1);
    }

    munmap(ptr, mapRdLen);
    shm_unlink(shareReadMemName);

    return 0;
}