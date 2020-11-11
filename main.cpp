#include <iostream>
#include "laboratorio.h"
using namespace std;

int main() {
    Laboratorio v;
    string op;

    while (true)
    {
        cout << "1) Agregar Computadora" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Buscar" << endl;
        cout << "10) Ordenar Sistema Operativo" << endl;
        cout << "11) Ordenar Procesador" << endl;
        cout << "12) Ordenar Ram" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            Computadora c;

            cin >> c;

            v.agregarComputadora(c); 
            cin.ignore();
        } 
        else if (op == "2") {
            v.mostrar();
        }
        else if (op == "3") {
            v.respaldar();
        }
        else if (op == "4") {
            v.recuperar();
        }
        else if (op == "5") {
            Computadora c;
            cin >> c;

            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.insertar(c, pos);
            }
        }
        else if (op == "6") {
            Computadora c;
            cin >> c;

            size_t n;
            cout << "n: ";
            cin >> n; cin.ignore();

            v.inicializar(c, n);
        }
        else if (op == "7") {
            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.eliminar(pos);
            }
        }
        else if (op == "8") {
            v.ordenar();
        }
        else if (op == "9") {
            Computadora c;
            cin >> c; cin.ignore();

            Computadora *ptr = v.buscar(c);

            if (ptr == nullptr) {
                cout << "no encontrado" << endl;
            }
            else {
                cout << *ptr << endl;
            }
        }
        else if (op == "10") {
            v.ordenarSistema();
        }
        else if (op == "11") {
            v.ordenarProcesador();
        }
        else if (op == "12") {
            v.ordenarRam();
        }
        else if (op == "0") {
            break;
        }
    }
    


    return 0;
}