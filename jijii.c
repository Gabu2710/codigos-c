#include <stdio.h>
#include <math.h>

int main() {
  // Declaración de variables
  float montoPrestamo, tasaInteresAnual, pagoMensual, saldoPendiente;
  int plazoPrestamo, mes;

  // Ingreso de datos por teclado
  printf("Bienvenido al simulador de crédito\n\n");

  printf("Ingrese el monto del préstamo: ");
  scanf("%f", &montoPrestamo);

  printf("Ingrese la tasa de interés anual (en decimal): ");
  scanf("%f", &tasaInteresAnual);

  printf("Ingrese el plazo del préstamo (en meses): ");
  scanf("%d", &plazoPrestamo);

  // Validación de datos (opcional)
  if (montoPrestamo <= 0 || tasaInteresAnual <= 0 || plazoPrestamo <= 0) {
    printf("Error: Los datos ingresados no son válidos.\n");
    return 1;
  }

  // Cálculo de la tasa de interés mensual
  float tasaInteresMensual = tasaInteresAnual / 1200;

  // Cálculo del pago mensual
  pagoMensual = montoPrestamo * tasaInteresMensual * (pow(1 + tasaInteresMensual, plazoPrestamo) / (pow(1 + tasaInteresMensual, plazoPrestamo) - 1));

  // Impresión de la tabla de resultados
  printf("\nMes | Interes | Cuota | Saldo\n");
  printf("---|---|---|---|");

  for (mes = 1; mes <= plazoPrestamo; mes++) {
    // Cálculo del interés mensual
    float interesMensual = saldoPendiente * tasaInteresMensual;

    // Cálculo del saldo pendiente
    saldoPendiente = saldoPendiente - (pagoMensual - interesMensual);

    // Impresión de la fila correspondiente al mes actual
    printf("\n%d | %.2f | %.2f | %.2f\n", mes, interesMensual, pagoMensual, saldoPendiente);
  }

  return 0;
}