#include <stdio.h>
#include "llist.c"
int main(void){
    node_t *list1 = NULL, *list2 = NULL, *lA = NULL, *lB = NULL;
    pushEnd(&list1, 1);
    pushEnd(&list1, 2);
    pushEnd(&list1, 73);
    pushEnd(&list1, 94);
    pushEnd(&list1, 5);
    pushEnd(&list1, 6);
    //mergeSort(&list1);
    //print_listRRev(list1);
    return 0;
}

