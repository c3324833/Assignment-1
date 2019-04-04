#include <stdio.h>

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
            case 'a': encryptRK();
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
    
    // Case 'a': Function prototype for encryptRK()
    void encryptRK(char message, int key);
    
    int main() {
        
        char message;
        int key;
        
        printf("Enter message to encrypt: ");
        scanf("%c", message);
        
        printf("Enter rotation key: ");
        scanf("%d", &key);
        
        encryptRK(message, key);
        
        return 0;
    }
    
    void encryptRK(char message [], int key)
   
    

  return 0;
}
