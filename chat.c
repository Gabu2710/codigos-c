#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  float p1x, p1y, p2x, p2y, p3x, p3y;
  float a, b, c, h1, b1, as;

  printf("Ingrese los componentes del punto 1 (x,y): ");
  scanf("%f %f", &p1x, &p1y);

  printf("Ingrese los componentes del punto 2 (x,y): ");
  scanf("%f %f", &p2x, &p2y);

  printf("Ingrese los componentes del punto 3 (x,y): ");
  scanf("%f %f", &p3x, &p3y);

  a = sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
  b = sqrt(pow(p3x - p2x, 2) + pow(p3y - p2y, 2));
  c = sqrt(pow(p3x - p1x, 2) + pow(p3y - p1y, 2));

  printf("La distancia de todos los puntos es: %.2f, %.2f, %.2f\n", a, b, c);

  // Cálculo del semiperímetro
  float s = (a + b + c) / 2.0;

  // Cálculo del área usando la fórmula de Herón
  as = sqrt(s * (s - a) * (s - b) * (s - c));

  printf("El área del triángulo es: %.2f\n", as);

  b1 = (a * b) / c;
  printf("El punto b1 es: %.2f\n", b1);

  return 0;
}
