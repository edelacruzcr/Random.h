# 🎲 Random Library

**Biblioteca header-only para C que genera valores aleatorios de forma simple, rápida y sin necesidad de inicialización manual.**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Language](https://img.shields.io/badge/Language-C-blue.svg)](random.h)
[![Version](https://img.shields.io/badge/version-1.0.0-green.svg)](random.h)

---

## 📋 Descripción

`random.h` es una biblioteca ligera de C que simplifica la generación de valores aleatorios (caracteres, strings, contraseñas, enteros, decimales, tiradas de dados, monedas, etc.). Es **header-only**, lo que significa que solo necesitas copiar el archivo `random.h` a tu proyecto o instalarlo en el sistema. Se inicializa automáticamente (`srand`) en su primer uso.

---

## 🚀 Uso Rápido

```c
#include <stdio.h>
#include "random.h" // o <random.h> si fue instalado en el sistema

int main(void) {
    // Carácter aleatorio
    char c = random_char("ABC"); 
    printf("Carácter: %c\n", c);

    // Cadena aleatoria de 8 caracteres
    char str[9]; 
    random_string(str, 8, "ABC");
    printf("String: %s\n", str);

    // Número entero entre 0 y 100
    int n = random_int(100);
    printf("Número: %d\n", n);

    return 0;
}
```

---

## 📦 Instalación y Descarga

### Opción 1: Clonar e instalar en el sistema (Recomendado)

```bash
# Clonar el repositorio
git clone https://github.com/edelacruzcr/Random.h.git
cd Random.h

# Copiar al directorio global de inclusión de C
sudo cp random.h /usr/local/include/
```

Una vez copiado, puedes incluirlo en cualquier programa C mediante:
```c
#include <random.h>
```

### Opción 2: Descargar solo el archivo `random.h` directamente

```bash
curl -O https://raw.githubusercontent.com/edelacruzcr/Random.h/main/random.h
```

Y luego moverlo a la carpeta de tu proyecto:
```c
#include "random.h"
```

---

## 🎯 Resumen de Funciones Principal

| Categoría | Función | Descripción | Ejemplo |
| :--- | :--- | :--- | :--- |
| **Caracteres** | `random_char(conjunto)` | Carácter de un grupo dado | `random_char("ABC")` |
| | `random_lowercase()` | Letra minúscula (`a-z`) | `random_lowercase()` |
| | `random_uppercase()` | Letra mayúscula (`A-Z`) | `random_uppercase()` |
| | `random_digit()` | Dígito (`0-9`) | `random_digit()` |
| **Strings** | `random_string(buf, len, conjunto)` | Cadena de caracteres | `random_string(buf, 8, "ABC")` |
| | `random_string_lower(buf, len)` | Solo minúsculas | `random_string_lower(buf, 8)` |
| | `random_string_upper(buf, len)` | Solo mayúsculas | `random_string_upper(buf, 8)` |
| | `random_string_digits(buf, len)` | Solo números | `random_string_digits(buf, 6)` |
| **Contraseñas**| `random_password(buf, len)` | Contraseña segura | `random_password(buf, 16)` |
| | `random_code(buf, len)` | Código alfanumérico limpio | `random_code(buf, 6)` |
| | `random_pin(buf, len)` | PIN numérico | `random_pin(buf, 4)` |
| **Números** | `random_int(max)` | Entero entre `0` y `max` | `random_int(100)` |
| | `random_range(min, max)` | Entero entre `min` y `max` | `random_range(10, 50)` |
| | `random_decimal()` | Decimal entre `0.0` y `1.0` | `random_decimal()` |
| | `random_decimal_range(min, max)`| Decimal entre `min` y `max` | `random_decimal_range(1.5, 9.9)` |
| **Utilidades** | `random_dado()` | Entero de `1` a `6` | `random_dado()` |
| | `random_moneda()` | Cara (`1`) o Cruz (`0`) | `random_moneda()` |
| | `random_shuffle(str)` | Mezcla los caracteres | `random_shuffle(mi_texto)` |

---

## 🔧 Compilación

```bash
# Compilar un programa de ejemplo
gcc programa.c -o programa

# Ejecutar
./programa
```

---

## 📁 Estructura del Repositorio

```text
random-lib/
├── README.md              # Descripción principal del proyecto
├── random.h               # Código fuente (Header-only)
├── LICENSE                # Licencia MIT
├── .gitignore             # Archivos ignorados por Git
├── examples/              # Ejemplos demostrativos de uso
│   ├── example1.c
│   ├── example2.c
│   └── example3.c
└── docs/                  # Documentación extendida
    └── manual.md          # Manual de referencia completo
```

---

## 📄 Licencia

Este proyecto está bajo la Licencia **MIT**. Consulta el archivo [LICENSE](LICENSE) para más detalles.
