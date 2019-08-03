CC = g++

OBJECTS = projX.o SmartPtr.o DataType.o
DEPS = SmartPtr.h DataType.h
EXE = projX

all: $(OBJECTS) $(DEPS)
	$(CC) -o $(EXE) $(OBJECTS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm *.o $(EXE) 
