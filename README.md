# StarMadeNative

### Recommeded compilers/IDEs:

Windows - Visual Studio 2015

Linux - CodeBlocks GCC 4.7+

OSX - XCode

## Notes

You made need to update the JDK location in the compiler includes

The configured JDK location on CodeBlocks is "../java/jdk1.8.0_92/"

To change the configured location in CodeBlocks navigate to 'Project -> Build Options'

Check the image below for the location, make sure you select "StarMadeNative" on the left side
![CBP JDK Settings](http://i.imgur.com/codt2kl.png)

## Compiling with the Makefile
Clone this repo and navigate to the StarMadeNative directory; <br>
`git clone https://github.com/Schine/StarMadeNative.git && cd StarMadeNative`<br><br>
Check compiler options in the Makefile are correct (you **must** check that the JAVADIR and JAVAOSDIR variables are set to your Java 8 installation directories; <br>
JAVADIR should look like this, but it will differ depending on your operating system, these examples are for Debian Linux 11 with Oracle Java 8 installed.<br>
`JAVADIR= /usr/lib/jvm/jdk1.8.0_321/include`<br>
JAVAOSDIR should look like this, again, will differ depending on operating system.<br>
`JAVAOSDIR = /usr/lib/jvm/jdk1.8.0_321/include/linux`<br>
However if you are not on Linux, for example you are on FreeBSD, then the `include/linux` will instead be `include/FreeBSD`<br>
Once the compiler options in the Makefile are adapted to your system, run <br>
`make clean && make all`<br>
You will then find the compiled StarMade native library in `StarMadeNative/bin/Releases/libStarMadeNative64.so`.
