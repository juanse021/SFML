CC	= g++ -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: gravedad

gravedad: gravedad.cpp
	$(CC) -o gravedad gravedad.cpp $(LDFLAGS)

