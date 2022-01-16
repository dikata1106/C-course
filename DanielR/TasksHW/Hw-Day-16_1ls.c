#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>



int main(int argc, char **argv){
    DIR *dir;
    struct dirent *entry;
    char dirname[256];
    int mode = 0;
    if(argc > 3 || strcmp(argv[1], "--help")==0) {
        fprintf(stderr, "Usage: %s [--help | -{a, f, d, ad, af}] [path_to_dir]\n", argv[0]);
        // -all -files -directories
        exit(EXIT_FAILURE);
    }
    if(1 == argc) {
        strcpy(dirname, ".");
        mode = 0;
    } else if (2 == argc && argv[1][0] =='-'){
        if((strcmp(argv[1], "-a")) == 0 || 
         (strcmp(argv[1], "-afd")) == 0 ||
         (strcmp(argv[1], "-adf")) == 0 ||
         (strcmp(argv[1], "-fda")) == 0 || 
         (strcmp(argv[1], "-fad")) == 0 || 
         (strcmp(argv[1], "-daf")) == 0 || 
         (strcmp(argv[1], "-dfa")) == 0) {
            mode = 1;
        } else if ((strcmp(argv[1], "-f")) == 0) {
            mode = 2;
        } else if((strcmp(argv[1], "-d")) == 0) {
            mode = 3;
        } else if((strcmp(argv[1], "-af")) == 0||
                  (strcmp(argv[1], "-fa")) == 0) {
            mode = 4;
        } else if((strcmp(argv[1], "-ad")) == 0||
                  (strcmp(argv[1], "-da")) == 0) {
            mode = 5;
        } else if((strcmp(argv[1], "-fd")) == 0 ||
                  (strcmp(argv[1], "-df")) == 0) {
            mode = 0;
        } else {
            fprintf(stderr, "Wrong option %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        strcpy(dirname, ".");
    } else if (2 == argc) {
        strcpy(dirname, argv[1]);
    } else {
        if(argv[1][0] =='-') {
            if((strcmp(argv[1], "-a")) == 0 || 
            (strcmp(argv[1], "-afd")) == 0 ||
            (strcmp(argv[1], "-adf")) == 0 ||
            (strcmp(argv[1], "-fda")) == 0 || 
            (strcmp(argv[1], "-fad")) == 0 || 
            (strcmp(argv[1], "-daf")) == 0 || 
            (strcmp(argv[1], "-dfa")) == 0) {
                mode = 1;
            } else if ((strcmp(argv[1], "-f")) == 0) {
                mode = 2;
            } else if((strcmp(argv[1], "-d")) == 0) {
                mode = 3;
            } else if((strcmp(argv[1], "-af")) == 0||
                    (strcmp(argv[1], "-fa")) == 0) {
                mode = 4;
            } else if((strcmp(argv[1], "-ad")) == 0||
                    (strcmp(argv[1], "-da")) == 0) {
                mode = 5;
            } else if((strcmp(argv[1], "-fd")) == 0 ||
                    (strcmp(argv[1], "-df")) == 0) {
                mode = 0;
            } else {
                fprintf(stderr, "Wrong option %s\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            strcpy(dirname, argv[2]);
        } else {
            if((strcmp(argv[2], "-a")) == 0 || 
            (strcmp(argv[2], "-afd")) == 0 ||
            (strcmp(argv[2], "-adf")) == 0 ||
            (strcmp(argv[2], "-fda")) == 0 || 
            (strcmp(argv[2], "-fad")) == 0 || 
            (strcmp(argv[2], "-daf")) == 0 || 
            (strcmp(argv[2], "-dfa")) == 0) {
                mode = 1;
            } else if ((strcmp(argv[2], "-f")) == 0) {
                mode = 2;
            } else if((strcmp(argv[2], "-d")) == 0) {
                mode = 3;
            } else if((strcmp(argv[2], "-af")) == 0||
                    (strcmp(argv[2], "-fa")) == 0) {
                mode = 4;
            } else if((strcmp(argv[2], "-ad")) == 0||
                    (strcmp(argv[2], "-da")) == 0) {
                mode = 5;
            } else if((strcmp(argv[2], "-fd")) == 0 ||
                    (strcmp(argv[2], "-df")) == 0) {
                mode = 0;
            } else {
                fprintf(stderr, "Wrong option %s\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            strcpy(dirname, argv[1]);
        }

    }
    if ((dir = opendir(dirname)) == NULL){
        perror("opendir() error");
        exit(EXIT_FAILURE);
    }
    
    switch (mode) {
    case 0:
        // without options (or -fd -df)
        while ((entry = readdir(dir)) != NULL){
            if (*(entry->d_name) != '.'){
                printf("%s\n", entry->d_name);
            }
        }
        break;
    case 1:
        // -a (or -afd -adf -daf -dfa -fad -fda)
        while ((entry = readdir(dir)) != NULL){
            printf("%s\n", entry->d_name);
        }
        break;
    case 2:
        // -f
        while ((entry = readdir(dir)) != NULL){
            if (*(entry->d_name) != '.' && entry->d_type != DT_DIR){
                printf("%s\n", entry->d_name);
            }
        }
        break;
    case 3:
        // -d
        while ((entry = readdir(dir)) != NULL){
            if (*(entry->d_name) != '.' && entry->d_type == DT_DIR){
                printf("%s\n", entry->d_name);
            }
        }
        break;
    case 4:
        // -af -fa
        while ((entry = readdir(dir)) != NULL){
            if (entry->d_type != DT_DIR){
                printf("%s\n", entry->d_name);
            }
        }
        break;
    case 5:
        // -ad -da
        while ((entry = readdir(dir)) != NULL){
            if (entry->d_type == DT_DIR){
                printf("%s\n", entry->d_name);
            }
        }
        break;
    default:
        break;
    }
    if (closedir(dir) != 0) {
        perror("closedir() error");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}