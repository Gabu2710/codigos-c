

#include <stdio.h>
#include "cabecera.h"

void inicializar_cuenta(CuentaAhorros *cuenta, double saldo_inicial, double tasa_interes_anual) {
    cuenta->saldo = saldo_inicial;
    cuenta->tasa_interes_anual = tasa_interes_anual;
}

void depositar(CuentaAhorros *cuenta, double monto) {
    cuenta->saldo += monto;
}

void calcular_interes(CuentaAhorros *cuenta, int num_meses) {
    double tasa_interes_mensual = cuenta->tasa_interes_anual / 12.0 / 100.0;

    for (int i = 0; i < num_meses; i++) {
        double interes_mensual = cuenta->saldo * tasa_interes_mensual;
        cuenta->saldo += interes_mensual;
        printf("Mes %d - Interés Ganado: %.2f - Saldo Total: %.2f\n", i + 1, interes_mensual, cuenta->saldo);
    }
}

void mostrar_saldo_final(CuentaAhorros *cuenta) {
    printf("Saldo final: %.2f\n", cuenta->saldo);
}
