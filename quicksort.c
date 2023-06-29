#include <stdio.h>

void quicksort(int arr[], int low, int high); 
void swap(int *a, int *b);

int main()
{
    int array[] = {22511, 22501, 22506, 22508, 22502, 22505, 22504, 0, -1}; //Массив для сортировки
    int n = sizeof(array)/sizeof(array[0]); //Количество элеметнов в массиве

    printf("До сортировки\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');

    quicksort(array, 0, n - 1); 
    printf("После сортировки:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]); 
    }

    putchar('\n');
    return 0;
}

//Функция для перемещения элементов между левым и правым подмассивами
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Алгоритм быстрой сортировки | Схема Хоара
void quicksort(int arr[], int low, int high)
{
    int stack[high], top = -1; 
    stack[++top] = low; 
    stack[++top] = high; 

    while (top >= 0) 
    {
	
        high = stack[top--];
        low = stack[top--]; 

        int pivot = arr[(low + high) / 2]; // Выбор опорного элемента
        int i = low, j = high;

	//Сближение происходит с двух концов массива
        while (i <= j) 
        {
            while (arr[i] < pivot) 
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) 
            {
	//Перемещение между правым и левым подмассивами 
                swap(&arr[i], &arr[j]);
                i++; 
                j--;
            }
        }

	//Добавление границ в стек
        if (low < j) 
        {  
            stack[++top] = low;
            stack[++top] = j; 
        }

        if (i < high)
        {
            stack[++top] = i;
            stack[++top] = high; 
        }

        
    }
}


