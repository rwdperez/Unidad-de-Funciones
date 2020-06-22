#include <iostream>
using namespace std;

string holamundo();

int main(int argc, char *argv[]) {
	
	cout<<holamundo();
	
	return 0;
}

string holamundo()
{
	string hola = "hola";
	string mundo = "mundo";
	string saludo = hola+mundo;
	return saludo;
}
