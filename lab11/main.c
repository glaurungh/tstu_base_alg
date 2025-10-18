#include <stdio.h>

int digits(const char* s) {
    if (*s == '\0') return 0;
    return (*s >= '0' && *s <= '9') + digits(s + 1);
}

int main() {
    char str[256];
    fgets(str, sizeof(str), stdin);
    printf("Количество цифр: %d\n", digits(str));
    return 0;
}
