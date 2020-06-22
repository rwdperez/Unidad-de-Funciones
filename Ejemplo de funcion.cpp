#include <iostream>
using namespace std;

int encontrarMax(int x, int y);

int main(int argc, char *argv[]) {
	
	int n1;
	int n2;
	
	cout<<" Digite 2 numeros ";
	cin>>n1>>n2;
	cout<< " el mayo de los 2 numeros es "<<encontrarMax(n1,n2)<<endl;
	
	
	
	
	return 0;
}


int encontrarMax(int x, int y)
{
	int numMax;
	if (x>y)
	{
		numMax = x;
	}
	else
	{
		numMax = y;
	}
	return numMax;
}
