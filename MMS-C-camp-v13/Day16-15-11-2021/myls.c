#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char **argv){
     DIR *dir;
     struct dirent *entry;
     char dirname[200];
     strcpy(dirname, ".");
     if (argc == 2){
         strcpy(dirname, argv[1]);
     }
    if ((dir = opendir(dirname)) == NULL){
        perror("opendir() error");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL){
        if (*(entry->d_name) != '.' && entry->d_type == DT_DIR){
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);
    return 0;
}