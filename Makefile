CC = g++
EXEC = Interpolation
FLAGS = -Wall -pedantic -O3 -Os
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
STD = -std=c++17
S = src
O = obj
B = bin

all: $(O) $(B) $(O)/Main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/Main.o: $(O)/Engine.o
	$(CC) $(S)/Main.cpp -c -o $(O)/Main.o $(STD) $(FLAGS)

$(O)/Engine.o: $(O)/Board.o
	$(CC) $(S)/Engine.cpp -c -o $(O)/Engine.o $(STD) $(FLAGS)

$(O)/Board.o: $(O)/Polynome.o
	$(CC) $(S)/Board.cpp -c -o $(O)/Board.o $(STD) $(FLAGS)

$(O)/Polynome.o:
	$(CC) $(S)/Polynome.cpp -c -o $(O)/Polynome.o $(STD) $(FLAGS)

clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)
