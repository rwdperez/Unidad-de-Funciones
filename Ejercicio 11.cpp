#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

//Funcion donde ocurre toda la jugada del jugador.
void dadosJ (int &puntajeJ, int dado[]);
//Funcion donde ocurre la jugada de la maquina.
void dadosM (int &puntajeM, int dado[]);
//Funcion donde se realiza la comparacion de los puntajes.
string ganador (int puntajeJ, int puntajeM);

int main(int argc, char *argv[]) {
	//Semilla para generar los valores aleatorios.
	srand(time(NULL));
	//Bool para controlar cuando el jugador puede presionar la tecla para jugar.
	bool tirada = true;
	//Nose para que la puse a esta.
	int dado[5];
	//Puntaje jugador.
	int puntajeJ = 0;
	//Puntaje maquina.
	int puntajeM = 0;
	
	cout<<"Bienvenido, te propongo que juguemos a la generala, si ganas prometo durar mucho tiempo sin darte fallas, sino dame vacaciones :D"<<endl;
	
	cout<<"Supongo que sabes como funciona el juego, en este caso solo lo haremos con una tirada de dados, estas listo?"<<endl<<endl;
	
	cout<<" Presione enter para tirar los dados "<<endl<<endl;
	
	
	while(tirada == true){
		if (kbhit()){
			int tecla = getch();
			switch (tecla){
				
			case 13: dadosJ(puntajeJ,dado);
					 tirada = false;
					 break;
			default: cout<<" Presione enter "<<endl<<endl;
					 break;
			
			}
			
		}
	}
	
	cout<<"Ahora me toca tirar a mi "<<endl<<endl;
	
	dadosM(puntajeM,dado);
	
	cout<<ganador(puntajeJ,puntajeM);
	
	return 0;
}
//Implementacion de la variable.
void dadosJ (int &puntajeJ, int dado[]){
	//Copia de la variable dados.
	int valores[5];
	//Variable que llevara la cantidad de veces que se repite un numero.
	int numeros[6];
	//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada full.
	int jugadaFull[6];
	//Variable para almacenar el puntaje de la tirada.
	puntajeJ = 0;
	//Bool poker para saber si se cumplio una condicion de esta jugada.
	bool poker = false;
	//Bool full para saber si se cumplio una condicion de esta jugada.
	bool full = false;
	//Variable que almacena la suma de todos los dados, asi detecta si es escalera.
	int escalera = 0;
	//Variable para almacenar el numero que mas se repite, comparandolo con la variable numeros.
	int numMayor = 0;
	
	
	//Inicializo numeros.
	for (int i = 0; i < 6; i++){
		
		numeros[i] = 0;
	}
	//Doy valor a las variables.
	for (int i = 0; i < 5; i++){
		
		dado[i] = rand()%5+1;
		valores[i] = dado[i];
		escalera = escalera + dado[i];
	}
	
	cout<<" Los dados que salieron son:";
	//Muestro los dados.
	for (int i = 0; i < 5; i++){
		
		cout<<" "<<dado[i];
		
	}
	
	cout<<endl;
	//Chequeo cuantas veces se repite un determinado numero.
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
	//Esto lo tengo que borraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaar.
	cout<<"num1: "<<numeros[0]<<" num2: "<<numeros[1]<<"num3: "<<numeros[2]<<"num4: "<<numeros[3]<<"num5: "<<numeros[4]<<"num6: "<<numeros[5]<<endl;
	
	
	//Estructura for donde chequeo que condiciones se cumplen, para saber que jugada es la que salio.
	for (int i = 0; i < 6; i++){
		//Igualo la variable para full a numeros, de esta forma puedo cambiar el valor de ese indice de numero, para que se cumpla la siguiente condicion del full.
		jugadaFull[i] = numeros[i];
		//Si alguno de los numeros se repite 5 veces significa que hay 5 dados iguales, por lo tanto es generala.
		if (numeros[i] == 5){
			
			cout<<"Generala, sumas 60 puntos "<<endl;
			puntajeJ = 60;
			
		}
		//Si algun numero se repite 4 veces significa que hay 4 dados iguales y se habilita la opcion de poker.
		if (numeros[i] == 4){
			
			poker = true;
			
		}
		//Si poker es verdadero, y hay algun numero que solo se repite 1 ves, la jugada es poker.
		if (poker == true && numeros[i] == 1){
			
			cout<<"Poker, sumas 40 puntos "<<endl;
			puntajeJ = 40;
			
		}
		//Si algun numero se repite 2 o 3 veces se habilita la opcion de full y se da valor 0 a ese indice, porque sino vuelve a detectar el mismo indice en valor 2 o 3 en el siguiente if y me salta esa jugada aunque no sea.
		if (jugadaFull[i] == 3 || jugadaFull[i] == 2){
			
			full = true;
			jugadaFull[i] = 0;
		}
		//Si full es verdadero y el resto de numeros se repite 2 o 3 veces entonces es full.
		if ((full == true && jugadaFull[i] == 2) || (full == true && jugadaFull[i] == 3)){
			
			cout<<"Full, sumas 30 puntos "<<endl;
			puntajeJ = 30;
			
		}
		else{
			//Si la suma de los dados es igual a 15 o 20 la jugada es escalera.
			if (escalera == 15 || escalera == 20){
				
				cout<<"Escalera, sumas 50 puntos "<<endl;
				puntajeJ = 50;
				
			}
			
			else{
				//compruebo cual es el numero que mas se repite.
				if (numeros[i] > numMayor){
					
					numMayor = numeros[i];
					
				}
				
				else{
					//Swicheo el numero que mas se repite y lo comparo con los indices de la variable numeros pora saber de que numero se trata.
					switch (numMayor){
						//En caso que se repita 3 veces.
					case 3: if (numMayor == numeros[0]){
						
								cout<<"Todo al 1, sumas 3 puntos "<<endl;
								puntajeJ = 3;
								break;
							}
							
							if (numMayor == numeros[1]){
								
								cout<<"Todo al 2, sumas 6 puntos "<<endl;
								puntajeJ = 6;
								break;
							}
							
							if (numMayor == numeros[2]){
								
								cout<<"Todo al 3, sumas 9 puntos "<<endl;
								puntajeJ = 9;
								break;
							}
							
							if (numMayor == numeros[3]){
								
								cout<<"Todo al 4, sumas 12 puntos "<<endl;
								puntajeJ = 12;
								break;
							}
							
							if (numMayor == numeros[4]){
								puntajeJ = 15;
								cout<<"Todo al 5, sumas 15 puntos "<<endl;
								
								break;
							}
							
							if (numMayor == numeros[5]){
								puntajeJ = 18;
								cout<<"Todo al 6, sumas 18 puntos "<<endl;
								
								break;
							}
						//En caso que se repita 2 veces.	
					case 2: if (numMayor == numeros[0]){
						
								cout<<"Todo al 1, sumas 2 puntos "<<endl;
								puntajeJ = 2;
								break;
							}
							
							if (numMayor == numeros[1]){
								
								cout<<"Todo al 2, sumas 4 puntos "<<endl;
								puntajeJ = 4;
								break;
							}
							
							if (numMayor == numeros[2]){
								
								cout<<"Todo al 3, sumas 6 puntos "<<endl;
								puntajeJ = 6;
								break;
							}
							
							if (numMayor == numeros[3]){
								
								cout<<"Todo al 4, sumas 8 puntos "<<endl;
								puntajeJ = 8;
								break;
							}
							
							if (numMayor == numeros[4]){
								
								cout<<"Todo al 5, sumas 10 puntos "<<endl;
								puntajeJ = 10;
								break;
							}
							
							if (numMayor == numeros[5]){
								
								cout<<"Todo al 6, sumas 12 puntos "<<endl;
								puntajeJ = 12;
								break;
							}
					}
				}
			}
			
		}
		
		
		
	}
	
	cout<<" Tu puntaje es: "<<puntajeJ<<endl<<endl;
	
	
}

//Implementacion de la variable.
void dadosM (int &puntajeM, int dado[]){
//Implementacion de la variable.
		//Copia de la variable dados.
		int valores[5];
		//Variable que llevara la cantidad de veces que se repite un numero.
		int numeros[6];
		//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada full.
		int jugadaFull[6];
		//Variable para almacenar el puntaje de la tirada.
		puntajeM = 0;
		//Bool poker para saber si se cumplio una condicion de esta jugada.
		bool poker = false;
		//Bool full para saber si se cumplio una condicion de esta jugada.
		bool full = false;
		//Variable que almacena la suma de todos los dados, asi detecta si es escalera.
		int escalera = 0;
		//Variable para almacenar el numero que mas se repite, comparandolo con la variable numeros.
		int numMayor = 0;
		
		
		//Inicializo numeros.
		for (int i = 0; i < 6; i++){
			
			numeros[i] = 0;
		}
		//Doy valor a las variables.
		for (int i = 0; i < 5; i++){
			
			dado[i] = rand()%5+1;
			valores[i] = dado[i];
			escalera = escalera + dado[i];
		}
		
		cout<<" Los dados que salieron son:";
		//Muestro los dados.
		for (int i = 0; i < 5; i++){
			
			cout<<" "<<dado[i];
			
		}
		
		cout<<endl;
		//Chequeo cuantas veces se repite un determinado numero.
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
		//Esto lo tengo que borraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaar.
		cout<<"num1: "<<numeros[0]<<" num2: "<<numeros[1]<<"num3: "<<numeros[2]<<"num4: "<<numeros[3]<<"num5: "<<numeros[4]<<"num6: "<<numeros[5]<<endl;
		
		
		//Estructura for donde chequeo que condiciones se cumplen, para saber que jugada es la que salio.
		for (int i = 0; i < 6; i++){
			//Igualo la variable para full a numeros, de esta forma puedo cambiar el valor de ese indice de numero, para que se cumpla la siguiente condicion del full.
			jugadaFull[i] = numeros[i];
			//Si alguno de los numeros se repite 5 veces significa que hay 5 dados iguales, por lo tanto es generala.
			if (numeros[i] == 5){
				
				cout<<"Generala, sumas 60 puntos "<<endl;
				puntajeM = 60;
				
			}
			//Si algun numero se repite 4 veces significa que hay 4 dados iguales y se habilita la opcion de poker.
			if (numeros[i] == 4){
				
				poker = true;
				
			}
			//Si poker es verdadero, y hay algun numero que solo se repite 1 ves, la jugada es poker.
			if (poker == true && numeros[i] == 1){
				
				cout<<"Poker, sumas 40 puntos "<<endl;
				puntajeM = 40;
				
			}
			//Si algun numero se repite 2 o 3 veces se habilita la opcion de full y se da valor 0 a ese indice, porque sino vuelve a detectar el mismo indice en valor 2 o 3 en el siguiente if y me salta esa jugada aunque no sea.
			if (jugadaFull[i] == 3 || jugadaFull[i] == 2){
				
				full = true;
				jugadaFull[i] = 0;
			}
			//Si full es verdadero y el resto de numeros se repite 2 o 3 veces entonces es full.
			if ((full == true && jugadaFull[i] == 2) || (full == true && jugadaFull[i] == 3)){
				
				cout<<"Full, sumas 30 puntos "<<endl;
				puntajeM = 30;
				
			}
			else{
				//Si la suma de los dados es igual a 15 o 20 la jugada es escalera.
				if (escalera == 15 || escalera == 20){
					
					cout<<"Escalera, sumas 50 puntos "<<endl;
					puntajeM = 50;
					
				}
				
				else{
					//compruebo cual es el numero que mas se repite.
					if (numeros[i] > numMayor){
						
						numMayor = numeros[i];
						
					}
					
					else{
						//Swicheo el numero que mas se repite y lo comparo con los indices de la variable numeros pora saber de que numero se trata.
						switch (numMayor){
							//En caso que se repita 3 veces.
						case 3: if (numMayor == numeros[0]){
							
							cout<<"Todo al 1, sumas 3 puntos "<<endl;
							puntajeM = 3;
							break;
						}
						
						if (numMayor == numeros[1]){
							
							cout<<"Todo al 2, sumas 6 puntos "<<endl;
							puntajeM = 6;
							break;
						}
						
						if (numMayor == numeros[2]){
							
							cout<<"Todo al 3, sumas 9 puntos "<<endl;
							puntajeM = 9;
							break;
						}
						
						if (numMayor == numeros[3]){
							
							cout<<"Todo al 4, sumas 12 puntos "<<endl;
							puntajeM = 12;
							break;
						}
						
						if (numMayor == numeros[4]){
							puntajeM = 15;
							cout<<"Todo al 5, sumas 15 puntos "<<endl;
							
							break;
						}
						
						if (numMayor == numeros[5]){
							puntajeM = 18;
							cout<<"Todo al 6, sumas 18 puntos "<<endl;
							
							break;
						}
						//En caso que se repita 2 veces.	
						case 2: if (numMayor == numeros[0]){
							
							cout<<"Todo al 1, sumas 2 puntos "<<endl;
							puntajeM = 2;
							break;
						}
						
						if (numMayor == numeros[1]){
							
							cout<<"Todo al 2, sumas 4 puntos "<<endl;
							puntajeM = 4;
							break;
						}
						
						if (numMayor == numeros[2]){
							
							cout<<"Todo al 3, sumas 6 puntos "<<endl;
							puntajeM = 6;
							break;
						}
						
						if (numMayor == numeros[3]){
							
							cout<<"Todo al 4, sumas 8 puntos "<<endl;
							puntajeM = 8;
							break;
						}
						
						if (numMayor == numeros[4]){
							
							cout<<"Todo al 5, sumas 10 puntos "<<endl;
							puntajeM = 10;
							break;
						}
						
						if (numMayor == numeros[5]){
							
							cout<<"Todo al 6, sumas 12 puntos "<<endl;
							puntajeM = 12;
							break;
						}
						}
					}
				}
				
			}
			
			
			
		}
		
		cout<<" Tu puntaje es: "<<puntajeM<<endl<<endl;
		
		
	}
string ganador (int puntajeJ, int puntajeM){
	
	string gano;
	
	if (puntajeJ > puntajeM){
		
		gano = "Gana el jugador";
	}
	else{
		
		gano = "Gana la maquina";
	}
	
	return gano;
}
