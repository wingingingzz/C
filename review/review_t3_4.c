#include <stdio.h>
int main() 
{ 
int a = 10; 
if(!a) 
    printf("True\n"); 
else 
    printf("False\n");
while(a) 
{ 
    printf("%d\n", a); a--; }
}