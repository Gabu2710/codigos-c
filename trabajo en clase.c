#include <stdio.h>
#include <math.h>

// Función para calcular el área de un triángulo
float calcular_area_triangulo(float x1, float y1, float x2, float y2, float x3, float y3) {
    float area = fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
    return area;
}

// Función para verificar si un triángulo es rectángulo
int es_triangulo_rectangulo(float x1, float y1, float x2, float y2, float x3, float y3) {
    // Calcular los cuadrados de las longitudes de los lados
    float lado1_cuadrado = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    float lado2_cuadrado = pow((x3 - x2), 2) + pow((y3 - y2), 2);
    float lado3_cuadrado = pow((x3 - x1), 2) + pow((y3 - y1), 2);

    // Ordenar los lados de menor a mayor
    float lados_ordenados[3] = {lado1_cuadrado, lado2_cuadrado, lado3_cuadrado};
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (lados_ordenados[i] > lados_ordenados[j]) {
                float temp = lados_ordenados[i];
                lados_ordenados[i] = lados_ordenados[j];
                lados_ordenados[j] = temp;
            }
        }
    }

    // Verificar el teorema de Pitágoras
    if (fabs(lados_ordenados[0] + lados_ordenados[1] - lados_ordenados[2]) < 0.0001) {
        return 1; // Es un triángulo rectángulo
    } else {
        return 0; // No es un triángulo rectángulo
    }
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    float area;
    int es_rectangulo;

    // Entrada de coordenadas de los puntos del triángulo
    printf("Coordenadas del primer punto (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Coordenadas del segundo punto (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Coordenadas del tercer punto (x3 y3): ");
    scanf("%f %f", &x3, &y3);

    // Calcular el área del triángulo
    area = calcular_area_triangulo(x1, y1, x2, y2, x3, y3);
    printf("El área del triángulo es: %.2f\n", area);

    // Verificar si el triángulo es rectángulo
    es_rectangulo = es_triangulo_rectangulo(x1, y1, x2, y2, x3, y3);
    if (es_rectangulo) {
        printf("El triángulo es rectángulo.\n");
    } else {
        printf("El triángulo no es rectángulo.\n");
    }

    return 0;
}
