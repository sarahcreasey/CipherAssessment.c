/* Programming Assignment 1: English Text Ciphers
Created: 3 / 04 / 2019
Author: Sarah Creasey
Description:
*/

#include <stdio.h>
#include <string.h>  
#include <ctype.h>

/*  TO DO
successfully read text string from input output file
create substitution cipher
use menu system with switch case statements
 -- Do not encrypt white space, punctuation, or numerals (if input character is not a letter it should
be copied to the output unmodied)

*/



// ENCRYPTION CIPHER FUNCTION PROTOTYPE
char encryption(char plainText[]);

// DECRYPTION CIPHER FUNCTION DEFINITION
char decryption(char plainText[]);



int main()  {
    
    printf(" Select an option from the following menu: \n");
    
    printf("1 Encryption with a rotation cipher given input text and key \n");
    printf("2 Decryption with a rotation cipher given input text and key \n");
    printf("3 Encryption with a substitution cipher given input text and key \n");
    printf("4 Decryption with a substitution cipher given input text and key \n");
    printf("5 Decryption with a rotation cipher given the input text \n");
    
    int menuSelection = 0;
    scanf("%d", &menuSelection);
    
    printf(" The option selected was %d \n", menuSelection);
   
    char plainText[300];
    int key = 0;
    
    scanf("%s", plainText);  // newCustom run will read text from the plainText file which essentially performs a scanf
    scanf("%d", &key);
   //char plainText[] = "The quick brown fox jumped over the lazy dog";
    //char plainText[] = "ZNK WAOIQ HXUCT LUD PASVKJ UBKX ZNK RGFE JUM";
    
    printf("%d", key);
    printf("\n Initial message: \n");
    printf("\n %s\n", plainText);      // to test if the value of caeserCipher changes - debugging purposes
    
    encryption(plainText);
    
    //decryption(plainText);
    
    printf("\n Result: \n");
    printf("\n %s\n", plainText);
    
    return 0;

}

// ENCRYPTION CIPHER FUNCTION DEFINITION:
char encryption(char *plainText)    {

        for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0' ; index ++)   {  // note: '00' is the ASCII character for NULL
                  
           int shift = 6; 
                  
               if ( plainText[index] < 65 && plainText[index] > 32)    {
               plainText[index] = plainText[index] + shift;   // this try to ensure that punctuation and numbers do not change
                 }
            
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
                   
                   if ( plainText[index] < 65 && plainText[index] > 32)    {
                     plainText[index] = plainText[index] + shift;   // this try to ensure that punctuation and numbers do not change
                    }
                 
            
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



