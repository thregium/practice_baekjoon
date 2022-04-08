#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
문제 : N * N(N <= 1000) 크기의 배열에 0부터 N까지의 수를 채워넣는다. 다음 조건에 맞게 채워넣는 방법이
있는 지 확인하고, 있다면 그러한 방법을 출력한다.
1. 모든 가로, 세로, 대각선의 값 합이 같아야 한다.
2. 0보다 큰 모든 수 i는 i번 이내로 등장해야 한다.
3. 0보다 큰 서로 다른 수는 2개 이상 나와야 한다.

해결 방법 : 4까지의 크기에서는 그러한 방법이 없다. 5 이상의 크기에서는 여러 가지 방법이 있는데,
간단한 방법으로는 홀수와 짝수일 때를 나누고, N - 2개의 줄은 모두 N으로 채우고, 나머지 칸들은
N / 2 - 1과 N / 2 + 1을 교대로 써서 채우는 방법이 있다.
자세한 채우는 방법은 코드를 참고한다.

주요 알고리즘 : 수학, 구성적

출처 : INC 2020 E번
*/

int cnt[1024], a[1024][1024];

int verify(int n) {
    int ls = 0, ts = 0, nc = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > i) return 0;
        else if (cnt[i] > 0) nc++;
    }
    if (nc < 2) return 0;
    for (int i = 0; i < n; i++) ls += a[i][0];
    for (int i = 0; i < n; i++) {
        ts = 0;
        for (int j = 0; j < n; j++) {
            ts += a[i][j];
        }
        if (ts != ls) return 0;
        ts = 0;
        for (int j = 0; j < n; j++) {
            ts += a[j][i];
        }
        if (ts != ls) return 0;
    }
    ts = 0;
    for (int i = 0; i < n; i++) ts += a[i][i];
    if (ts != ls) return 0;
    ts = 0;
    for (int i = 0; i < n; i++) ts += a[i][n - i - 1];
    if (ts != ls) return 0;
    return 1;
}

void track(int n, int x, int y, int z) {
    if (x >= n) {
        if (verify(n)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
                printf("\n");
            }
            printf("\n");
        }
        return;
    }
    int s;
    for (int i = 0; i <= n; i++) {
        if (i > 0 && cnt[i] >= i) continue;
        a[x][y] = i;
        s = 0;
        for (int j = 0; j <= y; j++) s += a[x][j];
        if (s > z || (y == n - 1 && s < z)) continue;
        s = 0;
        for (int j = 0; j <= x; j++) s += a[j][y];
        if (s > z || (x == n - 1 && s < z)) continue;
        cnt[i]++;
        track(n, y == n - 1 ? x + 1 : x, y == n - 1 ? 0 : y + 1, z);
        cnt[i]--;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (n > 2 && (n % 2 == 0)) return 1;
    if (n <= 4) {
        printf("-1");
        return 0;
    }
    /*
    for (int i = 0; i <= n * n; i++) {
        track(n, 0, 0, i);
    }
    */
    if (n & 1) {
        a[n >> 1][n >> 1] = n;
        a[0][(n >> 1) - 1] = (n >> 1);
        a[0][(n >> 1) + 1] = (n >> 1) + 1;
        a[n - 1][(n >> 1) - 1] = (n >> 1) + 1;
        a[n - 1][(n >> 1) + 1] = (n >> 1);
        for (int i = 1; i < (n >> 1); i++) a[i][i - 1] = n;
        for (int i = (n >> 1) + 1; i < n - 1; i++) a[i][i + 1] = n;
    }
    else {
        a[0][0] = n;
        a[1][n - 2] = n;
        a[2][1] = n;
        a[3][n - 1] = n;
        for (int i = 4; i <= (n >> 1); i++) a[i][i - 2] = n;
        if (n == 8) a[(n >> 1) + 1][3] = n;
        else a[(n >> 1) + 1][n - 3] = n;
        for (int i = (n >> 1) + 2; i < n - 2; i++) a[i][i - 1] = n;
        if (n == 8) {
            a[6][4] = 6;
            a[6][5] = 2;
            a[7][4] = 2;
            a[7][5] = 6;
        }
        else {
            a[n - 2][n >> 1] = (n >> 1) - 1;
            a[n - 2][(n >> 1) - 1] = (n >> 1) + 1;
            a[n - 1][n >> 1] = (n >> 1) + 1;
            a[n - 1][(n >> 1) - 1] = (n >> 1) - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
            cnt[a[i][j]]++;
        }
        printf("\n");
    }
    if (!verify(n)) {
        printf("ERROR!");
        return 1;
    }
    return 0;
}