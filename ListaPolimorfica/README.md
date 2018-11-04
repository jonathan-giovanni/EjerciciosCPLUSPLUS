# Lista polimorfica utilizando plantillas

Lista polimorfica sencilla con metodos para insertar, buscar, y otros que ayudaran a facilitar el entendimiento de como funcionan internamente.

Ejemplo de uso



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
