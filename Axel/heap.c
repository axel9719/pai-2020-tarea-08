#indef HEAP_T08
#define HEAP_T08

#include <stdio.h>
#include <stdlib.h>


typedef struct HeapStruct{
	unsigned int capacity;
	unsigned int n;
	int *data;
} Heap;

Heap * Heap_new(int capacity);
void free_THeap(Heap ** hptr);


void Insertar(Heap *h, int data);
void swap(int *arr, int i, int j);
int removeMax(Heap *h);
void topDownHeapify(int *arr, int k,int n);
void bottomUpHeapify(int *arr, int k);
int getMax(Heap *h);

//Peor caso,nuevo dato es mayor que su papa, mayor a todos los datos del arbol ,numero de spaws igual a la altura del arbol O(log_3 n)
//Mejor caso, nuevo dato menor que su papa, ningun swap, complejidad constante O(1)
//Arbol vacio, complejidad constante O(1)
void Insertar(Heap *h, int data) {
	if(h->n==h->capacity-1){
		return;
	}
	h->data[++(h->n)]=data;
	bottomUpHeapify(h->data, h->n);
}

//Complejidad constante O(1)
void swap(int *arr, int i, int j){
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
	int tmp=h->data[0];
	h->data[0]=h->data[h->n--];
	topDownHeapify(h->data,0,h->n);
	return tmp;


}

//Complejidad constante O(1), solo verificas la raiz no importa altura del arbol o raiz de este.
int getMax(Heap *h){
	if(h->n==-1){
		return -1;
	}
	int tmp=h->data[0];
	return tmp;
}

//Se saca la raiz, el arbol queda vacio, arbol de 1 nodo
//Tiene que corregir hasta ultimo nodo del arbol, peor caso, O(log_3 n)
void topDownHeapify(int *arr, int k,int n) {
	while((3*k)+1<=n){
		int j=(3*k)+1;
		if(j<n && arr[j]<arr[j+1]){
			j++;
			if(j<n && arr[j]<arr[j+1]){
				j++;
			}

		}
		else{
			if(j+1<n && arr[j]<arr[j+2]){
				j=j+2;
			}
		}
		if(arr[k]>=arr[j]){
			break;
		}
		swap(arr,k,j);
		k=j;
	}
}

//Peor caso Recorrido desde el noda hasta la raiz O(log_3 n)
//Mejor caso el hijo satisface propiedades de arbol, menor que el padre ,O(1)
void bottomUpHeapify(int *arr, int k){
	while(k>=1 && arr[(k-1)/3]<arr[k]){
		swap(arr,k,(k-1)/3);
		k=(k-1)/3;
	}
}

Heap * Heap_new(int capacity){
	Heap *UNO = (Heap *) malloc (sizeof(Heap));
	if (UNO == NULL) {
		printf("Error memoria\n");
		exit(-1);
	}

	UNO->capacity = capacity;
  	UNO->n = -1;
  	UNO->data = (int *) calloc (capacity, sizeof(int));
  	if (UNO->data == NULL) {
    		printf("Error memoria\n");
    		exit(-1);
    	}

	return UNO;
}

void free_Heap(Heap ** hptr){
	free((*hptr)->data);
  	free(*hptr);
  	hptr = NULL;
}

#endif
