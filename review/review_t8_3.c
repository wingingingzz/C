#include<stdio.h>
void func1(int *x, int *y) { *y = 1; x = y; }
void func2(int **x, int *y) { *y = 2; *x = y; }

void func1(int *x, int *y); void func2(int **x, int *y); 
int main(void) 
{ 
    int a; 
    int *p1 = NULL;
func1(p1, &a); 
printf("%d   %p\n", a, p1);
func2(&p1, &a); 
printf("%d   %p\n", a, p1);
printf("%d   %d\n", p1, &a);
printf("%p\n",&a);
return 0;
}
