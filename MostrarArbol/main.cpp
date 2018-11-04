#include <iostream>

using namespace std;

typedef struct Distancia{
    int izquierda=0;
    int derecha=0;
    int ancho=0;
    int profundidad;
} Distancia;

class ArbolBinario {

private:

    typedef struct Nodo {
        char valor;
        Nodo *izquierda, *derecha;

        Nodo() {
            izquierda = derecha = NULL;
        }
    } Nodo;

    Nodo *raiz;
    Distancia distancia;
    void estructura(Nodo *nodo,char **matriz,int i,int j) {
        if(nodo != NULL) {
            estructura(nodo->izquierda,matriz, i+1,j-1);
            matriz[i][j] = nodo->valor;
            estructura(nodo->derecha,matriz,i+1,j+1);
        }
    }

    Nodo *insertar(Nodo *nodo, char valor) {
        if (nodo == NULL) {
            nodo = new Nodo;
            nodo->valor = valor;
        } else if(valor < nodo->valor) {
            nodo->izquierda = insertar(nodo->izquierda, valor);
        } else if(valor > nodo->valor) {
            nodo->derecha = insertar(nodo->derecha, valor);
        }
        return nodo;
    }

    Nodo *eliminarNodo(Nodo *nodo, char valor) {
        if(nodo == NULL)
            return NULL;
        else if(valor < nodo->valor)
            nodo->izquierda = eliminarNodo(nodo->izquierda, valor);
        else if(valor > nodo->valor)
            nodo->derecha = eliminarNodo(nodo->derecha, valor);
        else
        {
            Nodo *actual, *tmp;

            if(nodo->izquierda == NULL) {
                tmp = nodo->derecha;
                delete nodo;
                return tmp;
            } else if(nodo->derecha == NULL) {
                tmp = nodo->izquierda;
                delete nodo;
                return tmp;
            } else {

                for(actual = nodo->derecha;
                    actual != NULL;
                    actual = actual->izquierda) {}

                nodo->valor = actual->valor;
                eliminarNodo(actual, actual->valor);
            }
        }
        return nodo;
    }

public:
    ArbolBinario() {
        raiz = NULL;
    }
    //falta funcion de eliminar

    void insertar(char valor) {
        raiz = insertar(raiz, valor);
    }

    void eliminarNodo(char valor) {
        raiz = eliminarNodo(raiz, valor);
    }
    /**
     * Para mostrar la estructura del arbol necesito:
     * 1. Profundidad del arbol
     * 2. Ancho de arbol
     * 3. Matriz de Profundidad*Ancho llenada con espacios
     * 4. Funcion estructura que posiciona los valores en la matriz de manera recursiva
     */
    void mostrarEstructura(){
        cout <<"\nEstructura del arbol"<<endl;

        distancia.profundidad   = alturaArbol(raiz);
        distancia.ancho         = anchoArbol(raiz);

        int filas       = distancia.profundidad;
        int columnas    = distancia.ancho;
        char **matriz;

        matriz = new char*[filas];
        for(int  i=0;i<filas;i++){
            matriz[i] = new char[columnas];
            for(int j=0;j<columnas;j++){
                matriz[i][j] = ' ';
            }
        }
        //obtengo la estructura guardada en la matriz
        estructura(raiz, matriz,0,distancia.izquierda);

        for(int  i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                cout << matriz[i][j] ;
            }
            cout << endl;
        }

    }



    void inOrden(Nodo *nodo) {
        if(nodo != NULL) {
            inOrden(nodo->izquierda);
            cout << nodo->valor << ' ';
            inOrden(nodo->derecha);
        }
    }

    Nodo * getRaiz(){
        return raiz;
    }

    int alturaArbol(Nodo *nodo){
        if(nodo==NULL){
            return 0;
        }else{
            return (1+ max(alturaArbol(nodo->izquierda), alturaArbol(nodo->derecha)));
        }
    }

    int anchoArbol(Nodo *nodo)
    {
        if (nodo==NULL)
            return 0;
        int altura_izq  = alturaArbol(nodo->izquierda);
        int altura_der  = alturaArbol(nodo->derecha);
        int ancho_izq   = anchoArbol(nodo->izquierda);
        int ancho_der   = anchoArbol(nodo->derecha);
        distancia.izquierda = ancho_izq;
        distancia.derecha   = ancho_der;
        return max((1+altura_izq+altura_der),max(ancho_izq,ancho_der));
    }

};

int main() {
    cout << "Arbol binario de busqueda en C++ utilizando plantillas" << endl;


    ArbolBinario arbolBinario;
    arbolBinario.insertar('1');
    arbolBinario.insertar('0');
    arbolBinario.insertar('3');
    arbolBinario.insertar('4');
    arbolBinario.insertar('7');
    arbolBinario.insertar('2');



    arbolBinario.inOrden(arbolBinario.getRaiz());

    arbolBinario.alturaArbol(arbolBinario.getRaiz());


    cout << "\nAltura "<< arbolBinario.alturaArbol(arbolBinario.getRaiz()) << endl;
    cout << "Diametro "<< arbolBinario.anchoArbol(arbolBinario.getRaiz()) << endl;

    arbolBinario.mostrarEstructura();

    return 0;
}