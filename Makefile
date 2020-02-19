
prog1.out: quash.cpp quash.h hash.cpp hash.h
	g++ -o prog1.out quash.cpp hash.cpp

clean:
	/bin/rm -f prog1.out *.o
