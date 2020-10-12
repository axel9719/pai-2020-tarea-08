#ifndef MEDIAN_T8
#define MEDIAN_T8

//En esta función, heap_max tiene la mitad inferior de los datos y min_heap la parte superior de los datos
#include "./heap.c"
// Prototipo ==================================================================

double theap_median(Heap * min_heap, Heap * max_heap, int data, double *m);

// Definiciones ===============================================================
//Agregué la mediana en double *m

double theap_median(Heap * min_heap, Heap * max_heap, int data, double *m){


if(max_heap->n==min_heap->n){

	if(max_heap->n==-1)
	{
         Insertar(max_heap,data);
         int aux = getMax(max_heap);
         m[0]=(double) aux;
	}
	else if( data < m[0] ) // El elemento debe ir en max_heap
        {
           Insertar(max_heap,data);
           int aux = getMax(max_heap);
           m[0]=(double) aux;
        }
        else
        {
            // El elemento debe ir en min_heap
           Insertar(min_heap,data);
           int aux = getMax(min_heap);
           m[0]=(double) aux;
        }
}
else if (max_heap->n-min_heap->n==1)
{
	        if( data < m[0] ) // El elemento se debe poner en max_heap
        {
            // Quitar el elemento top de max_heap y ponerlo en min_heap
            int aux=removeMax(max_heap);
            Insertar(min_heap,aux);

            // Meter el dato nuevo en max_heap
             Insertar(max_heap,data);
        }
        else
        {
            // El elemento debe ir en min_heap
             Insertar(min_heap,data);
        }

        // Los dos árboles quedaron con la misma cantidad de elementos,
        // por tantola mediana es el promedio de las dos raíces
        m[0] = (getMax(max_heap)+getMax(min_heap))/2.0;

}

else if (max_heap->n-min_heap->n==-1)
{

        if( data < m[0] ) // El elemento va en max_heap
        {
                  Insertar(max_heap,data);
        }
        else
        {
            // Quitar el elemneto raíz de min_heap y pasarlo a max_heap
            int aux=removeMax(min_heap);
            Insertar(max_heap,aux);
            // Poner el elemento nuevo en min_heap
              Insertar(min_heap,data);
        }

         // Los dos árboles quedaron con la misma cantidad de elementos,
        // por tantola mediana es el promedio de las dos raíces
        m[0] = (getMax(max_heap)+getMax(min_heap))/2.0;

}



  printf("El nuevo valor de la mediana es %.2f \n", m[0]);
  return m[0];

}

void print_list(Heap * min_heap, Heap * max_heap)
{
	printf("El montículo max es \n");
	print_Heap(max_heap);
	printf("El montículo min es \n");
	print_Heap(min_heap);
}
#endif 
