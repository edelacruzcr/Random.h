# 🤝 Guía de Contribución

¡Gracias por tu interés en contribuir a **Random Library** (`random.h`)!

## 🚀 Cómo Contribuir

1. **Haz un Fork** del repositorio.
2. **Crea una rama** para tu funcionalidad o corrección:
   ```bash
   git checkout -b feature/NuevaFuncionalidad
   ```
3. **Realiza tus cambios** y asegúrate de mantener el estándar del código C.
4. **Prueba los ejemplos**:
   ```bash
   gcc examples/example1.c -o example1 && ./example1
   ```
5. **Haz un Commit** claro con tus cambios:
   ```bash
   git commit -m "feat: agregar nueva función random_xyz"
   ```
6. **Haz Push** a tu rama:
   ```bash
   git push origin feature/NuevaFuncionalidad
   ```
7. **Abre un Pull Request** explicando tus mejoras.

## 📏 Estándar de Código
- Mantener las funciones como `static inline` en `random.h`.
- Documentar las funciones con comentarios concisos en español.
- Respetar la compatibilidad C99+.
