# Triplex

Triplex es un pequeño programa que emula la lógica de un juego simple, el cual le da la oportunidad al jugador de intentar abrir una
caja fuerte, la cual contiene monedas que puede saquear. Cada caja fuerte tiene un nivel asociado, y puede ser abierta si se adivina
la secuencia correcta de los tres números que protegen sus pasadores protectores. Hay cinco cajas fuertes disponislbes para saquear, 
y la dificultad va en aumento (i.e. aumenta el ragno de números disponibles).

Creé este programa siguiendo el curso "Unreal Engine C++ Developer: Learn C++ and Make Video Games" que tomé en Udemy [1].

El proyecto tiene la siguiente estructura estándar para aplicaciones C++:
* include - contiene los encabezados con las declaraciones de las clases. 
* src - contiene el código fuente con la implementación de las clases y la aplicación en general. 
* .vscode - algunos archivos de configuración de Visual Studio Code.

El código está organizado en los siguientes archivos:
* program.cpp - contiene la función _main_ y es el punto de entrada de la aplicación. 
* application.cpp - contiene la clase que gestiona el flujo de la aplicación, incluyendo la entrada y salida desde la consola. 
* game.cpp - contiene la clase que gestiona los niveles del juego y el puntaje general. 
* safe_box.cpp - contiene la clase que gestiona el nivel, la generación de códigos y determina las condiciones de victoria o derrota, así como el nivel del botín. 

El código está integrado con Visual Studio Code, utiliza el último compilador de Visual C++ y el estándar de lenguaje C++ 20. Se proporciona un archivo _CMakeLists.txt_ para integrarlo con CMake. Desde Visual Studio Code, con las extensiones de C++ y CMake instaladas, solo se necestia ejecutar estos dos comandos en la paleta de comandos:

```
CMake: Configure
CMake: Build
```

Con ello, el ejecutable estará disponible en la ruta  _build/debug/triplex.exe_. 

References:
[1] https://www.udemy.com/course/unrealcourse
