#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura para representar una tarea
struct Tarea {
    string descripcion;
    bool completada;
};

// Función para agregar una tarea
void agregarTarea(vector<Tarea>& tareas) {
    Tarea nueva;
    cout << "Ingrese la descripcion de la tarea: ";
    getline(cin >> ws, nueva.descripcion);
    nueva.completada = false;
    tareas.push_back(nueva);
    cout << "Tarea agregada exitosamente.\n";
}

// Función para listar las tareas
void listarTareas(const vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas registradas.\n";
        return;
    }
    cout << "Lista de tareas:\n";
    for (size_t i = 0; i < tareas.size(); ++i) {
        cout << i + 1 << ". [" << (tareas[i].completada ? "X" : " ") << "] "
             << tareas[i].descripcion << endl;
    }
}

// Función para marcar una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas para completar.\n";
        return;
    }
    listarTareas(tareas);
    cout << "Ingrese el numero de la tarea a marcar como completada: ";
    size_t num;
    cin >> num;
    if (num < 1 || num > tareas.size()) {
        cout << "Numero de tarea invalido.\n";
        return;
    }
    tareas[num - 1].completada = true;
    cout << "Tarea marcada como completada.\n";
}

// Menú principal
void menu() {
    vector<Tarea> tareas;
    int opcion;
    do {
        cout << "\n--- Gestor de Tareas ---\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Listar tareas\n";
        cout << "3. Marcar tarea como completada\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1: agregarTarea(tareas); break;
            case 2: listarTareas(tareas); break;
            case 3: completarTarea(tareas); break;
            case 4: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);
}

int main() {
    menu();
    return 0;
}