CC = g++

OBJECTS = proj7.o MyString.o
DEPS = MyString.h
EXE = proj7

all: $(OBJECTS) $(DEPS)
	$(CC) -o $(EXE) $(OBJECTS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm *.o $(EXE) 
