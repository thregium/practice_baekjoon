#include <stdio.h>

int num[3], max[2][3], min[2][3];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        max[1][0] = big(max[0][0], max[0][1]) + num[0];
        max[1][1] = big(big(max[0][0], max[0][1]), max[0][2]) + num[1];
        max[1][2] = big(max[0][1], max[0][2]) + num[2];
        min[1][0] = small(min[0][0], min[0][1]) + num[0];
        min[1][1] = small(small(min[0][0], min[0][1]), min[0][2]) + num[1];
        min[1][2] = small(min[0][1], min[0][2]) + num[2];
        for (int j = 0; j < 3; j++) {
            max[0][j] = max[1][j];
            min[0][j] = min[1][j];
        }
    }
    x = big(big(max[0][0], max[0][1]), max[0][2]);
    m = small(small(min[0][0], min[0][1]), min[0][2]);
    printf("%d %d", x, m);
    return 0;
}