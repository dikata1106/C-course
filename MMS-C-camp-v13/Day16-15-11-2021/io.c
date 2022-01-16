#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>

#include <errno.h>
extern int errno;

void repeatInput(void);
int mygetchar(void);
int mygetcharB(void);
void strrev(char *str);
void itostr(char* buf, int num);
void ftostr(char* buf, double num);
int myputchar(int c);
int myprintf(char *fmt, ...);



typedef struct {
    char title[100];
    int num;
    double price;
} book_t;

void head(int fd, unsigned rows);
void readBack(int fd);

int main(int argc, char **argv){

    int fd = open("myfile3434.txt", O_WRONLY, 0777);
    if (-1 == fd){
        perror("Opening file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return EXIT_SUCCESS;
}


/*
void head(int fd, unsigned rows){
    char ch;
    int n = 0;
    while (read(fd, &ch, 1)){
        write(STDOUT_FILENO, &ch, 1);
        if (ch == '\n'){
            if(++n == rows){
                return;
            }
        }
    }
}

void readBack(int fd){
    char ch;
    int n = -1;
    while (lseek(fd, n, SEEK_END) != -1){
        read(fd, &ch, 1);
        write(STDOUT_FILENO, &ch, 1);
        n--;
    }
    ch = '\n';
    write(STDOUT_FILENO, &ch, 1);
    
}

void repeatInput(void){
    char buf[BUFSIZ];
    int n;
    while ((n = read(STDIN_FILENO, buf, BUFSIZ)) > 0){
        write(STDOUT_FILENO, buf, n);
    }
}

int mygetchar(void){
    char c;
    return (read(STDIN_FILENO, &c, 1) ? (unsigned char)c : EOF);
}

int mygetcharB(void){
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;
    if (n == 0){
        n = read(STDIN_FILENO, buf, BUFSIZ);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

void strrev(char *str){
      int len = strlen(str);
      for (int i = 0; i < len / 2; i++){
          char c = str[i];
          str[i] = str[len - i - 1];
          str[len - i - 1] = c; 
      }
}

void itostr(char* buf, int num){
    int n = 0;
    int negative = 0;
    if (num < 0){
        n++;
        num = -num;
        negative = 1;
    }
    while (num != 0){
        buf[n++] = num % 10 + '0';
        num /= 10;
    }
    buf[n] = '\0';
    if (negative){
        buf[0] = '-';
        strrev(buf + 1);
    } else {
        strrev(buf);
    }
}

void ftostr(char* buf, double num){
    int n = num * 100;
    itostr(buf, n);
    int len = strlen(buf);
    if (len == 2){
        buf[2] = buf[1];
        buf[1] = buf[0];
        buf[0] = '0';
        len++;
    }
    buf[len] = buf[len - 1];
    buf[len - 1] = buf[len - 2];
    buf[len - 2] = '.';
    buf[len + 1] = '\0';
}

int myputchar(int c){
    return write(STDOUT_FILENO, &c, 1) ? (unsigned char)c : EOF;
}

int myprintf(char *fmt, ...){
    int cnt;
    int num;
    double dbl;
    char *s;
    char buf[200];
    char ch;
    va_list args;
    va_start(args, fmt);
    for (char* p = fmt; *p != '\0'; p++){
        if (*p != '%'){
            write(STDOUT_FILENO, p, 1);
            continue;
        }
        switch (*++p)
        {
        case 'd':
            num = va_arg(args, int);
            itostr(buf, num);
            write(STDOUT_FILENO, buf, strlen(buf));
            break;
        case 's':
            s = va_arg(args, char*);
            write(STDOUT_FILENO, s, strlen(s));
            break;
        case 'c':
            num = va_arg(args, int);
            write(STDOUT_FILENO, &num, 1);
            break;
        case 'f':
            dbl = va_arg(args, double);
            ftostr(buf,С Ваше позволение бих искал, ако няма друг начин да записвам лекциите.  dbl);
            write(STDOUT_FILENO, &buf, strlen(buf));
            break;
        case '%':
            ch = '%';
            write(STDOUT_FILENO, &ch, 1);
            break;
        case 'n':
            ch = '\n';
            write(STDOUT_FILENO, &ch, 1);
        default:
            break;
        }
    }
    va_end(args);
} */