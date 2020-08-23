#include<stdio.h> 
int g_n = 42;

void func_ptr1(int* pp) 
{ 
    *pp = g_n; 
}

void func_ptr2(int** pp) 
{ 
    *pp = &g_n;
}

int main() 
{ 
    int n = 23; 
    int* pn = &n; 
    printf("%d\n", *pn); 
    func_ptr1(pn); 
    printf("%d\n", n);
    printf("%d\n", *pn); 

    int m = 23; 
    int* pm = &m; 
    printf("%d\n", *pm); 
    func_ptr2(&pm); 
    printf("%d\n", m);
    printf("%d\n", *pm);
}