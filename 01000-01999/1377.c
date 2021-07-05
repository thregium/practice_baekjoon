#include <stdio.h>
#define SZ 1048576

/*
문제 : 길이 N(N <= 500000)의 배열이 주어질 때, 이 배열을 버블소트한다면 몇 회 소트 후 정렬이 완료되는지 구한다.

해결 방법 : 각 수들은 자신의 앞에 있는 자신보다 큰 수가 전부 자신의 뒤로 가야 정렬이 완료된다.
그런데, 이 수들은 각 소트마다 1개씩만 뒤로 가기 때문에 자신의 앞에 있는 자신보다 큰 수의 개수의 최대값이 답이 된다.
이 값은 세그먼트 트리를 이용해 찾아낼 수 있다.

주요 알고리즘 : 그리디 알고리즘, 세그먼트 트리
*/

int a[524288], seg[SZ << 1];

int big(int a, int b) {
    return a > b ? a : b;
}

int find(int fl, int fr, int sl, int sr, int p) {
    if (fr < sl || fl > sr) return 0;
    if (fl <= sl && sr <= fr) return seg[p];
    return find(fl, fr, sl, (sl + sr) >> 1, p << 1) + find(fl, fr, ((sl + sr) >> 1) + 1, sr, (p << 1) + 1);
}

int upd(int x) {
    seg[x + SZ]++;
    for (int i = ((x + SZ) >> 1); i > 0; i >>= 1) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r = big(r, find(a[i] + 1, SZ - 1, 0, SZ - 1, 1));
        upd(a[i]);
    }
    printf("%d", r + 1);
    return 0;
}