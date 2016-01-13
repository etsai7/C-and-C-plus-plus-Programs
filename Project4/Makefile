C++ = g++
CFLAGS = -c -g

all: try_hash try_random test part2_test

test:  Main_Test.o ML_hash.o random_op.o
		$(C++) -o test ML_hash.o Main_Test.o random_op.o

part2_test: part2_test.o Service_Center.o Task.o Vehicle.o Cars.o Hybrids.o Motorcycles.o Bus.o ML_hash.o
		$(C++) -o part2_test  part2_test.o Service_Center.o Task.o Vehicle.o Cars.o Hybrids.o Motorcycles.o Bus.o ML_hash.o
		
try_hash:	try_hash.o ML_hash.o
		$(C++) -o try_hash try_hash.o ML_hash.o

try_random:	try_random.o random_op.o
		$(C++) -o try_random try_random.o random_op.o

clean:
		rm -f *.o 

%.o:	%.cpp
		$(C++) $(CFLAGS) $*.cpp

