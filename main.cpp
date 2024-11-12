	#include <iostream>
	#include "dialogos.h"
	#include "operaciones.h"
	#include "matriz.h"
	
	using namespace std;
	
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
	
/* Changelog v0.7.4: // 08/11/2024
	- Se han distribuido distintas funciones en varios archivos
	para organizar el programa.
*/