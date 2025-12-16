#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define SIZE 1000
#define N 5

// Прототипы функций
void task11(void);
void task14(int size);
void task16(int size);
double* full_elements(double* arr, int size);
double put_elements(double* arr, int size);
double calc_elements(double* arr, int size);
double find_max_in_range(double* arr, int size, int K, int L);


int main() {
    setlocale(LC_ALL, "RUS");
    puts("Лабораторные работы 11, 14, 16, 19, 25: Работа с массивами ===\n");

    int size;
    puts("Укажите размер массива");
    scanf("%d", &size);
    task11();
    task14(size); // для всех заданий лаб. 14
    task16(size); // для всех заданий лаб. 16

    return 0;
}

void task11()
{
    setlocale(LC_ALL, "RUS");
    float A[N], B[N];
    float temp, summ = 0;

    // Задание 1. Заполнение массива с консоли
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
        summ += A[i];
    }

    // Задание 2. Преобразование массива
    for (int i = 0; i < N; i++) {
        B[i] = -A[i];
    }
    // Задание 3. Печать массива
    printf("|Индекс|Исходное значение|Новое значение|\n");
    for (int i = 0; i < N; i++) {
        printf("|%-6d|%17.2f|%14.2f|\n", i, A[i], B[i]);
    }

    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int array[SIZE];
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int max = array[0];
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    }
    int count = 0;
    for (int i = 0; i < max_index; i++) {
        if (array[i] > 0) {
            count++;
        }
    }
    printf("Количество положительных элементов, расположенных до максимального: %d\n", count);
}

void task14(int size)
{
    double array[SIZE];
    int K, L;
    double max_in_range;

    // Задание 1. Заполнение массива
    full_elements(array, size);
    put_elements(array, size);

    // Задание 2. Преобразование массива
    calc_elements(array, size);
    put_elements(array, size);

    printf("\n5. Поиск максимального значения в диапазоне [K; L]:\n");
    printf("Введите K (от 0 до %d): ", size - 1);
    scanf("%d", &K);
    printf("Введите L (от %d до %d): ", K, size - 1);
    scanf("%d", &L);

    if (K < 0 || L >= size || K > L) {
        printf("Некорректный диапазон! K должно быть в [0, %d], L в [K, %d]\n",
            size - 1, size - 1);
    }
    else {
        max_in_range = find_max_in_range(array, size, K, L);
        printf("Максимальное значение в диапазоне [%d; %d]: %.4f\n",
            K, L, max_in_range);
    }
}

void task16(int size)
{

}

// Реализация вспомогательных функций
double* full_elements(double* arr, int size) {
    printf("\n=== Заполнение массива ===\n");
    for (int i = 0; i < size; i++) {
        printf("Введите элемент array[%d]: ", i);
        scanf("%lf", &arr[i]);
    }
}

double put_elements(double* arr, int size) {
    printf("\n=== Вывод массива ===\n");
    printf("Индекс | Значение\n");
    for (int i = 0; i < size; i++) {
        printf("%6d | %8.2f\n", i, arr[i]);
    }
}

double calc_elements(double* arr, int size) {
    printf("\n=== Преобразование массива ===\n");
    for (int i = 0; i < size; i++) {
        // Пример преобразования: квадрат каждого элемента
        arr[i] = arr[i] * arr[i];
    }
    printf("Все элементы возведены в квадрат.\n");
}

double find_max_in_range(double* arr, int size, int K, int L) {
    if (K < 0 || L >= size || K > L) {
        return 0.0;
    }

    double max_val = arr[K];
    for (int i = K + 1; i <= L; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}