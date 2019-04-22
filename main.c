/* Programming Assignment 1: English Text Ciphers
Created: 3 / 04 / 2019
Author: Sarah Creasey
Description: This code encrypts and decrypts input text based off a Rotation Cipher or a Substitution Cipher.
The input is read from the relevant files (input.txt and inputKey.txt) and printed to the console. The output is also 
sent to a text file (output.txt). Users must first select which option they wish to execute in the terminal using ./a.out
*/

#include <stdio.h>
#include <string.h>  


// ENCRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char encryptionRotation(char plainText[], int shift);

// DECRYPTION ROTATION CIPHER FUNCTION PROTOTYPE
char decryptionRotation(char plainText[], int shift);

// ENCRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char encryptionSubstitution(char plainText[]);

// DECRYPTION SUSTITUTION CIPHER FUNCTION PROTOTYPE
char decryptionSubstitution(char plainText[]);

// DECRYPTION ROTATION CIPHER WITHOUT KEY PROTOTYPE
int decryptionNoKey(char plainText[]);

// STRING TEST FOR MOST COMMON ENGLISH WORDS
int stringTest(char plainText[], char testString[]);


int main()  {
    
    // Prints a user-friendly menu system to the interface. Users must select an integer from 1-5 to successfully run the cipher code.

    printf("Please select an option from the following menu: \n");
    printf("1 - Encryption with a rotation cipher given input text and key \n");
    printf("2 - Decryption with a rotation cipher given input text and key \n");
    printf("3 - Encryption with a substitution cipher given input text and key \n");
    printf("4 - Decryption with a substitution cipher given input text and key \n");
    printf("5 - Decryption with a rotation cipher given the input text \n");
    
    // The integer must be entered into the file menuSelection.txt and then the code must be run using the 
    
    int menuSelection = 0;      // The user's menu selection is to be stored in this integer 
    scanf("%d", &menuSelection); // Uses a custom run function to recieve an input from the text file labelled menuSelection
    char plainText[1000];        // Initialises the string of type char to a length of 500 characters
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
                printf("\n The option selected was 5 : Decryption with a rotation cipher given the input text \n\n");
              
              input1 = fopen( "input.txt", "r" );      // Opens the file input.txt and establishes that data will be read from the file ("r")
               
                        if (input1 == NULL) {           // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                            perror("fopen()");
                            return -1;
                        }
                        
               fscanf(input1, " %[^\n]s", plainText);              // The fscaf() reads data from the file input1 until a new line character is reached and stores the string in the variable plainText
                
               printf("Encrypted text : %s \n\n", plainText);
              
               decryptionNoKey(plainText);                       // The decryptionNoKey function is called and the string inputText is the input value
               
            
               break;                               // Once the case has been executed this block of code will "break" i.e. jump to the next line of code outside the switch case statments
               
       default: printf("\n Select 1, 2, 3, 4, or 5 and enter into the text file 'menuSelection' \n");         // This will be printed to the screen by default on the first run 
		   											      // Users are prompted to enter their selection into a text file then run using runCipher
		   											      // note: runCipher scans the input for menuSelection from the text file
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
 * The shift integer must be between 0 and 25. The input string must have a length less than 999 characters as per 
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
 * The shift integer must be between 0 and 25. The input string must have a length less than 999 characters as per 
 * the initialisation of the variable. A pointer to the string plainText is returned by the function.
 *
 */
char decryptionRotation( char plainText[], int shift )   {
    
        for ( int index = 0; index <= strlen(plainText) && plainText[index] != '\0'; index ++ )   {      // note: '\0' is the ASCII 'zero' character which terminates the string
                        
                plainText[index] = ( plainText[index] - shift );  
                    
                   if ( ( plainText[index] + shift ) < 65 && ( plainText[index]+ shift) >= 32)    {
                             plainText[index] = plainText[index] + shift;       // This ensures that punctuation, space and number characters do not change
                    }
                
                 
                  if ( plainText[index] < 65 && plainText[index] > 39 && plainText[index] != '.')    {          // By checking that the character is not '.' punction is left unchanged
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
 * input string must have a length less than 999 characters as per the initialisation of the variable
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
 * input string must have a length less than 999 characters as per the initialisation of the variable
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
 * The function executes a brute force attack by printing the decryption attempt for key values between 0 and 25.
 *
 * The decryption operates within a for() loop that increments based off an index counter for each value in the string.
 * The function keeps punction, spaces and numbers the same by adding the shift key to ASCII values.
 * between 32 and 65. To prevemt letters from exceeding the ASCII characters for the upper case alphabet, 26 is added. Lower case
 * characters have ASCII values above 97, therefore by subtracting 32 the upper case equivalent can be obtained.
 *
 * The input string must have a length less than 499 characters as per the initialisation of the variable. 
 * A pointer to the string plainText is returned by the function.
 *
 */
int decryptionNoKey(char plainText[])          {

        FILE *output;
        output = fopen( "outputText.txt", "w");         // Opens the file inputKey.txt and establishes that data will be written to the file ("w")
                
                if (output == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                      perror("fopen()");
                      return -1;
                }  


   for (int counter = 1; counter <= 26; counter ++ )   {
    int shift = 1;
    
        decryptionRotation(plainText, shift);			// The decryptionRotation function is called with the shift integer being 1 each time
	   							// note: The function returns a string one shift away from the initial input, 
	   							// therefore the next shift key only needs to be one to obtain the next rotation
        
        printf(" Decryption attempt %d : %s \n", counter, plainText); 
        fprintf(output, "Decryption attempt %d: %s \n", counter, plainText);      // The plainText string is printed to the outputText file 
         
        // Testing the decryption attempt with the 12 most common words in the English language
        stringTest(plainText, " THE ");
         stringTest(plainText, " AND ");
         stringTest(plainText, " OF");
         stringTest(plainText, " TO");
         stringTest(plainText, " IS");
         stringTest(plainText, " THAT");
         stringTest(plainText, " THIS");
         stringTest(plainText, " WITH");
         stringTest(plainText, " YOU");
         stringTest(plainText, " ARE");
         stringTest(plainText, " FROM");
         stringTest(plainText, " NOT");

      }
   return 0;  
}



// STRING TEST FOR MOST COMMON ENGLISH WORDS
/* The stringTest function accepts the plainText string of encrypted text and the testString of a 
 * word in the English language that the string is to be searched for. The strstr() function is called 
 * and compares the two strings. If a match is found between the strings, the strstr() function returns 1.
 *
 * If the return value of strstr() is not NULL, a match has been found and the string with the correct 
 * decrypted text is re-printed to the interface. The stringTest function returns 1 if a match is found.
 * 
 * The plainText input string must have a length less than 499 characters as per the initialisation 
 * of the variable. 
 */
int stringTest(char plainText[], char testString[])     {
    	 
    	FILE *output;
        output = fopen( "outputText.txt", "w");         // Opens the file inputKey.txt and establishes that data will be written to the file ("w")
                
                if (output == NULL) {                // If the input is NULL (nothing) then an error message is printed and the value -1 is returned
                      perror("fopen()");
                      return -1;
                }  
                
                
        	if ( (strstr(plainText, testString) ) != NULL) {           // the strstr() function tests for matching characters
        		                                                      // If NULL is not returned, a match has been found between the strings
        		printf(" A match found : %s \n", testString);
        		printf("\n Decrypted text: %s \n \n", plainText);
                fprintf(output, "Decrypted text: %s \n", plainText);      // The correctly decrypted plainText string is printed to the outputText file 
                return 1;
             }	 
   return 0;
}


