# 📚 MANUAL DE USO - RANDOM LIBRARY v1.0.0

## Tabla de Contenidos
1. [Instalación](#1-instalación)
2. [Importación](#2-importación)
3. [Funciones de Caracteres](#3-funciones-de-caracteres)
4. [Funciones de Strings](#4-funciones-de-strings)
5. [Funciones de Números](#5-funciones-de-números)
6. [Funciones de Contraseñas y Códigos](#6-funciones-de-contraseñas-y-códigos)
7. [Funciones de Utilidad](#7-funciones-de-utilidad)
8. [Funciones de Arrays (Choice)](#8-funciones-de-arrays-choice)
9. [Ejemplos Prácticos](#9-ejemplos-prácticos)
10. [Referencia Rápida](#10-referencia-rápida)

---

## 1. Instalación

### Opción A: Instalación Global (Recomendada)

```bash
# Copiar a /usr/local/include/
sudo cp random.h /usr/local/include/

# Verificar
ls -la /usr/local/include/random.h
```

### Opción B: Instalación Local (Sin sudo)

```bash
# Crear carpeta include en tu proyecto
mkdir -p include

# Copiar random.h
cp random.h include/
```

---

## 2. Importación

### Si instalaste globalmente:
```c
#include <random.h>   // Como stdio.h
```

### Si está en tu proyecto:
```c
#include "random.h"   // Con comillas
```

---

## 3. Funciones de Caracteres

### `random_char(conjunto)`
Selecciona un carácter aleatorio de un string.
```c
char c = random_char("ABC123");
```

### `random_lowercase()`
Devuelve una letra minúscula aleatoria (`a-z`).

### `random_uppercase()`
Devuelve una letra mayúscula aleatoria (`A-Z`).

### `random_digit()`
Devuelve un dígito aleatorio (`0-9`).

### `random_alnum()`
Devuelve un carácter alfanumérico (`A-Z`, `a-z`, `0-9`).

### `random_hex()`
Devuelve un carácter hexadecimal (`0-9`, `A-F`).

---

## 4. Funciones de Strings

### `random_string(destino, longitud, conjunto)`
Genera un string aleatorio de `longitud` caracteres usando el `conjunto`.

### `random_string_lower(destino, longitud)`
Genera un string con letras minúsculas.

### `random_string_upper(destino, longitud)`
Genera un string con letras mayúsculas.

### `random_string_digits(destino, longitud)`
Genera un string con solo dígitos.

### `random_string_alnum(destino, longitud)`
Genera un string alfanumérico.

### `random_string_hex(destino, longitud)`
Genera un string hexadecimal.

### `random_string_alloc(longitud, conjunto)`
Genera string y devuelve puntero asignado dinámicamente con `malloc` (requiere `free()`).

---

## 5. Funciones de Números

### `random_int(max)`
Número entero aleatorio entre 0 y `max` (inclusive).

### `random_range(min, max)`
Número entero aleatorio entre `min` y `max` (inclusive).

### `random_decimal()`
Número decimal aleatorio entre 0.0 y 1.0.

### `random_decimal_range(min, max)`
Número decimal aleatorio entre `min` y `max`.

### `random_normal(media, desviacion)`
Número con distribución normal (aproximada).

---

## 6. Funciones de Contraseñas y Códigos

### `random_password(destino, longitud)`
Genera una contraseña segura (mayúsculas, minúsculas, números, especiales).

### `random_code(destino, longitud)`
Genera código de verificación (evita caracteres confusos como O, 0, I, 1).

### `random_pin(destino, longitud)`
Genera PIN numérico.

### `random_uuid(destino)`
Genera UUID simple (8 caracteres hexadecimales).

### `random_token(destino, longitud)`
Genera token alfanumérico.

---

## 7. Funciones de Utilidad

### `random_shuffle(texto)`
Mezcla (desordena) los caracteres de un string.

### `random_dado()`
Lanza un dado (1 a 6).

### `random_moneda()`
Lanza una moneda (0 = cruz, 1 = cara).

### `random_bool()`
Devuelve un valor booleano (0 o 1).

---

## 8. Funciones de Arrays (Choice)

### `random_choice(opciones, total)`
Elige un elemento aleatorio de un array de strings.

### `random_choice_int(opciones, total)`
Elige un elemento aleatorio de un array de enteros.

### `random_choice_double(opciones, total)`
Elige un elemento aleatorio de un array de doubles.

---

## 9. Referencia Rápida

| Categoría | Función | Ejemplo |
| :--- | :--- | :--- |
| **Caracteres** | `random_char("ABC")` | `char c = random_char("ABC");` |
| **Strings** | `random_string(buf, 8, "ABC")` | `random_string(buf, 8, "ABC");` |
| **Contraseñas** | `random_password(buf, 16)` | `random_password(buf, 16);` |
| **Números** | `random_int(100)` | `int n = random_int(100);` |
| **Utilidades** | `random_dado()` | `int d = random_dado();` |

---

## 10. Licencia

MIT License - Libre uso comercial y personal.
