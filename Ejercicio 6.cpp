#include <iostream>
using namespace std;

string multiplo(int x, int y);

int main(int argc, char *argv[]) {
	
	int numero;
	int divisor;
	
	cout<<"Ingrese el numero y luego el otro numero para saber si son multiplos"<<endl;
	cin>>numero;
	cin>>divisor;
	
	cout<< "Son multiplos? : "<<multiplo(numero,divisor)<<endl;
	
	
	
	return 0;
}


string multiplo(int x, int y)
{
	string siNo;
	if (x%y == 0)
	{
		siNo = " Si es multiplo ";
	}
	else
	{
		siNo = " no son  multiplo ";
	}
	
	return siNo;
}
