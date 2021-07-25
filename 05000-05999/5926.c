#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 50000)개의 수가 수직선상에 있다. 각 수는 10^9 이하의 자연수이고, 수들이 있는 위치도 10^9 이하의 자연수이다.
이때, 모든 종류의 수들이 존재하는 구간 중 가장 짧은 구간을 찾는다.

해결 방법 : 먼저, 모든 수들을 좌표 압축하여 50000 이하의 수로 줄여준다. 이제 투 포인터를 통해 왼쪽에서부터 구간을 넓히며
모든 종류의 수들이 존재할 때 까지 범위를 넓힌다. 그리고 모든 수가 존재하는 경우, 시작점을 움직여 범위를 좁힌다.
이를 반복하여 모든 구간을 찾고, 그 중 가장 짧은 것을 구하면 된다.
이때, 몇 가지 종류의 수들이 존재하는지는 카운트 배열을 통해 구할 수 있다. 새로운 수를 셀 때 개수가 1개가 되었다면
새로운 종류가 들어온 것이고, 개수가 0개로 줄어들면 해당 종류가 사라진 것이다.

주요 알고리즘 : 투 포인터, 정렬, 값 압축

출처 : USACO 2011N S2번
*/

int cows[65536][3], cnt[65536];

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
    int n, c, r = INF, lo = 0, hi = 0, t = 1;
    //freopen("E:\\PS\\Olympiad\\USA\\Silver\\2011_11\\lineup\\I.12", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cows[i][0], &cows[i][1]);
    }
    qsort(cows, n, sizeof(int) * 3, cmp2);
    cows[0][2] = 1;
    for (int i = 1; i < n; i++) {
        if (cows[i][1] == cows[i - 1][1]) cows[i][2] = cows[i - 1][2];
        else cows[i][2] = cows[i - 1][2] + 1;
    }
    c = cows[n - 1][2];
    qsort(cows, n, sizeof(int) * 3, cmp1);
    cnt[cows[0][2]]++;
    while (hi < n) {
        if (t == c) {
            if (cows[hi][0] - cows[lo][0] < r) r = cows[hi][0] - cows[lo][0];
            cnt[cows[lo][2]]--;
            if (cnt[cows[lo][2]] == 0) t--;
            lo++;
        }
        else {
            cnt[cows[++hi][2]]++;
            if (cnt[cows[hi][2]] == 1) t++;
        }
    }
    printf("%d", r);
    return 0;
}