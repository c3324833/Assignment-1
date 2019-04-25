  
#include <stdio.h>
#include <string.h>      

void encryptRK(char *message, int rKey); // Function prototype for encypting a rotation cipher with key
void decryptRK(char *message, int rKey); // Function prototype for decrypting a rotation cipher with key
void encryptSK(char *message, char *sKey);
void decryptSK(char *message, char *sKey);
/*void decryptR(char character);
void decryptS(char character);*/


int main() {
    char *message[100];
    int rKey;
    char sKey[26];
    char c;
    
    printf("Please select an option: \n");\
    printf("a) Encrypt a message using rotation cipher with key given\n");
    printf("b) Decrypt a message using rotation cipher with key given\n");
    printf("c) Encrypt a message using substitution cipher with substitutions given\n");
    printf("d) Decrypt a message using substitution cipher with substitutions given\n");
    printf("e) Decrypt a message using rotation cipher given text only\n");
    printf("f) Decrypt a message using substitution cipher given text only\n");

    printf("Selected option: ");
    scanf("%c", &c);
    
    if (c < 'a' || c > 'f'){
        printf("Invalid option\n Please select a letter a to f");
    }

    while(c >= 'a' && c <= 'f'){
        if(c == 'a' || c == 'c'){
            printf("Enter a message to encrypt: ");
        }
        else{
            printf("Enter a message to decrypt: ");
        }
        
        scanf(" %[^\n]s", message);
        
        if(c == 'a' || c == 'b'){
            printf("Enter rotation key: ");
	        scanf("%d", &rKey); 
        }
        
        if(c == 'c' || c == 'd'){
            printf("Enter substitution key (string of letters to be allocated to the alphabet in given order: ");
            scanf("%s", sKey);
        }
        
        
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

	      
 