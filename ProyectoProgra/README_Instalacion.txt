ARCHIVOS CORREGIDOS - ProyectoProgra MVC

1. Reemplaza tus archivos actuales por estos archivos.
2. No uses ModeloLogin.h para declarar Usuario. El modelo correcto es ModeloUsuario.h.
3. Verifica que solo exista un main(), y debe estar únicamente en Login.cpp.
4. En Visual Studio, agrega todos los .cpp al proyecto:
   - dbConexion.cpp
   - ControladorLogin.cpp
   - ControladorRegistro.cpp
   - ControladorMenu.cpp
   - Login.cpp
   - Registro.cpp
   - MenuPrincipal.cpp
5. Verifica la referencia a MySql.Data.
6. Ejecuta:
   Build > Clean Solution
   Build > Rebuild Solution

TABLAS USADAS:
- tbl_usuario
- tbl_rol

CAMPOS USADOS:
tbl_usuario:
- id_usuario
- nombre
- correo
- nombre_usuario
- contrasena_usuario
- estado_usuario
- id_rol

tbl_rol:
- id_rol
- nombre_rol
