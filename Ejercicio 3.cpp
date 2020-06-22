#include <iostream>
using namespace std;

string saludo(string nombreJugador);

int main(int argc, char *argv[]) {
	
	string nombre;
	
	cout<<" cual es tu nombre ";
	cin>>nombre;
	cout<<endl<<endl;
	
	cout<<saludo(nombre)<<endl;
	
	
	return 0;
}

string saludo(string nombreJugador)
{
	string hola = "hola "+nombreJugador;
	
	return hola;
	
}
