#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : L(L <= 6)자리 자연수에 대해 자릿수를 재배치하여 만들 수 있는 가장 큰 수와 가장 작은 수의 차이를
다음 수로 하는 연산을 반복하였다. 이때, 처음으로 같은 수가 나왔을 때의 반복 시작점과 구간의 길이,
그때 나온 수를 각각 출력한다. 반복이 20회 이내에 나오는 연산만 주어진다.

해결 방법 : 각 수에 대해 방문한 시점을 배열에 저장해둔다. 반복이 빠르게 나오기 때문에 직접 다음 수를 계산해 나가며
시뮬레이션하면 된다. 다음 수는 수를 숫자 단위로 쪼갠 후 오름차순과 내림차순으로 각각 정렬하여 붙인 다음,
두 수의 차를 구하는 방식으로 만들 수 있다. 만약 현재 수가 배열에 이미 저장되어 있다면
탐색을 종료하고 반복에 관한 정보들을 출력하면 된다.

주요 알고리즘 : 수학, 시뮬레이션, 정렬

출처 : JDC 2012D B번
*/

char vis[1048576];
int nm[8];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, l, r, hi, lo;
    while (1) {
        memset(vis, -1, sizeof(vis));
        scanf("%d %d", &n, &l);
        if (l == 0) break;
        if (n > 999999) return 1;
        for (r = 0; vis[n] < 0; r++) {
            vis[n] = r;
            for (int i = 0; i < l; i++) {
                nm[i] = n % 10;
                n /= 10;
            }
            qsort(nm, l, sizeof(int), cmp1);
            hi = 0, lo = 0;
            for (int i = 0; i < l; i++) {
                hi *= 10, lo *= 10;
                lo += nm[i], hi += nm[l - i - 1];
            }
            n = hi - lo;
        }
        printf("%d %d %d\n", vis[n], n, r - vis[n]);
    }
    return 0;
}