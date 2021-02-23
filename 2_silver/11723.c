#include <stdio.h>
#include <string.h>

int main(void) {
    int x, m, s = 0;
    char o[8];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", o);
        if (!strcmp(o, "add")) {
            scanf("%d", &x);
            if ((s >> (x - 1)) % 2 == 0) {
                s += (1 << (x - 1));
            }
        }
        if (!strcmp(o, "remove")) {
            scanf("%d", &x);
            if ((s >> (x - 1)) % 2 == 1) {
                s -= (1 << (x - 1));
            }
        }
        if (!strcmp(o, "check")) {
            scanf("%d", &x);
            printf("%d\n", (s >> (x - 1)) % 2 == 1);
        }
        if (!strcmp(o, "toggle")) {
            scanf("%d", &x);
            if ((s >> (x - 1)) % 2 == 1) {
                s -= (1 << (x - 1));
            }
            else {
                s += (1 << (x - 1));
            }
        }
        if (!strcmp(o, "all")) {
            s = (1 << 20) - 1;
        }
        if (!strcmp(o, "empty")) {
            s = 0;
        }
    }
    return 0;
}