#include <stdio.h>
#include <stdlib.h>
#define SIZE 524288

/*
문제 : 길이 N(N <= 500000)의 수열을 버블소트 하려고 할 때 필요한 swap 연산의 횟수를 구한다.

해결 방법 : 먼저 수열과 그 수열의 인덱스를 같이 저장한 후 정렬한다. 그 다음 세그먼트 트리의 0부터 N까지 모든 리프 노드에 1을 채운다.
그 뒤로는 정렬된 배열에서 0부터 그 수의 인덱스 전 수까지의 합을 세그먼트 트리에서 찾아 결괏값에 더한 다음 그 수의 인덱스에 있는 값을
세그먼트 트리에서 찾아 0으로 업데이트 해주는 것을 반복하면 된다. 이는 정렬된 배열에서 그 수 앞에 있는 수 가운데 그 수보다 큰 수의 개수를 찾는것과 같다.

주요 알고리즘 : 자료구조, 세그먼트 트리
*/

int a[524288][2], seg[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
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
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i;
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    for (int i = SIZE; i < SIZE + n; i++) seg[i] = 1;
    for (int i = SIZE - 1; i > 0; i--) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    for (int i = 0; i < n; i++) {
        r += find(0, SIZE - 1, 1, 0, a[i][1] - 1);
        update(a[i][1], 0);
    }
    printf("%d", r);
    return 0;
}