#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

int dados ();

int main(int argc, char *argv[]) {
	
	srand(time(NULL));

cout<<" el numero del dado es "<< dados()<<endl;


	return 0;
}

int dados ()
{
	int x = rand()%5+1;
	return x;
}
