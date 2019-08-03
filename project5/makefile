CC = g++

OBJECTS = proj5.o Vehicle.o Car.o
DEPS = Vehicle.h Car.h
EXE = proj5

all: $(OBJECTS) $(DEPS)
	$(CC) -o $(EXE) $(OBJECTS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm *.o $(EXE) 
