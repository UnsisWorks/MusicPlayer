/*
 * Listas.c
 * Por: Dr. Víctor Alberto Gómez Pérez
 * Universidad de la Sierra Sur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"

struct nodo *Crear_Lista(){
	return NULL;
}

void Insertar_Principio (struct nodo **Lista, int num){
	struct nodo *p;
	p=crea_nodo();
	p->info=num;
	p->sig=*Lista;
	*Lista=p;
}

void Insertar_Final (struct nodo **Lista, int num){
	struct nodo *p,*aux;
	if(*Lista==NULL){
           Insertar_Principio(Lista,num);
	}
	else{
	     aux=*Lista;
             p=crea_nodo();
             p->info=num;
             p->sig=NULL;
	     for(;aux->sig!=NULL;)
                 aux=aux->sig;
             aux->sig=p;
	    }
}

int Eliminar_Principio(struct nodo **Lista)
{
	int num,e;
	struct nodo *p;
	//p=crea_nodo();
	p=*Lista;
	num=Cuenta_nodo (*Lista);
	if (num==0)
	{
		printf ("La lista estÃ¡ vacÃ­a...\n");
		return -9999;
	}
	else if (num==1)
			*Lista=NULL;
		else
			*Lista=(*Lista)->sig;	
	e=p->info;
	free (p);
	return e;
}

int Eliminar_Final(struct nodo **Lista) {
	int cont, ele=0;
	struct nodo *p, *aux;;
	cont=Cuenta_nodo(*Lista);
	aux=*Lista;
	if(cont == 0)
               {
		printf("La lista estÃ¡ vacÃ­a...\n");
                return -9999;
               }
	else{
		if(cont==1){
			ele = aux->info;
			*Lista=NULL;
		}
		else{
			for(;aux->sig!=NULL;){
				p=aux;
				aux=aux->sig;
			}
			ele = aux->info;
			p -> sig = NULL;
			//free(aux);
		}
	}
        free(aux);
	return ele;	
}


int Buscar_Elemento(struct nodo *Lista,int num){	
	struct nodo *aux;
	int x=0,ban=0;
	aux=Lista;
	if(Lista==NULL)
	   printf("\nLista vacÃ­a Buscar_Elemento\n");
	else{
	     for( ;aux!=NULL && ban==0; ){
		 if(aux->info==num)
		    ban=1;
		 aux=aux->sig;
		 x++;
		}
	    }
        if(ban==0)
		return 0;
	else
		return x; 
}


void Eliminar_Lista(struct nodo **Lista){
	int i,cont;
	struct nodo *aux;
	aux=*Lista;
	cont=Cuenta_nodo(aux);
	for(i=0;i<cont;i++)
	    Eliminar_Final(Lista);
	//~printf("\nLista eliminada Eliminar_Lista\n");
}

struct nodo *crea_nodo(){
	return ((struct nodo *)malloc(sizeof(struct nodo)));
}

void Imprimir_Lista(struct nodo *Lista){
	for(;Lista!=NULL;Lista=Lista->sig)
		printf("%d->",Lista->info);
	printf("NULL");
	printf("\n");
}

int Cuenta_nodo(struct nodo *Lista){
	int i=0;
	for( ;Lista!=NULL; Lista=Lista->sig)
		i++;
	return i;
}

void Insertar_Antes(struct nodo **Lista, int num, int ele){
	struct nodo *Q, *X, *T;
	int band=1;
	Q=*Lista;
	while(Q->info != ele && band == 1){
		if(Q->sig!=NULL){
			T = Q;
			Q = Q->sig;
		}
		else
			band = 0;
	}
	if(band==1){
		X=crea_nodo();
		X->info=num;
		if(*Lista == Q)
			Insertar_Principio(Lista, num);
		else{
			T->sig=X;
			X->sig =Q;
		}
	}
	else
		printf("El nodo %d dado como referencia no se encuentra en la lista.\n",ele);
}

void Insertar_Despues(struct nodo **Lista, int num, int ele){
	struct nodo *Q, *T;
	int band =1;
	Q=*Lista;
	while(Q->info!=ele && band==1){
		if(Q->sig!=NULL)
			Q=Q->sig;
		else
			band = 0;
	}
	if(band==1){
		T=crea_nodo();
		T->info=num;
		T->sig=Q->sig;
		Q->sig=T;
	}
	else
		printf("El nodo %d dado como referencia no se encuentra en la lista.\n",ele);
}

void Eliminar_X(struct nodo **Lista, int x){
	struct nodo *Q, *T;
	int band = 1;
	Q=*Lista;
	while(Q->info!=x && band == 1){
		if(Q->sig!=NULL){
			T=Q;
			Q=Q->sig;
		}
		else
			band = 0;
	}
	if(band==0){
		printf("El nodo con informacion %d no se encuentra en la lista.\n",x);
	}
	else{
		if(*Lista == Q)
			*Lista=Q->sig;
		else
			T->sig=Q->sig;
                free(Q);
	}
	
}
