#include<stdio.h> 
int main(int argc, char *argv[]) 
{ 
    int a = 1; int b = 2;   
    int *p1 = &a; int *p2 = &b; 
    int **pp1 = &p1; printf("%d    %p     %p\n", **pp1, *pp1, pp1);
    *pp1 = p2; //  pp1 = &p2; 
    printf("%d    %p     %p\n", **pp1, *pp1, pp1); 
    printf("%p    %p\n", &a,  &b); 
    printf("%p    %p\n", p1,  p2);
return 0;
}