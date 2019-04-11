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

    while(c < 'a' || c > 'f'){
        switch(c){
            case 'a': encryptRK(character, key);
                break;
            /*case 'b': decryptRK();
                break;
            case 'c': encryptSK();
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
    
       char message[100] = {0}; 
       int i; // character counter 
        
        printf("Enter message to encrypt: ");
        scanf("%s", message);

        printf("Enter rotation key: ");
        scanf("%d", &key);
        
        char encrypted = (((character - 65) + 390) + (key % 26) % 26) + 65;
        
        for(i = 0; i < 100; i++ ){
        message[i] = encrypted;
        printf("%c", message[i]);
        }
        
        return encrypted;

 