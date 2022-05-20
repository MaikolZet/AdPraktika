CFLAGS=-Wall
CPPFLAGS=
CC= g++
SOURCES= IN_script.c OUT_script.c main.c Prim.c lag.c Kruskal.c

all: exek proba

.PHONY: clean

clean:
	rm exek prim_out.txt kruskal_out.txt

exek: $(SOURCES) 
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(SOURCES)

proba:
	./exek
	

