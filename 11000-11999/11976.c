#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 브론즈, 실버, 골드, 플래터넘 티어가 있고, 새로 시작하는 사람은 브론즈에서 시작한다고 한다.
각 티어별로 이전 시험과 최근 시험의 응시자수가 주어지면, 각 티어별로 해당 구간에서 티어가 오른 사람의 수를 출력한다.

해결 방법 : 가장 높은 티어부터 순서대로 이전에 비해 늘어난 사람 수를 확인한다.
그 다음, 아래 티어의 이전 인원에서 그 수만큼을 빼준다. 이전의 티어에서 해당하는 인원만큼은 다음 티어로 올라갔기 때문이다.
이를 반복하면 각 구간별 티어가 오른 사람의 수를 알 수 있다.

주요 알고리즘 : 수학

출처 : USACO 2016J B1번
*/

int rank[4][2], prom[3];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("promote.in", "r");
        fo = fopen("promote.out", "w");
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &rank[i][0], &rank[i][1]);
    }
    for (int i = 2; i >= 0; i--) {
        prom[i] = rank[i + 1][1] - rank[i + 1][0];
        rank[i][0] -= prom[i];
    }
    for (int i = 0; i < 3; i++) printf("%d\n", prom[i]);
    return 0;
}