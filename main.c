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
//char plainText[] = "The quick brown fox jumped over the lazy dog";
char plainText[] = "ZNK WAOIQ HXUCT LUD PASVKJ UBKX ZNK RGFE JUM";

//scanf("%s", plainText[] );
// newCustom run will read text from the plainText file which essentially performs a scanf

printf("Initial message: \n");
printf("%s\n", plainText);      // to test if the value of caeserCipher changes - debugging purposes

//encryption(plainText);

decryption(plainText);

printf("Cipher result: \n");
printf("%s\n", plainText);

return 0;

}

// ENCRYPTION CIPHER FUNCTION DEFINITION:
char encryption(char *plainText)    {

        for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0' ; index ++)   {
               
            int shift = 6; 
            plainText[index] = (plainText[index] + shift);  
                   
                 if ( plainText[index] >= 97 )  {
                     plainText[index] = plainText[index] - 32;      // this will convert lower case to capitals
                 }
            
                 if ( plainText[index] > 90)    {
                     plainText[index] = plainText[index] - 26;   // this wall prevent letters falling off the end
                 }
                 
                 if ( plainText[index] == (32 + shift) ) {
                            plainText[index] = plainText[index] - shift;        // this will ensure spaces remain the same
                }
         }   
         return *plainText;
}
// DECRYPTION CIPHER FUNCTION DEFINITION

char decryption(char plainText[])   {
    
        for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++)   {
                   
                int shift = 6; 
                plainText[index] = (plainText[index] - shift);  
                // if c - k < 0 add 26 to the result 
        
                     
                       if ( plainText[index] < 65 && plainText[index] > 32)    {
                     plainText[index] = plainText[index] + 26;   // this wall prevent letters falling off the end
                    }
                 
                     if ( plainText[index] == (32 - shift) ) {
                                plainText[index] = plainText[index] + shift;         // this will ensure spaces remain the same
                    }
                    
                     if ( plainText[index] >= 97 )  {
                         plainText[index] = plainText[index] - 32;      // this will covert lower case to capitals 
                     }
             }   
             
             return *plainText;
            
}










