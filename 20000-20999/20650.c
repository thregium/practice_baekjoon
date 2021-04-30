#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 자연수 A, B, C(A + B + C <= 10^9, A <= B, B <= C)에 대해 A, B, C, A + B, A + C, B + C, A + B + C가 무작위 순서로 섞여있을 때,
A, B, C를 순서대로 출력한다.

해결 방법 : 주어진 7개의 수를 정렬한다. 그러면 가장 큰 수는 A + B + C이고, 가장 작은 두 수는 A, B가 된다.(A에 C를 더하면 B <= C이므로 B보다 커지기 때문에)
따라서, 가장 작은 2 수와 가장 큰 수에서 앞의 두 수를 뺀 것을 출력하면 된다.

주요 알고리즘 : 수학, 정렬

출처 : USACO 2020D B1번
*/

int a[7];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("f.in", "r");
        fo = fopen("f.out", "w");
    }
    for (int i = 0; i < 7; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, 7, sizeof(int), cmp1);
    printf("%d %d %d", a[0], a[1], a[6] - a[0] - a[1]);
    return 0;
}