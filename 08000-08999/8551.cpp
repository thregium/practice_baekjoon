#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 10000)���� �������� �̷���� ������ġ ����׷������� 1�� �������� N�� �������� �� �� ���� �ϱ� ����
�����ؾ� �� �ּ� ���� ������ ���Ѵ�.

�ذ� ��� : �̴� 1�� �������� N�� �������� ���ϴ� �ִ� ������ ���ϴ� ������ ����.
��, N�� ����� ũ�� ������ ��� �˰����� �̿��ؾ� Ǯ �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �ִ� ����, �ּ� ��, ���

��ó : PA 2002.11 4-1��
*/

int level[10240], see[10240];
vector<pair<tuple<int, int, int>, int>> ed[10240]; // (nxt / usg / cap) / revi
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

void set_level(void) {
    int x;
    while (q.size()) q.pop();
    q.push(1);
    level[1] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (auto i : ed[x]) {
            if (get<1>(i.first) == get<2>(i.first) || level[get<0>(i.first)]) continue; //������ �긱 �� ���ų� �̹� �湮�� ���
            q.push(get<0>(i.first));
            level[get<0>(i.first)] = level[x] + 1; //�ִܰŸ� + 1�� ������ ����.
        }
    }
}

int dinic(int x, int e, int f) {
    if (x == e) return f; //���� ������ ������ ���
    int ff;

    for (int i = see[x]; i < ed[x].size(); i++) {
        //���������� Ȯ���� ���� ���� ������ Ȯ��
        if (level[get<0>(ed[x][i].first)] != level[x] + 1 || get<1>(ed[x][i].first) == get<2>(ed[x][i].first)) {
            see[x] = i + 1;
            continue;
        }
        //���� ������ �ƴϰų� ������ �긱 �� ���� ������ ���
        ff = dinic(get<0>(ed[x][i].first), e, small(f, get<2>(ed[x][i].first) - get<1>(ed[x][i].first))); //��ü ������ Ȯ����
        if (ff) {
            //������ �긱 �� �ִ� ��� ������ �긮�� ������ ����
            get<1>(ed[x][i].first) += ff;
            get<1>(ed[get<0>(ed[x][i].first)][ed[x][i].second]) -= ff;
            return ff;
        }
        see[x] = i + 1; //������ Ȯ�� ��ġ�� ������Ʈ(�̹� Ȯ���� ������ �ٽ� �� �ʿ䰡 ����)
    }

    return 0; //���� Ȯ�ο� ������ ���
}

int main(void) {
    int n, m, a, b, r = 0, c;
    tuple<int, int, int> t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(pair<tuple<int, int, int>, int>(make_tuple(b, 0, 1), ed[b].size()));
        ed[b].push_back(pair<tuple<int, int, int>, int>(make_tuple(a, 0, 0), ed[a].size() - 1));
    }
    while (1) {
        memset(level + 1, 0, n * sizeof(int));
        memset(see + 1, 0, n * sizeof(int));
        set_level();
        if (!level[n]) break; //���̻� ���� �߰� �Ұ���
        while (1) {
            c = dinic(1, n, INF);
            if (!c) break; //���ο� ���� �׷��� ���� �ʿ��
            r += c;
        }
    }
    printf("%d", r);
    return 0;
}