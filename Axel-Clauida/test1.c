#include <stdio.h>
#include <stdlib.h>
#include "./heap.c"
#include "./median.c"


int main() {
	int par=100,valor, valsal;

	Heap *UNO;
	UNO=Heap_new(20,'M');
	
	while(par!=0){
		printf("--------------------------------------------------------------------------\n");	 			
		printf("Inserte un numero\n");	 			
		printf("1 para insert \n");
		printf("2 para removeMax\n");
		printf("3 para getMax\n");
		printf("4 para saber cuantos datos tiene el montículo \n");
		printf("5 para imprimir el montículo\n");
		printf("0 para salir \n");
		scanf("%d", &par);
		if(par==1){
			printf("Inserta el valor a añadir al arbol: ");
			scanf("%d", &valor);
 			Insertar(UNO,valor); 
		}
		if(par==2){
			valsal=removeMax(UNO);
			printf("Salio: %d\n",valsal);	
		}
		if(par==3){
 			valsal=getMax(UNO);
			printf("Máximo es: %d\n",valsal);	
		}

		if(par==4){
 			valsal=UNO->n+1;
			printf("El montículo tiene: %d datos\n",valsal);	
		}

		if(par==5){
 			print_Heap(UNO);
		}


		if(par<0 || par>5){
			printf("Debe de ser 0,1,2,3,4,5\n");	
		}
	}
   	free_THeap(&UNO);
	return 0;
}


