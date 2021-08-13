#include <stdio.h>

/*
문제 : N(N <= 100)명이 타깃이 누구인지 맞추는 게임을 M(M <= 100)번 하였다. 각 게임마다 타깃은 자기 이름을 적고
그 외의 사람들은 타깃의 이름을 추측해 적는다. 적은 사람이 맞다면 그 사람은 1점을 얻고, 틀리다면 타깃이 1점을 얻는다.
게임이 전부 끝났을 때 모든 사람의 점수를 각각 출력한다.

해결 방법 : 문제에서 주어진대로 구현하면 된다.

주요 알고리즘 : 구현

출처 : JOI 2015예 2번
*/

int a[128], scores[128];

int main(void) {
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x == a[i]) scores[j]++;
            else scores[a[i] - 1]++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", scores[i]);
    }
    return 0;
}