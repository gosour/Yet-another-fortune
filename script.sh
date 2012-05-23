#! /bin/sh
# Does everything for you
make
rm ./file.o
rm ./main.o
rm ./random.o

echo "Now run ./bin/main"
echo "You can also include this in your ~/.bashrc file for automatic startup"
