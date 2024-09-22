#include<iostream>
using namespace std;

void titulo(); void matriz2x2(); void matriz3x3();
void imp2x2();
int menu(); int mcd(int a,int b); 

// Variables Públicas //
char varX,varY,varZ;
char varX2,varY2,varZ2;
float coefX,coefY,coefZ,cons,detA,detX,detY,detZ,numdX,numdY,denmX,denmY;
float coefX2,coefY2,coefZ2,cons2;

int main(){

	int opc;
	do{
		titulo();
		opc = menu();
		switch(opc){
			case 1:
				titulo();
				matriz2x2();
				break;
			case 2:
				matriz3x3();
				break;
		}
	}while(opc!=3);
	return 0;
}

void titulo(){
	system("cls");
	string marco = "	::::::::::::::::::::::::::::::::::::::::\n";
	cout << endl << marco << "	:: TextoMath v 0.1 - Por: Camilo Cruz ::\n"<< marco << endl;
}

int menu(){
	int opc;
	cout << "	:: Ingrese la actividad que desea ingresar\n"<< endl ;
	cout << "	:: 1. Matrices 2x2\n	:: 2. Matrices 3x3\n"<< endl <<"	[]: ";
	cin >> opc;
	return opc;
}

void matriz2x2(){

	float x,y;
	varX = 'x'; varY = 'y';
	coefX = 4; coefY = -2; cons = 8;
	coefX2 = 3; coefY2 = 1; cons2 = 2;

	detA = ((coefX*coefY2)-(coefX2*coefY)); // Calcular determinantes //
	detX = ((cons*coefY2)-(cons2*coefY));
	detY = ((coefX*cons2)-(coefX2*cons));
	
	x = detX/detA, y = detY/detA;

	titulo();
	cout << "	:: Matriz a resolver:\n" << endl;
	
	// Imprime la ecuación 1 //
	cout << "	 | " << coefX << varX; if(coefY>0){cout<<"+";}else{cout<<"-";}cout<<coefY<<varY<<" = " << cons << endl;
	cout << "	 | " << coefX2 << varX; if(coefY2>0){cout<<"+";}else{cout<<"-";}cout<<coefY2<<varY<<" = " << cons2 << endl;
	
	cout << "	:: Det A: " << detA << endl;
	cout << "	:: Det X: " << detX << endl;
	cout << "	:: Det Y: " << detY << endl << endl;
	cout << "	:: X: " << x << endl;
	cout << "	:: Y: " << y << endl << endl;

cout << "	:: ";
system("pause");
}

void matriz3x3(){
}

/* Changelog v0.1 (anterior: v0.05) // 18/09/2024

	- Ahora se muestra un + o un - dependiendo del valor del coeficiente.
	- Ahora las variables X y Y son tipo Char, para que en el futuro se puedan cambiar.
	- Mejoras visuales en la interfaz.
	- Pequeñas optimizaciones a la hora de imprimir texto
*/
