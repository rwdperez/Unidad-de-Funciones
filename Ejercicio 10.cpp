#include <iostream>
using namespace std;

void vocales(string x);

int main(int argc, char *argv[]) {
	
	string palabra;
		
	cout<<" por favor escriba una palabra y le indicare cuantas vocales tiene y cuanto se repiten "<<endl;
	cin>>palabra;
	
	vocales(palabra);
	
	return 0;
}

void vocales (string x){
	
	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;
	for (int i = 0; i < x.length(); i++){
		switch (x[i]){
		case 'a': a++;
		break;
		case 'e': e++;
		break;
		case 'i': i++;
		break;
		case 'o': o++;
		break;
		case 'u': u++;
		break;
		}
	}
	
	cout<<" a: "<<a<<" e: "<<e<<" i: "<<i<<" o: "<<o<<" u: "<<u<<endl;
}
