.PHONY: test pre-submit

all: proj3.exe

proj3.exe: ColorClass.o PPMClass.o LocationClass.o proj3.o
	# link object files to produce executable
	g++ ColorClass.o PPMClass.o LocationClass.o proj3.o -o proj3.exe

proj3.o: proj3.cpp constants.h PPMClass.h
	g++ -g -std=c++98 -Wall -c proj3.cpp -o proj3.o
ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -g -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o
PPMClass.o: PPMClass.cpp PPMClass.h constants.h
	g++ -g -std=c++98 -Wall -c PPMClass.cpp -o PPMClass.o
LocationClass.o: LocationClass.cpp LocationClass.h constants.h
	g++ -g -std=c++98 -Wall -c LocationClass.cpp -o LocationClass.o

test:
	./proj3.exe < test.1.in.txt | tee test.1.out.txt
	./proj3.exe < test.2.in.txt | tee test.2.out.txt
	
	for N in 1 2 3 4 5; do rm -f new$$N.ppm; done 
	./proj3.exe < test.3.in.txt | tee test.3.out.txt
	diff test/test.3.out.txt test.3.out.txt
	for N in 1 2 3 4 5; do (set -x; cmp test/new$$N.ppm new$$N.ppm); done

gdb:
	gdb proj3.exe
	
# Valgrind Memcheck
# https://valgrind.org/docs/manual/quick-start.html
valgrind:
	valgrind --leak-check=yes --track-origins=yes proj3.exe

pre-submit:
	sh pre-submit.sh

clean:
	rm -f *.o *.exe


# g++ args
#   -g to include debugging information
#   -std=c++98 to specify the 1998 ISO C++ standard plus the 2003
#       technical corrigendum and some additional defect reports
#   -Wall
#   -c to compile or assemble the source files, but do not link
#   -o to place the primary output in file ...
