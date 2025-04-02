#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t child;
    int status;
    
    char* env[] = { "env1", "env2", "env3", NULL};

    for (size_t i = 1; i < argc; i++) {
        printf("arg No.%zu - %s;\n", i, argv[i]);
    }

    pid_t pid = fork();
    if (pid == -1) {

        perror("fork");

    } else if (pid == 0) {

        child = getpid();
        execle("lab4_1", "arg1_first", "arg2_second", "arg3_third", NULL, env);

    } else {
        
        printf("lab4_2 id: %d; parent id: %d; child id: %d\n", getpid(), getppid(), child);


        while (waitpid(0, &status, WNOHANG) == 0) {

            printf(" Wait for lab4_1 to end...\n");
            usleep(500000);
        }
        printf("Exit child code: %d\n", WEXITSTATUS(status));
    }

    return 0;
}