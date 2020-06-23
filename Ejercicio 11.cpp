#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;


void dados (int dado[]);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	bool tirada = true;
	int dado[5];
	
	
	cout<<" Presione enter para tirar los dados "<<endl<<endl;
	
	
	while(tirada == true){
		if (kbhit()){
			int tecla = getch();
			switch (tecla){
				
			case 13: dados(dado);
					 tirada = false;
					 break;
			default: cout<<" Presione enter "<<endl<<endl;
					 break;
			
			}
			
		}
	}
	
	
	return 0;
}

void dados (int dado[]){
	
	for (int i = 0; i < 5; i++){
		
		dado[i] = rand()%5+1;
	}
	
	cout<<" Los dados que salieron son:";
	
	for (int i = 0; i < 5; i++){
		
		cout<<" "<<dado[i];
	}
	
}
