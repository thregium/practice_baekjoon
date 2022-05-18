#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 도전이 주어진다. 각 도전은 A_i만큼의 돈을 내고 성공시 B_i만큼의 돈을 얻을 수 있다.
이때, 초기 소지금 M(A_i, B_i, M <= 10^6)이 주어지면, 모든 도전을 성공할 수 있을 때 가능한
최대 소지금을 구한다. 빚을 내거나 한 도전을 여러 번 할 수는 없다.

해결 방법 : 각 도전을 내야 할 돈을 기준으로 오름차순 정렬한 후, 첫 도전부터 차례로 시도해본다.
만약 얻는 돈이 내는 돈보다 적다면 그 도전은 넘어가고, 그만큼 낼 돈이 없는 경우에는 도전을 종료한다.
도전 종료시 소지금이 최대 소지금이 된다. 이는 도전을 통해 소지금이 줄어들 일이 없음을 이용한 것이다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : CornH 2016 I번
*/

int chal[103000][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m;
    long long res = 0;
    scanf("%d %d", &n, &m);
    res = m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &chal[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &chal[i][1]);
    }
    qsort(chal, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (chal[i][0] < chal[i][1] && res >= chal[i][0]) {
            res += chal[i][1] - chal[i][0];
        }
    }
    printf("%lld", res);
    return 0;
}