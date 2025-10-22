#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], *word;
    char words[100][100];
    int word_count = 0;
    
    printf("Введите текст: ");
    fgets(text, sizeof(text), stdin);
    
    // Разбивка на слова
    word = strtok(text, " ,.!?:;\"()\n\t");
    while (word && word_count < 100) {
       strcpy(words[word_count], word);
       word_count++;
       word = strtok(NULL, " ,.!?:;\"()\n\t");
    }
    
    if (word_count == 0) {
        printf("Нет слов.\n");
        return 0;
    }
    
    char voiced[] = "бвгджзйлмнр";
    char result[20];
    int res_len = 0;
    
    for (int i = 0; voiced[i]; i++) {
        char c = voiced[i];
        int in_all_odd = 1, in_any_even = 0;
        
        // Проверка нечётных слов
        for (int j = 0; j < word_count; j += 2) {
            if (!strchr(words[j], c)) {
                in_all_odd = 0;
                break;
            }
        }
        if (!in_all_odd) continue;
        
        // Проверка чётных слов
        for (int j = 1; j < word_count; j += 2) {
            if (strchr(words[j], c)) {
                in_any_even = 1;
                break;
            }
        }
        if (!in_any_even) {
            result[res_len++] = c;
        }
    }
    
    printf("Результат: ");
    if (res_len == 0) {
        printf("таких букв нет");
    } else {
        for (int i = 0; i < res_len; i++) {
            printf("%c ", result[i]);
        }
    }
    printf("\n");
    return 0;
}
