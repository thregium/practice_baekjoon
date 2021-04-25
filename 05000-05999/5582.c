#include <stdio.h>

char a[4096], b[4096];
int mem[4096][4096];

int main(void) {
    int r = 0;
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1; a[i]; i++) {
        for (int j = 1; b[j]; j++) {
            if (a[i] == b[j]) {
                mem[i][j] = mem[i - 1][j - 1] + 1;
                if (mem[i][j] > r) r = mem[i][j];
            }
            else mem[i][j] = 0;
        }
    }
    printf("%d", r);
    return 0;
}