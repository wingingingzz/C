#include<stdio.h>
void swap(int* arg1, int* arg2) { int* value = NULL; value = arg1; arg1 = arg2; arg2 = value; }
int main() { int a = 1, b = 2; printf("%p, %p\n", &a, &b); swap(&a, &b); printf("%p, %p\n", &a, &b); }