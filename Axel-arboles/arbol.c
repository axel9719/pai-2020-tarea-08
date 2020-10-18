#define RED 1
#define BLACK 0

typedef struct _nodo {
	int key;
	int val;
	struct _nodo *derecho;
	struct _nodo *izquierdo;
	struct _nodo  *papa;
	int color;
} tipoNodo;
 

tipoNodo* put(tipoNodo* T,int k,int v);
int get(tipoNodo *root, int key);
int vacio(tipoNodo *root);
int size(tipoNodo *root,int contador);

void preorder(tipoNodo *root);


void arreglar(tipoNodo** root, tipoNodo** hojita);
void Rotar_D(tipoNodo** root,tipoNodo** hojita);
void Rotar_I(tipoNodo** root,tipoNodo** hojita);

int main() {
	int valor,llave,adios=2,contador=0;
	tipoNodo *arbolito = NULL, *hojita = NULL;
	printf("Programa Arbol sin repeticiondes de Axel\n");
	while(adios!=0){
		printf("0 Salir\n");
		printf("1 insertar numero\n");
		printf("2 get()\n");
		printf("3 Vacio()\n");
		printf("4 Preorden\n");
		printf("\n");
		scanf("%d", &adios);
		printf("----------------\n");
		if(adios==1){
			printf("Valor a insertar: ");
			scanf("%d", &valor);
			printf("key asociado: ");
			scanf("%d", &llave);
			printf("----------------\n");
			arbolito= put(arbolito,llave,valor);
			contador=contador+1;
		}
		if(adios==2){
			printf("key asociado: ");
			scanf("%d", &llave);
			valor=get(arbolito,llave);
			printf("Valor: %d, llave: %d\n",valor,llave);
			printf("----------------\n");
		}
		if(adios==3){
			valor=vacio(arbolito);
			printf("Valor: %d\n",valor);			

			printf("----------------\n");			
		}
		if(adios==4){
			preorder(arbolito);
			printf("\n");
			printf("----------------\n");					
		}
		if (adios!=0 && adios!=1 && adios!=2 && adios!=3 && adios!=4 ){
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

int get(tipoNodo *root, int key) {
	tipoNodo *x = root;
	while (x != NULL) {
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

void Rotar_I(tipoNodo** root,tipoNodo** hojita){
	tipoNodo* hojita2 = (*hojita)->derecho;
	(*hojita)->derecho = hojita2->izquierdo;

	if(hojita2->izquierdo!=NULL){
		hojita2->izquierdo->papa = *hojita;
	}

	hojita2->papa = (*hojita)->papa;

	if((*hojita)->papa == NULL){
		*root = hojita2;
	}
	
	else if(*hojita == (*hojita)->papa->izquierdo){
		(*hojita)->papa->izquierdo = hojita2;
	}

	else{
		(*hojita)->papa->derecho = hojita2;
	}

	hojita2->izquierdo = *hojita;

	(*hojita)->papa = hojita2;

}

void Rotar_D(tipoNodo** root,tipoNodo** hojita){
	tipoNodo* hojita2 = (*hojita)->izquierdo;
	(*hojita)->izquierdo = hojita2->derecho;

	if(hojita2->derecho!=NULL){
		hojita2->derecho->papa = *hojita;
	}

	hojita2->papa = (*hojita)->papa;

	if((*hojita)->papa==NULL){
		*root = hojita2;
	}

	else if((*hojita)== (*hojita)->papa->izquierdo){
		(*hojita)->papa->izquierdo = hojita2;
	}
	else{
		(*hojita)->papa->derecho = hojita2;
	}
	hojita2->derecho = *hojita;
	(*hojita)->papa = hojita2;

}

void arreglar(tipoNodo** root, tipoNodo** hojita){
	tipoNodo* Abue = NULL;
	tipoNodo* PPapa = NULL;

	while( ( (*hojita)!=*root ) && ( (*hojita)->color!= BLACK ) && ( (*hojita)->papa->color == RED ) ){
		PPapa = (*hojita)->papa;
		Abue = (*hojita)->papa->papa;

		if(PPapa == Abue->izquierdo){
			tipoNodo* Tio = Abue->derecho;

			if(Tio!=NULL && Tio->color == RED){
				Abue->color = RED;
				PPapa->color = BLACK;
				Tio->color = BLACK;
				*hojita = Abue;
			}

			else{
				if((*hojita) == PPapa->derecho){
					Rotar_I(root,&PPapa);
					(*hojita) = PPapa;
					PPapa = (*hojita)->papa;
				}

				Rotar_D(root,&Abue);
				PPapa->color = BLACK;
				Abue->color = RED;
				(*hojita) = PPapa;
			}
		}

		else{
			tipoNodo* Tio = Abue->izquierdo;

			if(Tio!=NULL && Tio->color == RED){
				Abue->color = RED;
				PPapa->color = BLACK;
				Tio->color = BLACK;
				(*hojita) = Abue;
			}

			else{
				if((*hojita) == PPapa->izquierdo){
					Rotar_D(root,&PPapa);
					(*hojita) = PPapa;
					PPapa = (*hojita)->papa;
				}

				Rotar_I(root,&Abue);
				PPapa->color = BLACK;
				Abue->color = RED;
				(*hojita) = PPapa;
			}
		}
	}
	(*root)->color = BLACK;

}

tipoNodo* put(tipoNodo* root,int k,int v){

	tipoNodo* hojita = (tipoNodo*)malloc(sizeof(tipoNodo ));
	hojita->key = k;
	hojita->val = v;
	hojita->izquierdo = NULL;
	hojita->derecho = NULL;
	hojita->papa = NULL;
	hojita->color = RED;

	tipoNodo* a = NULL;
	tipoNodo* b = root;

	while(b!=NULL){
		a = b;
		if(hojita->key < b->key)
			b = b->izquierdo;

		else
			b = b->derecho;
	}
	hojita->papa = a;

	if(a==NULL){
		root = hojita;
	}
	else if(hojita->key < a->key){
		a->izquierdo = hojita;
	}
	else{
		a->derecho = hojita;
	}
	arreglar(&root,&hojita);

	return root;
}




