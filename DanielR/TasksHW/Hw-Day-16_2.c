#include <unistd.h>

// can do it better with formatters using machine state and no one library function.
// int myfprintf(int channel, char *str) {
//     if (channel < 0 || str == NULL) {
//         return -1;
//     }
//     return write(channel, str, strlen(str));    // uses string.h
// }

int myfprintf2(int channel, char *str) {
    int n = 0;
    if (channel < 0 || str == NULL) {
        return -1;
    }
    while (str[n] != '\0') {
        write(channel, &str[n++], 1);
    }
    return n;
}

int main(void) {

    // myfprintf(1, "heyaa'\n");
    myfprintf2(1, "heyyaaaa adeuu\n");
    return 0;
}