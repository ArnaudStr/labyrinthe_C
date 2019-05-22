CFLAGS = -O2 -Wall -g -Llib

all : bin/genlab bin/cheminlab

bin/genlab : lib/libens.a lib/libmat.a lib/libgraph.a obj/main.o obj/genlab.o 
	gcc $(CFLAGS) obj/genlab.o obj/main.o -lens -lgraph -lmat -L/usr/X11R6/lib -lX11 -o genlab
	mv genlab bin/.
	
bin/cheminlab : lib/libens.a lib/libmat.a lib/libgraph.a obj/cheminlab.o obj/genlab.o 
	gcc $(CFLAGS) obj/genlab.o obj/cheminlab.o -lens -lgraph -lmat -L/usr/X11R6/lib -lX11 -o cheminlab
	mv cheminlab bin/.	

obj/genlab.o : src/genlab.c include/genlab.h
	gcc $(CFLAGS) -c -lens -lgraph -lmat -L/usr/X11R6/lib -lX11 src/genlab.c -Iinclude
	mv genlab.o obj/
	
obj/cheminlab.o : src/cheminlab.c include/cheminlab.h
	gcc $(CFLAGS) -c -lens -lgraph -lmat -L/usr/X11R6/lib -lX11 src/cheminlab.c -Iinclude
	mv cheminlab.o obj/

obj/ensemble.o: src/ensemble.c include/ensemble.h
	gcc $(CFLAGS) -c src/ensemble.c -Iinclude
	mv ensemble.o obj/
	
obj/graph.o: src/graph.c include/graph.h
	gcc $(CFLAGS) -c -L/usr/X11R6/lib -lX11 src/graph.c -Iinclude
	mv graph.o obj/
		
obj/matrice.o: src/matrice.c include/matrice.h
	gcc $(CFLAGS) -c src/matrice.c -Iinclude
	mv matrice.o obj/

obj/main.o: src/main.c
	gcc $(CFLAGS) -c -lens -lgraph -lmat -L/usr/X11R6/lib -lX11 src/main.c src/genlab.c -Iinclude
	mv main.o obj/
			
lib/libens.a: obj/ensemble.o
	ar -crs ./lib/libens.a obj/ensemble.o
	ranlib ./lib/libens.a

lib/libgraph.a: obj/graph.o
	ar -crs ./lib/libgraph.a obj/graph.o
	ranlib ./lib/libgraph.a
	
lib/libmat.a: obj/matrice.o
	ar -crv ./lib/libmat.a obj/matrice.o
	ranlib ./lib/libmat.a

gendoc :
	doxygen -g
	
exedoc :
	doxygen Doxyfile
	
archive:
	tar -cvz src/ include/ bin/ lib/ obj/ html/ Doxyfile makefile -f STRAUMANN_Arnaud.tar.gz
			
clean :
	rm obj/* bin/* lib/*
