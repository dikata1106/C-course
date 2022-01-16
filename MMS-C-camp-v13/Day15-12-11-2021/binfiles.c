#include <stdio.h>
#include <inttypes.h>

#define RW 1

typedef struct {
    char title[100];
    char autor[100];
    double price;
    int pages;
    int p;
} book_t;

int main(){
    #if RW == 1
    FILE* fp = fopen("binary.dat", "wb");
    book_t books[2] = {
        { .autor= "Aleko", .pages = 200, .title="Bai Ganio", .price=55.20},
        { .autor= "Dennis Richie", .pages = 300, .title="The C programming", .price=25.20}
        };
    fwrite(books, sizeof(book_t), 2, fp);
    fclose(fp);
    #else
        FILE* fp = fopen("binary.dat", "rb");
        book_t b[2];
        fread(b, sizeof(book_t), 2, fp);
        printf("Title: %s\n", b[1].title);
        fclose(fp);
    #endif
    return 0;
}