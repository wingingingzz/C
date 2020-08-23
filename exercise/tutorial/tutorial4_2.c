#include <stdio.h>

int main(int argc,int* argv[])
{
    int a[]={1,2,3};
    printf("%d %d %d\n",a[0],a[1],a[2]);
    printf("%p %p %p\n",a[0],a[1],a[2]);
    
    int b[]={1,2,3};
    printf("%p %p\n",a,b);

    char* s1="Paul";
    char* s2="Paul";
    printf("%p %p\n",s1,s2);//2 pointers point to only 1 address; only 1 "Paul" in memory

    return 0;
}