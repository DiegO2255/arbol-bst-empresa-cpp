#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Empleado emp) : dato(emp), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolBST {
private:
    Nodo* raiz;

    // INSERTAR (BST real)
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) return new Nodo(emp);

        if (emp.codigo < nodo->dato.codigo)
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        else if (emp.codigo > nodo->dato.codigo)
            nodo->derecho = insertar(nodo->derecho, emp);
        else
            cout << "?? Codigo duplicado, no se inserta.\n";

        return nodo;
    }

    // BUSCAR
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (!nodo || nodo->dato.codigo == codigo)
            return nodo;

        if (codigo < nodo->dato.codigo)
            return buscar(nodo->izquierdo, codigo);
        else
            return buscar(nodo->derecho, codigo);
    }

    // RECORRIDOS
    void inorden(Nodo* nodo) {
        if (nodo) {
            inorden(nodo->izquierdo);
            mostrar(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo) {
            mostrar(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrar(nodo);
        }
    }

    // ALTURA
    int altura(Nodo* nodo) {
        if (!nodo) return 0;
        return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
    }

    // HOJAS
    void hojas(Nodo* nodo) {
        if (nodo) {
            if (!nodo->izquierdo && !nodo->derecho)
                mostrar(nodo);

            hojas(nodo->izquierdo);
            hojas(nodo->derecho);
        }
    }

    // MOSTRAR EMPLEADO
    void mostrar(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl;
    }

    // ?? NUEVO: MOSTRAR POR NIVELES (ORGANIGRAMA)
void mostrarNiveles() {
    if (!raiz) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    int nivel = 0;

    while (!cola.empty()) {
        int size = cola.size();

        cout << "\nNivel " << nivel 
             << " (" << size << " empleado(s)):\n";

        for (int i = 0; i < size; i++) {
            Nodo* actual = cola.front();
            cola.pop();

            cout << " - ";
            mostrar(actual);

            if (actual->izquierdo) cola.push(actual->izquierdo);
            if (actual->derecho) cola.push(actual->derecho);
        }

        nivel++;
    }
}

public:
    ArbolBST() : raiz(nullptr) {}

    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }

    void buscarEmpleado(int codigo) {
        Nodo* res = buscar(raiz, codigo);
        if (res) {
            cout << "\nEmpleado encontrado:\n";
            mostrar(res);
        } else {
            cout << "\nEmpleado no encontrado\n";
        }
    }

    void mostrarRaiz() {
        if (raiz) {
            cout << "\nRAIZ (Nivel 0):\n";
            mostrar(raiz);
        } else {
            cout << "Arbol vacio\n";
        }
    }

    void mostrarInorden() {
        cout << "\nINORDEN:\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\nPREORDEN:\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\nPOSTORDEN:\n";
        postorden(raiz);
    }

    void mostrarAltura() {
        cout << "\nAltura: " << altura(raiz) << endl;
    }

    void mostrarHojas() {
        cout << "\nHOJAS:\n";
        hojas(raiz);
    }

    void mostrarOrganigrama() {
        cout << "\n=== ORGANIGRAMA POR NIVELES ===\n";
        mostrarNiveles();
    }
};

int main() {
    ArbolBST arbol;
    int op;

    do {
        cout << "\n==== MENU BST EMPRESA ====\n";
        cout << "1. Insertar empleado\n";
        cout << "2. Buscar empleado\n";
        cout << "3. Mostrar raiz\n";
        cout << "4. Mostar Recorrido Inorden\n";
        cout << "5. Mostar Recorrido Preorden\n";
        cout << "6. Mostar Recorrido Postorden\n";
        cout << "7. Mostar Altura\n";
        cout << "8. Mostar Hojas\n";
        cout << "9. Mostar Niveles (num Empelados)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        if (op == 1) {
            Empleado e;
            cout << "Codigo: "; cin >> e.codigo;
            cin.ignore();
            cout << "Nombre: "; getline(cin, e.nombre);
            cout << "Cargo: "; getline(cin, e.cargo);

            arbol.insertarEmpleado(e);
        }
        else if (op == 2) {
            int c;
            cout << "Codigo: "; cin >> c;
            arbol.buscarEmpleado(c);
        }
        else if (op == 3) arbol.mostrarRaiz();
        else if (op == 4) arbol.mostrarInorden();
        else if (op == 5) arbol.mostrarPreorden();
        else if (op == 6) arbol.mostrarPostorden();
        else if (op == 7) arbol.mostrarAltura();
        else if (op == 8) arbol.mostrarHojas();
        else if (op == 9) arbol.mostrarOrganigrama();

    } while (op != 0);

    return 0;
}
//Fin
