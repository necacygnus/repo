all: domaci_1
domaci_1: domaci_1.o
	gcc -o domaci_1 domaci_1.o
domaci_1.o: domaci_1.c
	gcc -c domaci_1.c
clean:
	rm domaci_1.o domaci_1
run:
	./domaci_1
