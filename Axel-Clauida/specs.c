#include "./heap.c"
#include "./median.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_insert_element(void){ 
	printf("Al probar un elemento se debe mantener la propiedad del heap: \n"); 
  // Create heap 
	Heap *UNO;
	UNO=Heap_new(10,'M');
  // add 0
  // if(getMax(th) != 0){puts("ERROR"); return 0;}
	printf("Insertamos 0\n"); 
	Insertar(UNO,0); 	
	if(getMax(UNO) != 0){puts("ERROR"); return 0;}
  // add 1
  // if(getMax(th) != 1){puts("ERROR"); return 0;}
	printf("Insertamos 1\n"); 
	Insertar(UNO,1); 	
	if(getMax(UNO) != 1){puts("ERROR"); return 0;}
  // add 5
  // if(getMax(th) != 5){puts("ERROR"); return 0;}
	printf("Insertamos 5\n"); 
	Insertar(UNO,5); 	
	if(getMax(UNO) != 5){puts("ERROR"); return 0;}
  // add 3
  // if(getMax(th) != 5){puts("ERROR"); return 0;}
	printf("Insertamos 3\n"); 
	Insertar(UNO,3); 	
	if(getMax(UNO) != 5){puts("ERROR"); return 0;}


	free_THeap(&UNO);
	puts("OK\n"); 
	return 1;
} 

int test_median(void){ 
	printf("Al probar un elemento se debe mantener la Mediana: \n"); 
  	Heap *max_heap=Heap_new(20,'M');
	Heap *min_heap=Heap_new(20,'m');
	double *m=calloc(1,sizeof(double));
	double mediana;
	printf("Insertamos 2\n"); 
 	mediana=theap_median( min_heap, max_heap, 2 , m);
	if(mediana != 2){puts("ERROR"); return 0;}

	printf("Insertamos 3\n"); 
 	mediana=theap_median( min_heap, max_heap, 3 , m);
	if(mediana != 2.5){puts("ERROR"); return 0;}

	printf("Insertamos 7\n"); 
	mediana=theap_median( min_heap, max_heap, 7 , m);
	if(mediana != 3){puts("ERROR"); return 0;}

	printf("Insertamos 4\n"); 
	mediana=theap_median( min_heap, max_heap, 4 , m);
	if(mediana != 3.5){puts("ERROR"); return 0;}

	printf("Insertamos 15\n"); 
	mediana=theap_median( min_heap, max_heap, 15 , m);
	if(mediana != 4){puts("ERROR"); return 0;}

	free_THeap(&max_heap);
	free_THeap(&min_heap);
	puts("OK mediana\n"); 
	return 1;
} 

int main(int num_args, char ** args){
  int all_tests_ok = 1;
  all_tests_ok &= test_insert_element();
  assert(all_tests_ok);
  all_tests_ok &=test_median();  
  assert(all_tests_ok);
  return 0;
} 
