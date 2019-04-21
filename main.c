/* Programming Assignment 1: English Text Ciphers
Created: 3 / 04 / 2019
Author: Sarah Creasey
Description: This code encrypts and decrypts input text based off a Rotation Cipher or a Substitution Cipher.
The input is read from the relevant files (input.txt and inputKey.txt) and printed to the console. The output is also 
sent to a text file (output.txt). Users must first select which option they wish to execute in the terminal using ./a.out
*/

#include <stdio.h>
#include <string.h>  
#include <ctype.h>


// ENCRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char encryptionRotation(char plainText[], int shift);

// DECRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char decryptionRotation(char plainText[], int shift);

// ENCRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char encryptionSubstitution(char plainText[]);

// DECRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char decryptionSubstitution(char plainText[]);

// DECRYPTION ROTATION CIPHER WITHOUT KEY PROTOTYPE
char decryptionNoKey(char plainText[]);


int main()  {
    
    // Prints a user-friendly menu system to the interface. Users must select an integer from 1-5 to successfully run the cipher code.
    
    
    printf("Please select an option from the following menu: \n");
    printf("1 - Encryption with a rotation cipher given input text and key \n");
    printf("2 - Decryption with a rotation cipher given input text and key \n");
    printf("3 - Encryption with a substitution cipher given input text and key \n");
    printf("4 - Decryption with a substitution cipher given input text and key \n");
    printf("5 - Decryption with a rotation cipher given the input text \n");
    
    
    int menuSelection = 5;      // The user's menu selection is to be stored in this integer 
    scanf("%d", &menuSelection); // Uses a custom run function to recieve an input from the text file labelled menuSelection
    char plainText[500];        // Initialises the string of type char to a length of 500 characters
                                // note: This length will dictate the maximum length of the input string as it determines the memorally allocation available to the string
    int shift = 0;              // Initialises the integer shift which will be used in the rotation ciphers
   
   
   
   switch (menuSelection)   {
       case 1:        // If the user selects 1, the following code will run
               printf("\n The option selected was 1 : Encryption with a rotation cipher given input text and key \n\n");
          
               FILE *input1;
               input1 = fopen( "input.txt", "r" );      // Opens the file input.txt and establishes that data will be read from the file ("r")
               
                        if (input1 == NULL) {           // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                        }
                                     
                FILE *input2;
                input2 = fopen( "inputKey.txt", "r" );       // Opens the file inputKey.txt and establishes that data will be read from the file ("r")
               
                        if (input2 == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                            }       
                        
                    fscanf(input2, "%d", &shift);                        // The fscanf() reads data from the file input2 and stores the integer value in the variable shift
                    printf("The rotation key is: %d \n \n", shift);      
                    
                    fscanf(input1, " %[^\n]s", plainText);              // The fscaf() reads data from the file input1 until a new line character is reached and stores the string in the variable plainText
                    printf(" Initital Text : %s \n", plainText);   
                         
                    encryptionRotation(plainText, shift);               // The encryptionRotation function is called and the previously obtained values for plainText and shift are used as inputs
                    printf("\n Encrypted text : %s", plainText);
                      
                      
                FILE *output;
                output = fopen( "outputText.txt", "w");         // Opens the file inputKey.txt and establishes that data will be written to the file ("w")
                
                        if (output == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                            }  
                            
                    fprintf(output, "Encrypted text : %s", plainText);      // The plainText string is printed to the outputText file
                    
               break;                                  // Once the case has been executed this block of code will "break" i.e. jump to the next line of code outside the switch case statments
               
       
       
       case 2:          // If the user selects 2, the following code will run
                printf("\n The option selected was 2 : Decryption with a rotation cipher given input text and key \n\n ");
               
                 input1 = fopen( "input.txt", "r" );         // Opens the file input.txt and establishes that data will be read from the file ("r")
               
                        if (input1 == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                        }
                                         
                input2 = fopen( "inputKey.txt", "r" );      // Opens the file inputKey.txt and establishes that data will be read from the file ("r")
               
                        if (input2 == NULL) {               // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                            }       
                        
                    fscanf(input2, "%d", &shift);                       // The fscanf() reads data from the file input2 and stores the integer value in the variable shift
                    printf("The rotation key is: %d \n \n", shift);
                    
                    fscanf(input1, " %[^\n]s", plainText);               // The fscaf() reads data from the file input1 until a new line character is reached and stores the string in the variable plainText
                    printf(" Encrypted text: %s \n", plainText);   
                         
                    decryptionRotation(plainText, shift);               // The decryptionRotation function is called and the previously obtained values for plainText and shift are used as inputs
                    printf("\n Decrypted text: %s", plainText);
                     
                   
                output = fopen( "outputText.txt", "w");         // Opens the file inputKey.txt and establishes that data will be written to the file ("w")
                
                        if (output == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                            }  
                            
                    fprintf(output, "Decrypted text : %s", plainText);      // The plainText string is printed to the outputText file
                    
               break;                              // Once the case has been executed this block of code will "break" i.e. jump to the next line of code outside the switch case statments
              
      
      
      case 3:          // If the user selects 3, the following code will run
                printf("\n The option selected was 3 : Encryption with a substitution cipher given input text and key \n");
               
                  input1 = fopen( "input.txt", "r" );       // Opens the file input.txt and establishes that data will be read from the file ("r")
               
                        if (input1 == NULL) {               // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                        }

                
                    fscanf(input1, " %[^\n]s", plainText);          // The fscaf() reads data from the file input1 until a new line character is reached and stores the string in the variable plainText
                    printf("\n Initial text: %s \n", plainText);   
                         
                    encryptionSubstitution(plainText);              // The encryptionSubstitution function is called and the previously obtained values for plainText string are used as an input
                    printf("\n Encrypted text: %s", plainText);
                   
                  output = fopen( "outputText.txt", "w");         // Opens the file inputKey.txt and establishes that data will be written to the file ("w")
                
                        if (output == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                            }  
                            
                    fprintf(output, "Encrypted text : %s", plainText);      // The plainText string is printed to the outputText file
                
               break;                               // Once the case has been executed this block of code will "break" i.e. jump to the next line of code outside the switch case statments
               
      
      
      case 4:         // If the user selects 4, the following code will run
                printf("\n The option selected was 4 : Decryption with a substitution cipher given input text and key \n");
           
                  input1 = fopen( "input.txt", "r" );         // Opens the file input.txt and establishes that data will be read from the file ("r")
               
                        if (input1 == NULL) {                  // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                        }

                
                    fscanf(input1, " %[^\n]s", plainText);              // The fscaf() reads data from the file input1 until a new line character is reached and stores the string in the variable plainText
                    printf("\n Encrypted text: %s \n", plainText);   
                         
                    decryptionSubstitution(plainText);                  // The decryptionSubstitution function is called and the previously obtained values for plainText string are used as an input
                    printf("\n Decrypted text: %s", plainText);
               
               output = fopen( "outputText.txt", "w");         // Opens the file inputKey.txt and establishes that data will be written to the file ("w")
                
                        if (output == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                            }  
                            
                    fprintf(output, "Decrypted text : %s", plainText);      // The plainText string is printed to the outputText file
                
                break;                              // Once the case has been executed this block of code will "break" i.e. jump to the next line of code outside the switch case statments
               
      
      
      case 5:          // If the user selects 5, the following code will run
                printf("\n The option selected was 5 : Decryption with a rotation cipher given the input text \n");
              
              input1 = fopen( "input.txt", "r" );      // Opens the file input.txt and establishes that data will be read from the file ("r")
               
                        if (input1 == NULL) {           // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                        }
                        
               fscanf(input1, " %[^\n]s", plainText);              // The fscaf() reads data from the file input1 until a new line character is reached and stores the string in the variable plainText
                  
              decryptionNoKey(plainText);                       // The decryptionNoKey function is called and the string inputText is the input value
              printf("\n Decrypted text: %s", plainText);
               
               output = fopen( "outputText.txt", "w");         // Opens the file inputKey.txt and establishes that data will be written to the file ("w")
                
                        if (output == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                            }  
                            
                    fprintf(output, "Decrypted text : %s", plainText);      // The plainText string is printed to the outputText file
                 
               
               
               break;                               // Once the case has been executed this block of code will "break" i.e. jump to the next line of code outside the switch case statments
               
       default: printf("\n An unknown option was selected. Please select 1, 2, 3, 4, or 5 \n");         // If the user does not select an option from 1-5, the defualt case will print this warning to the screen
   }
  
    return 0;

}



// ENCRYPTION ROTATION CIPHER FUNCTION DEFINITION:
/* The encryptionRotation function accepts a string of characters in plainText and for each value within the string, 
 * The function also accepts an integer shift which is the key that determines what value to add to each character.
 *
 * The rotation cipher operates within a for() loop that increments based off an index counter for each value in the string.
 * The function keeps punction, spaces and numbers the same by adding the shift key to ASCII values.
 * between 32 and 65. To prevemt letters from exceeding the ASCII characters for the upper case alphabet, 26 is subtracted. Lower case
 * characters have ASCII values above 97, therefore by subtracting 32 the upper case equivalent can be obtained.
 *
 * The shift integer must be between 0 and 25. The input string must have a length less than 499 characters as per 
 * the initialisation of the variable. A pointer to the string plainText is returned by the function.
 *
 */
char encryptionRotation(char plainText[], int shift)    {

        for (int index = 0; index <= strlen(plainText) && plainText[index] != '\0' ; index ++)   {      // note: '\0' is the ASCII 'zero' character which terminates the string
          
                if ( plainText[index] >= 97 )  {
                     plainText[index] = plainText[index] - 32;        // This coverts lower case to capitals by subtracting 32 from characters with ASCII values above 97
                }   
            
                plainText[index] = ( plainText[index] + shift ); 
             
                if ( plainText[index] <= 65 && plainText[index] >= 32)    {
                      plainText[index] = plainText[index] - shift;      // This ensures that punctuation, spaces and number charcaters do not change
                 }
                   
                 if ( plainText[index] > 90)    {   
                     plainText[index] = plainText[index] - 26;        // Will prevent letters falling off the end if plainText[index] - shift < 0
                 }
                 
         }   
         
        return *plainText;       // Returns a pointer to the string plainText
}



// DECRYPTION ROTATION CIPHER FUNCTION DEFINITION
/* The decryptionRotation function accepts a string of characters in plainText.
 * The function also accepts an integer shift which is the key that determines what value to subtract from each character
 *
 * The rotation cipher operates within a for() loop that increments based off an index counter for each value in the string.
 * The function keeps punction, spaces and numbers the same by adding the shift key to ASCII values.
 * between 32 and 65. To prevemt letters from exceeding the ASCII characters for the upper case alphabet, 26 is added. Lower case
 * characters have ASCII values above 97, therefore by subtracting 32 the ipper case equivalent can be obtained.
 *
 * The shift integer must be between 0 and 25. The input string must have a length less than 499 characters as per 
 * the initialisation of the variable. A pointer to the string plainText is returned by the function.
 *
 */
char decryptionRotation( char plainText[], int shift )   {
    
        for ( int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++ )   {      // note: '\0' is the ASCII 'zero' character which terminates the string

   
                   if ( plainText[index] <= 65 && plainText[index] >= 32)    {
                             plainText[index] = plainText[index] + shift;       // This ensures that punctuation, space and number characters do not change
                    }
                 
            
                    plainText[index] = ( plainText[index] - shift );  
        
                     
                       if ( plainText[index] < 65 && plainText[index] > 32)    {
                             plainText[index] = plainText[index] + 26;       // Will prevent letters falling off the end if plainText[index] - shift < 0
                    }
                 
                    
                     if ( plainText[index] >= 97 )  {
                             plainText[index] = plainText[index] - 32;       // This coverts lower case to capitals by subtracting 32 from characters with ASCII values above 97
                     }
             }   
             
             return *plainText;      // Returns a pointer to the string plainText
            
}



// ENCRYPTION SUSTITUTION CIPHER FUNCTION DEFINITION
/* The encryptionSubstin accecpts a string input (array of type char) and will replace 
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
      
    return *plainText;              // Returns a pointer to the string plainText
    
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
      
    return *plainText;              // Returns a pointer to the string plainText
    
}



// DECRYPTION ROTATION CIPHER WITHOUT KEY DEFINITION
/* The decryptionNoKey function accepts a string of type char as an input.
 * The function executes three main steps to find the decrypted cipher text. It first determines the most
 * frequently occurring character in the plainText string and then assumes this character must be 'E'. 
 * The shiftKey is then calculated by determining the difference between the ASCII value for E and the ASCII value
 * of the most common character. The decryption algorithm can then be used with the value of shiftKey.
 *
 * The decryption operates within a for() loop that increments based off an index counter for each value in the string.
 * The function keeps punction, spaces and numbers the same by adding the shift key to ASCII values.
 * between 32 and 65. To prevemt letters from exceeding the ASCII characters for the upper case alphabet, 26 is added. Lower case
 * characters have ASCII values above 97, therefore by subtracting 32 the upper case equivalent can be obtained.
 *
 * If the output is incorrect and the shiftKey does not decrypt the text, the user can input 'NO' to the terminal
 * and the second most common letter will be assumed to be key. This process can be continued until the correct
 * decryption is found.
 *
 * The input string must have a length less than 499 characters as per the initialisation of the variable. 
 * A pointer to the string plainText is returned by the function.
 *
 */
char decryptionNoKey(char plainText[])          {
    
    // The following code finds most repeated character in the string plainText

int array[500] = {0};       // Initialize all elements of the array to 0
int max = array[0];         // Initialises the integer max to the first element of the array
int i = 0;                  // Index for the most frequent character in the string

        for( int index = 0; plainText[index] != '\0'; index ++ )    {
           ++array[ plainText[index] ];                 // This will count the number of times a character appears in the string
        }
    
        for(int index = 0; plainText[index] != '\0'; index ++)     {
           
                if( array[plainText[index]] > max && plainText[index] != ' ')     {
                     max = array[plainText[index] ];        // If the character's frequency is greater than the previous maximum, it becomes the new maximum
                     i = index;
                 }
        }

   printf("\n The most frequently occuring character is : %c \n", plainText[i]);     // For debugging purposes
   
   // This code will assume the most frequently occuring character is E and calculate the shift key based on this assumption
   // The shiftKey becomes the difference between the decrypted letter assumed to be E and the ASCII value for E
  int shiftKey = 0;           
    // To ensure the shiftKey is a positive number between 1 and 25, its value is calculated according to whether the letter is above/below 69 on the ASCII table
   if ( plainText[i] > 69)  {               // note: ASCII for 'E' is 69
       shiftKey = plainText[i] - 69;
   }
   else    shiftKey = 69 - plainText[i];
   
   
   
   // The following code then decrypts the message with the value of shiftKey 
   
   for ( int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++ )   {      // note: '\0' is the ASCII 'zero' character which terminates the string

   
                   if ( plainText[index] <= 65 && plainText[index] >= 32)    {
                             plainText[index] = plainText[index] + shiftKey;       // This ensures that punctuation, space and number characters do not change
                    }
                 
            
                    plainText[index] = ( plainText[index] - shiftKey );  
        
                     
                       if ( plainText[index] < 65 && plainText[index] > 32)    {
                             plainText[index] = plainText[index] + 26;       // Will prevent letters falling off the end if plainText[index] - shift < 0
                    }
   
   }
   
   // This section of the function will take a user input to identify whether the decryption was correct
   char result [10];
   
   printf(" Has the text been decrypted correctly? \n");
   printf(" Please input 'YES' or 'NO' \n");
   scanf("%s", result);
   
       if ( result == 'YES')    {
            return *plainText;          // Returns a pointer to the string plainText
       }
           else if (result == 'NO') {
    // The previous code is repeated but this time the most common character is assumed to be A
        int array[500] = {0};       // Initialize all elements of the array to 0
        int max = array[0];         // Initialises the integer max to the first element of the array
        int i = 0;                  // Index for the most frequent character in the string
        
                for( int index = 0; plainText[index] != '\0'; index ++ )    {
                   ++array[ plainText[index] ];                 // This will count the number of times a character appears in the string
                }
            
                for(int index = 0; plainText[index] != '\0'; index ++)     {
                   
                        if( array[plainText[index]] > max && plainText[index] != ' ')     {
                             max = array[plainText[index] ];        // If the character's frequency is greater than the previous maximum, it becomes the new maximum
                             i = index;
                         }
                }
        
           printf("\n The most frequently occuring character is : %c \n", plainText[i]);     // For debugging purposes
           
           // This code will assume the most frequently occuring character is A and calculate the shift key based on this assumption
           // The shiftKey becomes the difference between the decrypted letter assumed to be A and the ASCII value for A
          int shiftKey = 0;           
            // To ensure the shiftKey is a positive number between 1 and 25, its value is calculated according to whether the letter is above/below 69 on the ASCII table
           if ( plainText[i] > 65)  {               // note: ASCII for 'A' is 65
               shiftKey = plainText[i] - 65;
           }
           else    shiftKey = 65 - plainText[i];
           
           
           
           // The following code then decrypts the message with the value of shiftKey 
           
           for ( int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++ )   {      // note: '\0' is the ASCII 'zero' character which terminates the string
        
           
                           if ( plainText[index] <= 65 && plainText[index] >= 32)    {
                                     plainText[index] = plainText[index] + shiftKey;       // This ensures that punctuation, space and number characters do not change
                            }
                         
                    
                            plainText[index] = ( plainText[index] - shiftKey );  
                
                             
                               if ( plainText[index] < 65 && plainText[index] > 32)    {
                                     plainText[index] = plainText[index] + 26;       // Will prevent letters falling off the end if plainText[index] - shift < 0
                            }
           
           }
                       
                
           }
   
    return *plainText;              // Returns a pointer to the string plainText
    
}
