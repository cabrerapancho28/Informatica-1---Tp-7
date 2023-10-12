#include <stdio.h>
#include <math.h>


int main(){
	
	FILE *ptrCf;
	double valor, suma = 0, cuadrados = 0;
	
	if( (ptrCf = fopen("valores.dataa","r")) ==  0)
	{
		printf("Error!");
		return -1;
	}
	else {
	for ( int i = 0; i < 20; i++) {
	     if (fscanf(ptrCf, "%lf", &valor) == 1) {
			suma =  suma +  valor;
			cuadrados = cuadrados + valor * valor;
			}
		}
	
	}
	
	fclose(ptrCf);
	
	
	double promedio = suma / 20;
	double error_cuadratico_medio = sqrt(cuadrados / 20 - promedio * promedio);
	
	printf("Promedio: %lf\n", promedio);
	printf("Valor Cuadrático Medio de Error: %lf\n", error_cuadratico_medio);
	
	return 0;
	
}
	
	
