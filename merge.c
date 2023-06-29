#include <stdio.h>

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    // Проходим по левой и правой половинам массива, сравниваем элементы и объединяем их в результирующий массив arr
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++]; // Если элемент в левой половине меньше или равен элементу в правой половине, добавляем его в arr
        } else {
            arr[k++] = right[j++]; // Если элемент в правой половине меньше элемента в левой половине, добавляем его в arr
        }
    }

    // Если в левой или правой половине остались элементы, добавляем их в arr
    while (i < left_size) {
        arr[k++] = left[i++];
    }
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size) {
    // Если размер массива меньше 2, то массив уже отсортирован
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Заполняем левую и правую половины массива
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Рекурсивно вызываем сортировку для левой и правой половин
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Слияние отсортированных половин
    merge(arr, left, mid, right, size - mid);
}

int main() {
    int arr[] = {5, 8, 1, 6, 3, 9, 2, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, size);

    printf("\nОтсортированный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}
