#include<iostream>
using namespace std;

void titulo(); void titulo_matriz(); void titulo_matriz2();
void matriz2x2();
void compX(float coefX); void compY(float coefY);
void dialogoMatriz(int numText);
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
	cout << endl << marco << "	:: AlgeMath v 0.4 (alpha) - Por: Camilo Cruz  ::\n"<< marco << endl;
}

int menu(){
	int opc;
	cout << "	:: Ingrese la actividad que desea ingresar\n"<< endl ;
	cout << "	:: 1. Matrices 2x2\n	:: 2. Matrices 3x3\n"<< endl <<"	[]: ";
	cin >> opc;
	return opc;
}

void titulo_matriz(){
	system("cls");
	titulo();
	cout << "\n	:: Arma tu matriz!\n\n	   | ";
}

void titulo_matriz2(){
	system("cls");
	titulo();
	cout << "\n	:: Excelente, ahora crea la segunda matriz!!\n\n";
}

void matriz2x2(){ // [][]+/-[][]=[]
char varX,varY;
float coefX,coefY,cons; float coefX2,coefY2,cons2;
	
	titulo_matriz(); dialogoMatriz(5);
		dialogoMatriz(0); cin >> coefX;
		
	titulo_matriz(); compX(coefX); cout << "[]+/-[][] = []\n" << endl;
		dialogoMatriz(1); cin >> varX;

	titulo_matriz(); compX(coefX); cout << varX << "+/-[][] = []\n" << endl;
		dialogoMatriz(2); cin >> coefY;

	titulo_matriz(); compX(coefX); cout << varX; compY(coefY); cout << "[] = []\n" << endl;
		dialogoMatriz(3); cin >> varY;

	titulo_matriz(); compX(coefX); cout << varX; compY(coefY); cout << varY << " = []\n" << endl;
		dialogoMatriz(4); cin >> cons;

	titulo_matriz2(); matriz2x2_print(varX, coefX, varY, coefY, cons);
		cout << "	   | "; dialogoMatriz(5);
			dialogoMatriz(0); cin >> coefX2;

	titulo_matriz2(); matriz2x2_print(varX, coefX, varY, coefY, cons);	
		cout << "	   | "; compX(coefX2); cout << varX << "+/-[][] = []\n" << endl;
			dialogoMatriz(2); cin >> coefY2;
			
	titulo_matriz2(); matriz2x2_print(varX, coefX, varY, coefY, cons);	
		cout << "	   | "; compX(coefX2); cout << varX; compY(coefY2); cout << varY << " = []\n" << endl;
			dialogoMatriz(4); cin >> cons2;

	matriz2x2_math(varX, varY, coefX, coefY, cons, coefX2, coefY2, cons2);

}

void compX(float coefX){
	
	if (coefX<0){ // Imprime el valor de X //
		cout << "-";
		if(coefX != 1 && coefX != -1 && coefX != 0){
			cout << abs(coefX);}
	} else{
		if(coefX != 1 && coefX != -1 && coefX != 0){
			cout << abs(coefX);}
	}
}

void compY(float coefY){
	
	if(coefY>=0){ // Imprime el valor de Y //
		cout<<"+";
		if(coefY != 1 && coefY != -1 && coefY != 0){
			cout << abs(coefY);}
	} else{
		cout << "-";
		if(coefY != 1 && coefY != -1 && coefY != 0){
			cout << abs(coefY);}
	}
}


void dialogoMatriz(int numText){
	
	static const string DialogosMatriz[]{
	"\n	:: Ingresa el valor que tendra la primera variable: ", // 0
	"\n	:: Asigna una letra para la primera variable: ", 	   // 1
	"\n	:: Ingresa el valor que tendra la segunda variable: ", // 2
	"\n	:: Ahora, asignale una letra a la segunda variable: ", // 3
	"\n	:: Ingresa el valor que llevara la constante: ", 	   // 4
	"[][]+/-[][] = []\n\n",									   // 5
	};
	
	cout << DialogosMatriz[numText];
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
	
	cout << "	   | ";
	
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

/* Changelog v0.4: // 24/09/2024
	- Ahora el usuario puede digitar las variables y sus valores.
	- Se mejoraron los dialogos para que sean más entendibles para el usuario.
	- Se optimización a la hora de imprimir ecuaciones
	- Se quitaron variables que no se estaban usando.
*/
