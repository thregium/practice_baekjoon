#include <stdio.h>

/*
문제 : N(N <= 200000)개의 일이 있다. K(K <= 10^9)일동안 일들을 하고, 하루에 최대 P(P <= 10^9)동안의 시간에
일을 한다. 일들은 순서대로 1번째부터 N번째까지 한 다음 다시 처음으로 돌아와서 이를 반복한다.
이때, 모든 일을 마치는 것을 최대 몇 번 할 수 있는 지 구한다. 각 일을 하는 데 걸리는 시간은 P 이하다.

해결 방법 : 투 포인터 알고리즘을 이용해 각 일을 시작했을 때 하루에 할 수 있는 일의 개수를 센다.
단, 일을 한 바퀴 돌면 원점이기 때문에 P를 전체 일에 걸리는 시간으로 나눈 나머지를 이용한다.
이를 이용해 각 일을 시작해 2^i일간 일을 했을 때 할 수 있는 일의 개수를 희소 배열에 채운다.
그 다음, 희소배열의 값들을 이용해 1번째 일을 시작해 K일간 할 수 있는 일의 개수를 구하고,
여기에 K * (P / 전체 일의 시간)을 더해주면 답이 된다.

주요 알고리즘 : 자료 구조, 희소 배열, 투 포인터

출처 : MidAtl 2021 C번 // NCNA 2021 M번
*/

int d[204800];
long long cnt[32][204800];

int main(void) {
    int n, p, k, turn, ed = 0, pos = 0;
    long long s = 0, r = 0;
    scanf("%d %d %d", &n, &p, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        s += d[i];
    }
    turn = p / s;
    p %= s;
    s = 0;
    for (int i = 0; i < n; i++) {
        while (s <= p) {
            s += d[ed++];
            if (ed >= n) ed = 0;
        }
        cnt[0][i] = ed - i - 1;
        if (cnt[0][i] < 0) cnt[0][i] += n;
        s -= d[i];
    }
    for (int i = 1; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][(j + cnt[i - 1][j]) % n];
        }
    }
    for (int i = 31; i >= 0; i--) {
        if ((k >> i) & 1) {
            r += cnt[i][pos];
            pos = (pos + cnt[i][pos]) % n;
        }
    }
    printf("%lld", r / n + (long long)turn * k);
    return 0;
}