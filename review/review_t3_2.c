#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i=5, j=7, k=4, m=-2;
    printf("%d", i==5);
    printf("%d", j!=3);
    printf("%d", i>=5 && j<4);
    printf("%d", !m && k>m); 
    printf("%d", !k || m); 
    printf("%d", k-m<j || 5-j>=k); 
    printf("%d", j+m<=i && !0); 
    printf("%d", !(j-m));
    printf("%d", !(k>m)); 
    printf("%d", !(j>k));
}