#include <stdio.h>

int main() {
  float monto_prestamo;
  float tasa_interes_anual;
  float tiempo_prestamo_anios;

  printf("Ingrese el monto del préstamo: ");
  scanf("%f", &monto_prestamo);

  printf("Ingrese la tasa de interés anual (en %): ");
  scanf("%f", &tasa_interes_anual);

  printf("Ingrese el tiempo del préstamo (en años): ");
  scanf("%f", &tiempo_prestamo_anios);

 
  float tasa_interes_mensual = tasa_interes_anual / 1200;
  int numero_pagos = tiempo_prestamo_anios * 12;
  float pago_mensual = monto_prestamo * (tasa_interes_mensual * pow(1 + tasa_interes_mensual, numero_pagos)) / (pow(1 + tasa_interes_mensual, numero_pagos) - 1);


  printf("\nTabla de amortización:\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("| Año | Interés pagado | Pago capital | Saldo pendiente |\n");
  printf("--------------------------------------------------------------------------------\n");

  float saldo_pendiente = monto_prestamo;
  float interes_pagado_total = 0;

  for (int anio = 1; anio <= tiempo_prestamo_anios; anio++) {
    float interes_pagado_mensual = saldo_pendiente * tasa_interes_mensual;
    float pago_capital_mensual = pago_mensual - interes_pagado_mensual;
    saldo_pendiente -= pago_capital_mensual;

    float interes_pagado_anual = interes_pagado_mensual * 12;
    float pago_capital_anual = pago_capital_mensual * 12;

    interes_pagado_total += interes_pagado_anual;

    printf("| %d | %.2f | %.2f | %.2f |\n", anio, interes_pagado_anual, pago_capital_anual, saldo_pendiente);
  }

  printf("--------------------------------------------------------------------------------\n");
  printf("Total intereses pagados: %.2f\n", interes_pagado_total);

  return 0;
}
