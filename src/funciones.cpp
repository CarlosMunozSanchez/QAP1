#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief Función que lee los datos del fichero de entrada y actualiza.
 * los vectores flujo y distancia con dichos valores.
 * @param entrada ubicación del fichero de entrada.
 * @param flujos matriz de flujos.
 * @param distancias matriz de distancias.
 */
void leerDatos(const string & entrada , vector<vector<int>> & flujos, vector<vector<int>> & distancias){
    
    flujos.clear();
    distancias.clear();
    
    fstream fs;
    char aux[6];
    
    fs.open(entrada);
    
    int tam;
    
    //leer el tamaño de la matriz
    fs.getline(aux, 6);
    tam = atoi(aux);
        
    //actualizar tamaños
    flujos.resize(tam);
    distancias.resize(tam);
    
    for(int i = 0; i < tam; i++){
        flujos[i].resize(tam);
        distancias[i].resize(tam);
    }
    
    //leer los datos para inicializar las matrices
    //matriz de flujos
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            //me salto los espacios en blanco
            while(fs.peek() == ' ' or fs.peek() == '\n'){
                fs.ignore();
            }
            
            string cadena;
            //escribo en la matriz
            while(fs.peek() != ' ' and fs.peek() != '\n'){
                cadena.push_back(fs.get());
            }
            flujos[i][j] = stoi(cadena);
        }
    }
    
    
    //matriz de distancias
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            //me salto los espacios en blanco
            while(fs.peek() == ' ' or fs.peek() == '\n'){
                fs.ignore();
            }
            
            string cadena;
            //escribo en la matriz
            while(fs.peek() != ' ' and fs.peek() != '\n'){
                cadena.push_back(fs.get());
            }
            distancias[i][j] = stoi(cadena);
        }
    }
            
    fs.close();
}

/**
 * @brief Función para mostrar por pantalla una matriz.
 * @param matriz  Matriz que se desea mostrar.
 */
void mostrarMatriz(const vector<vector<int>> & matriz){
    cout << endl;
    cout << "Tamaño de la matriz: " << matriz.size() << " x " << matriz[0].size() << endl;
    
    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[i].size(); j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Función que calcula el coste de una solución. 
 * @param permutacion Solución propuesta al problema.
 * @param flujos Matriz de flujos asociada.
 * @param distancias Matriz de distancias asociada.
 * @return El coste asociado al vector solución proporcionado
 */
int evaluarSolucion(const vector<int> & permutacion, const vector<vector<int>> & flujos, const vector<vector<int>> & distancias ){
    int sol = 0;
    
    for(int i = 0; i < permutacion.size(); i++){
        for(int j = 0; j < permutacion.size(); j++){
        
            sol += flujos[i][j] * distancias[permutacion[i]-1][permutacion[j]-1];
        
        }
        
    }
    
    return sol;
}


int main(){

    string fichero = "./Instancias_QAP/chr22a.dat";
    
    vector<vector<int>> flujos, distancias;
    
    leerDatos(fichero, flujos, distancias);
    
    //mostrarMatriz(flujos);
    //mostrarMatriz(distancias);
    
    int valores[] = {15, 2, 21, 8, 16, 1, 7, 18, 14, 13, 5, 17, 6, 11, 3, 4, 20, 19, 9, 22, 10, 12};
    vector<int> solucion (valores, valores + sizeof(valores) / sizeof(int) );
    
    for(int i = 0; i < solucion.size(); i++){
        cout << solucion[i] << " ";
    }
    
    cout << endl;
    
    int s = evaluarSolucion(solucion, flujos, distancias);
    
    cout << s;
    
    
}