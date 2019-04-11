#include <stdio.h>

char shift(char character, int key);
char encryptRK(char character, int key); // Function prototype for encypting a rotation cipher with key

int main() {

    printf("Please select an option: \n");\
    printf("a) Encrypt a message using rotation cipher with key given\n");
    printf("b) Decrypt a message using rotation cipher with key given\n");
    printf("c) Encrypt a message using substitution cipher with substitutions given\n");
    printf("d) Decrypt a message using substitution cipher with substitutions given\n");
    printf("e) Decrypt a message using rotation cipher given text only\n");
    printf("f) Decrypt a message using substitution cipher given text only\n");

    char c;
    scanf("%c", &c);

    while(c < 'a' || c > 'f'){
        switch(c){
            case 'a': shift();
                      encryptRK();
                break;
            case 'b': decryptRK();
                break;
            case 'c': encryptSK();
                break;
            case 'd': decryptSK();
                break;
            case 'e': decryptR();
                break;
            case 'f': decryptS();
                break;
            default: printf("Unknown option %c\nPlease enter a, b, c, d, e or f\n");
        }
    }
    return 0;

    /***********************************************************************************/
    // Case 'a': Function for encryptRK() by first doing the function for shifting 
    
    char shift(char character, int key){
        char shifted = (((character - 65) + 390) + (key % 26)) % 26) + 65;
        return shifted;
    }
    
    char encryptRK(char character, int key); // Function prototype
       
       char message[100]; 
       int i; // character counter 
        
        printf("Enter message to encrypt: ");
        scanf("%s"\ns, message);

        printf("Enter rotation key: ");
        scanf("%d", &key);
        
    for(i = 0; i < message; i++ ){
        printf("%s", message[i]);
        
    }


 