#include <stdio.h>

int div(int n, int r, int c) {
    if (n == 0) return 0;
    if (r < (1 << (n - 1))) {
        if (c < (1 << (n - 1))) {
            return div(n - 1, r, c);
        }
        else {
            return (1 << ((n - 1) * 2)) + div(n - 1, r, c - (1 << (n - 1)));
        }
    }
    else {
        if (c < (1 << (n - 1))) {
            return (1 << ((n - 1) * 2)) * 2 + div(n - 1, r - (1 << (n - 1)), c);
        }
        else {
            return (1 << ((n - 1) * 2)) * 3 + div(n - 1, r - (1 << (n - 1)), c - (1 << (n - 1)));
        }
    }
}

int main(void) {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", div(n, r, c));
    return 0;
}
