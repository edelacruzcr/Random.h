#include <stdio.h>
#include "../random.h"

int main(void) {
    // Caracteres
    printf("=== CARACTERES ===\n");
    printf("random_char(\"ABC\"): %c\n", random_char("ABC"));
    printf("random_lowercase(): %c\n", random_lowercase());
    printf("random_uppercase(): %c\n", random_uppercase());
    printf("random_digit(): %c\n", random_digit());
    
    // Strings
    printf("\n=== STRINGS ===\n");
    char str[13];
    random_string(str, 12, "ABC123");
    printf("random_string: %s\n", str);
    random_string_lower(str, 8);
    printf("random_string_lower: %s\n", str);
    
    // Contraseñas
    printf("\n=== CONTRASEÑAS ===\n");
    char pass[17];
    random_password(pass, 16);
    printf("Contraseña: %s\n", pass);
    
    char code[7];
    random_code(code, 6);
    printf("Código: %s\n", code);
    
    // Números
    printf("\n=== NÚMEROS ===\n");
    printf("random_int(100): %d\n", random_int(100));
    printf("random_range(50, 100): %d\n", random_range(50, 100));
    printf("random_decimal(): %.4f\n", random_decimal());
    
    // Utilidades
    printf("\n=== UTILIDADES ===\n");
    printf("Dado: %d\n", random_dado());
    printf("Moneda: %s\n", random_moneda() ? "Cara" : "Cruz");
    
    char texto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_shuffle(texto);
    printf("Mezclado: %s\n", texto);
    
    return 0;
}
