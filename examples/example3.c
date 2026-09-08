#include <stdio.h>
#include "../random.h"

int main(void) {
    printf("=== GENERADOR DE CÓDIGOS ===\n\n");
    
    for (int i = 0; i < 5; i++) {
        char code[7];
        random_code(code, 6);
        printf("Código %d: %s\n", i + 1, code);
    }
    
    return 0;
}
