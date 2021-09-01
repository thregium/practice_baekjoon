#include <stdio.h>

/*
문제 : N * M(N, M <= 4) 크기의 격자에 수들이 쓰여 있다. 이 수들을 가로 또는 세로로 적당히 잘라서
나오는 수들의 합이 가장 크도록 할 때, 수의 합을 구한다.

해결 방법 : 모든 경우를 전부 탐색하는 것을 통해 해결 가능하다. 맨 왼쪽 위 칸에서 시작해서 놓을 수 있는 모든 경우를 놓아보고,
다음번에는 비어있는 가장 처음 칸에서 시작해서 모든 경우를 놓아본다. 이를 반복하다 마지막 칸까지 전부 차게 되면
합을 최댓값과 비교해 최댓값을 갱신한다. 이 값들 중 가장 큰 것이 답이 된다.

주요 알고리즘 : 브루트 포스, 백트래킹
*/

char nums[8][8], chk[32];
int best = 0, n, m;

void track(int pos, int sum) {
    if (pos >= (n - 1) * 4 + m) {
        if (sum > best) best = sum;
    }
    int x = (pos >> 2), y = (pos & 3), t = 0, npos = pos, l = n;
    for (int i = x; i < n; i++) {
        t *= 10;
        t += nums[i][y] - '0';
        if (chk[i * 4 + y]) {
            l = i;
            break;
        }
        else chk[i * 4 + y] = 1;
        while (chk[npos] || (npos & 3) >= m) npos++;
        track(npos, sum + t);
    }
    for (int i = x + 1; i < l; i++) chk[i * 4 + y] = 0;
    t = nums[x][y] - '0', npos = pos, l = m;
    for (int i = y + 1; i < m; i++) {
        t *= 10;
        t += nums[x][i] - '0';
        if (chk[x * 4 + i]) {
            l = i;
            break;
        }
        else chk[x * 4 + i] = 1;
        while (chk[npos] || (npos & 3) >= m) npos++;
        track(npos, sum + t);
    }
    for (int i = y; i < l; i++) chk[x * 4 + i] = 0;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", nums[i]);
    }
    track(0, 0);
    printf("%d", best);
    return 0;
}