#include <stdio.h>

/*
문제 : N(N <= 1000)장의 일렬로 놓인 카드를 두 명이서 차례로 양 끝의 카드 중 하나를 가져간다고 한다.
이때, 두 사람이 최적의 전략(수의 합이 가장 크도록)으로 가져간다면 선공의 카드에 적힌 수의 합을 구한다.

해결 방법 : 먼저 카드가 1장 남은 경우부터 역으로 거슬러 올라가며 그때의 두 사람이 얻을 수 있는 값을 구한다.
먼저 1장 남은 경우에는 그 때의 턴인 사람이 그 카드의 값을 얻고 다른 사람은 얻을 수 없다.
N + 1장 남은 경우에는 왼쪽 구간과 오른쪽 구간을 살펴보며 카드를 가져갔을 때 더 많은 점수를 얻는 쪽을 가져가면 된다.
그리고 다른 한 사람은 그때의 값을 왼쪽 또는 오른쪽 구간에서 그대로 가져간다.
이를 반복해 모든 카드가 나올 때 까지 반복한 후 모든 카드의 구간일 때의 값을 구하면 된다.

주요 알고리즘 : DP, 게임 이론

출처 : Seoul 2015I B번
*/

int a[1024], memg[1024][1024], memm[1024][1024];

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            memg[i][i] = ((n & 1) ? a[i] : 0);
            memm[i][i] = ((n & 1) ? 0 : a[i]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                if ((i + n) & 1) {
                    if (a[j] + memg[j + 1][j + i] > a[j + i] + memg[j][j + i - 1]) {
                        memg[j][j + i] = a[j] + memg[j + 1][j + i];
                        memm[j][j + i] = memm[j + 1][j + i];
                    }
                    else {
                        memg[j][j + i] = a[j + i] + memg[j][j + i - 1];
                        memm[j][j + i] = memm[j][j + i - 1];
                    }
                }
                else {
                    if (a[j] + memm[j + 1][j + i] > a[j + i] + memm[j][j + i - 1]) {
                        memm[j][j + i] = a[j] + memm[j + 1][j + i];
                        memg[j][j + i] = memg[j + 1][j + i];
                    }
                    else {
                        memm[j][j + i] = a[j + i] + memm[j][j + i - 1];
                        memg[j][j + i] = memg[j][j + i - 1];
                    }
                }
            }
        }
        printf("%d\n", memg[0][n - 1]);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                memm[i][j] = 0;
                memg[i][j] = 0;
            }
        }
    }
    return 0;
}