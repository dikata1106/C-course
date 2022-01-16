#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>


int count1(char *strKey, int fd) {
    int cnt = 0, state = 0, i = 0, len = strlen(strKey);
    char c;
    printf("%d\n", len);
    while (read(fd, &c, 1) == 1) {
        printf("%c %c %d %d\n", c,strKey[i], state, i);
        switch (state) {
        case 0:
            if (c == strKey[i]) {
                i++;
                state = 1;
            }
            break;
        case 1:
            if (i == len) {
                cnt++;
                i = 0;
                state = 0;
            } else if (c == strKey[i]) {
                i++;
            } else if (c == strKey[0]) {
                i == 1;
            }else {
                i = 0;
                state = 0;
            }
            break;
        default:
            break;
        }
    }
    return cnt;
}

int main(int argc, char **argv) {
    printf("NOTE: the FSM is not working propertly\n");
    if (argc < 3) {
        fprintf(stderr, "Wrong use.\nUSE: %s keyword file1 [list_of_files_2..n]", argv[0]);
    }
    
    int i, sum = 0, pfd[2], fd, cnt = 0, n;
    char buf[512];
    char word1[sizeof(argv[1])];
    char word2[sizeof(argv[1])];
    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    for (i=2; i<argc; i++) {
        switch (fork()) {
            case -1:
                perror("fork");
                exit(EXIT_FAILURE);
                break;
            case 0:
                strcmp(word1, argv[1]);
                if (close(pfd[0]) == -1) {
                    perror("close pfd in fork");
                }
                fd = open(argv[i], O_RDONLY);
                if (fd == -1) {
                    perror("open");
                } else {
                    cnt = count1(argv[1], fd);
                    close(fd);
                }
                sprintf(buf, "%d", cnt);
                if (write(pfd[1], buf, strlen(buf)) < 0) {
                    perror("write");
                }
                fprintf(stdout, "%s - %d\n", argv[i], cnt);
                exit(EXIT_SUCCESS);
                break;
            default:
                break;
        }
    }

    for (i=2; i<argc; i++) {
        read(pfd[0], buf, sizeof(buf));
        sum += atoi(buf);
    }
    while(wait(NULL) !=- 1);
    fprintf(stdout, "TOTAL - %d\n", sum);
    exit(EXIT_SUCCESS);
}