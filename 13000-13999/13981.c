#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 지점(|| <= 10^7)이 수직선상에 있다. 각 지점에는 M_i(M_i <= 10^7)개의 우편이 있다.
이때, 배달부가 K_i(K_i <= 10^7)개까지 한번에 우편을 들고 다닐 수 있다면 원점에서 출발해 모든 우편을
원점으로 모으기 위해 이동해야 하는 최소 거리를 구한다.

해결 방법 : 모든 지점을 정렬한 다음, 원점에서 먼 곳 부터 우편을 최대한 들고 와서 원점으로 돌아오면 된다.
이 과정에서 우편이 많이 있는 지점에서는 나눗셈을 이용해 최적화를 해야 시간 내에 들어올 수 있다.

주요 알고리즘 : 그리디 알고리즘

출처 : PacNW 2016 I/V번
*/

int a[1024][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, s;
    long long r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n && a[i][0] < 0;) {
        s = 0;
        if (a[i][1] > m) {
            r += -a[i][0] * 2LL * ((a[i][1] - 1) / m);
            a[i][1] -= (a[i][1] - 1) / m * m;
        }
        r += -a[i][0] * 2LL;
        while (i < n && a[i][0] < 0 && s <= m) {
            s += a[i][1];
            if (s > m) {
                s -= a[i][1];
                a[i][1] -= m - s;
                break;
            }
            a[i][1] = 0;
            i++;
        }
    }
    for (int i = n - 1; i >= 0 && a[i][0] > 0;) {
        s = 0;
        if (a[i][1] > m) {
            r += a[i][0] * 2LL * ((a[i][1] - 1) / m);
            a[i][1] -= (a[i][1] - 1) / m * m;
        }
        r += a[i][0] * 2LL;
        while (i >= 0 && a[i][0] > 0 && s <= m) {
            s += a[i][1];
            if (s > m) {
                s -= a[i][1];
                a[i][1] -= m - s;
                break;
            }
            a[i][1] = 0;
            i--;
        }
    }
    printf("%lld", r);
    return 0;
}