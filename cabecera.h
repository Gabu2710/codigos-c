

#ifndef CUENTA_AHORROS_H
#define CUENTA_AHORROS_H

typedef struct {
    double saldo;
    double tasa_interes_anual;
} CuentaAhorros;

void inicializar_cuenta(CuentaAhorros *cuenta, double saldo_inicial, double tasa_interes_anual);
void depositar(CuentaAhorros *cuenta, double monto);
void calcular_interes(CuentaAhorros *cuenta, int num_meses);
void mostrar_saldo_final(CuentaAhorros *cuenta);

#endif // CUENTA_AHORROS_H
