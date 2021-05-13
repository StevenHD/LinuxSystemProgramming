//
// Created by hlhd on 2021/5/12.
//

#include "../all.h"

const char* shareWriteMemName = "/myshm";
int mapLen = 4096;

int mainWR(int argc, char** argv)
{
    int fd = shm_open(shareWriteMemName, O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    printf("shm_open success\n");
    ftruncate(fd, 4096);

    // mmap
    void* ptr = mmap(0, mapLen, PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }
    printf("mmap success\n");

    int i = 0;
    while (1)
    {
        sprintf((char*)ptr, "DATA%d", i ++ );
        printf("write share memory\n");
        sleep(1);
    }

    munmap(ptr, mapLen);
    shm_unlink(shareWriteMemName);

    return 0;
}