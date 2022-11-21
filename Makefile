# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
SRC = Proyecto.c Listas.c Listas.h
CFLAGS2 = -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lallegro -lallegro_primitives -lallegro_audio -lallegro_acodec -o main `pkg-config --libs gtk+-3.0` 


# Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) main.c -o main $(CFLAGS2)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

Cola.o: Listas.c Listas.h
Proyecto.o: Proyecto.c Listas.h
