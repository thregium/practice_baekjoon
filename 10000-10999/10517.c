#include <stdio.h>

int main(void) {
    int n, x1, y1, x2, y2, x3, y3, l1, l2, l3;
    double d1, d2, c1, c2, rx, ry;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        l1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        l2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
        l3 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        if (l1 >= l2 + l3) {
            printf("Case #%d: %.2f %.2f\n", i, (x1 + x2) / 2.0, (y1 + y2) / 2.0);
        }
        else if (l2 >= l1 + l3) {
            printf("Case #%d: %.2f %.2f\n", i, (x2 + x3) / 2.0, (y2 + y3) / 2.0);
        }
        else if (l3 >= l1 + l2) {
            printf("Case #%d: %.2f %.2f\n", i, (x1 + x3) / 2.0, (y1 + y3) / 2.0);
        }
        else {
            if (y1 == y2) {
                d1 = -(double)(x3 - x2) / (double)(y3 - y2);
                c1 = (y3 + y2) / 2.0 - (x3 + x2) / 2.0 * d1;
                d2 = -(double)(x1 - x3) / (double)(y1 - y3);
                c2 = (y1 + y3) / 2.0 - (x1 + x3) / 2.0 * d2;
            }
            else if (y2 == y3) {
                d1 = -(double)(x2 - x1) / (double)(y2 - y1);
                c1 = (y2 + y1) / 2.0 - (x2 + x1) / 2.0 * d1;
                d2 = -(double)(x1 - x3) / (double)(y1 - y3);
                c2 = (y1 + y3) / 2.0 - (x1 + x3) / 2.0 * d2;
            }
            else {
                d1 = -(double)(x2 - x1) / (double)(y2 - y1);
                c1 = (y2 + y1) / 2.0 - (x2 + x1) / 2.0 * d1;
                d2 = -(double)(x3 - x2) / (double)(y3 - y2);
                c2 = (y3 + y2) / 2.0 - (x3 + x2) / 2.0 * d2;
            }
            rx = (c2 - c1) / (d1 - d2);
            ry = rx * d1 + c1;
            printf("Case #%d: %.2f %.2f\n", i, rx, ry);
        }
    }
    return 0;
}