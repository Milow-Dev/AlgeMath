#include<iostream>
using namespace std;

void titulo(); void matriz2x2(); void matriz3x3(); void simpFrac(int &numd, int &denm);
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
	string marco = "	:::::::::::::::::::::::::::::::::::::::::\n";
	cout << endl << marco << "	:: TextoMath v 0.2 - Por: Camilo Cruz  ::\n"<< marco << endl;
}

int menu(){
	int opc;
	cout << "	:: Ingrese la actividad que desea ingresar\n"<< endl ;
	cout << "	:: 1. Matrices 2x2\n	:: 2. Matrices 3x3\n"<< endl <<"	[]: ";
	cin >> opc;
	return opc;
}

int mcd(int a,int b){ // Calcula el maximo común divisor //
	if(b == 0) return a;
	return mcd(b, a % b);
}

void simpFrac(float &numd, float &denm){
	float divCom = mcd(abs(numd), abs(denm)); // Envia el valor absoluto //
	numd /= divCom; denm /= divCom;
}

void matriz2x2(){

	float x,y;
	varX = 'x'; varY = 'y';
	coefX = 4; coefY = -2; cons = 8;
	coefX2 = 3; coefY2 = 1;  cons2 = 2;

	detA = ((coefX*coefY2)-(coefX2*coefY)); // Calcular determinantes //
	detX = ((cons*coefY2)-(cons2*coefY));
	detY = ((coefX*cons2)-(coefX2*cons));
	
	numdX = detX, denmX = detA; numdY = detY, denmY = detA;
	x = detX/detA, y = detY/detA;
	
	simpFrac(numdX, denmX); // Simplifica las fracciones //
	simpFrac(numdY, denmY);
	
	titulo();
	cout << "	:: Matriz a resolver:\n" << endl;
	
	// Imprime la ecuación 1 //
	cout << "	 | ";
	
	if (coefX<0){ // Imprime el valor de X //
		cout << "-";
		if(coefX != 1 && coefX != -1 && coefX != 0){
			cout << abs(coefX);}
	} else{
		if(coefX != 1 && coefX != -1 && coefX != 0){
			cout << abs(coefX);}
	}
	
	cout << varX; // Imprime la variable X //
	
	if(coefY>=0){ // Imprime el valor de Y //
		cout<<"+";
		if(coefY != 1 && coefY != -1 && coefY != 0){
			cout << abs(coefY);}
	} else{
		cout << "-";
		if(coefY != 1 && coefY != -1 && coefY != 0){
			cout << abs(coefY);}
	}
				
	cout<<varY<<" = "<<cons<< endl;// Imprime la variable Y y la constante //
		
	// Imprime la ecuación 2 //
	cout << "	 | ";
	
	if (coefX2<0){ // Imprime el valor de X2 //
		cout << "-";
		if(coefX2 != 1 && coefX2 != -1 && coefX2 != 0){
			cout << abs(coefX2);}
	} else{
		if(coefX2 != 1 && coefX2 != -1 && coefX2 != 0){
			cout << abs(coefX2);}
	}
	
	cout << varX; // Imprime la variable X2 //
	
	if(coefY2>=0){ // Imprime el valor de Y2 //7
		cout<<"+";
		if(coefY2 != 1 && coefY2 != -1 && coefY2 != 0){
			cout << abs(coefY2);}
	} else{
		cout << "-";
		if(coefY2 != 1 && coefY2 != -1 && coefY2 != 0){
			cout << abs(coefY2);}
	}
				
	cout<<varY<<" = "<<cons2<< endl << endl;// Imprime la variable Y2 y la constante 2 //
	
	cout << "	:: Det A: " << detA << endl;
	cout << "	:: Det X: " << detX << endl;
	cout << "	:: Det Y: " << detY << endl << endl;
	cout << "	:: X: " << numdX << "/" << denmX << "	=	" << x << endl;
	cout << "	:: Y: " << numdY << "/" << denmY << "	=	" << y << endl << endl;

cout << "	:: ";
system("pause");
}

void matriz3x3(){
}

/* Changelog v0.2 pre-alpha // 19/09/2024
	
	- Ahora se puden mostrar los resultados en fracciones
	- Se mejoró el sistema para imprimir la variable:
		- Ya no se imprimirán los números 1, -1 y 0
		- Los valores negativos ya no se mostrarán 2 veces
*/
