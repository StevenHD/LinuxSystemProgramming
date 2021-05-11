//
// Created by hlhd on 2021/5/11.
//

#include "../all.h"

const char* mqName = "/mymq";

int mainSD(int argc, char** argv)
{
    mqd_t mq = mq_open(mqName, O_WRONLY | O_CREAT, 0666, NULL);
    if (mq == -1)
    {
        perror("mq_open");
        exit(1);
    }
    printf("mq_open success\n");

    char buf[32];
    int i = 0;
    int ret;
    while (1)
    {
        sprintf(buf, "DATA%d", i ++ );
        ret = mq_send(mq, buf, strlen(buf), 0);
        if (ret == -1)
        {
            perror("mq_send");
            exit(1);
        }

        printf("mq_send ret %d\n", ret);
        sleep(1);
    }

    mq_close(mq);
    mq_unlink(mqName);

    return 0;
}