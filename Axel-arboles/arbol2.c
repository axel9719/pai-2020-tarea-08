/*Respuesta al problema 7 Tarea 9
Claudia Acosta Díaz y Axel Baez
Se siguieron los pseudcódigos del Cormen Introduction to Algorithms 3rd edition*/
/*El árbol almacenará solamente llaves y valores enteros*/

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

//Estructura de nodo del arbol rojo-negro
typedef struct _nodo {
  int key; 
  int val;
  struct _nodo *derecho;
  struct _nodo *izquierdo;
  struct _nodo  *papa;
  int color;
} tipoNodo;

//Estructura de árbol rojo-negro
typedef struct RedBlackTree {
  tipoNodo *root; //Nodo raíz del árbol
  tipoNodo *NIL; //Nodo que está al final, abajo de cada hoja
  int tamano; //guarda el tamaño del arbol
}RBTree;
 
//Función pedida que inserta un nuevo nodo con cierto bvalor y llave en el árbol
void put(RBTree *t,int k,int v);

//Función pedida que devuelve un valor asociado a una llave o -1 si no existe tal llave
int get(RBTree *t, int key);

//Función pedida para saber si el árbol tiene elementos o está vacío
int vacio(RBTree *t);

//Función pedida para saber si una llave existe en el árbol , devuelve 0 si está, 1 si no está
int contains (RBTree * t , int key ) ; 

//Función pedida que nos dice la cantidad de nodos NO NIL del árbol
int size (RBTree * t) ;

//Función para imprimir el árbol. 
void preorder(RBTree *t,tipoNodo *r);

//Función auxiliar usadas para la inserción
void arreglar(RBTree *t, tipoNodo * hojita); //Arregla la estructura rojo-negro después de insertar

//Funciones auxiliares para la inserción y borrado
void Rotar_D(RBTree *t,tipoNodo * hojita); //Hace rotación a la derecha
void Rotar_I(RBTree *t,tipoNodo * hojita); //Hace rotación a la izquierda

//Funciones para hacer delete
void transplant(RBTree *t, tipoNodo* hojita,tipoNodo *otro); //Función para transplantar 
void delete(RBTree *t, int key); //Función pedida para hacer delete
tipoNodo *treeMinimum(RBTree *t,tipoNodo *z); //Función que encuentra el mínimo a partir de un nodo
void deleteFixUp(RBTree *t,tipoNodo *x); //Función que arregla la estructura rojo-negro después de borrar un nodo

//Función auxiliar para liberar la memoria alocada
void freeArbol(RBTree *t,tipoNodo *r);


//Programa principal
int main() {

  //Lo primero que se hace es crear un árbol
    RBTree *t = malloc(sizeof(RBTree));
    tipoNodo *nodoNIL = malloc(sizeof(tipoNodo));
    nodoNIL->izquierdo = NULL;
    nodoNIL->izquierdo = NULL;
    nodoNIL->papa = NULL;
    nodoNIL->color = BLACK;
    nodoNIL->val = 0;
    nodoNIL->key = 0;
    t->NIL = nodoNIL;
    t->root = t->NIL;
    t->tamano=0;

  int valor,llave,adios=2,contador=0; //Auxiliares
  
  printf("Programa Arbol Rojo-Negro\n");
  while(adios!=0){
    printf("0 Salir\n");
    printf("1 insertar numero\n");
    printf("2 get()\n");
    printf("3 Vacio()\n");
    printf("4 Preorden\n");
    printf("5 delete\n");
    printf("6 size\n");
    printf("\n");
    scanf("%d", &adios);
    printf("----------------\n");
    if(adios==1){
      printf("Valor a insertar: ");
      scanf("%d", &valor);
      printf("key asociado: ");
      scanf("%d", &llave);
      printf("----------------\n");
      put(t,llave,valor);
      contador=contador+1;
    }
    if(adios==2){
      printf("key asociado: ");
      scanf("%d", &llave);
      valor=get(t,llave);
      printf("Valor: %d, llave: %d\n",valor,llave);
      printf("----------------\n");
    }
    if(adios==3){
      valor=vacio(t);
      printf("Valor: %d\n",valor);      

      printf("----------------\n");     
    }
    if(adios==4){
      preorder(t,t->root);
      printf("\n");
      printf("----------------\n");         
    }
     if(adios==5){
          printf("key asociado: ");
          scanf("%d", &llave);
      delete(t,llave);
      printf("\n");
      printf("----------------\n");
      contador=contador-1;         
    }
     if(adios==6){
          
      printf("\n El tamaño del arbol (sin contar los NIL) es %d",size(t));
      printf("\n----------------\n");         
    }

    if (adios!=0 && adios!=1 && adios!=2 && adios!=3 && adios!=4 && adios!=5 && adios!=6){
      printf("8888888    8888b.      8888b.       .d88888b.    8888b.\n");         
      printf("888        8888888     8888888     d88P' 'Y88b   8888888\n");                   
      printf("888        888   88    888   88    888     888   88    88\n");                       
      printf("888        888    88   888   88    888     888   88     88\n");       
      printf("888888     888   88    888  88     888     888   888   88\n");      
      printf("888        88Y88b      88Y88b      888     888   88Y88b\n");   
      printf("888        88  d88     88  d88     Y88b. .d88P   88  d88\n"); 
      printf("8888888    88    d88   88    d88    'Y88888P'    88    d88\n"); 
      printf("\n Introduzca un nuevo número entre 0 y 6");
    }
    
  } 
  ;
  freeArbol(t,t->root);
  free(t->NIL);
  free(t);
}

//Función que busca un elemento. Devuelve -1 si no está, o el valor asociado si el key se encontró
int get(RBTree *t, int key) {
  tipoNodo *x = t->root;
  while (x != t->NIL) {
    if (key == x->key){ 
      return x->val;
    }
    else if (key<x->key){
      x = x->izquierdo;
    }
    else{
      x = x->derecho;
    }
  }
  return -1;
}

//Función para saber si el árbol está vacío
int vacio(RBTree *t){
  return t->root==t->NIL;
}

//Imprimir el árbol
void preorder(RBTree *t,tipoNodo *r){
  if(r==t->NIL)
    return;

  printf("%d ",r->key);
  preorder(t,r->izquierdo);
  preorder(t,r->derecho);
}

//Para rotar a la izquierda
void Rotar_I(RBTree *t, tipoNodo *hojita){
  tipoNodo * hojita2 = hojita->derecho;
  hojita->derecho = hojita2->izquierdo;

  if(hojita2->izquierdo!=t->NIL){
    hojita2->izquierdo->papa = hojita;
  }

  hojita2->papa = hojita->papa;

  if(hojita->papa == t->NIL){
    t->root = hojita2;
  }
  
  else if(hojita == hojita->papa->izquierdo){
    hojita->papa->izquierdo = hojita2;
  }

  else{
    hojita->papa->derecho = hojita2;
  }

  hojita2->izquierdo = hojita;

  hojita->papa = hojita2;

}

//Para rotar a la derecha
void Rotar_D(RBTree *t,tipoNodo *hojita){
  tipoNodo *hojita2 = hojita->izquierdo;
  hojita->izquierdo = hojita2->derecho;

  if(hojita2->derecho!=t->NIL){
    hojita2->derecho->papa = hojita;
  }

  hojita2->papa = hojita->papa;

  if(hojita->papa==t->NIL){
    t->root = hojita2;
  }

  else if(hojita== hojita->papa->izquierdo){
    hojita->papa->izquierdo = hojita2;
  }
  else{
    hojita->papa->derecho = hojita2;
  }
  hojita2->derecho = hojita;
  hojita->papa = hojita2;

}

//Para arreglar el rojo-negro después de inserción
void arreglar(RBTree *t, tipoNodo *hojita)
{
  while(hojita->papa->color == RED) {
    if(hojita->papa == hojita->papa->papa->izquierdo) 
    {
      tipoNodo *y = hojita->papa->papa->derecho; 

      if(hojita->color == RED) { 
        hojita->papa->color = BLACK;
        y->color = BLACK;
        hojita->papa->papa->color = RED;
        hojita = hojita->papa->papa;
      }
      else { 
        if(hojita == hojita->papa->derecho) { 
          hojita = hojita->papa; 
          Rotar_I(t, hojita);
        }
      
        hojita->papa->color = BLACK; 
        hojita->papa->papa->color = RED; 
        Rotar_D(t, hojita->papa->papa);
      }
    }
    else { 
      tipoNodo *y = hojita->papa->papa->izquierdo; 

      if(y->color == RED) {
        hojita->papa->color = BLACK;
        y->color = BLACK;
        hojita->papa->papa->color = RED;
        hojita = hojita->papa->papa;
      }
      else {
        if(hojita == hojita->papa->izquierdo) {
          hojita = hojita->papa; 
          Rotar_D(t, hojita);
        }
        hojita->papa->color = BLACK; 
        hojita->papa->papa->color = RED; 
        Rotar_I(t, hojita->papa->papa);
      }
    }
  }
  t->root->color = BLACK;
}

//Para insertar una llave y valor en un nuevo nodo
void put(RBTree *t,int k,int v){
  
  //Chequear primero si el nodo no está y se agrega
  if (get(t,k) == -1)
  {
     tipoNodo* hojita = (tipoNodo*)malloc(sizeof(tipoNodo ));
     hojita->key = k;
     hojita->val = v;
     hojita->izquierdo = NULL;
     hojita->derecho = NULL;
     hojita->papa = NULL;
     hojita->color = RED;

     tipoNodo* a = t->NIL;
     tipoNodo* b = t->root;
    while(b!=t->NIL){
    a = b;
    if(hojita->key < b->key)
      b = b->izquierdo;

    else
      b = b->derecho;
    }
    hojita->papa = a;
 
    if(a==t->NIL){
    t->root = hojita;
    }
    else if(hojita->key < a->key){
    a->izquierdo = hojita;
    }
    else{
      a->derecho = hojita;
    }

    hojita->derecho=t->NIL;
    hojita->izquierdo=t->NIL;
    arreglar(t,hojita);
    t->tamano++;
  }
  //Si el key ya existe, entonces se sobreescribe val
  else
  {
    tipoNodo *aux = t->root;
     
   //subrutina para encontrar el nodo que contiene Key y cambiar su VAL
    //Se hace esto porque en clase se dijo que en estos árboles si un key ya existía
    //Y se ponía otra vez, entonces se aplastaba el valor asociado y se ponía el nuevo
  while (aux != t->NIL) {
    if (k == aux->key){ 
      aux->val=v;
      break;
    }
    else if (k<aux->key){
      aux = aux->izquierdo;
    }
    else{
      aux = aux->derecho;
    }
  }

  }

  

}

//Transplantar
void transplant(RBTree *t, tipoNodo* u, tipoNodo *v)
{
  if(u->papa == t->NIL)
  {
        t->root = v;    
  }
    else if(u == u->papa->izquierdo)
    {
      u->papa->izquierdo = v;
    }
    else
    {
      u->papa->derecho = v;
    }
    
    v->papa = u->papa;
}

//Encontrar mínimo después de un nodo
tipoNodo *treeMinimum(RBTree *t, tipoNodo *z)
{
  while (z->izquierdo != t->NIL)
  {
    z=z->izquierdo;
  }
  return z;
}

//Arreglar rojo-negro después de delete
void deleteFixUp(RBTree *t, tipoNodo *x)
{

  while(x != t->root && x->color == BLACK) {
    if(x == x->papa->izquierdo) {
      tipoNodo *w = x->papa->derecho;
      if(w->color == RED) {
        w->color = BLACK;
        x->papa->color = RED;
        Rotar_I(t, (x->papa));
        w = x->papa->derecho;
      }
      if(w->izquierdo->color == BLACK && w->derecho->color == BLACK) {
        w->color = RED;
        x = x->papa;
      }
      else {
        if(w->derecho->color == BLACK) {
          w->izquierdo->color = BLACK;
          w->color = RED;
          Rotar_D(t, w);
          w = x->papa->derecho;
        }
        w->color = x->papa->color;
        x->papa->color = BLACK;
        w->derecho->color = BLACK;
        Rotar_I(t, (x->papa));
        x = t->root;
      }
    }
    else {
      tipoNodo *w = x->papa->izquierdo;
      if(w->color == RED) {
        w->color = BLACK;
        x->papa->color = RED;
        Rotar_D(t, (x->papa));
        w = x->papa->izquierdo;
      }
      if(w->derecho->color == BLACK && w->izquierdo->color == BLACK) {
        w->color = RED;
        x = x->papa;
      }
      else {
        if(w->izquierdo->color == BLACK) {
          w->derecho->color = BLACK;
          w->color = RED;
          Rotar_I(t, w);
          w = x->papa->izquierdo;
        }
        w->color = x->papa->color;
        x->papa->color = BLACK;
        w->izquierdo->color = BLACK;
        Rotar_D(t, (x->papa));
        x = t->root;
      }
    }
  }
  x->color = BLACK;
}

//Borrar un nodo 
void delete(RBTree *t, int key) {
    
    tipoNodo *aux = t->root;
    tipoNodo *z=t->NIL;
  
  //subrutina para encontrar el nodo que contiene Key
  while (aux != t->NIL) {
    if (key == aux->key){ 
      z=aux;
      break;
    }
    else if (key<aux->key){
      aux = aux->izquierdo;
    }
    else{
      aux = aux->derecho;
    }
  }

  //Si el nodo no está, acabo la función
  if (z==t->NIL)
    {
      printf("El nodo no se encuentra en el arbol\n");
      return;
    }

  tipoNodo *y = z;
  tipoNodo *x;
  int y_orignal_color = y->color;
  if(z->izquierdo == t->NIL) {
    x = z->derecho;
    transplant(t, z, z->derecho);
  }
  else if(z->derecho == t->NIL) {
    x = z->izquierdo;
    transplant(t, z, z->izquierdo);
  }
  else {
    y = treeMinimum(t,z->derecho);
    y_orignal_color = y->color;
    x = y->derecho;
    if(y->papa == z) {
      x->papa = z;
    }
    else {
      transplant(t, y, y->derecho);
      y->derecho = z->derecho;
      y->derecho->papa = y;
    }
    transplant(t, z, y);
    y->izquierdo = z->izquierdo;
    y->izquierdo->papa = y;
    y->color = z->color;
  }
  if(y_orignal_color == BLACK)
    deleteFixUp(t, x);
  t->tamano--;
  free(z); //Libero el nodo que se borró
}

//Contiene un key??
int contains (RBTree * t , int key )
{
  tipoNodo *x = t->root;
  while (x != t->NIL) {
    if (key == x->key){ 
      return 0;
    }
    else if (key<x->key){
      x = x->izquierdo;
    }
    else{
      x = x->derecho;
    }
  }
  return 1;
}

//Número de nodos distintos de NIL
int size (RBTree * t)
{
  return t->tamano;
}

//Liberar la memoria que se alocó para el árbol
void freeArbol(RBTree *t,tipoNodo *root)
{
    
    if (root==t->NIL)
      return;

    freeArbol(t,root->izquierdo);
    freeArbol(t,root->derecho);
   
    free(root);

    return;
}