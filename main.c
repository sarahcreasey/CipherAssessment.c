/* Programming Assignment 1: English Test Ciphers
Created: 3 / 04 / 2019
Author: Sarah Creasey
Description:
*/

//int shift (char text[]);

#include <stdio.h>

int main()  {
    
char x = 97;
x = x - 65;

printf("%d \n", x);

return 0;





 char text[] = "HELP" ;
 char newLetter = 0;
 // char text[] = "HELP" ;

    printf("letter is now %d\n", newLetter); 

    return 0;

}

int shift (char text[])     {
    char text[] = "HELP" ;
    char newLetter;      // result of rotation
    int x = text;
    int k = 5;     // degree of rotation

    newLetter = x + k;
    
    return newLetter;
}


*/
