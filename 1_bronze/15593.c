#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int lg[128][2], time[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("lifeguards.in", "r");
        fo = fopen("lifeguards.out", "w");
    }
    int n, max = 0, t, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lg[i][0], &lg[i][1]);
        for (int j = lg[i][0]; j < lg[i][1]; j++) {
            time[j]++;
        }
    }
    for (int i = 0; i < 1000; i++) max += !!time[i];
    for (int i = 0; i < n; i++) {
        t = max;
        for (int j = lg[i][0]; j < lg[i][1]; j++) {
            if (time[j] == 1) t--;
        }
        if (t > best) best = t;
    }
    printf("%d", best);
    return 0;
}