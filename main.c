/* This code allows the user to encrypt and decrypt cipher text using both rotation or
substitution cipher methods. The encryption process takes a “message” and “key” as inputs
from the user and produces cipher text. The decryption process performs the reverse by
converting cipher text and the key back into the human-readable original message. This
code allows the user to select from the different options provided depending on whether
they would like to use encryption or decrytion, and with both possible methods. It also 
allows the user to select an option if they key for their cipher text is unknown. It 
includes two header files, the first being the standard #include <stdio.h> which is used
for all C code, and the second being #include <string.h> which allows strings to be taken
from stdin and printed to stdout.*/ 
 
#include <stdio.h>
#include <string.h>      

/* Since this code uses a variety of functions, these functions must have prototypes
which are located above main in the code. These are in the form of return_datatype 
function_name (arguments). Each function will be furthered explained in their definitions.*/

void encryptRK(char *message, int rKey); // Function prototype for encypting a rotation cipher with key
void decryptRK(char *message, int rKey); // Function prototype for decrypting a rotation cipher with key
void encryptSK(char *message, char *sKey); // Function prototype for encrypting a substitution cipher with key given
void decryptSK(char *message, char *sKey); // Function prototype for decrypting a substitution cipher with key given 
/*void decryptR(char character); // Function prototype for decrypting a rotation cipher without key
void decryptS(char character);*/ // Function prototype for decrypting a substitution cipher without key


int main() {
    char *message[100]; // Declaring a string (array of type char) which stores a collection of variables, being the message entered by the user 
    int rKey; // Declaring an integer as the rotation key (integer number representes number of shifts of the alphabet to the right)
    char sKey[26]; // Declaring a string as the substitution key which stores a rearranged version of the alphabet and therefore holds 26 variable
    char c; // Declaring a char to be used to take in user input and select the relevant option from the menu
    
    // The following printf() statements print a menu to stdout for the user to read
    
    printf("Please select an option (a to f) and press <enter>: \n"); // This prompts the user to select a letter
    printf("a) Encrypt a message using rotation cipher with key given\n");
    printf("b) Decrypt a message using rotation cipher with key given\n");
    printf("c) Encrypt a message using substitution cipher with substitutions given\n");
    printf("d) Decrypt a message using substitution cipher with substitutions given\n");
    printf("e) Decrypt a message using rotation cipher given text only\n");
    printf("f) Decrypt a message using substitution cipher given text only\n");

    printf("Selected option: ");
    scanf("%c", &c); // This takes the user input from stdin and stores it in the char declared as 'c'
    
    // The following IF statement prints an error statement is the user does not enter a valid option
    if (c < 'a' || c > 'f'){
        printf("Invalid option\n Please select a letter a to f");
    }
    
    // The following WHILE statement executes the preceding IF statements, as long as the user inputs a valid option
    while(c >= 'a' && c <= 'f'){
        if(c == 'a' || c == 'c'){ 
            printf("Enter a message to encrypt: "); // If the user selects either encryption option (a or c) it prints a prompt for them to enter a human readable message
        }
        else{
            printf("Enter a message to decrypt: "); // Otherwise, all other options are decryption tasks so if a or c is not selected, it prompts the user to enter a message to be decoded
        }
        
        scanf(" %[^\n]s", message); /* This scanf() function takes in the user input 
        which will be enterted in the form of a string of letters (the message).
        the "%s" format specifier is used for storing strings, however by placing the 
        [^\n] within the format specifier here, it instructs the compiler to continue
        to read information from stdin even when whitespace is detected. It only quits
        reading the user input when a new line is detected. This allows messages with
        mutiple words to be enterd by the user and encrypted or decrypted. The & symbol
        is not used before the variable name (message) as an array name is already a
        pointer to the element when using strings.*/
        
        if(c == 'a' || c == 'b'){ // This IF statment is used to recognise if the user selected an option using rotaiton cipher with a key (a or b) using the Boolean OR and EQUALS symbols
            printf("Enter rotation key (number 0 to 25): "); // If this is true, it prints this message to prompt the user to enter a number as the rotation
	        scanf("%d", &rKey);  // The %d format specifier is used to store integers, and the & symbol is needed to point to where to store this input, being rKey
        }
        
        if(c == 'c' || c == 'd'){ // This IF statement is use to recognise if the user selected an option using substitution cipher with a key (c or d) using the Boolean OR and EQUALS symbols
            printf("Enter substitution key (string of letters to be allocated to the alphabet in given order: "); // If this is ttue, it prints this message to prompt the user to enter their chosen key which will be later used
            scanf("%s", sKey); // This is then read form stdin as a string that was entered, meaning th the %s format specifier is used and no & symbol necessary for strings
        }
        
        /* The following swith case is used with the user-friendly menu to replace a 
        long line of IF statements depending on which option the user selected as their
        task. */
        switch(c){ 
            case 'a': 
                encryptRK(message, rKey);
                printf("Encrypted message: %s\n", message);
                
                break;
                
            case 'b': 
                decryptRK(message, rKey);
                printf("Decrypted message: %s\n", message);
                
                break;
                
           case 'c': 
                encryptSK(message, sKey);
                printf("Encrypted message: %s\n", message);
                
                break;
                
            case 'd': 
                decryptSK(message, sKey);
                printf("Decrypted message: %s\n", message);
                
                break;
                
            /*case 'e': decryptR(character);
                break;
            case 'f': decryptS(character); 
                break;*/
                
            default: printf("Unknown option %c\nPlease enter a, b, c, d, e or f\n");
        }
    }
    return 0;
}


    /***********************************************************************************/
    // Case 'a': Function for encryptRK() 
    
    void encryptRK(char *message, int rKey){
        
    char character;
	int i;
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
	    
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
		    character = character + rKey;
			
			if(character > 'Z'){
				character = character - 26;
			}
		}
			
		else if(character >= 'A' && character <= 'Z'){
			character = (character + rKey);
			
		      if(character > 'Z'){
				character = character - 26;
			   }
	    }

			message[i] = character;
    }

	return 0;
    }



/**********************************************************************************************/
// Case 'b': Function for decryptRK()

void decryptRK(char *message, int rKey){
    
	char character;
	int i;
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
		    character = character - rKey;
			
			if(character < 'A'){
				character = character + 26;
	      }
	   }

			
		else if(character >= 'A' && character <= 'Z'){
			character = (character - rKey);
			
			if(character < 'A'){
				character = character + 26;
			}
		}
		
		message[i] = character;
}

	return 0;
}

/******************************************************************************************/
// Case 'c': Function for encryptSK()
    
void encryptSK(char *message, char *sKey){
        
    char character;
	int i;
	//char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
	    
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
			
			if(character > 'Z'){
				character = character - 26;
			}
	   }
	   
	   switch(character){
	       case 'A': character = sKey[0];
	            break;
	       case 'B': character = sKey[1];
	            break;
	       case 'C': character = sKey[2];
	            break;
	       case 'D': character = sKey[3];
	            break;
	       case 'E': character = sKey[4];
	            break;
	       case 'F': character = sKey[5];
	            break;
	       case 'G': character = sKey[6];
	            break;
	       case 'H': character = sKey[7];
	            break;
	       case 'I': character = sKey[8];
	            break;
	       case 'J': character = sKey[9];
	            break;
	       case 'K': character = sKey[10];
	            break;
	       case 'L': character = sKey[11];
	            break;
	       case 'M': character = sKey[12];
	            break;
	       case 'N': character = sKey[13];
	            break;
	       case 'O': character = sKey[14];
	            break;
	       case 'P': character = sKey[15];
	            break;
	       case 'Q': character = sKey[16];
	            break;
	       case 'R': character = sKey[17];
	            break;
	       case 'S': character = sKey[18];
	            break;
	       case 'T': character = sKey[19];
	            break;
	       case 'U': character = sKey[20];
	            break;
	       case 'V': character = sKey[21];
	            break;
	       case 'W': character = sKey[22];
	            break;
	       case 'X': character = sKey[23];
	            break;
	       case 'Y': character = sKey[24];
	            break;
	       case 'Z': character = sKey[25];
	            break;
	       default: character = ' ';
	   }
	   
		message[i] = character;
		
		}

	return 0;
	
    }

/**************************************************************************************/
// Case 'd': Function for decryptSK()

void decryptSK(char *message, char *sKey){
    
	char character;
	int i;
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
        }

		
		if(character < 'A' && character != 32){
				character = character + 26;
        }
        
        
    
        if(character == sKey[0]){
            character = 'A';
        }
        
        else if(character == sKey[1]){
            character = 'B';
        }
        
        else if(character == sKey[2]){
            character = 'C';
        }
        
        else if(character == sKey[3]){
            character = 'D';
        }
        
        else if(character == sKey[4]){
            character = 'E';
        }
        
        else if(character == sKey[5]){
            character = 'F';
        }
        
        else if(character == sKey[6]){
            character = 'G';
        }
        
        else if(character == sKey[7]){
            character = 'H';
        }
        
        else if(character == sKey[8]){
            character = 'I';
        }
        
        else if(character == sKey[9]){
            character = 'J';
        }
        
        else if(character == sKey[10]){
            character = 'K';
        }
        
        else if(character == sKey[11]){
            character = 'L';
        }
        
        else if(character == sKey[12]){
            character = 'M';
        }
        
        else if(character == sKey[13]){
            character = 'N';
        }
        
        else if(character == sKey[14]){
            character = 'O';
        }
        
        else if(character == sKey[15]){
            character = 'P';
        }
        
        else if(character == sKey[16]){
            character = 'Q';
        }
        
        else if(character == sKey[17]){
            character = 'R';
        }
        
        else if(character == sKey[18]){
            character = 'S';
        }
        
        else if(character == sKey[19]){
            character = 'T';
        }
        
        else if(character == sKey[20]){
            character = 'U';
        }
        
        else if(character == sKey[21]){
            character = 'V';
        }
        
        else if(character == sKey[22]){
            character = 'W';
        }
        
        else if(character == sKey[23]){
            character = 'X';
        }
        
        else if(character == sKey[24]){
            character = 'Y';
        }
        
        else if(character == sKey[25]){
            character = 'Z';
        }
        
        /*else if(character == 32){
            character = ' ';
        }*/
        
		message[i] = character;
		
	}

	return 0;
	
    }

	      
 