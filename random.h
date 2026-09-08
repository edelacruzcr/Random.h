#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// ============================================================
// CONFIGURACIÓN
// ============================================================

#define RANDOM_VERSION "1.0.0"

// ============================================================
// INICIALIZACIÓN (AUTOMÁTICA)
// ============================================================

static int _random_initialized = 0;

static void _random_init(void) {
    if (!_random_initialized) {
        srand((unsigned int)time(NULL));
        _random_initialized = 1;
    }
}

// Forzar reinicialización (opcional)
static inline void random_reseed(void) {
    srand((unsigned int)time(NULL));
    _random_initialized = 1;
}

// ============================================================
// FUNCIÓN PRINCIPAL
// ============================================================

// Obtener un número aleatorio entre 0 y RAND_MAX
static inline int random_number(void) {
    _random_init();
    return rand();
}

// ============================================================
// NÚMEROS ALEATORIOS
// ============================================================

// Número entre 0 y max (inclusive)
static inline int random_int(int max) {
    _random_init();
    return rand() % (max + 1);
}

// Número entre min y max (inclusive)
static inline int random_range(int min, int max) {
    _random_init();
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    return min + (rand() % (max - min + 1));
}

// Número decimal entre 0.0 y 1.0
static inline double random_decimal(void) {
    _random_init();
    return (double)rand() / (RAND_MAX + 1.0);
}

// Número decimal entre min y max
static inline double random_decimal_range(double min, double max) {
    _random_init();
    if (min > max) {
        double temp = min;
        min = max;
        max = temp;
    }
    return min + random_decimal() * (max - min);
}

// ============================================================
// CARACTERES ALEATORIOS
// ============================================================

// Elegir un carácter aleatorio de un string
static inline char random_char(const char *conjunto) {
    _random_init();
    int total = strlen(conjunto);
    if (total == 0) return '\0';
    return conjunto[rand() % total];
}

// Elegir una letra minúscula aleatoria (a-z)
static inline char random_lowercase(void) {
    return random_char("abcdefghijklmnopqrstuvwxyz");
}

// Elegir una letra mayúscula aleatoria (A-Z)
static inline char random_uppercase(void) {
    return random_char("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

// Elegir un dígito aleatorio (0-9)
static inline char random_digit(void) {
    return random_char("0123456789");
}

// Elegir un carácter alfanumérico (A-Z, a-z, 0-9)
static inline char random_alnum(void) {
    return random_char("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
}

// Elegir un carácter hexadecimal (0-9, A-F)
static inline char random_hex(void) {
    return random_char("0123456789ABCDEF");
}

// ============================================================
// STRINGS ALEATORIOS
// ============================================================

// Generar string aleatorio
static inline void random_string(char *destino, int longitud, const char *conjunto) {
    _random_init();
    int total = strlen(conjunto);
    if (total == 0) {
        destino[0] = '\0';
        return;
    }
    for (int i = 0; i < longitud; i++) {
        destino[i] = conjunto[rand() % total];
    }
    destino[longitud] = '\0';
}

// Generar string y devolver puntero (requiere free())
static inline char* random_string_alloc(int longitud, const char *conjunto) {
    char *resultado = (char *)malloc(longitud + 1);
    if (resultado == NULL) return NULL;
    random_string(resultado, longitud, conjunto);
    return resultado;
}

// Generar string con letras minúsculas
static inline void random_string_lower(char *destino, int longitud) {
    random_string(destino, longitud, "abcdefghijklmnopqrstuvwxyz");
}

// Generar string con letras mayúsculas
static inline void random_string_upper(char *destino, int longitud) {
    random_string(destino, longitud, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

// Generar string con números
static inline void random_string_digits(char *destino, int longitud) {
    random_string(destino, longitud, "0123456789");
}

// Generar string alfanumérico
static inline void random_string_alnum(char *destino, int longitud) {
    random_string(destino, longitud, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
}

// Generar string hexadecimal
static inline void random_string_hex(char *destino, int longitud) {
    random_string(destino, longitud, "0123456789ABCDEF");
}

// ============================================================
// CONTRASEÑAS Y CÓDIGOS
// ============================================================

// Generar contraseña (alfanumérico + especiales)
static inline void random_password(char *destino, int longitud) {
    random_string(destino, longitud, 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()_+-=[]{}|;:,.<>?");
}

// Generar código de verificación (sin caracteres confusos)
static inline void random_code(char *destino, int longitud) {
    random_string(destino, longitud, 
        "ABCDEFGHJKLMNPQRSTUVWXYZ"  // Sin O, I, etc.
        "23456789");                // Sin 0, 1, etc.
}

// Generar PIN numérico
static inline void random_pin(char *destino, int longitud) {
    random_string(destino, longitud, "0123456789");
}

// Generar UUID simple (8 caracteres hexadecimales)
static inline void random_uuid(char *destino) {
    random_string_hex(destino, 8);
}

// Generar token (alfanumérico largo)
static inline void random_token(char *destino, int longitud) {
    random_string_alnum(destino, longitud);
}

// ============================================================
// UTILIDADES
// ============================================================

// Mezclar un string (desordenar caracteres)
static inline void random_shuffle(char *texto) {
    _random_init();
    int len = strlen(texto);
    for (int i = len - 1; i > 0; i--) {
        int j = random_range(0, i);
        char temp = texto[i];
        texto[i] = texto[j];
        texto[j] = temp;
    }
}

// Lanzar un dado (1-6)
static inline int random_dado(void) {
    return random_range(1, 6);
}

// Lanzar una moneda (0 = cruz, 1 = cara)
static inline int random_moneda(void) {
    return random_int(1);
}

// Elegir un elemento de un array de strings
static inline const char* random_choice(const char **opciones, int total) {
    _random_init();
    if (total <= 0) return NULL;
    return opciones[random_range(0, total - 1)];
}

// Elegir un elemento de un array de enteros
static inline int random_choice_int(const int *opciones, int total) {
    _random_init();
    if (total <= 0) return 0;
    return opciones[random_range(0, total - 1)];
}

// Elegir un elemento de un array de doubles
static inline double random_choice_double(const double *opciones, int total) {
    _random_init();
    if (total <= 0) return 0.0;
    return opciones[random_range(0, total - 1)];
}

// ============================================================
// FUNCIONES ESTADÍSTICAS
// ============================================================

// Generar número con distribución normal (aproximada sin requerir <math.h> ni -lm)
static inline double random_normal(double media, double desviacion) {
    _random_init();
    double suma = 0.0;
    for (int i = 0; i < 12; i++) {
        suma += random_decimal();
    }
    double z = suma - 6.0; // Media = 0, Varianza = 1
    return media + desviacion * z;
}

// Generar número booleano (verdadero/falso)
static inline int random_bool(void) {
    return random_moneda();
}

#endif // RANDOM_H
