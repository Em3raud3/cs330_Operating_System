#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    pid_t pid;
    int pipeA[2];
    int pipeB[2];
    int i;

    if (pipe(pipeA) == -1)
    {
        printf("First Pipe failed");
        return 1;
    }

    /* #1: code to create pipeB goes here */
    pid = fork();

    /* #2: code to check for fork failure goes here */
    if (pid > 0)
    { /* parent process */

        /* close the unused ends of each pipe */
        close(pipeA[READ_END]);
        close(____________________);

        /* write message into the pipe */
        write(pipeA[WRITE_END], write_msg, strlen(write_msg) + 1);

        /* close the write end of pipeA */
        close(_____________________);

        /* read the converted string from pipeB when it's available */
        read(pipeB[READ_END], read_msg, BUFFER_SIZE);

        printf("parent read >%s<\n", read_msg);
        /* code to close pipeB goes here */
    }

    else
    { /* we must be the child process */

        /* close the unused ends of the pipes */
        close(_____________________);
        close(_____________________);

        /* read from pipeA */
        read(_________________________________________);
        printf("child read >%s<\n", read_msg);

        /* reverse the string */
        for (i = 0; i < strlen(read_msg); i++)
        {
            if (isupper(read_msg[i]))
                write_msg[i] = to_____(read_msg[i]);
            else if (islower(read_msg[i]))
                write_msg[i] = to_____(read_msg[i]);
            else
                write_msg[i] = ___________;
        }

        /* write to pipeB */
        write(pipeB[WRITE_END], write_msg, strlen(write_msg) + 1);

        /* close the pipes*/
        close(______________________);
        close(______________________);
    }
    return 0;
}