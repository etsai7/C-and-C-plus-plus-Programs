C++ = g++
CFlags = -c -g

all: project4

project4: project4_test.o Course.o Fact.o Rubric.o Student.o Project4_utilities.o
	$(C++) -o project4 project4_test.o Course.o Fact.o Rubric.o Student.o Project4_utilities.o

clean:
	find *.o ! -name Project4_utilities.o -exec rm -f {} +

%.o:	%.cpp
		$(C++) $(CFlags) $*.cpp
