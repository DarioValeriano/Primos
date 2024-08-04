#include <iostream>
using namespace std;
#include <fstream>
#include <ctime>
const unsigned int MAXIMO = 100000000;
const unsigned int CANTIDAD = 6000000;

bool es_primo(int numero, int* vector){
    bool respuesta = true;
    int posicion = 1;
    while((respuesta==true) && (numero>3) && ((vector[posicion]*vector[posicion])<=numero)){   
        if (numero%vector[posicion]==0){
            respuesta = false;
        }
        posicion+=1;
    }
    return respuesta;
}

int escribir_primos(int *vector,int ti){
    int contador=0;
    int valorInicial=2;
    vector[contador] = valorInicial;
    for(int i=valorInicial+1;i<=MAXIMO;i+=2){
        if(es_primo(i, vector)){
            contador += 1;
            vector[contador] = i;
        };
	}
    ofstream archivo("primos.txt");
    for (int i = 0; i<=contador; i++)
    {
        archivo<<vector[i]<<endl;
    }
    archivo.close(); 
    unsigned int tf = clock(); 
    double tiempo_total = (double(tf - ti)) / CLOCKS_PER_SEC;
    cout<<"tiempo empleado: "<< tiempo_total<< " segundos" << endl;
    return contador+=1;
}

int main(){
    unsigned int ti = clock(); 
    int* vector = new int[CANTIDAD];
    int primos_total = escribir_primos(vector, ti);
    cout<< "cantidad de numeros primos guardados: " << primos_total<< endl;
    delete[ ]vector;
    return 0;
}
