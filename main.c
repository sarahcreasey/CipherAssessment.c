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
Do not encrypt white space, punctuation, or numerals (if input character is not a letter it should
be copied to the output unmodifed) -- maybe use the ispunct() function?
*/



// ENCRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char encryptionRotation(char plainText[], int shift);

// DECRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char decryptionRotation(char plainText[], int shift);

// ENCRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char encryptionSubstitution(char plainText[]);

// DECRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char decryptionSubstitution(char plainText[]);



int main()  {
    
    printf("Please select an option from the following menu: \n");
    printf("1 - Encryption with a rotation cipher given input text and key \n");
    printf("2 - Decryption with a rotation cipher given input text and key \n");
    printf("3 - Encryption with a substitution cipher given input text and key \n");
    printf("4 - Decryption with a substitution cipher given input text and key \n");
    printf("5 - Decryption with a rotation cipher given the input text \n");
    
    int menuSelection = 1;
    scanf("%d", &menuSelection); 
    char plainText[] = "ZIT JXOEA WKGVF YGB PXDHL GCTK ZIT SQMN RGU";
    int shift = 6;
   
   switch (menuSelection)   {
       case '1': printf("\n The option selected was 1 : Encryption with a rotation cipher given input text and key \n");
               encryptionRotation(plainText, shift); 
               break;
       case '2': printf("\n The option selected was 2 : Decryption with a rotation cipher given input text and key \n ");
               decryptionRotation(plainText, shift);
               break;
       case '3': printf("\n The option selected was 3 : Encryption with a substitution cipher given input text and key \n");
               encryptionSubstitution(plainText);
               break;
       case '4': printf("\n The option selected was 4 : Decryption with a substitution cipher given input text and key \n");
               decryptionSubstitution(plainText);
               break;
       case '5': printf("\n The option selected was 5 : Decryption with a rotation cipher given the input text \n");
               // insert function here
               break;
       default: printf("\n An unknown option was selected. Please select 1, 2, 3, 4, or 5 \n");
   }
   
   
   
    //char plainText[300];
    
    //scanf("%s", plainText);  // newCustom run will read text from the plainText file which essentially performs a scanf
    //scanf("%d", &shift);
   //char plainText[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    //char plainText[] = "ZNK WAOIQ HXUCT LUD PASVKJ UBKX ZNK RGFE JUM";
    //printf("%d", key);
    printf("\n Initial message: \n");
    printf("\n %s\n", plainText);      // to test if the value of caeserCipher changes - debugging purposes
  
    
    printf("\n Result: \n");
    printf("\n %s\n", plainText);

    return 0;

}

// ENCRYPTION ROTATION CIPHER FUNCTION DEFINITION:
char encryptionRotation(char *plainText, int shift)    {

        for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0' ; index ++)   {  // note: '00' is the ASCII character for NULL
          
                  
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
char decryptionRotation(char plainText[], int shift)   {
    
        for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++)   {
           
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
             
    //n ote: the substitution key is based off QWERTY, the keyboard design for the Latin alphabet
    // enter the encryption key into the statements on the right hand side
           switch(plainText[index])      {
                  case 'A': plainText[index] = 'Q';
                    break;
                  case 'B': plainText[index] = 'W';
                    break;
                  case 'C': plainText[index] = 'E';
                    break;
                  case 'D': plainText[index] = 'R';
                    break;
                  case 'E': plainText[index] = 'T';
                    break;
                  case 'F': plainText[index] = 'Y';
                    break;
                  case 'G': plainText[index] = 'U';
                    break;
                  case 'H': plainText[index] = 'I';
                    break;
                  case 'I': plainText[index] = 'O';
                    break;
                  case 'J': plainText[index] = 'P';
                    break;
                  case 'K': plainText[index] = 'A';
                    break;
                  case 'L': plainText[index] = 'S';
                    break;
                  case 'M': plainText[index] = 'D';
                    break;
                  case 'N': plainText[index] = 'F';
                    break;
                  case 'O': plainText[index] = 'G';
                    break;
                  case 'P': plainText[index] = 'H';
                    break;
                  case 'Q': plainText[index] = 'J';
                    break;
                  case 'R': plainText[index] = 'K';
                    break;
                  case 'S': plainText[index] = 'L';
                    break;
                  case 'T': plainText[index] = 'Z';
                    break;
                  case 'U': plainText[index] = 'X';
                    break;
                  case 'V': plainText[index] = 'C';
                    break;
                  case 'W': plainText[index] = 'V';  
                    break;
                  case 'X': plainText[index] = 'B';
                    break;
                  case 'Y': plainText[index] = 'N';
                    break;
                  case 'Z': plainText[index] = 'M';
                    break;
        
                }  
                  
            }
      
    return *plainText;
    
}



// DECRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char decryptionSubstitution(char plainText[])       {
    
         for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++)   {
             
    // note: the substitution key is based off QWERTY, the keyboard design for the Latin alphabet
    // enter the decryption key into the condition statments on the left hand side
           switch(plainText[index])      {
                  case 'Q': plainText[index] = 'A';
                    break;
                  case 'W': plainText[index] = 'B';
                    break;
                  case 'E': plainText[index] = 'C';
                    break;
                  case 'R': plainText[index] = 'D';
                    break;
                  case 'T': plainText[index] = 'E';
                    break;
                  case 'Y': plainText[index] = 'F';
                    break;
                  case 'U': plainText[index] = 'G';
                    break;
                  case 'I': plainText[index] = 'H';
                    break;
                  case 'O': plainText[index] = 'I';
                    break;
                  case 'P': plainText[index] = 'J';
                    break;
                  case 'A': plainText[index] = 'K';
                    break;
                  case 'S': plainText[index] = 'L';
                    break;
                  case 'D': plainText[index] = 'M';
                    break;
                  case 'F': plainText[index] = 'N';
                    break;
                  case 'G': plainText[index] = 'O';
                    break;
                  case 'H': plainText[index] = 'P';
                    break;
                  case 'J': plainText[index] = 'Q';
                    break;
                  case 'K': plainText[index] = 'R';
                    break;
                  case 'L': plainText[index] = 'S';
                    break;
                  case 'Z': plainText[index] = 'T';
                    break;
                  case 'X': plainText[index] = 'U';
                    break;
                  case 'C': plainText[index] = 'V';
                    break;
                  case 'V': plainText[index] = 'W';  
                    break;
                  case 'B': plainText[index] = 'X';
                    break;
                  case 'N': plainText[index] = 'Y';
                    break;
                  case 'M': plainText[index] = 'Z';
                    break;
                  
                }  
                  
            }
      
    return *plainText;
    
}



