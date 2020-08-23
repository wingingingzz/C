#include <stdio.h> 
int f1(int x, int y) 
{ x = x + 2; y = y + 3; return x + y; } 
int f2(int *x, int y) 
{ *x = *x + 2; y = y + 3; return *x + y; } 
int f3(int *x, int *y) 
{ *x = *x + 2; *y = *y + 3; return *x + *y; } 
int main(int argc, char *argv[]) { int k = 3, m = 5, r = 0; printf("1) %d %d %d \n", k, m, r); r = f1(k, m); printf("2) %d %d %d \n", k, m, r); r = f2(&k, m); printf("3) %d %d %d \n", k, m, r); r = f3(&k, &m); printf("4) %d %d %d \n", k, m, r); return 0; }
