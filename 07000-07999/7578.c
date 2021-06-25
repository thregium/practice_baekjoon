#include <stdio.h>
#define SZ 524288

/*
문제 : 길이 N(N <= 500000)의 10^6 이하의 자연수로 이루어진 순열 2개가 주어진다. 두 순열의 구성이 같다고 하면,
두 순열 사이 같은 수들을 선으로 이었을 때 교차하는 쌍의 수를 구한다.

해결 방법 : 먼저 크기가 100만인 배열을 만들고 해당 배열에 첫 번째 순열의 값들에 대한 등장 위치를 저장한다.
그 다음으로는 앞의 배열을 이용해 두 번째 순열에서 등장하는 값들을 첫 번째 순열과 매치시켜 맞는 순서로 옮긴다.
그 다음으로는 첫 번째 순열과 매치된 배열을 통해 해당하는 번째의 수들을 차례로 확인하며 이전에 등장한 값 가운데
해당 값보다 큰 값의 합을 결괏값에 추가한 다음 세그먼트 트리에 해당 값을 집어넣는 것을 반복한다.
이를 완료하면 정답을 얻을 수 있다.

주요 알고리즘 : 자료구조, 세그먼트 트리

출처 : 정올 2013지 고3번
*/

int cnt[1048576], b[SZ], seg[SZ << 1];

void update(int x) {
    seg[SZ + x] = 1;
    for (int i = ((SZ + x) >> 1); i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int getsum(int l, int r, int sl, int sr, int p) {
    if (l > sr || r < sl) return 0;
    else if (l <= sl && sr <= r) return seg[p];
    else return getsum(l, r, sl, (sl + sr) >> 1, p << 1) + getsum(l, r, ((sl + sr) >> 1) + 1, sr, (p << 1) + 1);
}

int main(void) {
    int n, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        b[cnt[x]] = i;
    }

    for (int i = 1; i <= n; i++) {
        r += getsum(b[i] + 1, SZ - 1, 0, SZ - 1, 1);
        update(b[i]);
    }
    printf("%lld", r);
    return 0;
}