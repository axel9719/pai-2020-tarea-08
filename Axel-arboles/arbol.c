#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
	int dato;
	struct _nodo *derecho;
	struct _nodo *izquierdo;
} tipoNodo;
 


tipoNodo *insertar2(int dat, tipoNodo *);

void inorden(tipoNodo *, void (*func)(int*));
void preorden(tipoNodo *, void (*func)(int*));
void postorden(tipoNodo *, void (*func)(int*));

void Imprimir(int *);


int main() {
	int valor,adios=2,contador=0;
	tipoNodo *arbolito = NULL, *hojita = NULL;
	printf("Programa Arbol sin repeticiondes de Axel\n");
	while(adios!=0){
		printf("0 Salir\n");
		printf("1 insertar numero\n");
		printf("2 imprimir inorden\n");
		printf("3 imprimir preorden\n");
		printf("4 imprimir postorden\n");
		printf("\n");
		scanf("%d", &adios);
		printf("\n");
		if(adios==1){
			printf("Valor a insertar\n");
			scanf("%d", &valor);
			printf("\n");
			arbolito = insertar2(valor, arbolito);
			contador=contador+1;
		}
		if(adios==2){
			if(contador==0){
				printf("Arbol vacio");
				printf("\n");
				printf("\n");
			}
			else{
				printf("inorden: ");
				inorden(arbolito, Imprimir);
				printf("\n");
				printf("\n");
			}
		}
		if(adios==3){
			if(contador==0){
				printf("Arbol vacio");
				printf("\n");
				printf("\n");
			}
			else{
				printf("preorden: ");
				preorden(arbolito, Imprimir);
				printf("\n");
				printf("\n");
			}
		}
		if(adios==4){
			if(contador==0){
				printf("Arbol vacio");
				printf("\n");
				printf("\n");
			}
			else{
				printf("postorden: ");
				postorden(arbolito, Imprimir);
				printf("\n");
				printf("\n");
			}
		}
		if (adios!=0 && adios!=1 && adios!=2 && adios!=3 && adios!=4 ){
			printf("8888888    8888b.      8888b.       .d88888b.    8888b.\n");         
			printf("888        8888888     8888888     d88P' 'Y88b   8888888\n");                   
			printf("888        888   88    888   88    888     888   88    88\n");                       
			printf("888        888    88   888   88    888     888   88     88\n");       
			printf("888888     888   88    888  88     888     888   888   88\n");      
			printf("888        88Y88b      88Y88b      888     888   88Y88b\n");   
			printf("888        88  d88     88  d88     Y88b. .d88P   88  d88\n"); 
			printf("8888888    88    d88   88    d88    'Y88888P'    88    d88\n"); 
			printf("\n");
		}
		
	}	
}


tipoNodo *insertar2(int dat, tipoNodo *a) {
	if(a == NULL) {
		tipoNodo *hojita = malloc(sizeof(tipoNodo));
		hojita->dato = dat;
		hojita->izquierdo = hojita->derecho = NULL;
		return hojita;
	}
	else {
		if(dat <= a->dato){
			a->izquierdo = insertar2(dat, a->izquierdo);
		}
		else{
			a->derecho = insertar2(dat, a->derecho);
		}
	}
}

void inorden(tipoNodo *a, void (*func)(int*))
{
	if(a->izquierdo) inorden(a->izquierdo, func);
	func(&(a->dato));
	if(a->derecho) inorden(a->derecho, func);
}

void preorden(tipoNodo *a, void (*func)(int*))
{
	func(&a->dato);
	if(a->izquierdo) preorden(a->izquierdo, func);
	if(a->derecho) preorden(a->derecho, func);
}

void postorden(tipoNodo *a, void (*func)(int*))
{
	if(a->izquierdo) postorden(a->izquierdo, func);
	if(a->derecho) postorden(a->derecho, func);
	func(&a->dato);
}

void Imprimir(int *d)
{
	printf("%d, ", *d);
}



