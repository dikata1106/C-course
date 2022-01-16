#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define RW 1

typedef struct {
    int num;
    double price;
    char title[100];
} book_t;

typedef enum { left=2, right, up=1, down } dir_t;

int main(void){
    dir_t d, e;
    d = down;
    printf("%lu ", sizeof(dir_t));
    book_t b1, b2;
    book_t books[2];
  #if !RW
    strncpy(books[0].title, "This is the world", 100);
    strncpy(books[1].title, "The linux command line", 100);
    books[0].num = 10;
    books[1].num = 30;
    books[0].price = 50;
    books[1].price = 5.60;
    FILE* fp = fopen("books.data", "wb");
    fwrite(books, sizeof(book_t), 2, fp);
    //fwrite(&b2, sizeof(book_t), 1, fp);
    fclose(fp);
#elif RW
    FILE* fp = fopen("books.data", "rb");
    fseek(fp, sizeof(book_t), SEEK_SET);
    fread(&b1, sizeof(book_t), 1, fp);
    fseek(fp, -sizeof(book_t), SEEK_CUR);
    fread(&b2, sizeof(book_t), 1, fp);
    printf("%ld\n", ftell(fp));
    fclose(fp);
    printf("Book 1: %s, %d, %.2lf\n", b1.title, b1.num, b1.price);
    printf("Book 2: %s, %d, %.2lf\n", b2.title, b2.num, b2.price);
    printf("%lu\n", sizeof(book_t));
    fprintf(stderr, "Erorrr\n");
#endif
    return 0;
}