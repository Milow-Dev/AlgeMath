	#include<iostream>
	using namespace std;
	
	int menu				();
	void titulo				();
	void titulo_matriz		();
	void titulo_matriz2		();
	void matriz2x2			();
	void compX				(float coefX);
	void compY				(float coefY);
	void dialogoMatriz		(int numText);
	void matriz2x2_print	(char vars[2], float coefs[2],		float cons);
	void matriz2x2_math		(char vars[2], float coefs[2][2],	float cons[2]);
	void matriz3x3			();
	void simpFrac			(int &numd, int &denm);
	int mcd					(int a,		int b);
	
	const string ver = "0.6.2 (alpha)";
	
	int main()
	{
	    int opc;
	    do{
	        titulo();
	        opc = menu();
	        switch(opc){
	            case 1:
	                matriz2x2();
	                break;
	            case 2:
	                system("pause");
	                break;
	        }
	    }while(opc!=3);
	    return 0;
	}
	
	void titulo()
	{
	    system("cls"); system("color 0B");
	    string marco = "    ::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	    cout << endl << marco << "    :: AlgeMath v " << ver << " - Por: Camilo Cruz  ::\n"<< marco << endl;
	}
	
	int menu()
	{
	    int opc;
	    cout << "    :: Ingrese la actividad que desea ingresar\n"<< endl ;
	    cout << "    :: 1. Matrices 2x2\n    :: 2. Matrices 3x3 (vacio)\n\n    :: 3. Salir\n"<< endl <<"    []: ";
	    cin >> opc;
	    return opc;
	}
	
	void titulo_matriz()
	{
	    system("cls"); titulo();
	    cout << "\n    :: Arma tu matriz!\n\n       | ";
	}
	
	void titulo_matriz2()
	{
	    system("cls"); titulo();
	    cout << "\n    :: Excelente, ahora crea la segunda matriz!!\n\n";
	}
	
	void matriz2x2()
	{
	    char vars[2];
	    float coefs[2][2], cons[2];
	    
	    titulo_matriz(); dialogoMatriz(5);
	    dialogoMatriz(0); cin >> coefs[0][0];
	    
	    titulo_matriz(); compX(coefs[0][0]); dialogoMatriz(6);
	    dialogoMatriz(1); cin >> vars[0];
	    
	    titulo_matriz(); compX(coefs[0][0]); cout << vars[0]; dialogoMatriz(7);
	    dialogoMatriz(2); cin >> coefs[0][1];
	    
	    titulo_matriz(); compX(coefs[0][0]); cout << vars[0]; compY(coefs[0][1]); dialogoMatriz(8);
	    dialogoMatriz(3); cin >> vars[1];
	    
	    titulo_matriz(); compX(coefs[0][0]); cout << vars[0]; compY(coefs[0][1]); cout << vars[1]; dialogoMatriz(9);
	    dialogoMatriz(4); cin >> cons[0];
	    
	    titulo_matriz2(); matriz2x2_print(vars, coefs[0], cons[0]);
	    cout << "       | "; dialogoMatriz(10); cout << vars[0]; dialogoMatriz(11); cout << vars[1]; dialogoMatriz(9);
	    dialogoMatriz(0); cin >> coefs[1][0];
	    
	    titulo_matriz2(); matriz2x2_print(vars, coefs[0], cons[0]);    
	    cout << "       | "; compX(coefs[1][0]); cout << vars[0]; dialogoMatriz(11); cout << vars[1]; dialogoMatriz(9);
	    dialogoMatriz(2); cin >> coefs[1][1];
	    
	    titulo_matriz2(); matriz2x2_print(vars, coefs[0], cons[0]);    
	    cout << "       | "; compX(coefs[1][0]); cout << vars[0]; compY(coefs[1][1]); cout << vars[1]; dialogoMatriz(9);
	    dialogoMatriz(4); cin >> cons[1];
	    
	    matriz2x2_math(vars, coefs, cons);
	}
	
	void compX(float coefX)
	{
	    if (coefX < 0) {
	        cout << "-";
	        if(coefX != 1 && coefX != -1 && coefX != 0) {
	            cout << abs(coefX);
	        }
	    } else {
	        if(coefX != 1 && coefX != -1 && coefX != 0) {
	            cout << abs(coefX);
	        }
	    }
	}
	
	void compY(float coefY)
	{        
	    if(coefY >= 0) {
	        cout << " + ";
	        if(coefY != 1 && coefY != -1 && coefY != 0) {
	            cout << abs(coefY);
	        }
	    } else {
	        cout << " - ";
	        if(coefY != 1 && coefY != -1 && coefY != 0) {
	            cout << abs(coefY);
	        }
	    }
	}
	
	void dialogoMatriz(int numText)
	{    
	    static const string DialogosMatriz[]{
	    "\n    :: Ingresa el valor que tendra la primera variable: ", // 0
	    "\n    :: Asigna una letra para la primera variable: ",       // 1
	    "\n    :: Ingresa el valor que tendra la segunda variable: ", // 2
	    "\n    :: Ahora, asignale una letra a la segunda variable: ", // 3
	    "\n    :: Ingresa el valor que llevara la constante: ",       // 4
	    "[][] +/- [][] = []\n\n",                                    // 5
	    "[] +/- [][] = []\n\n",                                      // 6
	    " +/- [][] = []\n\n",                                        // 7
	    "[] = []\n\n",                                               // 8
	    " = []\n\n",                                                 // 9
	    "[]",                                                        // 10
	    " +/- []",                                                   // 11
	    };
	    
	    cout << DialogosMatriz[numText];
	}
	
	int mcd(int a,int b)
	{ 
	    if(b == 0) return a;
	    return mcd(b, a % b);
	}
	
	void simpFrac(float &numd, float &denm)
	{
	    float divCom = mcd(abs(numd), abs(denm));
	    numd /= divCom; denm /= divCom;
	}
	
	void matriz2x2_math(char vars[2], float coefs[2][2], float cons[2])
	{
	    float detA, detX, detY, numdX, numdY, denmX, denmY;
	    float x, y;
	
	    detA = ((coefs[0][0] * coefs[1][1]) - (coefs[1][0] * coefs[0][1]));
	    detX = ((cons [0] 	 * coefs[1][1]) - (cons [1]	   * coefs[0][1]));
	    detY = ((coefs[0][0] * cons [1]   ) - (coefs[1][0] * cons [0]   ));
	
	    numdX	= detX; denmX	= detA;
		numdY	= detY; denmY	= detA;
	    x		= detX / detA;
		y 		= detY / detA;
	
	    simpFrac(numdX, denmX);
	    simpFrac(numdY, denmY);
	
	    titulo();
	    matriz2x2_print(vars, coefs[0], cons[0]);
	    matriz2x2_print(vars, coefs[1], cons[1]);
	
	    cout << "\n    :: Det A: "	<< detA  << endl;
	    cout << "    :: Det X: "	<< detX  << endl;
	    cout << "    :: Det Y: "	<< detY  << endl << endl;
	    cout << "    :: X: "		<< numdX << "/"  << denmX << "    =    " << x << endl;
	    cout << "    :: Y: "		<< numdY << "/"  << denmY << "    =    " << y << endl << endl;
	
	    cout << "    :: "; system("pause");
	}
	
	void matriz2x2_print(char vars[2], float coefs[2], float cons)
	{
	    cout << "       | ";
	    compX(coefs[0]);
	    cout << vars[0];
	    compY(coefs[1]);
	    cout << vars[1] << " = " << cons << endl;
	}
	
	void matriz3x3()
	{
	}

/* Changelog v0.6.2: // 08/11/2024
	- Se ha optimizado el código, ahora las variables
	y los coeficientes se manejan en un arreglo.
	- Se ha mejorado la legibilidad del codigo.
	- Se han cambiado detalles esteticos.
*/
