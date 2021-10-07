#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <string.h> 

#define BUFFER_SIZE 25 
#define READ_END 0 
#define WRITE_END 1 

int main(int argc, char *argv[]) {

    char write_msg[BUFFER_SIZE] = "Greetings"; 
    char read_msg[BUFFER_SIZE]; 
    pid_t pORc; 
    int pipeA[2]; /*int array: 0 = read; 1 = write */ 

    if (pipe(pipeA) == -1) {  /* create the pipe */ 
        printf("Pipe failed"); 
        return 1; 
        }

    pORc = fork(); /* fork a child process */ 

    if (pORc < 0) { 
        printf("Fork failed"); return 1; 
        } 

    if (pORc > 0) { /* parent process */ 
        close(pipeA[READ_END]); /* close unused end */ 
        write(pipeA[WRITE_END], write_msg, 
        strlen(write_msg)+1); /* write to the pipe */ 
        close(pipeA[WRITE_END]); /* close write end */ 
        } 

    else { /* child process */ 
        close(pipeA[WRITE_END]); /* close unused end */ 
        read(pipeA[READ_END],
        read_msg,BUFFER_SIZE); /* read from the pipe */ 
        close(pipeA[READ_END]); /* close write end */ 
        printf("child read %s\n",read_msg); 
        } 
    return 0; 
}