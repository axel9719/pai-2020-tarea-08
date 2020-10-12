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
		printf("Inserte los valores mayores que 0 (Capacidad 40)\n");
		printf("-1 para imprimir \n");
		printf("0 para salir \n");
        
		scanf("%d", &par);
		
		if(par>0){
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

