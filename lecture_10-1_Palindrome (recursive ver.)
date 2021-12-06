#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* uint8_t is just a char */
uint8_t is_palindrome(char str[], int len, int j){
    if(str[j] != str[len-1-j]){
        return 0;
    } 
    if(j == len/2 -1) {
        return 1;
    }
    if (is_palindrome(str,len,++j) == 1) {
        return 1;
    }
  return 0;
}


int main(){
   char temp_c, str[30];
   int i=0, len=1;
   do{ // getting input from user
     scanf("%c", &temp_c);
     if(temp_c!=' ' && temp_c!='\n')
       str[i++] = temp_c;
   } while(temp_c!=' ' && temp_c!='\n' && i<30);
   len = i; //current i is string length

   if(is_palindrome(str,len,0)) {
     printf("a palindrome\n");
   } else {
     printf("not a palindrome\n");
   }
   
   return 0;
}
