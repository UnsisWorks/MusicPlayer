/*
 * Listas.h
 * Por: Dr. Víctor Alberto Gómez Pérez
 * Universidad de la Sierra Sur
 */

#include <stdio.h>

struct nodo{
	int info;
	struct nodo *sig;
};

struct nodo *Crear_Lista ();
void Insertar_Principio (struct nodo **Lista, int num);
void Insertar_Final(struct nodo **Lista, int num);
void Imprimir_Lista(struct nodo *Lista);
struct nodo *crea_nodo();
int Eliminar_Principio(struct nodo **Lista);
int Cuenta_nodo(struct nodo *Lista);
int Eliminar_Final(struct nodo **Lista);
int Buscar_Elemento(struct nodo *Lista,int num);
void Eliminar_Lista(struct nodo **Lista);
void Eliminar_X(struct nodo **Lista, int x);
void Insertar_Despues(struct nodo **Lista, int num, int ele);
void Insertar_Antes(struct nodo **Lista, int num, int ele);
