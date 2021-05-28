#include <stdio.h>

int main(void) {
    int n, w, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w);
        s += w;
    }
    if (s % 3) printf("no");
    else printf("yes");
    return 0;
}