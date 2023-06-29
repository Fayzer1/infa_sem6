#include <stdio.h>

int binSearch(int nums[], int left, int right, int request);

int main() {

   int request; //искомое число
   int mas[] = {-999, 0, 7, 15, 28, 40, 100 };

   printf("enter a number for searching: ");
   scanf("%d", &request);
 
   int len = sizeof(mas) / sizeof(mas[0]); //число элементов массива
   int left = 0, right = len - 1; //границы поиска
   int index = binSearch(mas, left, right, request);

   if (index != -1)
      printf("index is: %d\n", index);
   else
      printf("not found\n");

   return 0;
}

int binSearch(int nums[], int left, int right, int request) {

   if (left > right) 
      return -1; //тк массив отсортирован
 
   int mid = (right + left)/2;
 
   if (request == nums[mid])
        return mid;
   else if (request < nums[mid])
      return binSearch(nums, left, mid - 1, request); //задаем новые границы по смещению
   else 
      return binSearch(nums, mid + 1, right, request);
}
