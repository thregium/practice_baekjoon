#include <stdio.h>
#include <stdlib.h>
#define SIZE 1048576

/*
문제 : N(N <= 10^6)개의 정수로 이루어진 배열이 주어질 때, 이 배열의 각 값마다 앞에 있는 값 가운데
더 작은 값의 개수를 출력한다.

해결 방법 : 먼저 배열을 좌표 압축 한 다음, 세그먼트 트리를 0으로 초기화한다.
이후로 쿼리가 들어오는 순서대로 0부터 현재 수보다 작은 수 까지의 개수를 구해서 출력하고
세그먼트 트리에 현재 수에 개수를 1 더해서 넣는 연산을 한다.
이를 반복하면 답을 구할 수 있다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 좌표 압축

출처 : Startlink #1 E2번
*/

int a[1048576][3], seg[SIZE * 2];

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

int update(int pos, int x) {
    seg[SIZE + pos] = x;
    for (int p = (SIZE + pos) >> 1; p > 0; p >>= 1) seg[p] = seg[p << 1] + seg[(p << 1) + 1];
}

int find(int ss, int se, int p, int s, int e) {
    if (ss > e || se < s) return 0;
    if (ss >= s && se <= e) return seg[p];
    return find(ss, (ss + se) >> 1, p << 1, s, e) + find(((ss + se) >> 1) + 1, se, (p << 1) + 1, s, e);
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i;
    }
    qsort(a, n, sizeof(int) * 3, cmp1);
    a[0][2] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i][0] == a[i - 1][0]) a[i][2] = a[i - 1][2];
        else a[i][2] = a[i - 1][2] + 1;
    }
    qsort(a, n, sizeof(int) * 3, cmp2);
    for (int i = SIZE; i < SIZE + n; i++) seg[i] = 0;
    for (int i = SIZE - 1; i > 0; i--) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    for (int i = 0; i < n; i++) {
        printf("%lld\n", find(0, SIZE - 1, 1, 0, a[i][2] - 1));
        update(a[i][2], 1);
    }
    return 0;
}