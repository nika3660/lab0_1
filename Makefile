make all: build run 

clear:
	rm *.txt
	rm *.out

build:
	gcc main.c -fopenmp -lgmp

run:
	clear
	./a.out
	python3 main.py