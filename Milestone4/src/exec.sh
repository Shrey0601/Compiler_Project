gcc -S -fno-asynchronous-unwind-tables -fno-exceptions a.c
gcc -c a.s -o a.o; gcc a.o -o a
./a
cd ..
./milestone4 -i ./src/a.java 