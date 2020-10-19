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

typedef struct RedBlackTree {
  tipoNodo *root; //Nodo raíz del árbol
  tipoNodo *NIL; //Nodo que está al final, abajo de cada hoja
  int tamano; //guarda el tamaño del arbol
}RBTree;
 

void put(RBTree *t,int k,int v);
int get(RBTree *t, int key);
int vacio(tipoNodo *root);

int contains (RBTree * t , int key ) ; //Is there a data paired with key? //devuelve 0 si está, 1 si no está
int size (RBTree * t) ;

void preorder(tipoNodo *root);


void arreglar(RBTree *t, tipoNodo * hojita);
void Rotar_D(RBTree *t,tipoNodo * hojita);
void Rotar_I(RBTree *t,tipoNodo * hojita);

//Funciones para hacer delete
void transplant(RBTree *t, tipoNodo* hojita,tipoNodo *otro);
void delete(RBTree *t, int key);
tipoNodo *treeMinimum(RBTree *t,tipoNodo *z);
void deleteFixUp(RBTree *t,tipoNodo *x);

int main() {
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

  int valor,llave,adios=2,contador=0;
  //tipoNodo *arbolito = NULL; //*hojita = NULL;
  printf("Programa Arbol sin repeticiondes de Axel\n");
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
      valor=vacio(t->root);
      printf("Valor: %d\n",valor);      

      printf("----------------\n");     
    }
    if(adios==4){
      preorder(t->root);
      printf("\n");
      printf("----------------\n");         
    }
     if(adios==5){
          printf("key asociado: ");
          scanf("%d", &llave);
      delete(t,llave);
      printf("\n");
      printf("----------------\n");         
    }
     if(adios==6){
          
      printf("\n El tamaño del arbol (sin contar los NIL) es %d",size(t));
      printf("----------------\n");         
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
      printf("\n");
    }
    
  } 
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
int vacio(tipoNodo *root){
  return root==NULL;
}

void preorder(tipoNodo *root){
  if(root==NULL)
    return;

  printf("%d ",root->key);
  preorder(root->izquierdo);
  preorder(root->derecho);
}

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
        hojita->papa->papa->color = RED; //made parent red
        Rotar_I(t, hojita->papa->papa);
      }
    }
  }
  t->root->color = BLACK;
}


void put(RBTree *t,int k,int v){

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


tipoNodo *treeMinimum(RBTree *t, tipoNodo *z)
{
  while (z->izquierdo != t->NIL)
  {
    z=z->izquierdo;
  }
  return z;
}

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

void delete(RBTree *t, int key) {
    
    tipoNodo *aux = t->root;
    tipoNodo *z=t->NIL;
  
  //Función para encontrar el nodo que contiene Key
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
}

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

int size (RBTree * t)
{
  return t->tamano;
}