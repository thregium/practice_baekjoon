#include <stdio.h>
#include <vector>
#define INF 1234567890987654321
using namespace std;

/*
문제 : N * N(N <= 500) 크기의 격자에 K(K <= N * N) 이하의 자연수들이 적혀 있다.
1부터 K까지 차례로 각 자연수가 있는 칸으로 옮겨 가는 방법이 있는 지 확인하고 있다면
그 가운데 가장 거리가 짧은 것을 구한다. 없는 경우 -1을 출력한다.
거리는 X좌표와 Y좌표의 차이 가운데 작은 것이다.

해결 방법 : 각 수마다 해당하는 좌표의 목록을 저장한 다음, 1부터 차례대로 각 위치의 거리를 저장해 나가며
다이나믹 프로그래밍을 한다. 앞 수의 개수와 뒤 수의 개수의 곱이 N * N보다 작다면
직접 모든 경우에 대해 거리를 구하면서 가장 짧은 것을 찾아나가고,
N * N보다 큰 경우 각 행과 열마다의 최단 거리를 구한 후 각 점에 대해 최단 거리를 계산하여
구하는 방식을 사용한다.

최종적으로 K가 쓰인 칸 가운데 가장 거리가 작은 것의 거리가 답이 된다.
이 값이 무한대인 경우 그러한 방법이 없는 것이므로 -1을 출력한다.

주요 알고리즘 : DP, 밋 인 더 미들?

출처 : PacNW 2021 G번 // SCUSA 2021D1 F번 // NENA 2021 J번
*/

long long a[512][512], lowh[512], lowv[512], disth[512], distv[512], mem[512][512];
vector<pair<int, int>> pos[262144];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long getdist(pair<int, int> a, pair<int, int> b) {
    return small((a.first - b.first) * (a.first - b.first), (a.second - b.second) * (a.second - b.second));
}

int main(void) {
    int n, k;
    long long res = INF;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
            pos[a[i][j]].push_back({ i, j });
            if (a[i][j] == 1) mem[i][j] = 0;
            else mem[i][j] = INF;
        }
    }
    for (int i = 2; i <= k; i++) {
        if ((long long)pos[i].size() * pos[i - 1].size() >= (long long)n * n) {
            for (int j = 0; j < n; j++) {
                lowh[j] = INF; lowv[j] = INF;
                disth[j] = INF; distv[j] = INF;
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (a[j][k] != i - 1) continue;
                    if (mem[j][k] < lowh[j]) lowh[j] = mem[j][k];
                    if (mem[j][k] < lowv[k]) lowv[k] = mem[j][k];
                }
            }
            for (long long j = 0; j < n; j++) {
                for (long long k = 0; k < n; k++) {
                    if (lowh[j] + (j - k) * (j - k) < disth[k]) disth[k] = lowh[j] + (j - k) * (j - k);
                    if (lowv[j] + (j - k) * (j - k) < distv[k]) distv[k] = lowv[j] + (j - k) * (j - k);
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (a[j][k] == i) mem[j][k] = small(disth[j], distv[k]);
                }
            }
        }
        else {
            for (auto& j : pos[i]) {
                for (auto& k : pos[i - 1]) {
                    if (getdist(j, k) + mem[k.first][k.second] < mem[j.first][j.second]) {
                        mem[j.first][j.second] = getdist(j, k) + mem[k.first][k.second];
                    }
                }
            }
        }
    }

    for (auto& j : pos[k]) {
        if (mem[j.first][j.second] < res) res = mem[j.first][j.second];
    }
    if (res == INF) printf("-1");
    else printf("%lld", res);
    return 0;
}