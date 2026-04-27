# Árbol BST Empresarial en C++

##  Autor

* Diego Alexander Curillo Pilamunga

## Objetivo

Implementar un **Árbol Binario de Búsqueda (BST)** en C++ para organizar empleados de una empresa utilizando un código numérico como clave.
El sistema permite representar una estructura jerárquica similar a un **organigrama empresarial**.

## Funcionalidades

### Insertar empleados

```cpp
void insertarEmpleado(Empleado emp) {
    raiz = insertar(raiz, emp);
}
```


### Buscar empleados por código

```cpp
void buscarEmpleado(int codigo) {
    Nodo* res = buscar(raiz, codigo);
    if (res) {
        cout << "Empleado encontrado:\n";
        mostrar(res);
    } else {
        cout << "Empleado no encontrado\n";
    }
}
```


### Mostrar la raíz del árbol

```cpp
void mostrarRaiz() {
    if (raiz) {
        cout << "RAIZ:\n";
        mostrar(raiz);
    } else {
        cout << "Arbol vacio\n";
    }
}
```


### Recorrido Inorden

```cpp
void mostrarInorden() {
    inorden(raiz);
}
```

### Recorrido Preorden

```cpp
void mostrarPreorden() {
    preorden(raiz);
}
```

### Recorrido Postorden

```cpp
void mostrarPostorden() {
    postorden(raiz);
}
```


### Calcular altura del árbol

```cpp
void mostrarAltura() {
    cout << "Altura: " << altura(raiz) << endl;
}
```


### Mostrar nodos hoja

```cpp
void mostrarHojas() {
    hojas(raiz);
}
```


### Mostrar niveles (organigrama)

```cpp
void mostrarOrganigrama() {
    mostrarNiveles();
}
```

## Conceptos Aplicados

* **Árbol Binario de Búsqueda (BST):**

  * Los valores menores se insertan a la izquierda
  * Los valores mayores a la derecha

* **Raíz:** Primer nodo del árbol

* **Nodo interno:** Nodo con al menos un hijo

* **Hoja:** Nodo sin hijos

* **Nivel:** Posición jerárquica dentro del árbol

* **Altura:** Número máximo de niveles del árbol

## Capturas

A continuación se muestran evidencias del funcionamiento del programa:

1. Menú principal
<img width="342" height="296" alt="0_Menu" src="https://github.com/user-attachments/assets/3ecdd612-f3b9-429f-bd94-c7b6b0d0638e" />

2. Inserción de empleados
<img width="335" height="332" alt="1_Insertar Empleado" src="https://github.com/user-attachments/assets/a8b11081-ab70-43cd-bbb7-0b717a659e26" />

3. Busqueda de empleados
<img width="612" height="372" alt="2_BuscarEmpleado" src="https://github.com/user-attachments/assets/1cb992c2-f4eb-4e0e-bdae-c9348bf46df2" />

4. Mostrar Raiz
<img width="605" height="340" alt="3_MostarRaiz" src="https://github.com/user-attachments/assets/622aca15-7665-4b2f-bb9e-964894abbe26" />

5. Mostrar Inorden
<img width="653" height="455" alt="5_MostarPreorden" src="https://github.com/user-attachments/assets/4f8775de-eaaf-489e-983e-5ed5e6780ff2" />

6. Mostrar Postorden
<img width="647" height="446" alt="6_MostarPostorden" src="https://github.com/user-attachments/assets/d0f8b86c-adb7-476c-b49c-69c58bf42c7f" />

7. Mostrar Altura
<img width="335" height="322" alt="7_MostarAltura" src="https://github.com/user-attachments/assets/63bf709f-1f88-4a41-97e0-1840a45baad9" />

8. Mostrar Hojas
<img width="577" height="408" alt="8_MostarHojas" src="https://github.com/user-attachments/assets/6e7b59d6-2c67-40ed-bbbb-1d48cbf47f24" />

9. Mostrar Niveles
<img width="685" height="328" alt="9_MostarNiveles" src="https://github.com/user-attachments/assets/79cbf0c4-c880-4ccd-bdcf-61bbfd69006f" />

10. Salir
<img width="567" height="190" alt="10_Salir" src="https://github.com/user-attachments/assets/cd15e12d-c3e4-4cd1-baf6-573d44bd694f" />


## Tecnologías utilizadas

* Lenguaje: **C++**
* IDE: Visual Studio Code
* Compilador: **g++**
* Control de versiones: **Git**
* Plataforma: **GitHub**

## Ejecución del programa

### Compilar:

```bash
g++ src/main.cpp -o arbol
```

### Ejecutar:

```bash
./arbol
```

## Conclusión

El uso de un **Árbol Binario de Búsqueda (BST)** permite organizar información de manera eficiente y jerárquica, facilitando la búsqueda rápida de empleados.
Además, la representación por niveles permite visualizar el sistema como un **organigrama empresarial**, reforzando la comprensión de estructuras de datos en aplicaciones reales.

## repositorio

Hola
