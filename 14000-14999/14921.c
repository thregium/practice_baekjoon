#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 정수가 주어질 때, 두 정수의 합이 0에 가장 가까운 것의 합을 구한다.
주어지는 정수들은 절댓값이 10^8 이하로 주어진다.

해결 방법 : 정수들을 정렬한 다음, 왼쪽부터 값을 움직여준다. 이를 반복하며 가장 작은 것을 찾아가면 된다.

주요 알고리즘 : 정렬, 투 포인터

출처 : 홍익대 2017 D번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l = 0, h, bl = INF, bh = INF;
    scanf("%d", &n);
    h = n - 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = h; j > i; j--) {
            if (abs(a[i] + a[j]) < abs(bl + bh)) {
                bl = a[i];
                bh = a[j];
            }
            if (a[i] + a[j] > 0) h--;
            if (a[i] + a[j] < 0) break;
        }
    }
    printf("%d", bl + bh);
    return 0;
}