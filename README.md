# triplex
I created this program while following the course "Unreal Engine C++ Developer: Learn C++ and Make Video Games" found in Udemy [1]. The program is a simple game that will give 
the player the oportunity to crack open a safe box, which contains coins as loot. Each safe box has a level associated with, and can me cracked open by guessing the correct
sequence of three numbers that protect its lock. There are five safe boxes available to loot, and the difficulty increases (e.g. the range of numbers available widens). 

The project has the following folders.
* The folder src contains all the source code. 
* The folder bin contains a compiled executable (for Windows). 

The source code has the following files. 
* program.cpp. Contains the main function and is the entry point of the application.
* application.hpp, application.cpp. Contains a class to manage the application flow, including the input / output from / to the console.
* game.hpp, game.cpp. Contains the game class, which handles the levels of the game and the overall score. 
* safe_box.hpp, safe_box.cpp. Contains the safe_box class, which handles the level, the generation of codes and determines whether a player wins or loses the level loot. 

Following is the command I used to compile the executable:

```
cl /Fe"bin\triplex" /Fo"bin\tmp\\" /EHsc src\*.cpp
```

This will compile all the content found in the src file, output the exe to the bin directory and output all the intermediate objects to the bin\tmp directory.

References:
[1] https://www.udemy.com/course/unrealcourse
