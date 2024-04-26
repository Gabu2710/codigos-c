#include <stdio.h>
#include <math.h>

int main() {
    float p1x, p1y, p2x, p2y, p3x, p3y;
    float a, b, c, h1, b1, as, x, y, z;

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

    // Redondear los valores de a, b, c utilizando ceil
    a = ceil(a);
    b = ceil(b);
    c = ceil(c);

    if (c != 0) {
        h1 = (a * b) / c;
        printf("El punto b1 es: %.2f\n", h1);
    } else {
        printf("No se puede calcular b1 porque la distancia c es cero.\n");
        return 0;
    }

    // Revisión de lógica para determinar el triángulo rectángulo
    if (a > b && a > c) {
        z = a;
        x = b;
        y = c;
    } else if (b > a && b > c) {
        z = b;
        x = a;
        y = c;
    } else if (c > a && c > b) {
        z = c;
        x = b;
        y = a;
    }

    if (pow(z, 2) != pow(x, 2) + pow(y, 2)) {
        printf("No es un triángulo rectángulo.\n");
        return 0;
    }

    // Verificación de existencia de triángulo (desigualdad triangular)
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("No es un triángulo válido.\n");
        return 0;
    }

    b1 = sqrt(pow(x, 2) + pow(h1, 2));
    as = h1 * b1 / 2;
    printf("El área del triángulo es: %.2f\n", as);

    return 0;
}
