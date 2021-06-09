#include <stdio.h>
#include <stdlib.h>
#define SZ 524288

/*
문제 : 1부터 N(N <= 500000)으로 이루어진 3개의 순열이 주어진다.
이 순열에서 (다른 수들 중 세 순열 모두에서 먼저 오는 수)가 없는 수의 개수를 구한다.

해결 방법 : 먼저 각 수를 첫 번째 수에서 나온 번호 순으로 정렬한다.
그 다음으로는 수들을 순서대로 확인하며 세그먼트 트리에서 두 번째 순열의 앞 번호에 있는 수들의 세 번째 순열의 값들 중 최솟값을 확인해
세 번째 순열의 값이 현재 보고 있는 수의 세 번째 순열의 값보다 빨리 나오는지 확인하고 빨리 나온다면 결괏값에 1을 추가한다.
추가한 다음에는 현재 값을 세그먼트 트리에 업데이트해준다.
이를 반복해 나온 결괏값을 출력하면 된다.

주요 알고리즘 : 자료구조, 세그먼트 트리, 그리디 알고리즘, 정렬

출처 : BkOI 2004 2번
*/

int a[SZ][3], seg[SZ * 2]; //세그먼트 트리에는 2번째 값이 해당 범위인 수의 3번째 값의 최솟값을 집어넣는다.

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int fs, int fe, int ss, int se, int d) {
    if (ss > fe || se < fs) return SZ + 1;
    else if (ss >= fs && se <= fe) return seg[d];
    return small(find(fs, fe, ss, (ss + se) >> 1, d << 1), find(fs, fe, ((ss + se) >> 1) + 1, se, (d << 1) + 1));
}

void update(int p, int x) {
    seg[p + SZ] = x;
    for (int i = ((p + SZ) >> 1); i >= 1; i >>= 1) {
        seg[i] = small(seg[i << 1], seg[(i << 1) + 1]);
    }
}

int main(void) {
    int n, x, b, c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x][0] = i; //입력을 번호순으로 변경한다.
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x][1] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x][2] = i;
    }
    qsort(a + 1, n, sizeof(int) * 3, cmp1);
    for (int i = 1; i <= SZ + n; i++) {
        seg[i] = SZ + 1; //세그먼트 트리의 초기값을 가능한 최댓값보다 크게 설정한다.
    }

    for (int i = 1; i <= n; i++) {
        b = find(1, a[i][1] - 1, 0, SZ - 1, 1);
        if (b > a[i][2]) c++; //1, 2, 3번째 값이 모두 작은 수가 있는 경우
        update(a[i][1], a[i][2]);
    }
    printf("%d", c);
    return 0;
}