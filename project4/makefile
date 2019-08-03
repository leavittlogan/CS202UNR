CC = g++

OBJECTS = proj4.o Sensor.o Car.o Agency.o
DEPS = proj4.h Sensor.h Car.h Agency.h
EXE = proj4

all: $(OBJECTS) $(DEPS)
	$(CC) -o $(EXE) $(OBJECTS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm *.o $(EXE) 
