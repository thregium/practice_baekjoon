#include <stdio.h>

/*
문제 : N(N <= 100)번 택배를 받아야 하고, 서재와 현관의 편도 이동시 M(M <= 10000)만큼의 시간이 걸린다면,
각 택배가 오는 시각이 오름차순으로 주어질 때 T(T <= 10000)만큼의 시간동안 서재에서 공부할 수 있는 시간을 구한다.
단, M 이전의 시간에는 택배가 오지 않는다. 또한, 시작시에는 서재에 있다.

해결 방법 : 첫 택배가 오기 M만큼 전까지 처음에 공부할 수 있다. 그리고 마지막 택배가 오기 전까지
M * 2 이상의 시간이 남는 경우 서재에 갔다오며 남는 시간을 쪼개 공부 가능하다.
마지막 택배가 온 다음에는 서재로 가서 최대한 공부하면 된다.

주요 알고리즘 : 구현, 수학

출처 : JAG 2016DA B번
*/

int a[128];

int main(void) {
    int n, m, t, r = 0;
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    r = a[0] - m;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > m * 2) r += a[i] - a[i - 1] - m * 2;
    }
    if (t - a[n - 1] > m) r += t - a[n - 1] - m;
    printf("%d", r);
    return 0;
}