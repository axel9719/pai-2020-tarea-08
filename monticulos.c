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


int main() {
	int par=100,valor,contador=0, valsal;

	Heap *UNO;
	UNO=Heap_new(20);
	
	while(par!=0){
		printf("--------------------------------------------------------------------------\n");	 			
		printf("Inserte un numero\n");	 			
		printf("1 para insert \n");
		printf("2 para removeMax\n");
		printf("3 para getMax\n");
		printf("0 para salir \n");
		scanf("%d", &par);
		if(par==1){
			printf("Inserta el valor a añadir al arbol\n");
			scanf("%d", &valor);
 			Insertar(UNO,valor); 
			contador=contador+1;
		}
		if(par==2){
			if(contador==0){
				printf("Arbol vacio\n");	
			}
			else{
				valsal=removeMax(UNO);
				printf("Salio: %d\n",valsal);	
				contador=contador-1;
			}
		}
		if(par==3){
			if(contador==0){
				printf("Arbol vacio\n");
			}
			else{
 				valsal=getMax(UNO);
				printf("Salio: %d\n",valsal);	
			}
		}

		if(par<0 || par>3){
			printf("Debe de ser 0,1,2,3\n");	
		}
		
	}
	return 0;
}

void Insertar(Heap *h, int data) {
	if(h->n==h->capacity-1){
		return;
	}
	h->data[++h->n]=data;
	bottomUpHeapify(h->data, h->n);
}

void swap(int *arr, int i, int j){
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

int removeMax(Heap *h){
	if(h->n<0){
		return -1;
	}
	int tmp=h->data[0];
	h->data[0]=h->data[h->n--];
	topDownHeapify(h->data,0,h->n);
	return tmp;


}

int getMax(Heap *h){
	if(h->n<0){
		return -1;
	}
	int tmp=h->data[0];
	return tmp;
}

void topDownHeapify(int *arr, int k,int n) {
	while((3*k)+1<=n){
		int j=(3*k)+1;
		if(j<n && arr[j]<arr[j+1]){
			j++;
		}
		if(j<n && arr[j]<arr[j+1]){
			j++;
		}
		if(arr[k]>=arr[j]){
			break;
		}
		swap(arr,k,j);
		k=j;
	}
}

void bottomUpHeapify(int *arr, int k){
	if(k%3==0){
		while(k>=1 && arr[(k/3)-1]<arr[k]){
			swap(arr,k,(k/3)-1);
			k=(k/3)-1;
		}
	}
	else{
		while(k>=1 && arr[(k/3)]<arr[k]){
			swap(arr,k,(k/3));
			k=k/3;
		}	
	}
}

Heap * Heap_new(int capacity);
	Heap *UNO = (Heap *) calloc (1,sizeof(Heap));
	if (UNO == NULL) {
		printf("Error memoria\n");
		exit(-1);
	}

	UNO->capacity = capacity;
  	UNO->n = 0;
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
