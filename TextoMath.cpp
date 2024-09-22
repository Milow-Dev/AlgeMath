#include<iostream>
using namespace std;

void titulo();
void matriz2x2();
void matriz2x2_print(char varX, float coefX, char varY, float coefY, float cons);
void matriz2x2_math(char varX, char varY, float coefX, float coefY, float cons, float coefX2, float coefY2, float cons2);
void matriz3x3();
void simpFrac(int &numd, int &denm);
void dialogo(int numText);
int menu(); int mcd(int a,int b); 

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
				dialogo(1);
				system("pause");
				break;
		}
	}while(opc!=3);
	return 0;
}

void titulo(){
	system("cls");
	string marco = "	::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout << endl << marco << "	:: AlgeMath v 0.3 (alpha) - Por: Camilo Cruz  ::\n"<< marco << endl;
}

int menu(){
	int opc;
	cout << "	:: Ingrese la actividad que desea ingresar\n"<< endl ;
	cout << "	:: 1. Matrices 2x2\n	:: 2. Matrices 3x3\n"<< endl <<"	[]: ";
	cin >> opc;
	return opc;
}

void matriz2x2(){
char varX,varY;
float coefX,coefY,cons; float coefX2,coefY2,cons2;

	cout << "	:: Hola, ingresa la letra de la primera variable: "; cin >> varX; cout << endl;
	cout << "	:: Genial, ahora ingresa el valor de " << varX << ": "; cin >> coefX; cout << endl;
	cout << "	:: Ahora, ingresa la letra de segunda variable: "; cin >> varY; cout << endl;
	cout << "	:: Genial, ahora ingresa el valor de " << varY << ": "; cin >> coefY; cout << endl;
	cout << "	:: Por ultimo, la primera constante: "; cin >> cons; cout << endl;
	
	cout << "	:: Genial, ahora ingresa el valor de " << varX << ": "; cin >> coefX2; cout << endl;
	cout << "	:: Genial, ahora ingresa el valor de " << varY << ": "; cin >> coefY2; cout << endl;
	cout << "	:: Por ultimo, la primera constante: "; cin >> cons2; cout << endl;
	
	matriz2x2_math(varX, varY, coefX, coefY, cons, coefX2, coefY2, cons2);

	cout << endl;
	system("pause");
}

int mcd(int a,int b){ // Calcula el maximo común divisor //
	if(b == 0) return a;
	return mcd(b, a % b);
}

void simpFrac(float &numd, float &denm){
	float divCom = mcd(abs(numd), abs(denm)); // Envia el valor absoluto //
	numd /= divCom; denm /= divCom;
}

void matriz2x2_math(char varX, char varY, float coefX, float coefY, float cons, float coefX2, float coefY2, float cons2){
	
float detA,detX,detY,numdX,numdY,denmX,denmY;
float x,y;

	detA = ((coefX*coefY2)-(coefX2*coefY)); // Calcular determinantes //
	detX = ((cons*coefY2)-(cons2*coefY));
	detY = ((coefX*cons2)-(coefX2*cons));
	
	numdX = detX, denmX = detA; numdY = detY, denmY = detA;
	x = detX/detA, y = detY/detA;
	
	simpFrac(numdX, denmX); // Simplifica las fracciones //
	simpFrac(numdY, denmY);
	
	titulo();
	matriz2x2_print(varX, coefX, varY, coefY, cons);
	matriz2x2_print(varX, coefX2, varY, coefY2, cons2);
	cout << "\n	:: Det A: " << detA << endl;
	cout << "	:: Det X: " << detX << endl;
	cout << "	:: Det Y: " << detY << endl << endl;
	cout << "	:: X: " << numdX << "/" << denmX << "	=	" << x << endl;
	cout << "	:: Y: " << numdY << "/" << denmY << "	=	" << y << endl << endl;

cout << "	:: ";
system("pause");
}

void matriz2x2_print(char varX, float coefX, char varY, float coefY, float cons){
	
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
}

void matriz3x3(){
}

void dialogo(int numText){
	
	static const string Dialogos[]{
	"Este es el dialogo 0\n", // 0
	"Este es el dialogo 1\n", // 1
	"Este es el dialogo 2\n", // 2
	"Este es el dialogo 3\n", // 3
	};
	
	cout << Dialogos[numText];
}

/* Changelog v0.3:
	- Ahora el usuario puede digitar las variables y sus valores.
	- Se optimizó el código, implementando una función que imprime
	ambas matrices sin necesidad de escribir 2 veces la impresión.
	- Ahora la función que resuelve la matriz, recibe los datos por parámetro.
	- Se está probando una función que almacene todos los dialogos del programa
	para que el codigo se vea más limpio.
	- Se quitaron las variables públicas porque por el momento no son necesarias.
	- Se quitaron variables que no se estaban usando.
*/
