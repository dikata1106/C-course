#include <stdio.h>
#include <stdint.h>
#define PI 3.14

#define OPEN1 1
#define OPEN2 2
#define OPEN3 4
#define OPEN4 8
#define OPEN5 16
#define OPEN6 32
#define OPEN7 64
#define OPEN8 128
#define KEY 22

int main()
{
    //printf("%d\n", ('y' ^ 'o'));
	char text[100];
	int i;

	// Input text
	printf("Enter text to encrypt: ");
	fgets(text, 100, stdin);

	// Encrypt text
	for (i=0; text[i] != '\0'; i++)
	{
		text[i] = text[i] ^ KEY;
	}

	printf("Encrypted text: %s\n", text);

	// Decrypt text
	for (i = 0; text[i] != '\0'; i++)
	{
		text[i] = text[i] ^ KEY;
	}
	
	printf("Original text: %s\n", text);

    char *str = "Hello!";
    char *key = "1yk56_";
    char msg[7];
    for (int i = 0; i < 6; i++){
        msg[i] = str[i] ^ key[i];
    }
    msg[6] = '\0';
    printf("%s\n", msg);
    for (int i = 0; i < 6; i++){
        msg[i] = msg[i] ^ key[i];
    }
    printf("%s\n", msg);
	return 0;
}