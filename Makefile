
prog1: quash.cpp quash.h
	g++ -o prog1 quash.cpp

clean:
	/bin/rm -f prog1 *.o
