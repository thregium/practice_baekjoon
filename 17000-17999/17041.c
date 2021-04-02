#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char buff[8];
int road[128][3];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("traffic.in", "r");
        fo = fopen("traffic.out", "w");
    }
    int n, l, h;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", buff, &road[i][1], &road[i][2]);
        if (!strcmp(buff, "on")) {
            road[i][0] = 1;
        }
        else if (!strcmp(buff, "off")) {
            road[i][0] = -1;
        }
    }
    l = 0;
    h = 103000;
    for (int i = n - 1; i >= 0; i--) {
        if (road[i][0] > 0) {
            l -= road[i][2];
            h -= road[i][1];
            if (l < 0) l = 0;
        }
        else if (road[i][0] < 0) {
            l += road[i][1];
            h += road[i][2];
        }
        else {
            if (road[i][1] > l) l = road[i][1];
            if (road[i][2] < h) h = road[i][2];
        }
    }
    printf("%d %d\n", l, h);
    l = 0;
    h = 103000;
    for (int i = 0; i < n; i++) {
        if (road[i][0] > 0) {
            l += road[i][1];
            h += road[i][2];
        }
        else if (road[i][0] < 0) {
            l -= road[i][2];
            h -= road[i][1];
            if (l < 0) l = 0;
        }
        else {
            if (road[i][1] > l) l = road[i][1];
            if (road[i][2] < h) h = road[i][2];
        }
    }
    printf("%d %d", l, h);
    return 0;
}