#include <stdio.h>
#define swap(type, x, y) { type z = x; x = y; y = z; }

int main() 
{
    int x, y;
    printf("Введите x и y: ");
    scanf("%d%d",&x, &y);
    printf("x = %d\t y = %d\n",x,y);
    swap(int, x, y);
    printf("Замена x = %d\t Замена y = %d\n",x,y);
}
