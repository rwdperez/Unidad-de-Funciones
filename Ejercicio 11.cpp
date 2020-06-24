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
					 
					 break;
			default: cout<<" Presione enter "<<endl<<endl;
					 break;
			
			}
			
		}
	}
	
	
	
	return 0;
}

void dados (int dado[]){
	
	int valores[5];
	
	int numeros[6];
	
	bool poker = false;
	
	bool full = false;
	
	int escalera = 0;
	
	int numMayor = 0;
	
	
	
	for (int i = 0; i < 6; i++){
		
		numeros[i] = 0;
	}
	
	for (int i = 0; i < 5; i++){
		
		dado[i] = rand()%5+1;
		valores[i] = dado[i];
		escalera = escalera + dado[i];
	}
	
	cout<<" Los dados que salieron son:";
	
	for (int i = 0; i < 5; i++){
		
		cout<<" "<<dado[i];
		
	}
	
	cout<<endl;
	
	for ( int i = 0; i < 5; i++){
		
		switch(valores[i]){
			
		case 1: numeros[0]++;
				break;
		case 2: numeros[1]++;
				break;
		case 3: numeros[2]++;
				break;
		case 4: numeros[3]++;
				break;
		case 5: numeros[4]++;
				break;
		case 6: numeros[5]++;
				break;
		
		}
	}
	
	cout<<"num1: "<<numeros[0]<<" num2: "<<numeros[1]<<"num3: "<<numeros[2]<<"num4: "<<numeros[3]<<"num5: "<<numeros[4]<<"num6: "<<numeros[5]<<endl;
	
	
	
	for (int i = 0; i < 6; i++){
		
		if (numeros[i] == 5){
			
			cout<<"Generala, sumas 60 puntos "<<endl;
		}
		
		if (numeros[i] == 4){
			
			poker = true;
		}
		
		if (poker == true && numeros[i] == 1){
			
			cout<<"Poker, sumas 40 puntos "<<endl;
		}
		
		if (numeros[i] == 3 || numeros[i] == 2){
			
			full = true;
		}
		
		if (full == true && numeros[i] == 2 || full == true && numeros[i] == 3){
			
			cout<<"Full, sumas 30 puntos "<<endl;
		}
		else{
			
			if (escalera == 15 || escalera == 20){
				
				cout<<"Escalera, sumas 50 puntos "<<endl;
			}
			
			else{
				
				if (numeros[i] > numMayor){
					
					numMayor = numeros[i];
				}
				
				else{
					
					switch (numMayor){
						
					case 3: if (numMayor == numeros[0]){
						
								cout<<"Todo al 1, sumas 3 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[1]){
								
								cout<<"Todo al 2, sumas 6 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[2]){
								
								cout<<"Todo al 3, sumas 9 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[3]){
								
								cout<<"Todo al 4, sumas 12 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[4]){
								
								cout<<"Todo al 5, sumas 15 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[5]){
								
								cout<<"Todo al 6, sumas 18 puntos "<<endl;
								break;
							}
							
					case 2: if (numMayor == numeros[0]){
						
								cout<<"Todo al 1, sumas 2 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[1]){
								
								cout<<"Todo al 2, sumas 4 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[2]){
								
								cout<<"Todo al 3, sumas 6 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[3]){
								
								cout<<"Todo al 4, sumas 8 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[4]){
								
								cout<<"Todo al 5, sumas 10 puntos "<<endl;
								break;
							}
							
							if (numMayor == numeros[5]){
								
								cout<<"Todo al 6, sumas 12 puntos "<<endl;
								break;
							}
					}
				}
			}
			
		}
		
	}
	
	
}
