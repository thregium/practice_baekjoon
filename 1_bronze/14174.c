#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

int ca[26];
char head[16], tail[16], ha[26], ta[26];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("blocks.in", "r");
        fo = fopen("blocks.out", "w");
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", head, tail);
        for (int j = 0; j < strlen(head); j++) {
            ha[head[j] - 'a']++;
        }
        for (int j = 0; j < strlen(tail); j++) {
            ta[tail[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            ca[j] += big(ha[j], ta[j]);
            ha[j] = 0;
            ta[j] = 0;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d\n", ca[i]);
    }
    return 0;
}