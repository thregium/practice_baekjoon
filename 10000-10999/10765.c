#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : B, E, S, I, G, O, M이라는 변수가 될 수 있는 수들이 각각 최대 20개까지 주어진다.
이때, (B+E+S+S+I+E)(G+O+E+S)(M+O+O)라는 식의 결과가 짝수가 되는 경우의 수를 구한다.

해결 방법 : 각각의 덧셈식이 전부 홀수가 되는 경우만 제외하면 결과는 짝수가 된다. 모든 경우의 수는
모든 변수의 가짓수를 곱한 것과 같다. 각각의 덧셈식을 살펴보면 첫 번째 식에서는 E와 S는 2개씩 있어 항상 짝수일 것이므로
B와 I의 합이 홀수이면 홀수가 된다. 두 번째에서는 모든 수의 합이 홀수이면 홀수가 되고, 마지막은 M이 홀수이면 홀수가 된다.
각각의 경우는 브루트 포스를 통해 경우의 수를 구하고, 각 경우를 곱한 것이 모두 홀수인 경우의 수가 된다.
전체 경우에서 홀수인 경우의 수를 빼면 짝수인 경우의 수가 될 것이다.

주요 알고리즘 : 수학, 조합론

출처 : USACO 2015O B2번
*/

int vari[7][32];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("geteven.in", "r");
        fo = fopen("geteven.out", "w");
    }
    int n, v, r = 1, m1 = 0, m2 = 0, m3 = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &v);
        if (c == 'B') vari[0][++vari[0][0]] = v;
        else if (c == 'E') vari[1][++vari[1][0]] = v;
        else if (c == 'S') vari[2][++vari[2][0]] = v;
        else if (c == 'I') vari[3][++vari[3][0]] = v;
        else if (c == 'G') vari[4][++vari[4][0]] = v;
        else if (c == 'O') vari[5][++vari[5][0]] = v;
        else if (c == 'M') vari[6][++vari[6][0]] = v;
        else return 1;
    }
    for (int i = 0; i < 7; i++) {
        r *= vari[i][0];
    }
    for (int i = 1; i <= vari[6][0]; i++) {
        if (vari[6][i] & 1) m1++;
    }
    for (int i = 1; i <= vari[1][0]; i++) {
        for (int j = 1; j <= vari[2][0]; j++) {
            for (int k = 1; k <= vari[4][0]; k++) {
                for (int l = 1; l <= vari[5][0]; l++) {
                    if ((vari[1][i] + vari[2][j] + vari[4][k] + vari[5][l]) & 1) m2++;
                }
            }
        }
    }
    for (int i = 1; i <= vari[0][0]; i++) {
        for (int j = 1; j <= vari[3][0]; j++) {
            if ((vari[0][i] + vari[3][j]) & 1) m3++;
        }
    }
    printf("%d", r - m1 * m2 * m3);
    return 0;
}