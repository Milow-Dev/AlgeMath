	#include <iostream>
	using namespace std;
	
	
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
	
	void matriz3x3()
	{
	}