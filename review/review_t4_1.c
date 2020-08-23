#include<stdio.h>
int main(int argc, char* argv[ ])
{
	int a[] = {1, 2, 3};
	printf("%d, %d, %d\n", a[0], a[1], a[2]);
	printf("%p, %p, %p\n", &a[0], &a[1], &a[2]);

	int b[] = {1, 2, 3};
    printf("%p, %p, %p\n", &b[0], &b[1], &b[2]);
	printf("%p, %p\n", a, b);

	char* s1 = "Paul";
	char* s2 = "Paul"; 
	printf("%p, %p\n", s1, s2);
}

