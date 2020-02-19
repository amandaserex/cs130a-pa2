
prog1: quash.cpp quash.h hash.cpp hash.h
	g++ -o prog1 quash.cpp hash.cpp

clean:
	/bin/rm -f prog1 *.o
