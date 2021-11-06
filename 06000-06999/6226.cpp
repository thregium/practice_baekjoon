#include <stdio.h>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : R * C(R, C <= 30) 크기의 격자에 0, 1, 2, 3, 4가 있다. 3이 있는 곳에서 나이트 형태로 이동을 하여 4로 갈 때,
중간에 1인 곳만 지날 수 있다면 1로 바꿔야 하는 0의 최소 개수를 구하고(어떻게 해도 불가능하다면 -1 출력),
그때의 최소 이동 횟수를 구한 다음, 그 두 값을 갖는 서로 다른 방법의 수를 구한다.

해결 방법 : 0을 1로 바꾸는 연산을 가중치 1024로 두고, 1회 이동을 가중치 1로 둔 채로 다익스트라를 진행한다.
그러면 최소 변화 수와 이동 개수를 구할 수 있다.
방법의 수는 가중치 외에 따로 개수 배열을 두어 해결한다. 만약 이동하는 곳의 가중치가 현재 칸에서 이동시의 가중치보다
큰 경우에는 개수를 현재 칸의 개수로 갱신하고, 같은 경우에는 그 칸의 개수에 현재 칸의 개수를 더하고 우선순위 큐에는
넣지 않는 방식으로 해당 칸에 도달하는 방법의 개수를 구할 수 있다.
이를 반복하여 4에 도달하면 그 곳의 가중치로 변화 수와 이동 개수를 구하고 개수 배열로 방법의 수를 구하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : USACO 2007F S2번
*/

int lily[32][32], dist[32][32];
long long cnt[32][32]; //개수 배열, 2^31 이상의 값이 될 수 있으므로 long long을 사용한다.
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int m, n;
priority_queue<tuple<int, long long, int>, vector<tuple<int, long long, int>>, greater<tuple<int, long long, int>>> pq;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (lily[x][y] == 2) return 0;
    return 1;
}

int main(void) {
    int x = -1, y = -1, d;
    long long c;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &lily[i][j]);
            if (lily[i][j] == 3) {
                x = i; //시작점 확인
                y = j;
                cnt[x][y] = 1;
            }
        }
    }
    if (x < 0) return 1;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) dist[i][j] = INF; //가중치 배열 초기화
    }
    pq.push(make_tuple(0, 1, x * 32 + y));
    while (pq.size()) {
        x = get<2>(pq.top());
        y = (x & 31);
        x >>= 5;
        d = get<0>(pq.top());
        c = cnt[x][y];
        pq.pop();
        /*
        if (d > dist[x][y]) continue;
        else if (d == dist[x][y]) {
            cnt[x][y] += c;
            continue;
        }
        else*/ dist[x][y] = d;
        for (int i = 0; i < 8; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
            if (dist[x + dxy[i][0]][y + dxy[i][1]] > d + (lily[x + dxy[i][0]][y + dxy[i][1]] ? 1 : 1025)) {
                dist[x + dxy[i][0]][y + dxy[i][1]] = d + (lily[x + dxy[i][0]][y + dxy[i][1]] ? 1 : 1025);
                cnt[x + dxy[i][0]][y + dxy[i][1]] = c; //거리가 줄어드는 경우
                pq.push(make_tuple(d + (lily[x + dxy[i][0]][y + dxy[i][1]] ? 1 : 1025),
                    cnt[x][y], (x + dxy[i][0]) * 32 + y + dxy[i][1]));
            }
            else if (dist[x + dxy[i][0]][y + dxy[i][1]] == d + (lily[x + dxy[i][0]][y + dxy[i][1]] ? 1 : 1025)) {
                cnt[x + dxy[i][0]][y + dxy[i][1]] += c; //가중치가 같은 경우
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (lily[i][j] == 4) {
                if (dist[i][j] == INF) printf("-1");
                else printf("%d\n%d\n%lld", dist[i][j] >> 10, dist[i][j] & 1023, cnt[i][j]); //정답 출력
                return 0;
            }
        }
    }
    return 1;
}