#include <stdio.h>

/*
문제 : 길이 N(N <= 10^6)의 절댓값 10^9 이하의 정수로 이루어진 배열이 주어질 때,
이 배열의 각 값마다 오른쪽에 있는 값 중 이 값과 다른 첫 값의 번호를 구한다.
없는 경우 -1을 출력한다.

해결 방법 : 재귀를 통해 오른쪽으로 움직이면서 처음으로 다른 수가 나오는 지점을 찾고
그 값으로 재귀 범위에 있는 모든 값들을 바꿔주면 된다. 이미 답을 알고 있는 지점의 답은
구하지 않고 넘어간다.

주요 알고리즘 : 재귀

출처 : 성균관대 2022 A번
*/

int a[1048576], res[1048576];

int track(int n, int x) {
    if (x >= n - 1) return res[x] = -1;
    else if (a[x + 1] == a[x]) return res[x] = track(n, x + 1);
    else return res[x] = x + 2;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (res[i]) continue;
        track(n, i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}