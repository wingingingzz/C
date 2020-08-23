#include <stdio.h>
#include <string.h>
 
int main ()
{
   char src[15], dest[20];
 
   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");
 
   strcat(dest, src);
 
   printf("最终的目标字符串： |%s|\n", dest);
   
   return(0);
}