/* Programming Assignment 1: English Text Ciphers
Created: 3 / 04 / 2019
Author: Sarah Creasey
Description: 
*/

#include <stdio.h>
#include <string.h>  
#include <ctype.h>

/*  TO DO
write output to a file
write code description


Every function needs to be documented in a block comment above the function denition:
{ What are the inputs?
{ What is the return value?
{ What does the function do?
{ Are there limitations to the function? Must strings be less than a certain length? Are there data
type restrictions? etc.



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
    
    int menuSelection = 4;
   // scanf("%d", &menuSelection); 
    char plainText[500];
    int shift = 0;
   
   switch (menuSelection)   {
       case 1: printf("\n The option selected was 1 : Encryption with a rotation cipher given input text and key \n\n");
          
               FILE *input1;
               input1 = fopen( "input.txt", "r" );
               
                        if (input1 == NULL) {
                            perror("fopen()");
                            return -1;
                        }
                                     
                FILE *input2;
                input2 = fopen( "inputKey.txt", "r" );
               
                        if (input2 == NULL) {
                            perror("fopen()");
                            return -1;
                            }       
                        
                fscanf(input2, "%d", &shift);
                printf("The rotation key is: %d \n \n", shift);
                
                fscanf(input1, " %[^\n]s", plainText);
                printf(" Initital Text: %s \n", plainText);   
                     
                encryptionRotation(plainText, shift);
                printf("\n Encrypted text: %s", plainText);
                            
               break;
               
       case 2: printf("\n The option selected was 2 : Decryption with a rotation cipher given input text and key \n\n ");
               
               input1 = fopen( "input.txt", "r" );
               
                        if (input1 == NULL) {
                            perror("fopen()");
                            return -1;
                        }
                                         
                input2 = fopen( "inputKey.txt", "r" );
               
                        if (input2 == NULL) {
                            perror("fopen()");
                            return -1;
                            }       
                        
                fscanf(input2, "%d", &shift);
                printf("The rotation key is: %d \n \n", shift);
                
                fscanf(input1, " %[^\n]s", plainText);
                printf(" Encrypted text: %s \n", plainText);   
                     
                decryptionRotation(plainText, shift);
                printf("\n Decrypted text: %s", plainText);
                            
               break;
              
       case 3: printf("\n The option selected was 3 : Encryption with a substitution cipher given input text and key \n");
               
                  input1 = fopen( "input.txt", "r" );
               
                        if (input1 == NULL) {
                            perror("fopen()");
                            return -1;
                        }

                
                fscanf(input1, " %[^\n]s", plainText);
                printf("\n Initial text: %s \n", plainText);   
                     
                encryptionSubstitution(plainText);
                printf("\n Encrypted text: %s", plainText);
               
               break;
               
       case 4: printf("\n The option selected was 4 : Decryption with a substitution cipher given input text and key \n");
           
               input1 = fopen( "input.txt", "r" );
               
                        if (input1 == NULL) {
                            perror("fopen()");
                            return -1;
                        }

                
                fscanf(input1, " %[^\n]s", plainText);
                printf("\n Encrypted text: %s \n", plainText);   
                     
                decryptionSubstitution(plainText);
                printf("\n Decrypted text: %s", plainText);
               
                break;
               
       case 5: printf("\n The option selected was 5 : Decryption with a rotation cipher given the input text \n");
               // insert function here
               break;
       default: printf("\n An unknown option was selected. Please select 1, 2, 3, 4, or 5 \n");
   }
  
    return 0;

}



// ENCRYPTION ROTATION CIPHER FUNCTION DEFINITION:
char encryptionRotation(char plainText[], int shift)    {

        for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0' ; index ++)   {  // note: '00' is the ASCII character for NULL
          
                if ( plainText[index] >= 97 )  {
                     plainText[index] = plainText[index] - 32;      // this will convert lower case to capitals
                }
            
                plainText[index] = plainText[index] + shift; 
             
                if ( plainText[index] <= 65 && plainText[index] >= 32)    {
                      plainText[index] = plainText[index] - shift;   // this try to ensure that punctuation and numbers do not change
                 }
                   
                 if ( plainText[index] > 90)    {
                     plainText[index] = plainText[index] - 26;   // this wall prevent letters falling off the end
                 }
                 
         }   
         
        return *plainText;
}



// DECRYPTION ROTATION CIPHER FUNCTION DEFINITION
/* The decryptionRotation function accepts a string of characters in plainText and 
 * the integer shift. The rotation cipher operates within a for() loop
 */
char decryptionRotation( char plainText[], int shift )   {
    
        for ( int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++ )   {
   
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
/* The encryptionSubstituion function accecpts a string input (array of type char) and will replace 
 * each letter of the string with a new letter as determined by the switch case statement below. The 
 * input string must have a length less than 499 characters as per the initialisation of the variable
 * in the main loop.
 *
 * The function operates with a for() loop that runs until the index reaches the length of the plainText
 * inout string or a terminating character is reached. The switch case will substitue each letter of 
 * the plainText string with a new letter based on a key provided. The function returns a pointer to 
 * the string plainText.
 *
 * Punctuation, spaces and numbers are returned unchanged. The function converts lower case to capitals 
 * prior to the switch case statement to ensure all letters are substitued correctly.
 *
 */
char encryptionSubstitution( char plainText[] )   {

         for ( int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++ )   {
             
              if ( plainText[index] >= 97 )  {
                             plainText[index] = plainText[index] - 32;      // this will covert lower case to capitals 
                         }
             }   
             
    // note: the substitution key is based off QWERTY, the keyboard design for the Latin alphabet
    // enter the encryption key into the statements on the right hand side
           switch( plainText[index] )      {
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
/* The decryptionSubstituion function accecpts a string input (array of type char) and will replace 
 * each letter of the string with a new letter as determined by the switch case statement below. The
 * input string must have a length less than 499 characters as per the initialisation of the variable
 * in the main loop.
 *
 * The function operates with a for() loop that runs until the index reaches the length of the plainText
 * inout string or a terminating character is reached. The switch case will substitue each letter of 
 * the plainText string with a new letter based on a key provided. The function returns a pointer to 
 * the string plainText.
 *
 * Punctuation, spaces and numbers are returned unchanged. The function converts lower case to capitals 
 * prior to the switch case statement to ensure all letters are substitued correctly.
 *
 */
char decryptionSubstitution( char plainText[] )       {
    
         for ( int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++ )   {
            
              if ( plainText[index] >= 97 )  {
                                 plainText[index] = plainText[index] - 32;      // this will covert lower case to capitals 
                             }
               }   
    // note: the substitution key is based off QWERTY, the keyboard design for the Latin alphabet
    // manually hard code the decryption key into the condition statments on the left hand side
           switch( plainText[index] )      {
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

