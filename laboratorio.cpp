#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio()
{

}

void Laboratorio::agregarComputadora(const Computadora &c)
{
    computadoras.push_back(c);
}

void Laboratorio::mostrar()
{
    cout << left;
    cout << setw(20) << "Nombre del equipo";
    cout << setw(20) << "Sistema operativo";
    cout << setw(20) << "Procesador";
    cout << setw(5) << "Ram";
    cout << endl;

    for (size_t i=0; i < computadoras.size(); i++){
        Computadora &c = computadoras[i];
        cout << c;
    }
}

void Laboratorio::respaldar_tabla()
{
    ofstream archivo("computadoras_tabla.txt");
    if (archivo.is_open()) {
        archivo << left;
        cout << left;
    cout << setw(20) << "Nombre del equipo";
    cout << setw(20) << "Sistema operativo";
    cout << setw(20) << "Procesador";
    cout << setw(5) << "Ram";
    cout << endl;
        for (size_t i=0; i < computadoras.size(); i++){
        Computadora &p = computadoras[i];
            archivo << p;
        }
    }
    archivo.close();
}
void Laboratorio::respaldar()
{
    ofstream archivo("computadoras.txt");
    if (archivo.is_open()) {
        for (size_t i=0; i < computadoras.size(); i++){
        Computadora &c = computadoras[i];
            archivo << c.getNombre_E() << endl;
            archivo << c.getSistema_O() << endl;
            archivo << c.getProcesador_N() << endl;
            archivo << c.getRam() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar()
{
    ifstream archivo("computadoras.txt");
    if (archivo.is_open()) {
        string temp;
        int ram;
        Computadora c;

        while (true)
        {
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            c.setNombre_E(temp);

            getline(archivo, temp);
            c.setSistema_O(temp);

            getline(archivo, temp);
            c.setProcesador_N(temp);

            getline(archivo, temp);
            ram = stoi(temp);
            c.setRam(ram);

            agregarComputadora(c);          
        }
        
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &p, size_t pos)
{
    computadoras.insert(computadoras.begin()+pos, p);
}

size_t Laboratorio::size()
{
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &p, size_t n)
{
    computadoras = vector<Computadora>(n, p);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}
void Laboratorio::ordenarSistema()
{
    sort(computadoras.begin(), computadoras.end(), 
    [](Computadora p1, Computadora p2){return p1.getSistema_O() < p2.getSistema_O();});
}
void Laboratorio::ordenarProcesador()
{
    sort(computadoras.begin(), computadoras.end(),
    [](Computadora p1, Computadora p2){return p1.getProcesador_N() > p2.getProcesador_N();});
}
void Laboratorio::ordenarRam()
{
    sort(computadoras.begin(), computadoras.end(),
    [](Computadora p1, Computadora p2){return p1.getRam() < p2.getRam();});
}

Computadora* Laboratorio::buscar(const Computadora &p)
{
    auto it = find(computadoras.begin(), computadoras.end(), p);

    if (it == computadoras.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}
