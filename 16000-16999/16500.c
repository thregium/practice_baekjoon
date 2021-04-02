#include <stdio.h>
#include <string.h>

char s[128], a[128][128], mem[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, rt;
    scanf("%s", s);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    mem[0] = 1;
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; mem[i] == 1 && j < n; j++) {
            rt = 1;
            for (int k = i; k < small(strlen(s), i + strlen(a[j])); k++) {
                if (s[k] != a[j][k - i]) {
                    rt = 0;
                    break;
                }
            }
            if (rt) {
                mem[i + strlen(a[j])] = 1;
            }
        }
    }
    printf("%d", mem[strlen(s)]);
    return 0;
}