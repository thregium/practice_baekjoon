#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 300)���� ������ M(M <= 5000)���� �������� �̷���� �׷������� 1�� �������� N�� �������� �̵��ϸ�
�׷����� �� ��� 1�� �����. �׷����� ���� 1 �̻��� ������ �̵� �����ϴ�. �̶�, �̵� ������ �ִ� Ƚ���� ���Ѵ�.

�ذ� ��� : 1�� �������� N�� ���������� �ִ� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷ο�

��ó : UCPC 2018�� PC��
*/

int cap[512][512], usg[512][512], prv[512];
vector<int> ed[512];
queue<int> q;

int main(void) {
    //Edmonds-Karp �˰����� �̿��� �ִ� ����
    int n, p, w, l, r = 0;
    int x, s, e;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &s, &e, &w);
        ed[s].push_back(e);
        ed[e].push_back(s); //������ ������ �߰��� ��
        cap[s][e] += w;
        cap[e][s] += w;
    }

    while (1) {
        //n�� ���� ������ �� ���� ���� �߰�
        while (q.size()) q.pop();
        q.push(1);
        for (int i = 0; i < 512; i++) prv[i] = -1; //��� ������ ���� �迭
        while (q.size() && prv[n] < 0) {
            x = q.front();
            q.pop();
            for (int i : ed[x]) {
                if (cap[x][i] > usg[x][i] && prv[i] < 0) {
                    //�ش� �������� ���� �߰��� ������ ���
                    q.push(i);
                    prv[i] = x;
                    if (i == n) break; //n�� ���޽� ����
                }
            }
        }
        if (prv[n] < 0) break;
        l = INF;
        for (int now = n; now != 1; now = prv[now]) {
            if (cap[prv[now]][now] - usg[prv[now]][now] < l) l = cap[prv[now]][now] - usg[prv[now]][now];
            //��� �������� ���� ����� ���� �ּڰ� ã��
        }
        for (int now = n; now != 1; now = prv[now]) {
            usg[prv[now]][now] += l;
            usg[now][prv[now]] -= l; //���������δ� ������ ������ �߰�
        }
        r += l;
    }
    printf("%d", r);
    return 0;
}