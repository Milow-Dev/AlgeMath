	#include <iostream>
	using namespace std;
	
	const string ver = "0.7.4 (alpha)";
	
	void titulo()
	{
	    system("cls"); system("color 0B");
	    string marco = "    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	    cout << endl << marco << "    :: AlgeMath v " << ver << " - Por: Camilo Cruz - Nicolas Segura	::\n"<< marco << endl;
	}
	
	int menu()
	{
	    int opc;
	    cout << "    :: Ingrese la actividad que desea ingresar\n"<< endl ;
	    cout << "    :: 1. Calculadora de matrices\n    :: 2. Que es una matriz?\n\n    :: 3. Salir\n"<< endl <<"    []: ";
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