# Powerscript
Ok so this is my **custom language** and I like it. I didn't realize it but it looks like python, and I didn't know python had some of theses keywords.

The first version was made on 2019/02/13
The first github version was made on 2019/02/23

# Build and installation
> Currently no build tools are working 

Building is pretty easy considering the fact, that the language is only using the standard library and some OS specific api that every compiler on thoses OS have.
## Windows
If you are on windows you can use Visual Studio or Mingw or any other compiler that can compile C++ but no build tools at the moment are integrated to the source.
## Linux
Building on linux is pretty easy, you can use the standard ide approach or use one of the script in `../build`
#### G++
It's on pretty much every linux distro 
```sh
cd Powerscript/build
sh build/g++.sh
```
## Mac OS
Idk
