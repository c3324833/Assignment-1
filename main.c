#include <stdio.h>

char encryptRK(char character, int key); // Function prototype for encypting a rotation cipher with key

int main() {
    char character;
    int key;
    
    printf("Please select an option: \n");\
    printf("a) Encrypt a message using rotation cipher with key given\n");
    printf("b) Decrypt a message using rotation cipher with key given\n");
    printf("c) Encrypt a message using substitution cipher with substitutions given\n");
    printf("d) Decrypt a message using substitution cipher with substitutions given\n");
    printf("e) Decrypt a message using rotation cipher given text only\n");
    printf("f) Decrypt a message using substitution cipher given text only\n");

    char c;
    scanf("%c", &c);

    while(c > 'a' || c < 'f'){
        switch(c){
            case 'a': encryptRK(character, key);
                break;
            case 'b': decryptRK();
                break;
            /*case 'c': encryptSK();
                break;
            case 'd': decryptSK();
                break;
            case 'e': decryptR();
                break;
            case 'f': decryptS();
                break;*/
            default: printf("Unknown option %c\nPlease enter a, b, c, d, e or f\n");
        }
    }
    return 0;
}


    /***********************************************************************************/
    // Case 'a': Function for encryptRK() 
    
    char encryptRK(char character, int key){
        
	char message[100];
	int i;
	
	printf("Enter a message to encrypt: ");
	scanf("%s", message);
	
	printf("Enter rotation key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
		    character = character + key;
			
			if(character > 'z'){
				character = character - 'z' + 'a' - 1;
			}
			
			message[i] = character;
		}
		else if(character >= 'A' && character <= 'Z'){
			character = (character + key);
			
			if(character > 'Z'){
				character = character - 'Z' + 'A' - 1;
			}
			
			message[i] = character;
		}
	}
	
	printf("Encrypted message: %s", message);
	//return message[i];
}

/**********************************************************************************************/
// Case 'b': Function for decryptRK()

 char decryptRK(char character, int key){
        
	char message[100];
	int i;
	
	printf("Enter a message to decrypt: ");
	scanf("%s", message);
	
	printf("Enter rotation key: ");
	scanf("%d", &key);
	
	for(i = 0; message[i] != '\0'; ++i){
		character = message[i];
		
		if(character >= 'a' && character <= 'z'){
		    character = character - 32;
		    character = character - key;
			
			if(character > 'z'){
				character = character - 'z' + 'a' - 1;
			}
			
			message[i] = character;
		}
		else if(character >= 'A' && character <= 'Z'){
			character = (character - key);
			
			if(character > 'Z'){
				character = character - 'Z' + 'A' - 1;
			}
			
			message[i] = character;
		}
	}
	
	printf("Decrypted message: %s", message);
	//return message[i];
}   

/******************************************************************************************/
// Case 'c': Function for 
 