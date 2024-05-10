#include <stdio.h>

void calcular_cuotas() {
    // Declaración de variables
    float prestamo, interes_anual, interes_mensual, pago_sin_interes, pago_total_sin_interes, interes_total, pago_total_con_interes;
    int plazo_anios, num_pagos, i;

    // Pedir al usuario el monto del préstamo, la tasa de interés y el plazo en años
    printf("Ingrese el monto del préstamo: ");
    scanf("%f", &prestamo);
    printf("Ingrese la tasa de interés anual (%%): ");
    scanf("%f", &interes_anual);
    printf("Ingrese el plazo en años: ");
    scanf("%d", &plazo_anios);

    // Convertir la tasa de interés de porcentaje a decimal
    interes_mensual = interes_anual / 100 / 12;

    // Calcular el número total de pagos
    num_pagos = plazo_anios * 12;

    // Calcular el pago mensual sin intereses
    pago_sin_interes = prestamo / num_pagos;

    // Inicializar variables para cálculo del pago total sin intereses
    pago_total_sin_interes = prestamo;

    // Inicializar el interés total
    interes_total = 0;

    // Calcular el interés total
    for (i = 0; i < num_pagos; i++) {
        float interes_pago = pago_total_sin_interes * interes_mensual;
        interes_total += interes_pago;
        pago_total_sin_interes -= pago_sin_interes;
    }

    // Calcular el pago total incluyendo intereses
    pago_total_con_interes = prestamo + interes_total;

    // Imprimir resultados
    printf("Pago mensual sin intereses: %.2f\n", pago_sin_interes);
    printf("Interés total pagado: %.2f\n", interes_total);
    printf("Pago total con intereses: %.2f\n", pago_total_con_interes);
}

int main() {
    calcular_cuotas();
    return 0;
}
deded
