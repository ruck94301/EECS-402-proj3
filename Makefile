all: proj3.exe

proj3.exe: Color.o ColorImage.o Location.o PPMImage.o proj3.o
	# link object files to produce executable
	g++ Color.o ColorImage.o Location.o PPMImage.o proj3.o -o proj3.exe

proj3.o: proj3.cpp constants.h
	g++ -g -std=c++98 -Wall -c proj3.cpp -o proj3.o
Color.o: Color.cpp Color.h constants.h
	g++ -g -std=c++98 -Wall -c Color.cpp -o Color.o
ColorImage.o: ColorImage.cpp ColorImage.h constants.h
	g++ -g -std=c++98 -Wall -c ColorImage.cpp -o ColorImage.o
Location.o: Location.cpp Location.h constants.h
	g++ -g -std=c++98 -Wall -c Location.cpp -o Location.o
PPMImage.o: PPMImage.cpp PPMImage.h constants.h
	g++ -g -std=c++98 -Wall -c PPMImage.cpp -o PPMImage.o

test:
	./proj3.exe < test.1.in.txt | tee test.1.out.txt
	./proj3.exe < test.2.in.txt | tee test.2.out.txt

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
