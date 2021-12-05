#include <stdio.h>
#define HI 1234567898765

/*
문제 : N(N <= 5)명의 후보가 있고, 각 후보의 순위별로 투표 결과가 주어진다.(<= 10^6)
이때, 최소 몇 개의 표를 더해야 콩도르세 승자가 없게 되는지 구한다.
단, 무승부가 아닌 지는 경우가 나와야 콩도르세 승자가 아닌 것이다.

해결 방법 : N이 매우 작기 때문에 각 후보들을 이기는 후보들의 경우를 모두 확인해본다.
그 가운데 가장 추가할 표가 적은 경우를 찾으면 된다. 이기는 후보들로 생기는 사이클은 연결 그래프가 되는 경우
반드시 1개가 생기게 된다.
따라서, 이 사이클 내에서 추가해야 할 표와 사이클 밖에서 추가해야 할 표를 따로 구할 수 있다.
사이클 내에서 추가해야 할 표는 표를 추가할 때 마다 사이클의 어느 한 곳은 표가 감소해야 한다는 문제가 있다.
이를 식을 이용해서 매 표 수마다 해당 표로 사이클 내에서 답을 만족하게 할 수 있는지 구한다.
사이클 외에서 만족하는 가장 작은 값은 추가해야 할 표 수 가운데 가장 작은 간선을 찾으면 간단히 구할 수 있다.

두 값을 비교해서 더 큰 값이 추가해야 하는 표 수이다. 이 값이 가장 작은 것이 답이 된다.

주요 알고리즘 : 그래프 이론, 수학, 브루트 포스

출처 : SEUSA 2020 D번 // MidC 2020 C번 // PacNW 2020 K번 // SCUSA 2020 D번
*/

char cond[128][8];
int vote[128], lose[8], weight[8], vis[8];

int getres(int n, long long x) {
    long long s = 0, l = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            s += (weight[i] + x - 1) >> 1;
            if (weight[i] < l) l = weight[i];
        }
    }
    return (s >= x && 1 - l <= x);
}

int main(void) {
    int n, m, stt, sml, cnt, t;
    long long lo, hi, mid, res = HI;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2020\\condorcet\\data\\secret\\7002.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", cond[i], &vote[i]);
    }
    if (n != 3 && n != 4 && n != 5) return 1;
    for (int i = 0; i < (n == 3 ? 8 : n == 4 ? 81 : 1024); i++) {
        for (int j = 0, k = i; j < n; j++) {
            lose[j] = k % (n - 1);
            if (lose[j] >= j) lose[j]++;
            weight[j] = 0;
            k /= (n - 1);
        }
        t = 0;
        for (int j = 0; j < 5; j++) {
            if (lose[lose[j]] == j) t = 1;
        }
        if (t) continue;

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (lose[cond[j][k] - 'A'] == cond[j][l] - 'A') {
                        weight[cond[j][k] - 'A'] -= vote[j];
                    }
                    if (lose[cond[j][l] - 'A'] == cond[j][k] - 'A') {
                        weight[cond[j][l] - 'A'] += vote[j];
                    }
                }
            }
        }
        stt = 0, cnt = 0;
        for (int i = 0; i < n; i++) vis[i] = 0;
        while (!vis[stt]) {
            vis[stt] = 1;
            stt = lose[stt];
        }
        for (int i = 0; i < n; i++) vis[i] = 0;
        while (!vis[stt]) {
            vis[stt] = 1;
            stt = lose[stt];
            cnt++;
        }

        lo = 0, hi = HI;
        /*
        while (lo < hi) {
            mid = ((lo + hi) >> 1);
            if (getres(n, mid)) hi = mid;
            else lo = mid + 1;
        }
        */
        while (!getres(n, lo) && lo <= res) lo++;
        sml = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && weight[i] < sml) sml = weight[i];
        }
        //lo += 1 - sml;
        if (1 - sml > lo) lo = 1 - sml;

        if (lo < res) {
            res = lo;
        }
    }
    if (res == HI) return 2;
    printf("%lld", res);
    return 0;
}