# Towers_Of_Hanoi
Code is in C++ language. 
## OpenGL Installation
### Ubuntu
Open terminal and run the following
```sh
sudo apt install freeglut3-dev
```
To run the code
```sh
g++ ./main.cpp -o game -lGL -lGLU -lglut
./game
```

### Mac
Open terminal and run the following 
```sh
clang++ main.cpp -o game -framework OpenGL  -framework GLUT
```

