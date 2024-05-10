#include <stdio.h>
#include "cabecera.h"

int main() {
    CuentaAhorros cuenta;
    double saldo_inicial, tasa_interes_anual;
    int num_anios;

    printf("Ingrese el saldo inicial de la cuenta: ");
    scanf("%lf", &saldo_inicial);

    printf("Ingrese la tasa de interes anual (en porcentaje): ");
    scanf("%lf", &tasa_interes_anual);

    printf("Ingrese el número de meses que el dinero estara en la cuenta: ");
    scanf("%d", &num_anios);

    inicializar_cuenta(&cuenta, saldo_inicial, tasa_interes_anual);
    depositar(&cuenta, saldo_inicial); 

    calcular_interes(&cuenta, num_anios);
    mostrar_saldo_final(&cuenta);

    return 0;
}
