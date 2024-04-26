#include <stdio.h>
#include <math.h>

int main() {
    float monto, tasa_interes, interes, total_pagar, interes_acumulado = 0, total_acumulado = 0;
    int tiempo_meses, mes;

    // Entrada de datos
    printf("Ingrese el monto del préstamo: ");
    scanf("%f", &monto);
    printf("Ingrese la tasa de interés mensual (en porcentaje): ");
    scanf("%f", &tasa_interes);
    printf("Ingrese el tiempo en meses: ");
    scanf("%d", &tiempo_meses);

    // Encabezado de la tabla
    printf("\n|  Mes  |  Interés  |  Total a Pagar  |\n");

    // Cálculo del interés compuesto mensualmente y presentación en forma de tabla acumulativa por año
    for (mes = 1; mes <= tiempo_meses; mes++) {
        interes = monto * (tasa_interes / 100);
        total_pagar = monto + interes;
        interes_acumulado += interes;
        total_acumulado += total_pagar;

        // Si ha pasado un año, mostrar los resultados acumulados
        if (mes % 12 == 0 || mes == tiempo_meses) {
            printf("| %5d | %10.2f | %16.2f |\n", mes / 12, interes_acumulado, total_acumulado);
            interes_acumulado = 0;
            total_acumulado = 0;
        }

        // Actualizar el monto para el próximo mes
        monto = total_pagar;
    }

    return 0;
}
