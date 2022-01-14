all: main


main: add.o apple.o
	icc -o $@ $^ -g

%o: %c
	icc -c -o $< -g

%o: %cpp
	icc -c -o $< -g

clean:
	rm *.o main
