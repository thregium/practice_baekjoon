#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 2000)���� ������ M(M <= 10^6)���� ���� ���谡 �־��� ��, ��� ���迡�� ���� ���� ģ������ ���Ѵ�.

�ذ� ��� : ������踦 �׷����� �׷��� �� �̺� �׷��� ���¶�� �ش� ���谡 �����Ѵ�. BFS�� ���� �̺� �׷��� ���θ�
�Ǻ��ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �̺� �׷���, BFS
*/

int fd[20480];
vector<int> edge[20480];
queue<int> q;

int main(void) {
    int v, e, a, b, r, t, f, qz, vc;
    r = 1;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vc = v;
    while (vc) {
        for (int i = 1; i <= v; i++) {
            if (!fd[i]) {
                q.push(i);
                break;
            }
        }
        f = 1;
        while (q.size()) {
            qz = q.size();
            while (qz) {
                t = q.front();
                q.pop();
                qz--;
                if (fd[t] == 0) {
                    fd[t] = f;
                    vc--;
                }
                else {
                    if (fd[t] % 2 != f % 2) {
                        r = 0;
                        break;
                    }
                    else continue;
                }
                for (int i = 0; i < edge[t].size(); i++) {
                    q.push(edge[t][i]);
                }
            }
            f++;
            if (!r) break;
        }
    }
    printf("%d\n", r);
    for (int i = 1; i <= v; i++) {
        edge[i].clear();
        fd[i] = 0;
    }
    return 0;
}