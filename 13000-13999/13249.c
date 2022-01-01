#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 12)개의 일직선상에 있는 공의 위치(0 <=, <= 10^8, 정수)가 주어진다. 이때, 각 공의 방향은
좌 우 중 무작위 한 방향이라고 하고, 속도는 단위시간당 1이며, 충돌시 방향은 반대, 속도는 동일이라고 하면,
T(0 <= T <= 10^8, 정수)초동안 공이 충돌하는 횟수의 기댓값을 구한다.

해결 방법 : 각 시각마다 각 공의 위치를 선으로 이어보면 직선들로 나오는 것을 알 수 있다. 따라서, T초 이내에 두 직선이 만난다면
공이 충돌할 것임을 알 수 있다. 이를 이용해 각 공의 방향을 정한 다음, 모든 두 공의 쌍에 대해 두 직선이 만나는 횟수를 세고,
그 기댓값을 직접 구하면 된다.

주요 알고리즘 : 수학, 확률론, 애드 혹
*/

int pos[16], bit[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, t;
    double res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    qsort(pos, n, sizeof(int), cmp1);
    scanf("%d", &t);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            bit[j] = (i >> j) & 1;
        }
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (bit[j] != 0 || bit[k] != 1) continue;
                if (pos[k] - pos[j] <= t * 2) res += 1.0 / (1 << n);
            }
        }
    }
    printf("%.9f", res);
    return 0;
}