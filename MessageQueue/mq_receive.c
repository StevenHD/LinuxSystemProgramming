//
// Created by hlhd on 2021/5/11.
//

#include "../all.h"

const char* mqRecName = "/mymq";

int main(int argc, char** argv)
{
    mqd_t mq = mq_open(mqRecName, O_RDONLY | O_CREAT, 0666, NULL);
    if (mq == -1)
    {
        perror("mq_open");
        exit(1);
    }
    printf("mq_open success\n");

    // char buf[32];   // maybe lead to "out of memory", since this is "stack"
    int i = 0;
    int ret, msg_prio;
    struct mq_attr attr;
    mq_getattr(mq, &attr);
    char* buf = (char*) malloc(attr.mq_msgsize);

    while (1)
    {
        sprintf(buf, "DATA%d", i ++ );
        // ret = mq_receive(mq, buf, strlen(buf), &msg_prio);
        ret = mq_receive(mq, buf, attr.mq_msgsize, &msg_prio);
        if (ret == -1)
        {
            perror("mq_receive");
            exit(1);
        }
        buf[ret] = '\0';

        printf("mq_receive receive %d bytes, buf is %s, msg_prio is %d\n", ret, buf, msg_prio);
        sleep(1);
    }

    free(buf);
    mq_close(mq);
    mq_unlink(mqRecName);

    return 0;
}