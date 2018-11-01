#include <iostream>

using namespace std;

//crear definicion de la lista con plantillas
template <typename T>
class Lista;

//crear nodo con plantillas
template <typename T>
class Nodo
{
private:
    T valor;
    Nodo* siguiente;
    friend class Lista<T>;//clase amiga lista
public:
    Nodo(T valor){
        this->valor = valor;
        this->siguiente = NULL;
    }
    T obtenerValor(){
        return valor;
    }
};

//lista enlazada que utiliza plantillas
template <typename T>
class Lista
{
private:
    Nodo<T> *raiz;
    Nodo<T> *ultimo;
    int longi;
public:
    Lista(){
        raiz = ultimo = NULL; // cuando se crea la lista no posee elementos
        this->longi=0;
    }
    ~Lista(){
        if(!estaVacia()){//si la lista no esta vacia
            Nodo<T> *actual = raiz;
            Nodo<T> *temporal;
            while ( actual != 0 ) // recorrer los nodos y eliminarlos
            {
                temporal = actual;
                actual = actual->siguiente;
                delete temporal;
            }
        }
        this->longi=0;
    }
    void insertar(T valor){
        if(estaVacia())
        {
            Nodo<T> * nuevo = new Nodo<T>(valor);
            this->raiz   = nuevo;
            this->ultimo = nuevo;
        }
        else
        {
            //insertar el elemento al final
            Nodo<T> * nuevo = new Nodo<T>(valor);
            this->ultimo->siguiente = nuevo;
            this->ultimo = nuevo;
        }
        this->longi++;
    }
    void mostrar(){
        if(estaVacia())
        {
            cout << "Lista esta vacia" << endl;

        }else
        {
            Nodo<T> * actual = this->raiz;
            cout << "Contenido de la lista: ";
            while(actual != NULL)
            {
                cout << actual->obtenerValor() << " ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }
    Nodo<T>* buscar(T valor){
        Nodo<T>* buscado;
        bool encontrado = false;
        buscado = this->raiz;

        while((!encontrado) && (buscado != NULL))
        {
            if(buscado->obtenerValor() == valor)
                encontrado = true;
            else
                buscado = buscado->siguiente;
        }
        return buscado;
    }
    int posicionDe(T valor){
        int pos = 0;
        Nodo<T>* buscado;
        bool encontrado = false;
        buscado = this->raiz;
        while((!encontrado) && (buscado != NULL))
        {
            if(buscado->obtenerValor() == valor) {
                encontrado = true;
            }else{
                buscado = buscado->siguiente;
                pos++;
            }
        }
        if(!encontrado){
            return -1;
        }
        return pos;

    }
    T obtener(int posicion){
        if(posicion<=Longitud()){
            int contador=0;
            Nodo<T>* buscado;
            buscado = this->raiz;
            while (contador<=posicion && buscado!=NULL){
                if(contador==posicion){
                    return buscado->obtenerValor();
                }else{
                    buscado = buscado->siguiente;
                    contador++;
                }
            }
        }else{
            return NULL;
        }
    }

    int Longitud(){ return longi;}

    bool estaVacia(){
        if(raiz == NULL && ultimo == NULL)
            return true;
        else
            return false;
    }
};



int main() {
    cout << "Lista polimorficas " << endl;
    Lista<int> listaEntero;
    listaEntero.insertar(1);
    listaEntero.insertar(2);
    listaEntero.insertar(3);
    listaEntero.insertar(4);

    listaEntero.mostrar();

    cout << "Obtener valor en posicion 3 : "<< listaEntero.obtener(3) << endl;
    cout << "Longitud de lista "<< listaEntero.Longitud() << endl;
    cout << "Buscar 1 "<< listaEntero.buscar(1)->obtenerValor() << endl;


    return 0;
}