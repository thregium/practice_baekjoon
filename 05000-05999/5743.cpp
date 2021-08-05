#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : R * C(R, C <= 1000) 크기의 공간에 연잎들이 있다. 개구리가 어떠한 마른 연잎에서 다른 마른 연잎으로 이동하려 한다.
이때, 마른 연잎만 밟으며 이동하고, 주변 5 * 5 범위 내로 이동 가능하며, 각 이동마다 고유한 에너지 소비량이 존재한다면,
해당 지점까지 갈 수 있는지 확인하고, 가능하다면 그때의 최소 에너지 소비량을 구한다.
젖은 연잎은 W(W <= 1000)개의 직사각형 범위 형태로 주어진다.

해결 방법 : 2차원 누적 합을 이용해 각 칸이 젖은 연잎에 포함된 횟수를 구한다. 이 횟수가 0인 곳만이 마른 연잎일 것이다.
그 다음으로는 시작 연잎부터 도착 연잎까지의 최단거리를 다익스트라를 통해 찾으면 된다.
이때, 시간제한상 미리 최단거리 정보를 우선순위 큐에 넣으며 업데이트해 주며, 갖고있는 정보보다 늦는 경우는 제외함을 통해
결과를 더 빠르게 찾아내야 한다.

주요 알고리즘 : 그래프 이론, 다익스트라, 최적화

출처 : Latin 2006 B번
*/

short wc[1024][1024], wet[1024][1024];
int dist[1024][1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
long long moves[5][5] = { {7, 6, 5, 6, 7}, {6, 3, 2, 3, 6}, {5, 2, 0, 2, 5}, {6, 3, 2, 3, 6}, {7, 6, 5, 6, 7} };

int main(void) {
    long long r, c, rs, cs, re, ce, w, x1, y1, x2, y2;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2006\\frog.in", "r", stdin);
    while (1) {
        scanf("%lld %lld", &r, &c);
        if (r == 0) break;
        for (long long i = 1; i <= r; i++) {
            for (long long j = 1; j <= c; j++) {
                wc[i][j] = 0;
                wet[i][j] = 0;
                dist[i][j] = INF;
            }
        }
        scanf("%lld %lld %lld %lld", &rs, &cs, &re, &ce);
        pq.push(pair<int, int>(0, (rs << 10) + cs));
        scanf("%lld", &w);
        for (long long i = 0; i < w; i++) {
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            /*for (int x = x1; x <= x2; x++) {
                for (int y = y1; y <= y2; y++) {
                    wet[x][y] = 1;
                }
            }
        }
        */
            
            wc[x1][y1]++;
            wc[x1][y2 + 1]--;
            wc[x2 + 1][y1]--;
            wc[x2 + 1][y2 + 1]++;
        }
        for (long long i = 1; i <= r; i++) {
            for (long long j = 1; j <= c; j++) {
                wet[i][j] = wet[i][j - 1] + wc[i][j];
            }
        }
        for (long long i = 1; i <= c; i++) {
            for (long long j = 1; j <= r; j++) {
                wet[j][i] += wet[j - 1][i];
            }
        }
        
        while (!pq.empty()) {
            x1 = (pq.top().second >> 10);
            y1 = (pq.top().second & 1023);
            w = pq.top().first;
            pq.pop();
            if (w > dist[x1][y1]) continue;
            else dist[x1][y1] = w;
            if (x1 == re && y1 == ce) break;
            for (long long i = 0; i < 5; i++) {
                for (long long j = 0; j < 5; j++) {
                    if (!moves[i][j]) continue;
                    x2 = x1 + i - 2;
                    y2 = y1 + j - 2;
                    if (x2 < 1 || y2 < 1 || x2 > r || y2 > c || wet[x2][y2]) continue;
                    if (dist[x2][y2] > w + moves[i][j]) {
                        pq.push(pair<int, int>(w + moves[i][j], (x2 << 10) | y2));
                        dist[x2][y2] = w + moves[i][j];
                    }
                }
            }
        }
        while (pq.size()) pq.pop();
        if (dist[re][ce] == INF) printf("impossible\n");
        else printf("%d\n", dist[re][ce]);
    }
    return 0;
}