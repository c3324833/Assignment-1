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
void decryptR(char *message); // Function prototype for decrypting a rotation cipher without key
/*void decryptS(char character);*/ // Function prototype for decrypting a substitution cipher without key


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
        task. It is dependent on what c is equal to (i.e. the choice the user selects*/
        switch(c){ 
            case 'a': // This formatting means that if c is equal to 'a' it will complete the following tasks 
                encryptRK(message, rKey); // This calls the function in main and at this point in the code, it will jump to the function defintion and then go back to normal flow control once completed 
                printf("Encrypted message: %s\n", message); // After the function has been executed, it will print the user friendly prompt followed by the variable message using the %s format specifier for a string, and then enter a new line finish
                
                break; // Entering a break statement ensures that the other following options are not executed as they would with normal flow control. The break jumps out to the end of the swtich case statement
                 
            case 'b': 
                decryptRK(message, rKey); // This calls on the function for decrypting with a rotation cipher if 'b''is selected with the function arguments in brackets as formatted for all switch case options
                printf("Decrypted message: %s\n", message); // After executing the function, flow control continues to print a message labelled as the decrypted message with the same format for the string
                
                break;
                
           case 'c': 
                encryptSK(message, sKey);
                printf("Encrypted message: %s\n", message);
                
                break;
                
            case 'd': 
                decryptSK(message, sKey);
                printf("Decrypted message: %s\n", message);
                
                break;
                
            case 'e': 
                decryptR(message);
                //printf("Decrypted message: %s\n", message);
                
                break;
                
            /*case 'f': 
                decryptS(message); 
                printf("Decrypted message: %s\n", message);
                
                break;*/
                
            default: printf("Unknown option %c\nPlease enter a, b, c, d, e or f\n"); 
            /* The default option in the switch case is executed if the value of 'c' doesn't match any
            other value. In this case, this would occur if the user entered a letter that was not a 
            lowercase a to f. If this occurs the default option will print an error message for the user
            by stating 'unknown option' with the %c inserting the char value of c so that the user can see
            the option they incorrectly entered. After a new line it will then ask the user to select a 
            valid option, printing the possible options again. */
        }
    }
    return 0; // This closes main 
}


    /***************************************************************************************************/
    // Case 'a': Function for encryptRK() 
    
     /* This function does not need a return value since the message is stored in the memory location after 
    encryption, meaning the return data type is void. The function name is encryptRK, with the R standing
    for rotation, and the K indicating there is a key. The arguments that the function takes in are the 
    message and the key. The message is a string of letters (array of type char) and since message was 
    declared in main when the user inputs their message, a pointer (denoted by a *) is used infront of the
    variable name to instruct the function to change data in that memory location. The rotation key is a 
    whole number between 0 and 25 so it is of integer data type. */
    
    void encryptRK(char *message, int rKey){ // This is the function definition and begins by restating the prototype then opening braces 
    
    char character; // A char is declared called character so that the function can process individual letters rather than the whole message at once
	int i; // A integer is declared called i to be used as a counter in the FOR loop to cycle through each individual character in chronological order
	
	/* This FOR loop is initialised with the format of (initialisation; condition; increment) 
	To start at the first character of the message, the counter must start at zero (initialisation)
	As long as the message continues to exist, all characters should have the rotation key function
	executed, meaning that the condition is that while the message is not equal to zero. The Boolean != 
	symbol is used and '\0' is used to denote NULL which is the last value stored in string memory. As
	long as the message does not each NULL, the function will continue to execute. The increment means
	that one will be added to the counter each time the loop executes to move to the next character.*/
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i]; // The [i] element of message (value of i in each loop) is stored in the variable character for the function to be executed on 
	    
		if(character >= 'a' && character <= 'z'){ // This IF statement is used to detect if the message entered is in lowercase text 
		    character = character - 32; // If this is true, 32 is subtracted from the lowercase ASCII value of the letter to convert it to its uppercase version. This new ASCII value is then assigned to the variable character.
		    character = character + rKey; // Once the uppercase ASCII value is stored, the value of the key is added to the character
			
			if(character > 'Z'){ // If after executing this addition, the ASCII value of character is greater than Z, it will match to a symbol rather than a letter which will not be readable
				character = character - 26; // If this is true, 26 will be subracted from the ASCII value so that it can be matched to the correct uppercase letter in the alphabet
			}
		}
			
		else if(character >= 'A' && character <= 'Z'){ // If the message is entered as an uppercase string, the ASCII values are already in the correct form so need to be treated differently from the lowercase values, meaning a seperate IF statement
			character = (character + rKey); // The key can be added straight to these values and stored in the variable character 
			
		      if(character > 'Z'){ // If after executing this addition, the ASCII value of character is greater than Z, it will match to a symbol rather than a letter which will not be readable
				character = character - 26; // If this is true, 26 will be subracted from the ASCII value so that it can be matched to the correct uppercase letter in the alphabet
			   }
	    }

			message[i] = character; // Once the value of character is calculated with the rotation key added, this is then stored back in the corresponding string memory address of where it was taken, replacing the character in the string with its encrypted version
    }

	return 0; // Once this FOR loop has executed until reaching NULL in the message, all characters will have been replaced with their encrypted version so the function has been completed and can return to its position where called in main to resume flow control and print the result
    }



/*****************************************************************************************************/
// Case 'b': Function for decryptRK()

/* This function prototype is the same as case a, however the function name is different for decryption.
This is because it also has no return value and uses the same arguments and their data types. The same
variables of character and i are also declared to decrypt each individual character at a time with the
same FOR loop format used to execute the function.*/

void decryptRK(char *message, int rKey){
    
	char character;
	int i;
	

	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){ // This IF statement is used to detect if the message entered is in lowercase text 
		    character = character - 32; // If this is true, 32 is subtracted from the lowercase ASCII value of the letter to convert it to its uppercase version. This new ASCII value is then assigned to the variable character.
		    character = character - rKey; // The key is then subtracted from this ASCII value since this does the opposite of encryption
			
			if(character < 'A'){ // If this subtraction results in an ASCII value which is less than A this will not match to a letter and needs to be converted 
				character = character + 26; // If this is true, adding 26 to the ASCII value will match it to the correct letter in the alphabet to be read
	      }
	   }

			
		else if(character >= 'A' && character <= 'Z'){ // If the message is entered as an uppercase string, the ASCII values are already in the correct form
			character = (character - rKey); // If this is true, the key can be directly subtracted 
			
			if(character < 'A'){ // As seen above, if this subtraction does not match to a letter, 26 can be added to the ASCII value
				character = character + 26;
			}
		}
		
		message[i] = character; // Once the value of character is calculated with the rotation key subtracted, this is then stored back in the corresponding string memory address of where it was taken, replacing the character in the string with its decrypted version
}

	return 0; // Once this FOR loop has executed until reaching NULL in the message, all characters will have been replaced with their decrypted version so the function has been completed and can return to its position where called in main to resume flow control and print the result
}

/******************************************************************************************************/
// Case 'c': Function for encryptSK()

/*  This function also does does not need a return value as explained previously, meaning the return 
    data type is void. The function name is encryptSK, with the S now standing for substitution and the 
    K indicating there is a key. The arguments that the function takes in are the still the message and
    the key. The message is a string of letters (array of type char) and since message was declared in 
    main when the user inputs their message, a pointer (denoted by a *) is used infront of the variable
    name to instruct the function to change data in that memory location. The substitution key is also
    now enetered as a string since the user will enter 26 letters in non-alphabetical order, making it 
    an array of type char. Since this string was also declared in main, a pointer is used to pass it 
    to the function. */

void encryptSK(char *message, char *sKey){
        
    char character; // Same character and counter initialised to encrypt each individual letter at a time
	int i;
	
	// The same FOR loop conditions are initialised to cycle through each character of the message
	
	for(i = 0; message[i] != '\0'; i++){
		character = message[i]; 
	    
		if(character >= 'a' && character <= 'z'){ // If a lowercase letter is detected, this IF statement will convert the ASCII value to an uppercase by subtracting 32
		    character = character - 32;
	   }
	   
	   /* This switch case statement is used to replace a long series of IF statements, depending on 
	   what letter the character is (the compiler interprets this through ASCII values). Break 
	   statements are used ensure that only one case is executed and each character is only assigned
	   a new value from the key once. The switch case identifies which letter of the alphabet the 
	   character is, and depending on the position of that letter in the alphabet, it will replace
	   the character with the key value entered at that same position in the alphabet. For example,
	   case 'A' shows that if the character is equal to A, the A will be replaced with the first 
	   element of the string sKey and so on.*/
	   
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
	       /* The default statement will execute if the character identified in the message does not
	       match to any of the above options. This would occur if whitespace was entered by the user
	       and these spaces should be left as spaces to make the message readable. This default option
	       therefore assigns a space to the varaible character if a letter is not detected. */
	   }
	   
		message[i] = character; // Once the value of character is calculated with the matching key value replacing it, this is then stored back in the corresponding string memory address of where it was taken, replacing the character in the string with its encrypted version
		
		}

	return 0; // Once this FOR loop has executed until reaching NULL in the message, all characters will have been replaced with their encrypted version so the function has been completed and can return to its position where called in main to resume flow control and print the result
	
    }

/******************************************************************************************************/
// Case 'd': Function for decryptSK()

/* This function for decrypting a message using substitution cipher and a key is the reverse of case 'c'
so the function prototype is identical apart from the name. It has no return value and also uses pointers
from main to pass the strings of message ans sKey to the function which are the arguments. They are both 
strings so are of char data type. The same variables of character and i (counter) are declared and the
same FOR loop specification are used to execute the function. */

void decryptSK(char *message, char *sKey){
    
	char character;
	int i;
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){ // This IF statement again converts lowercase letter to uppercase letters by subracting 32
		    character = character - 32;
        }


        /* The following set of IF... ELSE IF statements are used in a similar way to the switch case in
        case 'c' as they execute one possible option depending on the value of character. A switch case
        would not have worked as easily in this scenario since it is dependent on the value of character
        being an integer data type. For decrypting below, it is testing which position in the string 
        the character is equal to and with this being an array, a switch case does not work. A series of
        IF... ELSE IF statements can be used instead. This tests which value of the substitution key the
        character is equal to and then assigns the corresponding letter of the alphabet to the variable
        character. Using ELSE IF ensures that only one option is executed since IF statements alone could
        allow a value to be assigned to the variable character, and this value could then match another 
        value of sKey and get replaced again. */
       
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
        
		message[i] = character; // This value of character is then stored back in the corresponding element of the message 
		
	}

	return 0; // This function quits after all characters have been decrypted and continues normal flow control in main where the result is printed
	
    }


/********************************************************************************************************/
// Case 'e': Function for decryptR()

void decryptR(char *message){
    
    char character;
	int i;
    
    for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message);


    for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message);

    for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message);

	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message);  
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
    	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
    
        if(character >= 'a' && character <= 'z'){ 
		    character = character - 32; 
        }
        if(character != 32){
            character = character - 1;
        }
        if(character < 'A' && character != 32){
                character = character + 26;
        }
        if(character == 32){
                character = ' ';
        }
        message [i] = character; 
    }   
    printf("Possible decryption: %s\n", message); 
    
}

