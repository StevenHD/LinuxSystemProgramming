//
// Created by hlhd on 2021/5/11.
//

#include "../all.h"

const char* mq_name = "/mymq";

int mainop(int argc, char** argv)
{
    mqd_t mq = mq_open(mq_name, O_RDONLY | O_CREAT, 0666, NULL);
    if (mq == -1)
    {
        perror("mq_open");
        exit(1);
    }
    printf("mq_open success");

    mq_close(mq);
    mq_unlink(mq_name);

    return 0;
}