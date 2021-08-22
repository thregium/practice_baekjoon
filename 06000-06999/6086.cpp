#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 700)���� ����� �������� �̷���� �׷����� �ִ�. �� �׷����� ������ ���ĺ� ��ҹ��� �� ���ڷ� �־�����.
�̶�, 'A'���� 'Z'�� ���ϴ� �ִ� ������ ���Ѵ�. �� ������ �뷮�� 1000 ������ �ڿ����̴�.

�ذ� ��� : ������-ī�� �˰����� ���� ������ ���� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �ִ� ����

��ó : USACO 2009J S2��
*/

int cap[128][128], usg[128][128], prv[128];
vector<char> ed[128];
queue<int> q;

int main(void) {
    //Edmonds-Karp �˰����� �̿��� �ִ� ����
    int n, w, l, r = 0;
    char x, s, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %c %d", &s, &e, &w);
        ed[s].push_back(e);
        ed[e].push_back(s); //������ ������ �߰��� ��
        cap[s][e] += w;
        cap[e][s] += w;
    }

    while (1) {
        //Z�� ���� ������ �� ���� ���� �߰�
        while (q.size()) q.pop();
        q.push('A');
        for (int i = 0; i < 128; i++) prv[i] = -1; //��� ������ ���� �迭
        while (q.size() && prv['Z'] < 0) {
            x = q.front();
            q.pop();
            for (char i : ed[x]) {
                if (cap[x][i] > usg[x][i] && prv[i] < 0) {
                    //�ش� �������� ���� �߰��� ������ ���
                    q.push(i);
                    prv[i] = x;
                    if (i == 'Z') break; //Z�� ���޽� ����
                }
            }
        }
        if (prv['Z'] < 0) break;
        l = INF;
        for (char now = 'Z'; now != 'A'; now = prv[now]) {
            if (cap[prv[now]][now] - usg[prv[now]][now] < l) l = cap[prv[now]][now] - usg[prv[now]][now];
            //��� �������� ���� ����� ���� �ּڰ� ã��
        }
        for (char now = 'Z'; now != 'A'; now = prv[now]) {
            usg[prv[now]][now] += l;
            usg[now][prv[now]] -= l; //���������δ� ������ ������ �߰�
        }
        r += l;
    }
    printf("%d", r);
    return 0;
}