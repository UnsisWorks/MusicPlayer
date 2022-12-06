# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = `pkg-config --cflags --libs gtk+-3.0 gstreamer-1.0`
SRC = Proyecto.c Listas.c Listas.h

# Reglas explicitas

all: $(OBJ)
	$(CC) main.c -o main $(CFLAGS) 
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

Cola.o: Listas.c Listas.h
Proyecto.o: Proyecto.c Listas.h
