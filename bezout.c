#include <stdio.h>

int main() {
    int a, b, c, r, a1, b1, d;
    int x1 = 1, x2 = 0, y1 = 0, y2 = 1, q, x, y;

    printf("Donner a : ");
    scanf("%d", &a);
    printf("Donner b : ");
    scanf("%d", &b);

    a1 = a;
    b1 = b;

    printf("\n=== Calcul du PGCD ===\n");
    while (b1 != 0) {
        q = a1 / b1;
        r = a1 % b1;
        printf("%d = %d * %d + %d\n", a1, b1, q, r);

        a1 = b1;
        b1 = r;

        int tx = x1 - q * x2;
        x1 = x2;
        x2 = tx;

        int ty = y1 - q * y2;
        y1 = y2;
        y2 = ty;
    }

    d = a1;
    x = x1;
    y = y1;

    printf("\nPGCD(%d, %d) = %d\n", a, b, d);
    printf("Bezout : %d*(%d) + %d*(%d) = %d\n", a, x, b, y, a*x + b*y);

    if (d == 1)
        printf("Les deux nombres sont premiers entre eux.\n");

    printf("\nDonner c : ");
    scanf("%d", &c);

    if (c % d != 0)
        printf("Pas de solution entiere.\n");
    else {
        int k = c / d;
        int xp = x * k, yp = y * k;
        printf("Solution particulière : x = %d, y = %d\n", xp, yp);
        printf("Solution générale : x = %d + %d*k, y = %d - %d*k\n", xp, b/d, yp, a/d);
    }

    return 0;
}
