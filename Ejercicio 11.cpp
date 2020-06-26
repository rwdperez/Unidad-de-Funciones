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
	//Bool para reiniciar el juego.
	bool juego = true;
	//Bool para controlar cuando el jugador puede presionar la tecla para jugar.
	bool tirada = true;
	//Arreglo para almacenar datos de los dados que salen.
	int dado[5];
	//Puntaje jugador.
	int puntajeJ = 0;
	//Puntaje maquina.
	int puntajeM = 0;

	
	cout<<"Bienvenido, te propongo que juguemos a la generala, si ganas prometo durar mucho tiempo sin darte fallas, sino dame vacaciones :D."<<endl;
	
	cout<<"Supongo que sabes como funciona el juego, si estas listo tira los dados. "<<endl<<endl;
//Estructura do while para reiniciar el juego las veces que quiera.	
do{	
	cout<<"Presione enter para tirar los dados "<<endl;
	cout<<"Presione escape para salir del juego "<<endl<<endl;
	
	
	while(tirada == true){
		if (kbhit()){
			int tecla = getch();
			switch (tecla){
				
			case 13: dadosJ(puntajeJ,dado);
					 tirada = false;
					 break;
			case 27: tirada = false;
					 juego = false;
					 break;
			default: cout<<" Presione la tecla indicada porfavor "<<endl<<endl;
					 break;
			
			}
			
		}
	}
	
	while (tirada == false && juego == true){
		cout<<endl<<"Ahora es el turno de la computadora "<<endl<<endl;
		
		dadosM(puntajeM,dado);
		
		cout<<endl<<ganador(puntajeJ,puntajeM);
		
		tirada = true;
		cout<<endl<<endl;
	}
	
} while (juego == true);

	return 0;
}
//Implementacion de la funcion.
void dadosJ (int &puntajeJ, int dado[]){
	//Copia de la variable dados.
	int valores[5];
	//Variable que llevara la cantidad de veces que se repite un numero.
	int numeros[6];
	//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada full.
	int jugadaFull[2];
	//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada poker.
	int jugadaPoker[2];
	//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada escalera.
	int jugadaEscalera[2];
	//Variable para chequear y guardar el puntaje de la jugada mas alta.
	int jugadaMayor = 0;
	//Variable para almacenar el puntaje de la tirada.
	puntajeJ = 0;
	//Bool poker para saber si se cumplio una condicion de esta jugada.
	bool poker = false;
	//Bool full para saber si se cumplio una condicion de esta jugada.
	bool full = false;
	//Bool escalera para saber si se cumplio una condicion de esta jugada.
	bool escalera = false;
	//Variable que almacena la suma de todos los dados, asi detecta si es escalera.
	int sumaEscalera = 0;
	//Variable para almacenar el numero que mas se repite, comparandolo con la variable numeros.
	int numMayor = 0;
	//Variable para llevar el control de las jugadas que salen.
	int jugadas[10];
	
	cout<<"El jugador tira los dados"<<endl<<endl;
	
	//Inicializo variables.
	for (int i = 0; i < 10; i++){
		
		jugadas[i] = 0;
	}
	//Inicializo variables.
	for (int i = 0; i < 2; i++){
		
		jugadaFull[i] = 0;
		jugadaPoker[i] = 0;
		jugadaEscalera[i] = 0;
	}
	//Inicializo numeros.
	for (int i = 0; i < 6; i++){
		
		numeros[i] = 0;
	}
	//Doy valor a las variables.
	for (int i = 0; i < 5; i++){
		
		dado[i] = rand()%6+1;
		valores[i] = dado[i];
		sumaEscalera = sumaEscalera + dado[i];
	}
	
	cout<<"Los dados que salieron son:";
	//Muestro los dados.
	for (int i = 0; i < 5; i++){
		
		cout<<" "<<dado[i];
		
	}
	
	cout<<endl<<endl;
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
	
	//Estructura for donde chequeo que condiciones se cumplen, para saber que jugada es la que salio.
	for (int i = 0; i < 6; i++){
		//Si alguno de los numeros se repite 5 veces significa que hay 5 dados iguales, por lo tanto es generala.
		if (numeros[i] == 5){
			
			//Guardo puntaje de generala.
			jugadas[9] = 60;
			
			
		}
		//Si algun numero se repite 4 veces significa que hay 4 dados iguales y se habilita la opcion de poker.
		if (numeros[i] == 4){
			
			poker = true;
			jugadaPoker[0] = 1;
			
		}
		//Si algun numero se repite solo 1 ves, existe la posibilidad de que otro se repita 4 veces y sea un posible poker.
		if (numeros[i] == 1){
			
			poker = true;
			jugadaPoker[1] = 1;
		}
		//Si poker es verdadero, y hay algun numero que se repite 1 o 4 veces y anteriormente ya salio uno que se repite 1 o 4 veces, la jugada es poker.
		if ((poker == true && numeros[i] == 1 && jugadaPoker[0] == 1) || (poker == true && numeros[i] == 4 && jugadaPoker[1] == 1)){
			
			//Guardo puntaje de poker.
			jugadas[7] = 40;
			
			
		}
		//Si algun numero se repite 2 o 3 veces se habilita la opcion de full y se da valor 0 a ese indice, porque sino vuelve a detectar el mismo indice en valor 2 o 3 en el siguiente if y me salta esa jugada aunque no sea.
		if (numeros[i] == 3){
			jugadaFull[0] = 1;
			full = true;
			
		}
		if (numeros[i] == 2){
			
			jugadaFull[1] = 1;
			full = true;
		}
		//Si full es verdadero y el resto de numeros se repite 2 o 3 veces entonces es full.
		if ((full == true && numeros[i] == 2 && jugadaFull[0] == 1) || (full == true && numeros[i] == 3 && jugadaFull[1] == 1)){
			
			//Guardo puntaje de full.
			jugadas[6] = 30;
			
			
		}
		//Si hay un numero que solo se repite 1 ves es posible escalera.
		if (numeros[i] == 1){
	
			escalera = true;
			jugadaEscalera[0] = 1;
		}
		//Si hay un numero que no salio ninguna ves es posible escalera.
		if (numeros[i] == 0){
			
			escalera = true;
			jugadaEscalera[1] = 1;
		}
		//Si la suma de los dados es igual a 15 o 20,hay o no numero 6, hay o no numero 1 y hay solo 1 numero 2 y escalera es verdadero, la jugada es escalera.
		if ((sumaEscalera == 15 && escalera == true && numeros [5] == 0 && numeros[0] == 1 && jugadaEscalera[0] == 1 && numeros[1] == 1) || (sumaEscalera == 20 && escalera == true && numeros[0] == 0 && numeros[5]== 1 && jugadaEscalera[1] == 1 && numeros[1] == 1)){
			
			//Guardo puntaje de escalera.
			jugadas[8] = 50;
			
			
		}
		
		//compruebo cual es el numero que mas se repite.
		if (numeros[i] > numMayor){
			
			numMayor = numeros[i];
			
		}
		
		//Swicheo el numero que mas se repite y lo comparo con los indices de la variable numeros pora saber de que numero se trata.
		switch (numMayor){
		//En caso que se repita 2 veces.
		case 2: if (numMayor == numeros[0]){
			
					//Todo al uno.
					jugadas[0] = 2;
					
					
				}
				
				if (numMayor == numeros[1]){
					
					//Todo al dos.
					jugadas[1] = 4;
					
					
				}
				
				if (numMayor == numeros[2]){
					
					//Todo al tres.
					jugadas[2] = 6;
					
					
				}
				
				if (numMayor == numeros[3]){
					
					//Todo al cuatro.
					jugadas[3] = 8;
					
					
				}
				
				if (numMayor == numeros[4]){
					//Todo al cinco.
					
					jugadas[4] = 10;
					
					
				}
				
				if (numMayor == numeros[5]){
					//Todo al seis.
					
					jugadas[5] = 12;
					
					
				}
				break;
		//En caso que se repita 3 veces.	
		case 3: if (numMayor == numeros[0]){
			
					//Todo al uno.
					jugadas[0] = 3;
					
					
				}
				
				if (numMayor == numeros[1]){
					
					//Todo al dos.
					jugadas[1] = 6;
					
					
				}
				
				if (numMayor == numeros[2]){
					
					//Todo al tres.
					jugadas[2] = 9;
					
					
				}
				
				if (numMayor == numeros[3]){
					
					//Todo al cuatro.
					jugadas[3] = 12;
					
					
				}
				
				if (numMayor == numeros[4]){
					
					//Todo al cinco.
					jugadas[4] = 15;
					
					
				}
				
				if (numMayor == numeros[5]){
					
					//Todo al seis.
					jugadas[5] = 18;
					
					
				}
				break;
			}
		
	}
	//Chequeo el arreglo jugadas para saber cual de todas es la mayor y sacar el puntaje.
	for (int i = 0; i < 10; i++){
		
		if (jugadas[i] > jugadaMayor){
			
			jugadaMayor = jugadas[i];
		}
	}
	
	//Se muestran las jugadas al jugador.
	cout<<"Todo al uno: "<<jugadas[0]<<endl;
	cout<<"Todo al dos: "<<jugadas[1]<<endl;
	cout<<"Todo al tres: "<<jugadas[2]<<endl;
	cout<<"Todo al cuatro: "<<jugadas[3]<<endl;
	cout<<"Todo al cinco: "<<jugadas[4]<<endl;
	cout<<"Todo al seis: "<<jugadas[5]<<endl;
	cout<<"Full: "<<jugadas[6]<<endl;
	cout<<"Poker: "<<jugadas[7]<<endl;
	cout<<"Escalera: "<<jugadas[8]<<endl;
	cout<<"Generala: "<<jugadas[9]<<endl;
	
	//Indica cuantos puntos consiguo con la jugada mayor.
	cout<<endl<<"La jugada mayor suma "<<jugadaMayor<<" puntos "<<endl;
	
	//Guardo el resultado del puntaje.
	puntajeJ = jugadaMayor;
}

//Implementacion de la funcion.
void dadosM (int &puntajeM, int dado[]){
	//Copia de la variable dados.
	int valores[5];
	//Variable que llevara la cantidad de veces que se repite un numero.
	int numeros[6];
	//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada full.
	int jugadaFull[2];
	//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada poker.
	int jugadaPoker[2];
	//Variable para llevar la cantidad de veces que se repite un numero solo para la jugada escalera.
	int jugadaEscalera[2];
	//Variable para chequear y guardar el puntaje de la jugada mas alta.
	int jugadaMayor = 0;
	//Variable para almacenar el puntaje de la tirada.
	puntajeM = 0;
	//Bool poker para saber si se cumplio una condicion de esta jugada.
	bool poker = false;
	//Bool full para saber si se cumplio una condicion de esta jugada.
	bool full = false;
	//Bool escalera para saber si se cumplio una condicion de esta jugada.
	bool escalera = false;
	//Variable que almacena la suma de todos los dados, asi detecta si es escalera.
	int sumaEscalera = 0;
	//Variable para almacenar el numero que mas se repite, comparandolo con la variable numeros.
	int numMayor = 0;
	//Variable para llevar el control de las jugadas que salen.
	int jugadas[10];
	
	//Inicializo variables.
	for (int i = 0; i < 10; i++){
		
		jugadas[i] = 0;
	}
	//Inicializo variables.
	for (int i = 0; i < 2; i++){
		
		jugadaFull[i] = 0;
		jugadaPoker[i] = 0;
		jugadaEscalera[i] = 0;
	}
	//Inicializo numeros.
	for (int i = 0; i < 6; i++){
		
		numeros[i] = 0;
	}
	//Doy valor a las variables.
	for (int i = 0; i < 5; i++){
		
		dado[i] = rand()%6+1;
		valores[i] = dado[i];
		sumaEscalera = sumaEscalera + dado[i];
	}
	
	cout<<"Los dados que salieron son:";
	//Muestro los dados.
	for (int i = 0; i < 5; i++){
		
		cout<<" "<<dado[i];
		
	}
	
	cout<<endl<<endl;
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
	
	//Estructura for donde chequeo que condiciones se cumplen, para saber que jugada es la que salio.
	for (int i = 0; i < 6; i++){
		//Si alguno de los numeros se repite 5 veces significa que hay 5 dados iguales, por lo tanto es generala.
		if (numeros[i] == 5){
			
			//Guardo el puntaje de generala.
			jugadas[9] = 60;
			
			
		}
		//Si algun numero se repite 4 veces significa que hay 4 dados iguales y se habilita la opcion de poker.
		if (numeros[i] == 4){
			
			poker = true;
			jugadaPoker[0] = 1;
			
		}
		//Si algun numero se repite solo 1 ves, existe la posibilidad de que otro se repita 4 veces y sea un posible poker.
		if (numeros[i] == 1){
			
			poker = true;
			jugadaPoker[1] = 1;
		}
		//Si poker es verdadero, y hay algun numero que se repite 1 o 4 veces y anteriormente ya salio uno que se repite 1 o 4 veces, la jugada es poker.
		if ((poker == true && numeros[i] == 1 && jugadaPoker[0] == 1) || (poker == true && numeros[i] == 4 && jugadaPoker[1] == 1)){
			
			//Guardo el puntaje de poker.
			jugadas[7] = 40;
			
			
		}
		//Si algun numero se repite 2 o 3 veces se habilita la opcion de full y se da valor 0 a ese indice, porque sino vuelve a detectar el mismo indice en valor 2 o 3 en el siguiente if y me salta esa jugada aunque no sea.
		if (numeros[i] == 3){
			jugadaFull[0] = 1;
			full = true;
			
		}
		if (numeros[i] == 2){
			
			jugadaFull[1] = 1;
			full = true;
		}
		//Si full es verdadero y el resto de numeros se repite 2 o 3 veces entonces es full.
		if ((full == true && numeros[i] == 2 && jugadaFull[0] == 1) || (full == true && numeros[i] == 3 && jugadaFull[1] == 1)){
			
			//Guardo el puntaje de full.
			jugadas[6] = 30;
			
			
		}
		//Si hay un numero que solo se repite 1 ves es posible escalera.
		if (numeros[i] == 1){
			
			escalera = true;
			jugadaEscalera[0] = 1;
		}
		//Si hay un numero que no salio ninguna ves es posible escalera.
		if (numeros[i] == 0){
			
			escalera = true;
			jugadaEscalera[1] = 1;
		}
		//Si la suma de los dados es igual a 15 o 20,hay o no numero 6, hay o no numero 1 y hay solo 1 numero 2 y escalera es verdadero, la jugada es escalera.
		if ((sumaEscalera == 15 && escalera == true && numeros [5] == 0 && numeros[0] == 1 && jugadaEscalera[0] == 1 && numeros[1] == 1) || (sumaEscalera == 20 && escalera == true && numeros[0] == 0 && numeros[5]== 1 && jugadaEscalera[1] == 1 && numeros[1] == 1)){
			
			//Guardo el puntaje de escalera.
			jugadas[8] = 50;
			
			
		}
		
		//compruebo cual es el numero que mas se repite.
		if (numeros[i] > numMayor){
			
			numMayor = numeros[i];
			
		}
		
		//Swicheo el numero que mas se repite y lo comparo con los indices de la variable numeros pora saber de que numero se trata.
		switch (numMayor){
			//En caso que se repita 2 veces.
		case 2: if (numMayor == numeros[0]){
			
			//Todo al uno.
			jugadas[0] = 2;
			
			
		}
		
		if (numMayor == numeros[1]){
			
			//Todo al dos.
			jugadas[1] = 4;
			
			
		}
		
		if (numMayor == numeros[2]){
			
			//Todo al tres.
			jugadas[2] = 6;
			
			
		}
		
		if (numMayor == numeros[3]){
			
			//Todo al cuatro.
			jugadas[3] = 8;
			
			
		}
		
		if (numMayor == numeros[4]){
			//Todo al cinco.
			
			jugadas[4] = 10;
			
			
		}
		
		if (numMayor == numeros[5]){
			//Todo al seis.
			
			jugadas[5] = 12;
			
			
		}
		break;
		//En caso que se repita 3 veces.	
		case 3: if (numMayor == numeros[0]){
			
			//Todo al uno.
			jugadas[0] = 3;
			
			
		}
		
		if (numMayor == numeros[1]){
			
			//Todo al dos.
			jugadas[1] = 6;
			
			
		}
		
		if (numMayor == numeros[2]){
			
			//Todo al tres.
			jugadas[2] = 9;
			
			
		}
		
		if (numMayor == numeros[3]){
			
			//Todo al cuatro.
			jugadas[3] = 12;
			
			
		}
		
		if (numMayor == numeros[4]){
			
			//Todo al cinco.
			jugadas[4] = 15;
			
			
		}
		
		if (numMayor == numeros[5]){
			
			//Todo al seis.
			jugadas[5] = 18;
			
			
		}
		break;
		}
		
	}
	//Chequeo el arreglo jugadas para saber cual de todas es la mayor y sacar el puntaje.
	for (int i = 0; i < 10; i++){
		
		if (jugadas[i] > jugadaMayor){
			
			jugadaMayor = jugadas[i];
		}
	}
	
	//Se muestran las jugadas al jugador.
	cout<<"Todo al uno: "<<jugadas[0]<<endl;
	cout<<"Todo al dos: "<<jugadas[1]<<endl;
	cout<<"Todo al tres: "<<jugadas[2]<<endl;
	cout<<"Todo al cuatro: "<<jugadas[3]<<endl;
	cout<<"Todo al cinco: "<<jugadas[4]<<endl;
	cout<<"Todo al seis: "<<jugadas[5]<<endl;
	cout<<"Full: "<<jugadas[6]<<endl;
	cout<<"Poker: "<<jugadas[7]<<endl;
	cout<<"Escalera: "<<jugadas[8]<<endl;
	cout<<"Generala: "<<jugadas[9]<<endl;
	
	//Indica cuantos puntos consiguo con la jugada mayor.
	cout<<endl<<"La jugada mayor suma "<<jugadaMayor<<" puntos "<<endl;
	
	//Guardo el resultado del puntaje.
	puntajeM = jugadaMayor;
}
//Implementacion de la funcion.
string ganador (int puntajeJ, int puntajeM){
	
	string gano;
	
	if (puntajeJ > puntajeM){
		
		gano = "Gana el jugador!!!";
	}
	else{
		
		gano = "Gana la maquina!!!";
	}
	
	return gano;
}
