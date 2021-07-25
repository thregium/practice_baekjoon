#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926253589793

/*
문제 : 원의 둘레가 N(N <= 180)개의 조각으로 쪼개져 있다. 이 쪼개진 조각들이 위치한 각도가 주어질 때,
모든 조각을 포함하는 울타리를 짓는데 드는 최소한의 울타리 길이를 구한다. 단, 쪼개진 조각들은 겹치지 않는다.

해결 방법 : 각 조각들은 그대로 원주형으로 두고 조각들 사이는 호 형태로 잇는 것이 울타리 길이를 최소로 할 수 있다.
그러기 위해서는 처음에는 원주에서 시작해 울타리들을 각도순으로 정렬한 후 사이사이 빈 공간을 현에서 호로 바꾸어 두면 된다.
그리고 원형이므로 맨 앞과 맨 뒤도 이어야 한다는 사실도 잊어서는 안 된다.

주요 알고리즘 : 정렬, 기하학

출처 : ROI 2004H B번
*/

int frags[192][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getarc(int r, int deg) {
    if (deg > 180) deg = 360 - deg;
    return r * 2.0 * sin(deg * PI / 360.0);
}

int main(void) {
    int n, r;
    double fence = 0;
    scanf("%d %d", &n, &r);
    fence = r * PI * 2.0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &frags[i][0], &frags[i][1]);
    }
    qsort(frags, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n; i++) {
        fence -= r * PI * 2.0 * ((frags[i][0] - frags[i - 1][1] + 360) % 360) / 360.0;
        fence += getarc(r, (frags[i][0] - frags[i - 1][1] + 360) % 360);
    }
    fence -= r * PI * 2.0 * ((frags[0][0] - frags[n - 1][1] + 360) % 360) / 360.0;
    fence += getarc(r, (frags[0][0] - frags[n - 1][1] + 360) % 360);
    printf("%f", fence);
    return 0;
}