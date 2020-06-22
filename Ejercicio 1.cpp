#include <iostream>
using namespace std;

int mayor(int arreglo[]);


int main(int argc, char *argv[]) {
	
	int arreglo[7];
	
	for (int i = 0; i < 8; i++)
	{
		cin>>arreglo[i];
		
	}
	
	for (int i = 0; i < 8; i++)
	{
		cout<<arreglo[i];
	}
	
	
	cout<<"El numero mayor es "<<mayor(arreglo);
	
	
	
	
	return 0;
}
int mayor(int x[])
{
	int numMayor = 0;
	for ( int i = 0; i < 8; i++)
	{
		if (x[i] > numMayor)
		{
			numMayor = x[i];
			
		}
	}
	return numMayor;
	
}

