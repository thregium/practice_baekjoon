#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : M(M <= 1000)���� �������� �̷���� �׷������� strahler ������ ���Ѵ�. ��ü �׷����� ������
M�� ������ ������ ����.

�ذ� ��� : ���� ������ �̿��Ѵ�. ���� ������ 0�� �Ǵ� �������� ���� �������� strahler ������ ���� �� ������
������ ���Ѵ�. ��� ������ ������ Ȯ�������� M�� ������ strahler ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����

��ó : GNY 2013 C��
*/

int ins[1024], sth[1024];
vector<int> ed[1024], edr[1024];
queue<int> q;

int main(void) {
    int t, k, m, p, a, b, c;
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2013\\c.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &k, &m, &p);
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &a, &b);
            ed[a].push_back(b);
            edr[b].push_back(a);
            ins[b]++;
        }
        for (int i = 1; i <= m; i++) {
            if (ins[i] == 0) {
                q.push(i);
                sth[i] = 1;
            }
        }
        while (q.size()) {
            a = q.front();
            q.pop();
            for (int i : ed[a]) {
                ins[i]--;
                if (ins[i] == 0) {
                    b = -1, c = 0;
                    for (int j : edr[i]) {
                        if (sth[j] > b) {
                            b = sth[j];
                            c = 1;
                        }
                        else if (sth[j] == b) c++;
                    }
                    if (c <= 0) return 1;
                    else if (c == 1) sth[i] = b;
                    else sth[i] = b + 1;
                    q.push(i);
                }
            }
        }
        printf("%d %d\n", k, sth[m]);

        for (int i = 0; i <= m; i++) {
            sth[i] = 0;
            ins[i] = 0;
            ed[i].clear();
            edr[i].clear();
        }
    }
    return 0;
}