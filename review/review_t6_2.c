#include <stdio.h>
#include <string.h>
 
int main ()
{
   char str1[15];
   char str2[15];
   int ret;
 
 
   strcpy(str1, "abcf");
   strcpy(str2, "abbm");
 
   ret = strcmp(str1, str2);
 
   if(ret < 0)
   {
      printf("str1 小于 str2\n");
   }
   else if(ret > 0) 
   {
      printf("str2 小于 str1\n");
   }
   else 
   {
      printf("str1 等于 str2\n");
   }
   
   return(0);
}