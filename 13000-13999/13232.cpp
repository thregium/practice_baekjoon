#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : D(D <= 5000)���� ������ ���� ���� �׷����� ���� ��, �� �׷������� ��� �������� �̵� ������ ����(SCC) ���
���� ū ���� ũ�⸦ ���Ѵ�.

�ذ� ��� : D^2�� 1�� �����̹Ƿ� D^2 �ð� �ȿ� Ǫ�� ���� �����ϴ�. ��� �������� BFS�� ������ ��
�� �������� ���� ������ �������� ������� ���·� ������ ���´�. ������ ������ �ٽ� ������ ����
���ݱ��� ����� SCC ��� �� �� �ִ� ���� �ִ��� Ȯ���ϰ� �ִٸ� �� ���� ����, ���ٸ� �� �׷쿡 �����Ѵ�.
�׸��� ��� SCC �׷��� ���� ���� ū ���� ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : AIPO 2015S 3��
*/

vector<int> e[5120], g[5120]; //����, SCC �׷�
//queue<int> q;
int reach[5120][5120], q[1048576]; //�������, ť
int gp = 0, qf, qr;

void bfs(int s, int x) {
    reach[s][x] = 1;
    qf = 0;
    qr = 0;
    q[qr++] = x;
    while (qf - qr) {
        x = q[qf++];
        for (int i = 0; i < e[x].size(); i++) {
            if (!reach[s][e[x][i]]) {
                reach[s][e[x][i]] = 1; //������Ŀ� ����
                q[qr++] = e[x][i];
            }
        }
    }
}

int main(void) {
    int d, l, a, b, t1, t2, r = 0;
    //freopen("C:\\1_����\\PS\\olympiad\\Ireland\\2015f\\test_cases\\s3\\test.17.in", "r", stdin);
    scanf("%d%d", &d, &l);
    for (int i = 0; i < l; i++) {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
    }
    for (int i = 1; i <= d; i++) {
        bfs(i, i); //BFS
    }
    for (int i = 1; i <= d; i++) {
        t1 = 0;
        for (int j = 0; j < gp; j++) {
            t2 = 1;
            for (int k = 0; k < g[j].size(); k++) {
                if (!reach[g[j][k]][i] || !reach[i][g[j][k]]) {
                    //i���� k�� �� �� ���ų� k���� i�� �� �� ���ٸ� j�� ���� Ž�� ����
                    t2 = 0;
                    break;
                }
            }
            if (t2) {
                g[j].push_back(i); //�� �� �ִ� SCC�� ã�� ���
                t1 = 1;
                break;
            }
        }
        if (!t1) g[gp++].push_back(i); //�� �� ���� SCC�� ã�� ���� ��� �� �׷� ����
    }

    for (int i = 0; i < gp; i++) {
        if (g[i].size() > r) r = g[i].size();
    }
    printf("%d", r);
    return 0;
}