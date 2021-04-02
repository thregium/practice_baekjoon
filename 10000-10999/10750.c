#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char s[1048576], t[128], st[1048576];
int top = 0;

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("censor.in", "r");
        fo = fopen("censor.out", "w");
    }
    scanf("%s%s", s, t);
    int sl = strlen(s), tl = strlen(t);
    for (int i = 0; i < sl; i++) {
        st[top++] = s[i];
        if (top >= tl) {
            if (!strcmp(&st[top - tl], t)) {
                top -= tl;
                for (int j = top; j < top + tl; j++) {
                    st[j] = '\0';
                }
            }
        }
    }
    printf("%s", st);
    return 0;
}