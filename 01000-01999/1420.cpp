#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#define INF 103000
using namespace std;

/*
���� : N * M(N, M <= 100) ũ���� ���ڰ� �ִ�. �� ���ڿ��� #���� ǥ�õ� ������ ������ �� ���ٰ� �� ��,
K���� H�� �� �� ������ �ϱ� ���� #���� �ٲ�� �� .�� �ּ� ������ ���Ѵ�. K�� H�� #���� �ٲ� �� ����,
��� �ص� �� �� �ִٸ� -1�� ����Ѵ�. �̵��� �����¿�θ� �� �� �ִ�.

�ذ� ��� : �̴� �ּ� ���� ã�� ������ �ٲ� �� �ְ�, �ٽ� �ִ� ������ ã�� ������ �ٲ� �� �ִ�.
��, �Ϲ����� �ּ� �ư��� �޸� ������ ������� �Ѵ�. �̴� �� ������ 2���� ������, �뷮 1�� �������� ���̸� �����ϴ� ���� ���� �ذ� �����ϴ�.
���⼭ �̹� #�� ������ ������ �߰����� �ʴ´�.(�̹� �뷮�� ��ȭ�Ǿ��� ����). ����, K�� H�� �뷮 ���Ѵ��� �������� �����Ѵ�.
����, ������ ���� ���̿��� �� ������ ���� ������ ��� ������ ���̸� �뷮 ���Ѵ��� �������� �̾��ش�.

���� K�� ��� �������� H�� ���� �������� ������ ���������, �̶��� �ִ� ������ ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �ִ� ����, �ּ� ��
*/

char s[128][128];
pair<int, int> path[20480];
vector<tuple<int, int, int, int>> ed[20480]; //������, ����, �뷮, �������� i��
queue<int> q;

int main(void) {
    int n, m, r = 0, k = -1, h = -1, x, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            //���� �߰�
            if (s[i][j] == '.') {
                //.�� ĭ�� �뷮 1�� ���� ����
                ed[i * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, 1, ed[i * m * 2 + j * 2 + 1].size()));
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2, 0, 0, ed[i * m * 2 + j * 2].size() - 1));
            }
            else if (s[i][j] == 'K' || s[i][j] == 'H') {
                //K �Ǵ� H�� �뷮 ���Ѵ��� ���� ����
                ed[i * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, INF, ed[i * m * 2 + j * 2 + 1].size()));
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2, 0, 0, ed[i * m * 2 + j * 2].size() - 1));
                if (s[i][j] == 'K') k = i * m * 2 + j * 2;
                else h = i * m * 2 + j * 2 + 1;
            }
            if (j > 0) {
                //�¿� ���� ����
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2 - 2, 0, INF, ed[i * m * 2 + j * 2 - 2].size()));
                ed[i * m * 2 + j * 2 - 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, 0, ed[i * m * 2 + j * 2 + 1].size() - 1));
                ed[i * m * 2 + j * 2 - 1].push_back(make_tuple(i * m * 2 + j * 2, 0, INF, ed[i * m * 2 + j * 2].size()));
                ed[i * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 - 1, 0, 0, ed[i * m * 2 + j * 2 - 1].size() - 1));
            }
            if (i > 0) {
                //���� ���� ����
                ed[i * m * 2 + j * 2 + 1].push_back(make_tuple((i - 1) * m * 2 + j * 2, 0, INF, ed[(i - 1) * m * 2 + j * 2].size()));
                ed[(i - 1) * m * 2 + j * 2].push_back(make_tuple(i * m * 2 + j * 2 + 1, 0, 0, ed[i * m * 2 + j * 2 + 1].size() - 1));
                ed[(i - 1) * m * 2 + j * 2 + 1].push_back(make_tuple(i * m * 2 + j * 2, 0, INF, ed[i * m * 2 + j * 2].size()));
                ed[i * m * 2 + j * 2].push_back(make_tuple((i - 1) * m * 2 + j * 2 + 1, 0, 0, ed[(i - 1) * m * 2 + j * 2 + 1].size() - 1));
            }
        }
    }
    if (k < 0 || h < 0) return 1;

    while (1) {
        while (q.size()) q.pop();
        q.push(k);
        for (int i = 0; i < n * m * 2; i++) path[i].first = -1;
        //������-ī�� �˰����� ���� ���� ã��
        while (q.size() && path[h].first < 0) {
            x = q.front();
            q.pop();
            for (int i = 0; i < ed[x].size(); i++) {
                if (get<2>(ed[x][i]) <= get<1>(ed[x][i]) || path[get<0>(ed[x][i])].first >= 0) continue;
                q.push(get<0>(ed[x][i]));
                path[get<0>(ed[x][i])].first = x;
                path[get<0>(ed[x][i])].second = i;
                if (get<0>(ed[x][i]) == h) break;
            }
        }
        if (path[h].first < 0) break;
        b = INF;
        for (int i = h; i != k; i = path[i].first) {
            if (get<2>(ed[path[i].first][path[i].second]) - get<1>(ed[path[i].first][path[i].second]) < b) {
                b = get<2>(ed[path[i].first][path[i].second]) - get<1>(ed[path[i].first][path[i].second]);
            }
        }
        for (int i = h; i != k; i = path[i].first) {
            get<1>(ed[path[i].first][path[i].second]) += b;
            get<1>(ed[i][get<3>(ed[path[i].first][path[i].second])]) -= b;
        }
        r += b;
    }
    printf("%d", r > 401 ? -1 : r);
    return 0;
}