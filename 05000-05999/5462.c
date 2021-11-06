#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 2000)명이 T(T <= 2000)개의 문제를 풀었는지 여부가 주어진다. 이때, 각 문제의 배점은 이 문제를
풀지 못한 사람 수와 같다고 한다. 순위는 점수가 높은 사람 -> 많은 문제를 맞춘 사람 -> ID 번호가 빠른(먼저 나온) 사람
순서로 정해진다면 ID 번호가 P(P번째로 나온)인 사람의 순위를 구한다.

해결 방법 : 먼저 문제 풀이 여부를 입력받은 다음, 각 문제의 배점을 구한다. 다시 이를 이용해 각 사람의 점수를 구하고,
문제를 맞춘 개수와 ID 번호와 함께 배열에 넣는다. 이 배열을 위에 나온 순서대로 정렬하고,
ID 번호가 P인 사람이 나오면 그 위치를 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : IOI 2009 3번
*/

int prob[2048][2048], part[2048][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 2);
    bi = *((int*)b + 2);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, t, p;
    scanf("%d %d %d", &n, &t, &p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            scanf("%d", &prob[i][j]);
        }
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) prob[0][i] += (!prob[j][i]);
    }
    for (int i = 1; i <= n; i++) {
        part[i - 1][2] = i;
        for (int j = 1; j <= t; j++) {
            if (!prob[i][j]) continue;
            part[i - 1][1]++;
            part[i - 1][0] += prob[0][j];
        }
    }
    qsort(part, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        if (part[i][2] == p) {
            printf("%d %d", part[i][0], i + 1);
            return 0;
        }
    }
    return 1;
}