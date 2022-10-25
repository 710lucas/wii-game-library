# Introduction

Hi! This is still an idea, but I'll try to make like a library that can be used with GRRLIB to make the process of creating games for the nintendo wii easier

As I said, it's just an idea, don't expect it to be perfect of even to be finished

# How to use it

## 1 - Download the important files

- You can clone the repository and edit the main.cpp file located inside the source folder in the template folder

## 2 - Compile

- After editing the main file, you can just use the make command and the program will compile normally

## 3 - Using without the template folder and files

- In order to use this library in any file, you'll need to copy the game-lib.cpp and game-lib.h files into the directory that you're using to compile the main cpp files

- Or you can mannually specify in the Makefile where the files are located and where to compile them

    -  Those changes can be made in the line 20 of the template's Makefile, adding a second path

    - And in the line 22, specifying where the files are included from

Idk if it's a good explanation, so feel free to change it and keep in mind that this is a really new project that's still WIP.