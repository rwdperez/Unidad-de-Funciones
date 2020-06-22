#include <iostream>
using namespace std;

float promedio(float v1, float v2, float v3, float v4, float v5);

int main(int argc, char *argv[]) {

	int valor1;
	int valor2;
	int valor3;
	int valor4;
	int valor5;
	
	cout<<"Por favor ingrese los 5 valores que desea promediar ";
	cin>>valor1;
	cin>>valor2;
	cin>>valor3;
	cin>>valor4;
	cin>>valor5;
	
	cout<<"El promedio es de "<<promedio(valor1,valor2,valor3,valor4,valor5)<<endl;
	
	
	return 0;
}

float promedio(float v1,float v2, float v3, float v4, float v5)
{
	float resultado = ((v1+v2+v3+v4+v5) / 5);
	return resultado;
}

//Creo que tenia que hacerlo con un arreglo asi puedo meter los valores que sean.
