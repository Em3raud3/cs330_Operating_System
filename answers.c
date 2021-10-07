/header files included
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
        printf("First pipe failed");
        return 1;
    }

    if (pipe(pipeB) == -1)
    {
        printf("Second pipe failed");
        return 1;
    }

    //#1 Code to create pipe B:
    pid = fork(); //creating a child process using fork system call

    if (pid > 0)
    {
        //it must be the parent process
        //closing the unused end of each pipe
        close(pipeA[READ_END]);
        close(pipeB[WRITE_END]);

        //now writing the message to the pipe A
        write(pipeA[WRITE_END], write_msg, strlen(write_msg) + 1);
        //now after writing, close the write end of pipe A
        close(pipeA[WRITE_END]);

        //read the converted string when it is available
        read(pipeB[READ_END], read_msg, BUFFER_SIZE);

        //print the read message
        printf("parent read > %s <\n", read_msg);

        //now close the read end of pipeB
        close(pipeB[READ_END]);
    }
    else
    {
        //it must be the child process
        //closing unused ends of the pipes
        close(pipeA[WRITE_END]);
        close(pipeB[READ_END]);

        //read the message from pipeA
        read(pipeA[READ_END], read_msg, BUFFER_SIZE);
        printf("child read > %s <\n", read_msg);

        //reverse the string
        for (int i = 0; i < strlen(read_msg); i++)
        {
            if (isupper(read_msg[i]))
                write_msg[i] = tolower(read_msg[i]);
            else if (islower(read_msg[i]))
                write_msg[i] = toupper(read_msg[i]);
            else
                write_msg[i] = read_msg[i];
        }

        //write the updated message to pipeB
        write(pipeB[WRITE_END], write_msg, strlen(write_msg) + 1);

        //close remaining ends of pipes
        close(pipeA[READ_END]);
        close(pipeB[WRITE_END]);
    }

    printf("\n");
    return 0;
}