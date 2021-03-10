#include <stdio.h>
#include <math.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int xy[128][2];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("triangles.in", "r");
        fo = fopen("triangles.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xy[i][0], &xy[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (xy[i][0] == xy[j][0] && xy[i][1] == xy[k][1]) {
                    if (abs((xy[j][1] - xy[i][1]) * (xy[k][0] - xy[i][0])) > r) r = abs((xy[j][1] - xy[i][1]) * (xy[k][0] - xy[i][0]));
                }
                if (xy[i][0] == xy[k][0] && xy[i][1] == xy[j][1]) {
                    if (abs((xy[k][1] - xy[i][1]) * (xy[j][0] - xy[i][0])) > r) r = abs((xy[k][1] - xy[i][1]) * (xy[j][0] - xy[i][0]));
                }
                if (xy[i][0] == xy[j][0] && xy[j][1] == xy[k][1]) {
                    if (abs((xy[j][1] - xy[i][1]) * (xy[k][0] - xy[j][0])) > r) r = abs((xy[j][1] - xy[i][1]) * (xy[k][0] - xy[j][0]));
                }
                if (xy[j][0] == xy[k][0] && xy[i][1] == xy[j][1]) {
                    if (abs((xy[k][1] - xy[j][1]) * (xy[j][0] - xy[i][0])) > r) r = abs((xy[k][1] - xy[j][1]) * (xy[j][0] - xy[i][0]));
                }
                if (xy[i][0] == xy[k][0] && xy[j][1] == xy[k][1]) {
                    if (abs((xy[k][1] - xy[i][1]) * (xy[k][0] - xy[j][0])) > r) r = abs((xy[k][1] - xy[i][1]) * (xy[k][0] - xy[j][0]));
                }
                if (xy[j][0] == xy[k][0] && xy[i][1] == xy[k][1]) {
                    if (abs((xy[k][1] - xy[j][1]) * (xy[k][0] - xy[i][0])) > r) r = abs((xy[k][1] - xy[j][1]) * (xy[k][0] - xy[i][0]));
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}