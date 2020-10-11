#ifndef HEAP_T08
#define HEAP_T08

#include <stdio.h>
#include <stdlib.h>


typedef struct HeapStruct{
	unsigned int capacity;
	unsigned int n;
	int *data;
	char type; //Esta variable almacenará M si es max_heap o m si es min_heap
} Heap;

// La variable tipo tendrá M si es max_heap o m si es min_heap
Heap * Heap_new(int capacity,char tipo); 
void free_THeap(Heap ** hptr);


void Insertar(Heap *h, int data);
void swap(int *arr, int i, int j);
int removeMax(Heap *h);
void topDownHeapify(int *arr, int k,int n,char tipo );
void bottomUpHeapify(int *arr, int k, char tipo);
int getMax(Heap *h);

//Peor caso,nuevo dato es mayor que su papa, mayor a todos los datos del arbol ,numero de spaws igual a la altura del arbol O(log_3 n)
//Mejor caso, nuevo dato menor que su papa, ningun swap, complejidad constante O(1)
//Arbol vacio, complejidad constante O(1)
void Insertar(Heap *h, int data) {
	//Si se sobrepasa la capacidad establecida, no hacer nada
	if(h->n==h->capacity-1){
		return;
	}
	//Si no, agregar elemento
	h->data[++(h->n)]=data;
	//Arreglar arbol, cumpla propiedades
	bottomUpHeapify(h->data, h->n,h->type);
}

//Complejidad constante O(1)
void swap(int *arr, int i, int j){
	//Cambiar de posicion los elementos del arreglo
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

//Arbol vacio, complejidad constante O(1).
//Mejor caso 1 topDownHeapify
//Peor caso Intercambio hasta el nodo hoja mas bajo del arbol, O(log_3 n)
int removeMax(Heap *h){
	if(h->n==-1){
		return -1;
	}
	//Por propiedades arbol, elemento maximo en primera entrada	
	int tmp=h->data[0];
	//Nueva raiz 
	h->data[0]=h->data[h->n--];
	//Arreglar el arbol, para que cumpla las propiedades, padre mayor a hijos.
	topDownHeapify(h->data,0,h->n, h->type);
	return tmp;


}

//Complejidad constante O(1), solo verificas la raiz no importa altura del arbol o raiz de este.
int getMax(Heap *h){
	if(h->n==-1){
		return -1;
	}
	//Por propiedades arbol, elemento maximo en primera entrada
	int tmp=h->data[0];
	return tmp;
}

//Se saca la raiz, el arbol queda vacio, arbol de 1 nodo
//Tiene que corregir hasta ultimo nodo del arbol, peor caso, O(log_3 n)
void topDownHeapify(int *arr, int k,int n, char tipo) {
	if(tipo=='M')
	{
		while((3*k)+1<=n){
		int j=(3*k)+1;
		//Revisar si segundo hijo mayor primero
		if(j<n && arr[j]<arr[j+1]){
			j++;
			//Revisar si tercer hijo mayor segundo
			if(j<n && arr[j]<arr[j+1]){
				j++;
			}

		}
		//Si segundo hijo menor que el primero
		else{
			//Revisar si tercer hijo mayor primero
			if(j+1<n && arr[j]<arr[j+2]){
				j=j+2;
			}
		}
		//Si padre mayor que hijo, break
		if(arr[k]>=arr[j]){
			break;
		}
		//Si hijo mayor que padre, cambiarlos de lugar
		swap(arr,k,j);
		k=j;
	    }
    }
	else if(tipo=='m') 
	{
		while((3*k)+1<=n){
		int j=(3*k)+1;
		//Revisar si segundo hijo menor primero
		if(j<n && arr[j]>arr[j+1]){
			j++;
			//Revisar si tercer hijo menor segundo
			if(j<n && arr[j]>arr[j+1]){
				j++;
			}

		}
		//Si segundo hijo mayor que el primero
		else{
			//Revisar si tercer hijo menor primero
			if(j+1<n && arr[j]>arr[j+2]){
				j=j+2;
			}
		}
		//Si padre menor que hijo, break
		if(arr[k]<=arr[j]){
			break;
		}
		//Si hijo menor que padre, cambiarlos de lugar
		swap(arr,k,j);
		k=j;

	}
	}

	
}

//Peor caso Recorrido desde el noda hasta la raiz O(log_3 n)
//Mejor caso el hijo satisface propiedades de arbol, menor que el padre ,O(1)
void bottomUpHeapify(int *arr, int k,char tipo){
	if(tipo=='M')
	{
		while(k>=1 && arr[(k-1)/3]<arr[k]){
		swap(arr,k,(k-1)/3);
		k=(k-1)/3;
	    }
	}
	else if(tipo == 'm')
	{
		while(k>=1 && arr[(k-1)/3]>arr[k]){
		swap(arr,k,(k-1)/3);
		k=(k-1)/3;
	    }
	}
	
}

//Crear arbol
Heap * Heap_new(int capacity, char tipo){
	//Pedir memoria
	Heap *UNO = (Heap *) malloc (sizeof(Heap));
	//Verificar si fue otorgada
	if (UNO == NULL) {
		printf("Error memoria\n");
		exit(-1);
	}
	//Asignar el tipo
	UNO->type=tipo;
	//Asignar capacidad
	UNO->capacity = capacity;
	//Asignar indice actual, empieza en n=-1, para que al agregar primer elemento, n=0
  	UNO->n = -1;
	//Memoria para arreglo
  	UNO->data = (int *) calloc (capacity, sizeof(int));
	//Verificar fue otorgada
  	if (UNO->data == NULL) {
    		printf("Error memoria\n");
    		exit(-1);
    	}
	//Regresar arbol
	return UNO;
}

//Liberar memoria de arbol
void free_THeap(Heap ** hptr){
	free((*hptr)->data);
  	free(*hptr);
  	hptr = NULL;
}

//Función que imprime el heap
void print_Heap(Heap * h)
{
	
    if(h->n==-1)
	{
		printf("El montículo está vacío\n");
	}
	else
	{
		printf("\n");
		for (int i=0;i<=h->n;i++){
		    printf("%d ",h->data[i]);
		    printf("\n");
	    }
	

	}
	
}

#endif