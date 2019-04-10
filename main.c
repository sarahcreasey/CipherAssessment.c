/* Programming Assignment 1: English Test Ciphers
Created: 3 / 04 / 2019
Author: Sarah Creasey
Description:
*/

#include <stdio.h>
#include <string.h>     // functions within library can be used to find the length of a string


//  CIPHER FUNCTION PROTOTYPE
char caesarCipher(char* plainText, int key);


int main()  {

char plainText[101];


scanf("%s", plainText[] )
// newCustom run will read text from the plainText file which essentially performs a scanf

printf("The cipher result text is: \n");
printf("%c\n", cipherResult);


return 0;
}

//  CIPHER FUNCTION DEFINITION
char caesarCipher(char* plainText, int key);    {

int key = 1;
char cipherResult;


for (index = 0; i <= strlen(plainText) ; index ++)   {
    
    cipherResult = (plainText[i] + key) % 26;    // will return ciphered letter as a number
    
    return cipherResult;
    
}

}









