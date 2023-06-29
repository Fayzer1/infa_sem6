#include <stdio.h>

void countingSort(int array[], int size, int place) {
    const int max = 10;
    int count[10] = {0};
    int output[size];

// Подсчитываем количество встречающихся цифр
    for (int i = 0; i < size; i++) {
        int digit = (array[i] / place) % 10;
        count[digit]++;
    }

// Считаем префиксные суммы для определения позиции каждой цифры в окончательном отсортированном массиве
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

// Помещаем каждый элемент на нужную позицию в выходном массиве
    for (int i = size - 1; i >= 0; i--) {
        int digit = (array[i] / place) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

// Копируем отсортированный массив обратно в исходный массив
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void radixSort(int array[], int size) {
    int max = array[0];
    
    // Находим максимальное число в массиве
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Применяем сортировку подсчётом для каждого разряда числа
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

void printArray(int array[], int size) {
    // Выводим элементы массива
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int size = sizeof(array) / sizeof(array[0]);

    printf("Исходный массив: ");
    printArray(array, size);

    radixSort(array, size);

    printf("Отсортированный массив: ");
    printArray(array, size);

    return 0;
}
