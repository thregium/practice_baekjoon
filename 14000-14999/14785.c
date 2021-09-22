#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 32000)개의 줄이 수평선상에 놓여있다. 줄의 시작점과 길이가 주어질 때,
모든 줄을 끊기 위해 필요한 절단의 횟수를 구한다. 단, 줄의 양 끝은 자르는 것에 포함되지 않는다.

해결 방법 : 줄을 끝나는 순으로 정렬한 다음, 아직 자르지 않은 줄 가운데 끝나는 위치가 가장 빠른 줄의
끝쪽을 자르는 것을 반복하는 것이 최적의 방법이다. 그 줄은 반드시 잘라야 하지만 일찍 자르면 잘리지 않는 줄이 생기기 때문에
손해이기 때문이다.

줄을 자를 때에는 시작하는 위치가 더 빠른 다른 줄들을 빠르게 찾기 위해 투 포인터 알고리즘을 이용할 수 있다.
줄을 시작하는 순서대로 정렬한 배열을 하나 더 만든 다음, 끝나는 순으로 정렬한 배열과 연동시키는 방식이다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 투 포인터

출처 : USACO 2006O B5번
*/

int leash[32768][2], fronts[32768][2], backs[32768][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0, fp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &leash[i][0], &leash[i][1]);
        leash[i][1] += leash[i][0];
    }
    qsort(leash, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        fronts[i][0] = leash[i][0];
        fronts[i][1] = leash[i][1];
        backs[i][0] = leash[i][1];
        backs[i][1] = i;
    }
    qsort(fronts, n, sizeof(int) * 2, cmp2);
    for (int i = 0; i < n; i++) {
        fronts[i][1] = i;
    }
    qsort(fronts, n, sizeof(int) * 2, cmp1);
    qsort(backs, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n; i++) {
        if (backs[i][1] < 0) continue;
        r++;
        backs[i][1] = -1;
        while (fronts[fp][0] < backs[i][0] && fp < n) {
            backs[fronts[fp][1]][1] = -1;
            fp++;
        }
    }
    printf("%d", r);
    return 0;
}