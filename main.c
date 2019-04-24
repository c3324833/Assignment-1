 
#include <stdio.h>
#include <string.h>      

void encryptRK(char *message, int rKey); // Function prototype for encypting a rotation cipher with key
void decryptRK(char *message, int rKey); // Function prototype for decrypting a rotation cipher with key
void encryptSK(char *message, char *sKey);
/*void decryptSK(char character, int sKey);
void decryptR(char character);
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
                
            /*case 'd': decryptSK(character, key);
                break;
            case 'e': decryptR(character);
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
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	for(i = 0; message[i] != '\0'; i++){
		character = message[i];
	    
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
			
			if(character > 'Z'){
				character = character - 26;
			}
	   }
		
		if(character == alphabet[1]){
		    character = sKey[1];
		}
		
		if(character == alphabet[2]){
		    character = sKey[2];
		}
		
		if(character == alphabet[3]){
		    character = sKey[3];
		}
		
		if(character == alphabet[4]){
		    character = sKey[4];
		}
		
		if(character == alphabet[5]){
		    character = sKey[5];
		}
		
		if(character == alphabet[6]){
		    character = sKey[6];
		}
		
		if(character == alphabet[7]){
		    character = sKey[7];
		}
		
		if(character == alphabet[8]){
		    character = sKey[8];
		}
		
		if(character == alphabet[9]){
		    character = sKey[9];
		}
		
		if(character == alphabet[10]){
		    character = sKey[10];
		}
		
		if(character == alphabet[11]){
		    character = sKey[11];
		}
		
		if(character == alphabet[12]){
		    character = sKey[12];
		}
		
		if(character == alphabet[13]){
		    character = sKey[13];
		}
		
		if(character == alphabet[14]){
		    character = sKey[14];
		}
		
		if(character == alphabet[15]){
		    character = sKey[15];
		}
		
		if(character == alphabet[16]){
		    character = sKey[16];
		}
		
		if(character == alphabet[17]){
		    character = sKey[17];
		}
		
		if(character == alphabet[18]){
		    character = sKey[18];
		}
		
		if(character == alphabet[19]){
		    character = sKey[19];
		}
		
		if(character == alphabet[20]){
		    character = sKey[20];
		}
		
		if(character == alphabet[21]){
		    character = sKey[21];
		}
		
		if(character == alphabet[22]){
		    character = sKey[22];
		}
		
		if(character == alphabet[23]){
		    character = sKey[23];
		}
		
		if(character == alphabet[24]){
		    character = sKey[24];
		}
		
		if(character == alphabet[25]){
		    character = sKey[25];
		}
		
		if(character == alphabet[26]){
		    character = sKey[26];
		}
		
		message[i] = character;
		
		}

	return 0;
	
    }
 