
#include <stdio.h>
#include <string.h>      

void encryptRK(char *message, int rKey); // Function prototype for encypting a rotation cipher with key
/*void decryptRK(char character, int rKey); // Function prototype for decrypting a rotation cipher with key
void encryptSK(char character, int sKey);
void decryptSK(char character, int sKey);
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
                
            /*case 'b': 
                decryptRK(character, key);
                break;
            case 'c': encryptSK(character, key);
                break;
            case 'd': decryptSK(character, key);
                break;
            case 'e': decryptR(character);
                break;
            case 'f': decryptS(character); */
                break;
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

void decryptRK(char character, int key){
    
	char message[100];
	int i;
	
	printf("Enter a message to decrypt: ");
	scanf("%[^\n]s", message);
	
	printf("Enter rotation key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
		    character = character - key;
			
			if(character < 'A'){
				character = character + 26;
	      }
	   }

			
		else if(character >= 'A' && character <= 'Z'){
			character = (character - key);
			
			if(character < 'A'){
				character = character + 26;
			}
		}
		
		message[i] = character;
}

	printf("Decrypted message: %s", message);
	//return message[i];
}

/******************************************************************************************/
// Case 'c': Function for encryptSK()


 