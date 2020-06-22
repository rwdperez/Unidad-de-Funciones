#include <iostream>
using namespace std;

int aparicion(int x[],int y);
int sumatoria(int x[],int y);

int main(int argc, char *argv[]) {
	
	int arreglo[10];
	int numElegido = 0;
	
	cout<<" Ingrese numeros "<<endl;
	
	for (int i = 0; i < 10; i ++){
		cin>>arreglo[i];
	}
	
	cout<<"Ahora elija el numero que desee saber cuantas veces se repite entre los que ingreso"<<endl;
	cin>>numElegido;
	
	cout<<"El numero "<<numElegido<<" se repite "<<aparicion(arreglo,numElegido)<<" veces"<<endl;
	cout<<" y la suma de las veces que se repite es "<<sumatoria(arreglo,numElegido)<<endl;
	
	return 0;
}

int aparicion(int x[], int y)
{
	int repite = 0;
	int suma = 0;
	
	for (int i = 0; i < 10; i++){
		if (x[i]==y){
			repite++;
			suma = suma + y;
		}
	}
	
	return repite;
	
}

int sumatoria(int x[], int y)
{
	int suma = 0;
	
	for (int i = 0; i < 10; i++){
		if (x[i]==y){
			suma = suma + y;
		}
	}
	
	return suma;
	
}
