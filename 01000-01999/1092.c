#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 50)대의 크레인과 M(M <= 10000)개의 화물이 있다. 각 크레인은 무게 제한이 있고, 무게 제한 이하의 화물 한개를
1분에 옮길 수 있다. 모든 크레인을 적절히 움직여 M개의 화물을 옮길 때, 가장 빠른 시간에 옮겼을 때의 소요 시간을 구한다.
전부 옮길 수 없는 경우 -1을 출력한다.

해결 방법 : 각 크레인의 무게 제한과 화물의 무게를 정렬한 다음, 각 크레인으로 들지 못하는 화물의 개수를 각각 구한다.
그 다음, 무게 제한이 가장 높은 크레인이 들지 못하는 화물이 있는지 확인한다. 그렇다면 -1을 출력한다.(옮길 수 없는 화물이므로)
없다면 그 다음 크레인부터 차례로 해당 무게 이상을 들 수 있는 크레인의 수를 확인하고,
나머지 화물을 해당 무게 이상의 제한을 갖는 크레인에 분배했을 때 필요한 크레인의 수를 확인하고, 그들 중 가장 큰 값을 찾는다.
마지막으로, 전체 화물과 전체 크레인에 대해 또 확인해보면, 그들 가운데 가장 큰 값이 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 수학
*/

int cranes[64], boxes[10240], limit[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, c, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cranes[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &boxes[i]);
    }
    qsort(cranes, n, sizeof(int), cmp1);
    qsort(boxes, m, sizeof(int), cmp1);
    cranes[n] = INF;
    c = 0;
    for (int i = 0; i < m; i++) {
        while (cranes[c] < boxes[i]) limit[c++] = m - i;
    }
    if (limit[n - 1]) {
        printf("-1");
        return 0;
    }
    for (int i = n - 2; i >= 0; i--) {
        c = n - i - 1;
        if ((limit[i] + c - 1) / c > r) r = (limit[i] + c - 1) / c;
    }
    if ((m + n - 1) / n > r) r = (m + n - 1) / n;
    printf("%d", r);
    return 0;
}