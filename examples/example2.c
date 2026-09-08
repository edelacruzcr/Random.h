#include <stdio.h>
#include "../random.h"

int main(void) {
    printf("=== GENERADOR DE CONTRASEÑAS ===\n\n");
    
    for (int i = 0; i < 5; i++) {
        char pass[17];
        random_password(pass, 16);
        printf("Contraseña %d: %s\n", i + 1, pass);
    }
    
    return 0;
}
