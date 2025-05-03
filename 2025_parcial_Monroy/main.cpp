#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>
using namespace std;
void crearArchivos(int cantidad);
void agregarTexto();
int contarArchivosDeDirectorio();
int contarArchivosDeDirectorio2();
void mostrarDetalles();
void mostrarDetalles2();
string generarCadenaAleatoria(int cantidad);
void bitacoraDeRegistro(string mensaje);

int main() {
    int opc;
    cout << "////Bienvenido--al--Programa--de--Creacion--de--Archivos////" << endl;
    do {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Elija una opcion a realizar" << endl;
        cout << "[1] Crear Archivosprimo o no primo " << endl;
        cout << "[2] Mostrar el peso de los archivos" << endl;
        cout << "[0] Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                cout << "Opcion seleccionada -> Crear Archivos primos o no primos" << endl;
                int cantidad;
                cout << "Ingrese la cantidad de archivos que desea crear" << endl;
                cin >> cantidad;
                crearArchivos(cantidad);
                bitacoraDeRegistro("Archivos creados");
                break;
            case 2:
                cout << "Opcion seleccionada -> Mostrar el peso de los archivos" << endl;
                mostrarDetalles();
                mostrarDetalles2();
                break;
            case 0:
                cout << "Gracias por Utilizar el Programa" << endl;
                break;
            default:
                cout << "Opcion incorrecta, vuelva a intentarlo" << endl;
                break;
        }
    } while (opc != 0);
    return 0;
}

void crearArchivos(int cantidad){
    string nombreArchivo = "documento";
    if (cantidad % 2 == 0){
        cout << "Cantidad de Archivos  no primos" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/Adonias/OneDrive/Escritorio/CarpetaParcial/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "linea de texto" << endl;
            }
            file.close();
        }
        cout << cantidad << " Archivos no primos creados con Exito" << endl;
        contarArchivosDeDirectorio();
    }else{
        cout << "Cantidad de Archivos primos" << endl;
        for (int i = 0; i < cantidad; ++i) {
            ofstream file;
            file.open("C:/Users/Adonias/OneDrive/Escritorio/parcial2/" + nombreArchivo + to_string(i + 1) + ".txt");
            agregarTexto();
            for (int j = 0; j < i+1; ++j) {
                file << "linea de texto" << endl;
            }
            file.close();
        }
        cout << cantidad << " Archivos primos creados con Exito" << endl;
        contarArchivosDeDirectorio2();
    }
}

void agregarTexto(){
    cout << "Agregando texto..." << endl;
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/Adonias/OneDrive/Escritorio/parcial2/", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}

int contarArchivosDeDirectorio2(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/Adonias/OneDrive/Escritorio/CarpetaParcial/", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    filesystem::directory_iterator directoryIterator("C:/Users/Adonias/OneDrive/Escritorio/parcial2/");
    cout <<"======================DIRECTORIO========================="<< endl;
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            cout<< endl;
            cout << "Tamanio en Bytes: " << file_size(entry.path()) << " bytes" << endl;
            cout << "Nombre de Archivo: " << entry.path().filename() << endl;
        }
    }
}

void mostrarDetalles2(){
    filesystem::directory_iterator directoryIterator("C:/Users/Adonias/OneDrive/Escritorio/CarpetaParcial/");

    cout<< endl <<"======================DIRECTORIO========================="<< endl;
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            cout<< endl;
            cout << "Peso: " << file_size(entry.path()) << " bytes" << endl;
            cout << "Nombre de Archivo: " << entry.path().filename() << endl;
        }
    }
    bitacoraDeRegistro("Archivos Leidos");
}
void bitacoraDeRegistro(string mensaje) {
    SYSTEMTIME st;
    GetSystemTime(&st);

    stringstream ss;
    ss << mensaje << endl
       << " Hora actual (UTC): "
       << (st.wHour < 10 ? "0" : "") << st.wHour << ":"
       << (st.wMinute < 10 ? "0" : "") << st.wMinute;

    string horaMensaje = ss.str();  // Convertir a string normal
    MessageBoxA(NULL, horaMensaje.c_str(), "Hora del Sistema", MB_OK | MB_ICONINFORMATION);
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.