#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void){

    printf("Test Message");

    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    pid_t pid;
    int pipeA[2];
    int pipeB[2];
    int i;   

    if (pipe(pipeA) == -1) {
        printf("First Pipe failed");
        return 1;
    }

    /*! #1: code to create pipeB goes here */

    if (pipe(pipeB) == -1) {  
    printf("Second Pipe failed"); 
    return 1; 
    }

    pid = fork();

    /* #2: code to check for fork failure goes here */

    if (pid > 0) { /* parent process */
    
        /* close the unused ends of each pipe */
        close(pipeA[READ_END]);
        close(pipeB[WRITE_END]);

        /* write message into the pipe */
        write(pipeA[WRITE_END], write_msg, strlen(write_msg)+1); 

        /* close the write end of pipeA */
        close(pipeA[WRITE_END]);

        /* read the converted string from pipeB when it's available */
        read(pipeB[READ_END], read_msg, BUFFER_SIZE);
        
        printf("parent read >%s<\n",read_msg);
        /* code to close pipeB goes here */
    }

    else { /* we must be the child process */
        /* close the unused ends of the pipes */
        close(pipeA[WRITE_END]);
        close(pipeB[READ_END]);

        /* read from pipeA */
        read(pipeA[READ_END], read_msg, BUFFER_SIZE);
        printf("child read >%s<\n",read_msg);

        /* reverse the string */
        for (i = 0; i < strlen(read_msg); i++) {

            if (isupper(read_msg[i]))
                write_msg[i] = tolower(read_msg[i]);

            else if (islower(read_msg[i]))
                write_msg[i] = toupper(read_msg[i]);

            else
                write_msg[i] = read_msg[i];
        }

        /* write to pipeB */
        write(pipeB[WRITE_END], write_msg, strlen(write_msg)+1);

        /* close the pipes*/
        close(pipeA[READ_END]);
        close(pipeB[WRITE_END]);
    }

        return 0;
            
}