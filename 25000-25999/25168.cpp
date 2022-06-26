#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 10000)���� ����� �����޾ƾ� �Ѵ�. M(M <= 100000)���� ���� ���谡 �־��� ��,
��� ������ �±� ���� �ʿ��� �� ���� ���Ѵ�. �� ����� ���� ���� ���̿��� �ּ� ��� �Ⱓ�� �ְ�,
7���� ��ȿ �Ⱓ�� �ִ�. ��ȿ �Ⱓ�� ������ ���� ����� �������ؾ� �Ѵ�.

�ذ� ��� : ���� ������ �ϸ鼭 �� ������� �� ������ ���� �ð��� ���� �ش�.
��, �� �������� 7���� �Ѵ� ������ ��� 1�� �����־�� �Ѵ�. ���������� ��ü ���� ��� ���� �ʰ�
������ ������ �� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����

��ó : ���縯�� 4ȸ D��
*/

int ins[10240], vis[10240], mem[10240];
vector<pair<int, int>> ed[10240];
queue<int> q;

int main(void) {
    int n, m, s, e, w, res = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &w);
        ed[s].push_back({ e, w });
        ins[e]++;
    }
    for (int i = 1; i <= n; i++) {
        mem[i] = 0;
        if (!ins[i]) {
            q.push(i);
            vis[i] = 1;
            mem[i] = 1;
        }
    }
    while (q.size()) {
        s = q.front();
        q.pop();
        for (auto& i : ed[s]) {
            ins[i.first]--;
            if (mem[s] + i.second + (i.second >= 7) > mem[i.first]) {
                mem[i.first] = mem[s] + i.second + (i.second >= 7);
            }
            if (!ins[i.first] && !vis[i.first]) {
                q.push(i.first);
                vis[i.first] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mem[i] > res) res = mem[i];
    }
    if (res < 0) return 1;
    printf("%d", res);
    return 0;
}