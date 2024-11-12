	#include <iostream>
	using namespace std;
	
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
	
		void matriz2x2_print(char vars[2], float coefs[2], float cons)
	{
	    cout << "       | ";
	    compX(coefs[0]);
	    cout << vars[0];
	    compY(coefs[1]);
	    cout << vars[1] << " = " << cons << endl;
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