#include <stdio.h>
#include <math.h>

int main() {
	FILE *archivo_entrada, *archivo_salida;
	double x, y, h;
	int i, n;
	
	n = 81;
	h = 8 * M_PI / (n - 1);
	
	archivo_entrada = fopen("valores.txt", "w");
	if (archivo_entrada == NULL) {
		printf("No se pudo abrir el archivo de entrada.\n");
		return 1;
	}
	
	for (i = 0; i < n; i++) {
		x = i * h;
		y = sin(4 * x);
		fprintf(archivo_entrada, "%lf %lf\n", x, y);
	}
	
	fclose(archivo_entrada);
	
	archivo_entrada = fopen("valores.txt", "r");
	archivo_salida = fopen("derivadas.txt", "w");
	
	if (archivo_entrada == NULL || archivo_salida == NULL) {
		printf("No se pudieron abrir los archivos de entrada o salida.\n");
		return 1;
	}
	
	double x_prev, y_prev, derivada;
	fscanf(archivo_entrada, "%lf %lf", &x_prev, &y_prev);
	
	for (i = 1; i < n; i++) {
		fscanf(archivo_entrada, "%lf %lf", &x, &y);
		derivada = (y - y_prev) / (x - x_prev);
		fprintf(archivo_salida, "%lf %lf\n", x, derivada);
		x_prev = x;
		y_prev = y;
	}
	
	fclose(archivo_entrada);
	fclose(archivo_salida);
	
	printf("Archivos generados con éxito: valores.txt y derivadas.txt\n");
	
	return 0;
}
