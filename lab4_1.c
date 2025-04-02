#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]) {
    printf("lab4_1 id: %d; parent id: %d\n", getpid(), getppid());
    
    for (size_t i = 0; i < argc; i++) {
        printf("arg No.%zu - %s; ", i, argv[i]);
        sleep(1);
    }

    printf("\n");

    size_t envCount = 0;
    for(char** env = envp; *env != NULL; env++){
        printf("Env No.%zu - %s; ", envCount, *env);
        envCount++;
    }

    printf("\n");

    exit(5);
}