#include <stdio.h>

long long arr[4] = { 6, 420, 360360, 72201776446800 };

int main(void) {
    long long a, b, r = 0;
    scanf("%lld %lld", &a, &b);
    r += (b - (a - 1)) * 2;
    r += (b / 2 - (a - 1) / 2);
    for (int i = 0; i < 4; i++) {
        r += (b / arr[i] - (a - 1) / arr[i]);
        r -= (b / (arr[i] * 2) - (a - 1) / (arr[i] * 2));
    }
    printf("%lld", r);
    return 0;
}