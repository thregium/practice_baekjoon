#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20000)개의 음표가 순서대로 주어질 때, 주어진 화성을 만족하는 구간을 모두 찾는다.
주어진 화성을 만족하는 구간은 이후 주어지는 C(C <= 10)개의 연속한 음에 대해 해당 음들의 순서를 바꾸고 일정한 음만큼 이동시켜
C개의 연속한 음을 만들 수 있는 구간이다.

해결 방법 : 먼저 주어지는 C개의 음을 정렬한 다음, 가장 낮은 음에 대한 상대음으로 전부 바꾸어 놓는다.
그 다음, N - C + 1개의 음표들에 대해 해당 음에서 시작하는 C개의 연속한 음을 정렬하고 가장 낮은 음에 대한 상대음으로 바꾼 다음,
원래 C개의 음과 비교해본다. 이렇게 하면 순서와 이동 문제가 모두 해결되기 때문에 바꿀 수 있다면 같을 것이고,
바꿀 수 없다면 같지 않을 것이다. 따라서, 여기서 같은 것을 모두 구하면 답이 된다.

주요 알고리즘 : 브루트 포스, 정렬

출처 : USACO 2011N B3번
*/

int notes[20480], rsc[16], tmp[16], res[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, r = 0, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &notes[i]);
    }
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &rsc[i]);
    }
    qsort(rsc, c, sizeof(int), cmp1);
    for (int i = c - 1; i >= 0; i--) {
        rsc[i] -= rsc[0];
    }

    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 0; j < c; j++) {
            tmp[j] = notes[i + j];
        }
        qsort(tmp, c, sizeof(int), cmp1);
        t = 1;
        for (int j = 0; j < c; j++) {
            if (tmp[j] - tmp[0] != rsc[j]) {
                t = 0;
                break;
            }
        }
        if (t) res[r++] = i;
    }

    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}