#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 10000

// Структура для хранения большого числа
typedef struct {
    char digits[MAX_DIGITS];
    int length;
} BigInt;

// Инициализация BigInt из целого числа
void init_bigint(BigInt* num, int value) {
    if (value == 0) {
        num->digits[0] = '0';
        num->digits[1] = '\0';
        num->length = 1;
        return;
    }
    
    int i = 0;
    int temp = value;
    while (temp > 0) {
        num->digits[i++] = (temp % 10) + '0';
        temp /= 10;
    }
    num->digits[i] = '\0';
    num->length = i;
    
    // Переворачиваем цифры для правильного порядка
    for (int j = 0; j < i/2; j++) {
        char tmp = num->digits[j];
        num->digits[j] = num->digits[i - 1 - j];
        num->digits[i - 1 - j] = tmp;
    }
}

// Умножение BigInt на целое число
void multiply_int(BigInt* num, int factor) {
    if (factor == 0) {
        init_bigint(num, 0);
        return;
    }
    if (factor == 1) return;
    
    int carry = 0;
    char result[MAX_DIGITS] = {0};
    int result_len = 0;
    
    // Умножаем, начиная с младших разрядов
    for (int i = num->length - 1; i >= 0; i--) {
        int product = (num->digits[i] - '0') * factor + carry;
        result[result_len++] = (product % 10) + '0';
        carry = product / 10;
    }
    
    // Добавляем оставшийся перенос
    while (carry > 0) {
        result[result_len++] = (carry % 10) + '0';
        carry /= 10;
    }
    
    // Переворачиваем результат
    for (int i = 0; i < result_len/2; i++) {
        char tmp = result[i];
        result[i] = result[result_len - 1 - i];
        result[result_len - 1 - i] = tmp;
    }
    result[result_len] = '\0';
    
    strcpy(num->digits, result);
    num->length = result_len;
}

// Сложение двух BigInt
void add_bigint(const BigInt* a, const BigInt* b, BigInt* result) {
    int max_len = (a->length > b->length) ? a->length : b->length;
    int carry = 0;
    char temp_result[MAX_DIGITS + 1] = {0};
    int idx = 0;
    
    // Складываем с конца
    for (int i = 0; i < max_len; i++) {
        int digit_a = (i < a->length) ? (a->digits[a->length - 1 - i] - '0') : 0;
        int digit_b = (i < b->length) ? (b->digits[b->length - 1 - i] - '0') : 0;
        
        int sum = digit_a + digit_b + carry;
        temp_result[idx++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    if (carry > 0) {
        temp_result[idx++] = carry + '0';
    }
    
    // Переворачиваем результат
    for (int i = 0; i < idx/2; i++) {
        char tmp = temp_result[i];
        temp_result[i] = temp_result[idx - 1 - i];
        temp_result[idx - 1 - i] = tmp;
    }
    temp_result[idx] = '\0';
    
    strcpy(result->digits, temp_result);
    result->length = idx;
}

// Сравнение двух BigInt
int compare_bigint(const BigInt* a, const BigInt* b) {
    if (a->length != b->length) {
        return a->length - b->length;
    }
    return strcmp(a->digits, b->digits);
}

// Вычитание (a >= b)
void subtract_bigint(const BigInt* a, const BigInt* b, BigInt* result) {
    int borrow = 0;
    char temp_result[MAX_DIGITS] = {0};
    int idx = 0;
    
    // Вычитаем с конца
    for (int i = 0; i < a->length; i++) {
        int digit_a = a->digits[a->length - 1 - i] - '0' - borrow;
        int digit_b = (i < b->length) ? (b->digits[b->length - 1 - i] - '0') : 0;
        
        if (digit_a < digit_b) {
            digit_a += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        temp_result[idx++] = (digit_a - digit_b) + '0';
    }
    
    // Удаляем ведущие нули
    while (idx > 1 && temp_result[idx - 1] == '0') {
        idx--;
    }
    
    // Переворачиваем результат
    for (int i = 0; i < idx/2; i++) {
        char tmp = temp_result[i];
        temp_result[i] = temp_result[idx - 1 - i];
        temp_result[idx - 1 - i] = tmp;
    }
    temp_result[idx] = '\0';
    
    strcpy(result->digits, temp_result);
    result->length = idx;
}

// Вычисление НОД с помощью алгоритма Евклида
void gcd_bigint(BigInt* a, BigInt* b, BigInt* result) {
    BigInt temp1, temp2, temp3;
    
    // Создаем копии входных чисел
    temp1 = *a;
    temp2 = *b;
    
    while (1) {
        int cmp = compare_bigint(&temp1, &temp2);
        
        if (cmp == 0) {
            // Числа равны - нашли НОД
            *result = temp1;
            return;
        } else if (cmp > 0) {
            // temp1 > temp2
            subtract_bigint(&temp1, &temp2, &temp3);
            temp1 = temp3;
        } else {
            // temp2 > temp1
            subtract_bigint(&temp2, &temp1, &temp3);
            temp2 = temp3;
        }
        
        // Проверяем, не стало ли одно из чисел нулем
        if (strcmp(temp1.digits, "0") == 0) {
            *result = temp2;
            return;
        }
        if (strcmp(temp2.digits, "0") == 0) {
            *result = temp1;
            return;
        }
    }
}

// Деление BigInt на целое число
void divide_bigint_int(const BigInt* num, int divisor, BigInt* result) {
    if (divisor == 0) {
        printf("Ошибка: деление на ноль!\n");
        return;
    }
    
    char quotient[MAX_DIGITS] = {0};
    long long remainder = 0;
    int idx = 0;
    int started = 0;
    
    for (int i = 0; i < num->length; i++) {
        remainder = remainder * 10 + (num->digits[i] - '0');
        
        if (remainder >= divisor) {
            quotient[idx++] = (remainder / divisor) + '0';
            remainder = remainder % divisor;
            started = 1;
        } else if (started) {
            quotient[idx++] = '0';
        }
    }
    
    if (idx == 0) {
        quotient[idx++] = '0';
    }
    quotient[idx] = '\0';
    
    strcpy(result->digits, quotient);
    result->length = idx;
}

// Основная программа
int main() {
    int n;
    printf("Введите n (>10): ");
    scanf("%d", &n);
    
    BigInt factorial, numerator, denominator;
    BigInt term, temp, gcd_val;
    BigInt reduced_num, reduced_den;
    
    // Инициализация
    init_bigint(&factorial, 1);
    init_bigint(&numerator, 0);
    init_bigint(&denominator, 0);
    init_bigint(&term, 0);
    init_bigint(&temp, 0);
    init_bigint(&gcd_val, 0);
    init_bigint(&reduced_num, 0);
    init_bigint(&reduced_den, 0);
    
    // Вычисляем n!
    printf("Вычисляем %d!...\n", n);
    for (int i = 1; i <= n; i++) {
        multiply_int(&factorial, i);
    }
    printf("Факториал: %s\n", factorial.digits);
    
    // Вычисляем числитель: sum_{k=1}^n n!/k!
    // Начинаем с term = n! (для k=1)
    term = factorial;
    numerator = factorial;
    
    printf("Вычисляем сумму...\n");
    for (int k = 2; k <= n; k++) {
        // term = term / k
        divide_bigint_int(&term, k, &term);
        // numerator = numerator + term
        add_bigint(&numerator, &term, &temp);
        numerator = temp;
    }
    
    // Знаменатель = n!
    denominator = factorial;
    
    printf("Числитель: %s\n", numerator.digits);
    printf("Знаменатель: %s\n", denominator.digits);
    
    // Сокращаем дробь
    printf("Вычисляем НОД...\n");
    gcd_bigint(&numerator, &denominator, &gcd_val);
    printf("НОД: %s\n", gcd_val.digits);
    
    // Преобразуем НОД в целое число (если возможно)
    long long gcd_num = atoll(gcd_val.digits);
    
    if (gcd_num > 1) {
        divide_bigint_int(&numerator, gcd_num, &reduced_num);
        divide_bigint_int(&denominator, gcd_num, &reduced_den);
        printf("Результат: %s / %s\n", reduced_num.digits, reduced_den.digits);
    } else {
        printf("Результат: %s / %s\n", numerator.digits, denominator.digits);
    }
    
    return 0;
}
