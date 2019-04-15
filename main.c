/* Programming Assignment 1: English Text Ciphers
Created: 3 / 04 / 2019
Author: Sarah Creasey
Description:
*/

#include <stdio.h>
#include <string.h>     // note: contains string length function
#include <ctype.h>


// ENCRYPTION CIPHER FUNCTION PROTOTYPE
char encryption(char plainText[]);


// DECRYPTION CIPHER FUNCTION DEFINITION
char decryption(char plainText[]);



int main()  {
char plainText[] = "This is a top secret message";

//scanf("%s", plainText[] );
// newCustom run will read text from the plainText file which essentially performs a scanf


printf("%s\n", plainText);      // to test if the value of caeserCipher changes - debugging purposes

encryption(plainText);

//decryption(plainText);

printf("Cipher result: \n");
printf("%s\n", plainText);

return 0;

}

// ENCRYPTION CIPHER FUNCTION DEFINITION
char encryption(char *plainText)    {

        for (int index = 0; index <= strlen(plainText) ; index ++)   {
               
            int shift = 6; 
            plainText[index] = plainText[index] + shift;  
        
                 if ( plainText[index] >= 97 )  {
                     plainText[index] = plainText[index] - 32;
                 }
                 
                 if ( plainText[index] == (32 + shift) ) {
                            plainText[index] = plainText[index] - shift;
                }
         }   
         
         return *plainText;
}

// DECRYPTION CIPHER FUNCTION DEFINITION
char decryption(char plainText[])   {
    
        for (int index = 0; index <= strlen(plainText) ; index ++)   {
                   
                int shift = 6; 
                plainText[index] = plainText[index] - shift;  
                // if c - k < 0 add 26 to the result 
            
                     if ( plainText[index] >= 97 )  {
                         plainText[index] = plainText[index] - 32;
                     }
                     
                     if ( plainText[index] == (32 + shift) ) {
                                plainText[index] = plainText[index] - shift;
                    }
             }   
             
             return *plainText;
            
}















