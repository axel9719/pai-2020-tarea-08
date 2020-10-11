#include "./heap.c"
#include "./median.c"
//Aquí probaremos la función para calcular la mediana 
int main()
{
	    int par=100;
	Heap *max_heap=Heap_new(20,'M');
	Heap *min_heap=Heap_new(20,'m');
	double *m=calloc(1,sizeof(double));
	

   while(par!=0){
		printf("--------------------------------------------------------------------------\n");
		printf("Inserte los valores mayores que 0 (maximo 40)\n");
		printf("-1 para imprimir \n");
		printf("0 para salir \n");
        
		scanf("%d", &par);
		
		if(par>0){
			//scanf("%d", &valor);
 			theap_median( min_heap, max_heap, par, m);
		}
		else if(par==-1)
		{
			print_list( min_heap, max_heap);
		}
		
	}

   free_THeap(&max_heap);
   free_THeap(&min_heap);
   free(m);
	return 0;
}

/*
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
		printf("4 para ver cuantos datos tiene el montículo \n");
		printf("5 para imprimir el montículo\n");
		printf("0 para salir \n");
		
		scanf("%d", &par);
		if(par==1){
			printf("Inserta el valor a añadir al arbol\n");
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
			printf("El montículo tiene: %d\n datos",valsal);	
		}

		if(par==5){
 			print_Heap(UNO);
		}


		if(par<0 || par>5){
			printf("Debe de ser 0,1,2,3,4,5\n");	
		}
		
	}
	return 0;
}
*/
