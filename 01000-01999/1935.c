#include <stdio.h>
#include <ctype.h>

char s[128];
int a[32];
double t[128];
int p = 0;

int main(void) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) {
            t[p++] = a[s[i] - 'A'];
        }
        else {
            p--;
            if (s[i] == '+') t[p - 1] = t[p - 1] + t[p];
            else if (s[i] == '*') t[p - 1] = t[p - 1] * t[p];
            else if (s[i] == '-') t[p - 1] = t[p - 1] - t[p];
            else if (s[i] == '/') t[p - 1] = t[p - 1] / t[p];
        }
    }
    printf("%.2f", t[0] + 1E-9);
    return 0;
}