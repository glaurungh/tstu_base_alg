#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i, l;

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str)-1] == '\n')
        str[strlen(str)-1] = '\0';

    l = strlen(str);

    for(i = 0; i < l; i++) {
        freq[(int)str[i]]++;
    }

    printf("Встречаемость символов:\n");
    for(i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            printf("'%c': %d\n", (char)i, freq[i]);
        }
    }

    return 0;
}
