//
// Created by hlhd on 2021/5/13.
//

#include "../all.h"

void initDaemon()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        setsid();
        chdir("/"); // only use root to create file in "/",
                        // in the end only use "kill" to kill the daemon process
        umask(0000);
        int i = 0;
        for (; i < NOFILE; i ++ ) close(i);
    }
    else if (pid > 0)
    {
        exit(0);
    }
    else if (pid == -1)
    {
        perror("fork");
    }
}

int main(int argc, char** argv)
{
    FILE* fp;
    time_t nowTime;

    initDaemon();

    while (1)
    {
        fp = fopen("log", "a+");
        if (fp == NULL)
        {
            perror("fopen");
            exit(1);
        }

        nowTime = time(NULL);
        fputs(ctime(&nowTime), fp);
        fclose(fp);
        sleep(1);
    }

    return 0;
}