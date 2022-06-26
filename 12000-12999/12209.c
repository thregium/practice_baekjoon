#include <stdio.h>
#include <string.h>

long long area[32][32];
char buff[8];

int main(void) {
    long long t, n, l, ln;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld %s", &n, buff);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &area[i][j]);
            }
        }
        if (!strcmp(buff, "up")) {
            for (int i = 0; i < n; i++) {
                l = 0, ln = 0;
                for (int j = 0; j < n; j++) {
                    if (area[j][i] && ln == 0) ln = area[j][i];
                    else if (ln > 0 && area[j][i] == ln) {
                        area[l++][i] = ln * 2;
                        ln = 0;
                    }
                    else if (area[j][i]) {
                        area[l++][i] = ln;
                        ln = area[j][i];
                    }
                }
                area[l++][i] = ln;
                while (l < n) area[l++][i] = 0;
            }
        }
        else if (!strcmp(buff, "left")) {
            for (int i = 0; i < n; i++) {
                l = 0, ln = 0;
                for (int j = 0; j < n; j++) {
                    if (area[i][j] && ln == 0) ln = area[i][j];
                    else if (ln > 0 && area[i][j] == ln) {
                        area[i][l++] = ln * 2;
                        ln = 0;
                    }
                    else if (area[i][j]) {
                        area[i][l++] = ln;
                        ln = area[i][j];
                    }
                }
                area[i][l++] = ln;
                while (l < n) area[i][l++] = 0;
            }
        }
        else if (!strcmp(buff, "down")) {
            for (int i = 0; i < n; i++) {
                l = n - 1, ln = 0;
                for (int j = n - 1; j >= 0; j--) {
                    if (area[j][i] && ln == 0) ln = area[j][i];
                    else if (ln > 0 && area[j][i] == ln) {
                        area[l--][i] = ln * 2;
                        ln = 0;
                    }
                    else if (area[j][i]) {
                        area[l--][i] = ln;
                        ln = area[j][i];
                    }
                }
                area[l--][i] = ln;
                while (l >= 0) area[l--][i] = 0;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                l = n - 1, ln = 0;
                for (int j = n - 1; j >= 0; j--) {
                    if (area[i][j] && ln == 0) ln = area[i][j];
                    else if (ln > 0 && area[i][j] == ln) {
                        area[i][l--] = ln * 2;
                        ln = 0;
                    }
                    else if (area[i][j]) {
                        area[i][l--] = ln;
                        ln = area[i][j];
                    }
                }
                area[i][l--] = ln;
                while (l >= 0) area[i][l--] = 0;
            }
        }

        printf("Case #%d:\n", tt);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%lld ", area[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}