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
use menu system with switch case statements
Do not encrypt white space, punctuation, or numerals (if input character is not a letter it should
be copied to the output unmodied) -- maybe use the ispunct() function?
modify rotation functions to have a second input which is the shift key
*/



// ENCRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char encryptionRotation(char plainText[]);

// DECRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char decryptionRotation(char plainText[]);

// ENCRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char encryptionSubstitution(char plainText[]);

int main()  {
    
    printf(" Select an option from the following menu: \n");
    printf("1 - Encryption with a rotation cipher given input text and key \n");
    printf("2 - Decryption with a rotation cipher given input text and key \n");
    printf("3 - Encryption with a substitution cipher given input text and key \n");
    printf("4 - Decryption with a substitution cipher given input text and key \n");
    printf("5 - Decryption with a rotation cipher given the input text \n");
    
    int menuSelection = 0;
    scanf("%d", &menuSelection);
    
    printf("\n The option selected was %d \n", menuSelection);
   
    //char plainText[300];
    //int key = 0;
    
    //scanf("%s", plainText);  // newCustom run will read text from the plainText file which essentially performs a scanf
    //scanf("%d", &key);
   char plainText[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    //char plainText[] = "ZNK WAOIQ HXUCT LUD PASVKJ UBKX ZNK RGFE JUM";
    
    //printf("%d", key);
    printf("\n Initial message: \n");
    printf("\n %s\n", plainText);      // to test if the value of caeserCipher changes - debugging purposes
    
    //encryptionRotation(plainText);
    
    //decryptionRotation(plainText);
    
    encryptionSubstitution(plainText);
    
    printf("\n Result: \n");
    printf("\n %s\n", plainText);
    
    /*
    case 1: 
        printf("Option 1 Selected: Encryption with a rotation cipher given input text and key \n");
        
        FILE *input;
        input = fopen("inputText.txt") ;     // needs revising
        
        if (input == NULL)      {
            printf("FILE COULD NOT BE OPENED \n");
        }
        */
    
    
    
    return 0;

}

// ENCRYPTION ROTATION CIPHER FUNCTION DEFINITION:
char encryptionRotation(char *plainText)    {

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



// DECRYPTION ROTATION CIPHER FUNCTION DEFINITION
char decryptionRotation(char plainText[])   {
    
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



// ENCRYPTION SUSTITUTION CIPHER FUNCTION DEFINITION
char encryptionSubstitution(char plainText[])   {

         for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++)   {
             
    //note: the substitution key is bases off QWERTY, the keyboard design for the Latin alphabet
           switch(plainText[index])      {
                  case 'A': *plainText = 'Q';
                    break;
                  case 'B': *plainText = 'W';
                    break;
                  case 'C': *plainText = 'E';
                    break;
                  case 'D': *plainText = 'R';
                    break;
                  case 'E': *plainText = 'T';
                    break;
                  case 'F': *plainText = 'Y';
                    break;
                  case 'G': *plainText = 'U';
                    break;
                  case 'H': *plainText = 'I';
                    break;
                  case 'I': *plainText = 'O';
                    break;
                  case 'J': *plainText = 'P';
                    break;
                  case 'K': *plainText = 'A';
                    break;
                  case 'L': *plainText = 'S';
                    break;
                  case 'M': *plainText = 'D';
                    break;
                  case 'N': *plainText = 'F';
                    break;
                  case 'O': *plainText = 'G';
                    break;
                  case 'P': *plainText = 'H';
                    break;
                  case 'Q': *plainText = 'J';
                    break;
                  case 'R': *plainText = 'K';
                    break;
                  case 'S': *plainText = 'L';
                    break;
                  case 'T': *plainText = 'Z';
                    break;
                  case 'U': *plainText = 'X';
                    break;
                  case 'V': *plainText = 'C';
                    break;
                  case 'W': *plainText = 'V';  
                    break;
                  case 'X': *plainText = 'B';
                    break;
                  case 'Y': *plainText = 'N';
                    break;
                  case 'Z': *plainText = 'M';
                    break;
                  default: printf("Something went wrong \n");
        
                }  
                  
    
            }
      
return *plainText;
    
}
