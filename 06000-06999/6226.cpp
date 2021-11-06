#include <stdio.h>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : R * C(R, C <= 30) ũ���� ���ڿ� 0, 1, 2, 3, 4�� �ִ�. 3�� �ִ� ������ ����Ʈ ���·� �̵��� �Ͽ� 4�� �� ��,
�߰��� 1�� ���� ���� �� �ִٸ� 1�� �ٲ�� �ϴ� 0�� �ּ� ������ ���ϰ�(��� �ص� �Ұ����ϴٸ� -1 ���),
�׶��� �ּ� �̵� Ƚ���� ���� ����, �� �� ���� ���� ���� �ٸ� ����� ���� ���Ѵ�.

�ذ� ��� : 0�� 1�� �ٲٴ� ������ ����ġ 1024�� �ΰ�, 1ȸ �̵��� ����ġ 1�� �� ä�� ���ͽ�Ʈ�� �����Ѵ�.
�׷��� �ּ� ��ȭ ���� �̵� ������ ���� �� �ִ�.
����� ���� ����ġ �ܿ� ���� ���� �迭�� �ξ� �ذ��Ѵ�. ���� �̵��ϴ� ���� ����ġ�� ���� ĭ���� �̵����� ����ġ����
ū ��쿡�� ������ ���� ĭ�� ������ �����ϰ�, ���� ��쿡�� �� ĭ�� ������ ���� ĭ�� ������ ���ϰ� �켱���� ť����
���� �ʴ� ������� �ش� ĭ�� �����ϴ� ����� ������ ���� �� �ִ�.
�̸� �ݺ��Ͽ� 4�� �����ϸ� �� ���� ����ġ�� ��ȭ ���� �̵� ������ ���ϰ� ���� �迭�� ����� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��

��ó : USACO 2007F S2��
*/

int lily[32][32], dist[32][32];
long long cnt[32][32]; //���� �迭, 2^31 �̻��� ���� �� �� �����Ƿ� long long�� ����Ѵ�.
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
                x = i; //������ Ȯ��
                y = j;
                cnt[x][y] = 1;
            }
        }
    }
    if (x < 0) return 1;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) dist[i][j] = INF; //����ġ �迭 �ʱ�ȭ
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
                cnt[x + dxy[i][0]][y + dxy[i][1]] = c; //�Ÿ��� �پ��� ���
                pq.push(make_tuple(d + (lily[x + dxy[i][0]][y + dxy[i][1]] ? 1 : 1025),
                    cnt[x][y], (x + dxy[i][0]) * 32 + y + dxy[i][1]));
            }
            else if (dist[x + dxy[i][0]][y + dxy[i][1]] == d + (lily[x + dxy[i][0]][y + dxy[i][1]] ? 1 : 1025)) {
                cnt[x + dxy[i][0]][y + dxy[i][1]] += c; //����ġ�� ���� ���
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (lily[i][j] == 4) {
                if (dist[i][j] == INF) printf("-1");
                else printf("%d\n%d\n%lld", dist[i][j] >> 10, dist[i][j] & 1023, cnt[i][j]); //���� ���
                return 0;
            }
        }
    }
    return 1;
}