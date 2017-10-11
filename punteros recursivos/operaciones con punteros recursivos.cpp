#include <iostream>
using namespace std;

//funcion para iniciar las matrices (f=filas,c=columnas)
void iMatriz(int**matriz,int f,int c,int i=0){
	if(i==f){	
		return;
	}
	*(matriz+i)=new int[c];
	return iMatriz(matriz,f,c,i+1);
}

//funcion que da origen a la matriz en 0
void oMatriz(int**matriz,int f,int c,int i=0,int j=0){
	if(j==c){
		return oMatriz(matriz,f,c,i+1,0);
	}
	if(i==f){
		return;
	}
	*(*(matriz+i)+j)=0;
	return oMatriz(matriz,f,c,i,j+1);
}

//funcion para ingresar valores a las matrices
void valores(int**matriz,int f,int c,int i=0,int j=0){
	if(j==c){
		return valores(matriz,f,c,i+1,0);
	}
	if(i==f){
		return;
	}
	int valor;
	cin>>valor;
	*(*(matriz+i)+j)=valor;
	return valores(matriz,f,c,i,j+1);
}

//funcion para determinar entre dos matrices los elementos mayores en una matriz resultante

void mayorE(int**matrizA,int**matrizB,int**matrizC,int f,int c,int i=0,int j=0){
	if(j==c){
		return mayorE(matrizA,matrizB,matrizC,f,c,i+1,0);
	}
	if(i==f){
		return;
	}
	if(*(*(matrizA+i)+j) >= *(*(matrizB+i)+j)){
		*(*(matrizC+i)+j)=*(*(matrizA+i)+j);
	}
	if(*(*(matrizB+i)+j)>=*(*(matrizA+i)+j)){
		*(*(matrizC+i)+j)=*(*(matrizB+i)+j);
	}
	return mayorE(matrizA,matrizB,matrizC,f,c,i,j+1);
	
}

//funcion para determinar entre dos matrices los elementos menores en una matriz resultante
void menorE(int**matrizA,int**matrizB,int**matrizC,int f,int c,int i=0,int j=0){
	if(j==c){
		return menorE(matrizA,matrizB,matrizC,f,c,i+1,0);
	}
	if(i==f){
		return;
	}
	if(*(*(matrizA+i)+j) <= *(*(matrizB+i)+j)){
		*(*(matrizC+i)+j)=*(*(matrizA+i)+j);
	}
	if(*(*(matrizB+i)+j)<=*(*(matrizA+i)+j)){
		*(*(matrizC+i)+j)=*(*(matrizB+i)+j);
	}
	return menorE(matrizA,matrizB,matrizC,f,c,i,j+1);
	
}
//funcion para sacar el promedio de los elementos entre dos matrices
void promE(int**matrizA,int**matrizB,int**matrizC,int f,int c,int i=0,int j=0){
    if(j==c){
        return promE(matrizA,matrizB,matrizC,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(matrizC+i)+j)= (*(*(matrizA+i)+j) + *(*(matrizB+i)+j))/2;
    return promE(matrizA,matrizB,matrizC,f,c,i,j+1);
}
//Funcion que calcula la suma de los elementos entre dos matrices
void sumaE(int**matrizA,int**matrizB,int**matrizC,int f,int c,int i=0,int j=0){
    if(j==c){
        return sumaE(matrizA,matrizB,matrizC,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(matrizC+i)+j)= *(*(matrizA+i)+j) + *(*(matrizB+i)+j);
    return sumaE(matrizA,matrizB,matrizC,f,c,i,j+1);
}

//Funcion que calcula la resta de los elementos entre dos matrices
void restaE(int**matrizA,int**matrizB,int**matrizC,int f,int c,int i=0,int j=0){
    if(j==c){
        return sumaE(matrizA,matrizB,matrizC,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    *(*(matrizC+i)+j)= *(*(matrizA+i)+j) - *(*(matrizB+i)+j);
    return restaE(matrizA,matrizB,matrizC,f,c,i,j+1);
}
//Funcion que calcula la multiplicacion entre dos matrices
void multi(int**matrizA,int**matrizB,int**matrizC,int f1,int c1,int f2,int c2,int i=0,int j=0,int k=0){
    if(f2!=c1){
        cout<<"No se puede realizar la multiplicacion, ingresa denuevo tus datos"<<endl;
        return multi(matrizA,matrizB,matrizC,f1,c1,f2,c2,i,j+1,0);
    }
    if(k==f2){
        return multi(matrizA,matrizB,matrizC,f1,c1,f2,c2,i,j+1,0);
    }
    if(j==c2){
        return multi(matrizA,matrizB,matrizC,f1,c1,f2,c2,i+1,0,k);
    }
    if(i==f1){
        return;
    }
    *(*(matrizC+i)+j)=*(*(matrizC+i)+j)+(*(*(matrizA+i)+j) * *(*(matrizB+i)+j));
    return multi(matrizA,matrizB,matrizC,f1,c1,f2,c2,i,j,k+1);

}

//Funcion para imprimir matriz
void impMatriz(int**matriz,int f,int c,int i=0,int j=0){
    if(j==c){
        cout<<endl;
        return impMatriz(matriz,f,c,i+1,0);
    }
    if(i==f){
        return;
    }
    cout<<*(*(matriz+i)+j)<<" ";
    return impMatriz(matriz,f,c,i,j+1);
}
//funcion para eliminar los espacios de memoria de las matrices
void eliminarM(int**matriz,int f,int i=0){
	if(i==f){
		delete []matriz;
		return;
	}
	delete [] matriz[i];
	return eliminarM(matriz,f,i+1);
}

int main(){
	//ingreso las filas y columnas de las matrices
	int f1,c1,f2,c2;
 	cout<<"Ingresa el numero de filas de la matriz 1"<<endl;
    cin>>f1;
    cout<<"Ingresa el numero de columnas de la matriz 1"<<endl;
    cin>>c1;
    cout<<"Ingresa el numero de filas de la matriz 2"<<endl;
    cin>>f2;
    cout<<"Ingresa el numero de columnas de la matriz 2"<<endl;
    cin>>c2;
    
    //doy inicio a las matrices:
    int**matrizA= new int*[f1];
    int**matrizB= new int*[f2];
    
    iMatriz(matrizA,f1,c1);
    iMatriz(matrizB,f2,c2);
    
    //pido al usuario que  introdusca los elementos de las matrices:
    cout<<"Ingresa los elementos de la matriz 1"<<endl;
    valores(matrizA,f1,c1);
    cout<<"Ingresa los elementos de la matriz 2"<<endl;
    valores(matrizB,f2,c2);

    //Se selecciona la operacion
    cout<<"Selecciona la Operacion"<<endl;
    cout<<"1 --> Mayores Elementos"<<endl;
    cout<<"2 --> Menores Elementos"<<endl;
    cout<<"3 --> Promedio de los Elementos"<<endl;
    cout<<"4 --> Suma de Matrices"<<endl;
    cout<<"5 --> Resta de Matrices"<<endl;
    cout<<"6 --> Multiplicacion de Matrices"<<endl;
    
    void(*ptrOpcomparacion)(int**,int**,int**,int,int,int,int);
    void(*ptrMultiplicacion)(int**,int**,int**,int,int,int,int,int,int,int);
    int operacion=0;
    cin>>operacion;

    //se apunta a la funcion especificada
    if(operacion==1){
        ptrOpcomparacion=mayorE;
    }
    else if(operacion==2){
        ptrOpcomparacion=menorE;
    }
    else if(operacion==3){
        ptrOpcomparacion=promE;
    }
    else if(operacion==4){
        ptrOpcomparacion=sumaE;
    }
    else if(operacion==5){
        ptrOpcomparacion=restaE;
    }

    //compruebo que las matrices tengan el tamaño correcto para las operaciones de comparacion
    if(operacion!=6){
        if(f1!=f2 || c1!=c2){
            cout<<"Las matrices deben ser iguales.introdusca sus datos nuevamente"<<endl;
            eliminarM(matrizA,f1);
            eliminarM(matrizB,f2);
            return 0;
        }
        int**matrizC= new int*[c1];
        iMatriz(matrizC,f1,c1);
        ptrOpcomparacion(matrizA,matrizB,matrizC,f1,c1,0,0);
        impMatriz(matrizC,f1,c1);
        eliminarM(matrizC,f1);
    }


    //se realiza la multiplicacion teniendo en cuenta la restriccion antes ya dada
    if(operacion==6){
    	ptrMultiplicacion=multi;
        int**matrizC= new int*[c1];
        iMatriz(matrizC,f1,c2);
        oMatriz(matrizC,f1,c2);
        multi(matrizA,matrizB,matrizC,f1,c1,f2,c2);
        impMatriz(matrizC,f1,c2);
        eliminarM(matrizC,f1);
    }

    eliminarM(matrizA,f1);
    eliminarM(matrizB,f2);

	cin.get(); //se vea mas bonito :D
    return 0;

}
    
    

