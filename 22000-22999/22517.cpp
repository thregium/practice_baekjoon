#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 500)���� ������ E(E <= 10000)���� �������� �̷���� ����ġ ���� ����� �׷����� �־�����
Q(Q <= 1000)���� ������ �־��� ��, �� ������ �����Ѵ�.
1. ���� A�� ���� B�� ������ �� 1���� N���� �帣�� ������ ���� ���Ѵ�. ���� A�� B�� ������� ���� �����̴�.
2. ���� A�� ���� B�� ������ �� 1���� N���� �帣�� ������ ���� ���Ѵ�. ���� A�� B�� ����� �����̴�.
��� ������ �ߺ����� �ʴ´�.

�ذ� ��� : ����, ó�� �־����� ������� 1���� N���� �帣�� ������ ���Ѵ�. �� ����, ������ Ȯ���� ������.

1�� ������ ������ ��쿡�� ������ �ִ� 1�� �ø� �� �����Ƿ� ���� ���̸� ������ �� 1���� ������ �ٽ� ������� �ȴ�.

2�� ������ ������ ��쿡�� �ش� ������ ������ �帣�� �ʴ´ٸ� �״�� ����� �ȴ�. ������ ���Ϳ��� �������
�� ������ �ִ� 499���� ������ �̾��� �� �����Ƿ� ����� �ð� ���� ���� �� �ִ�.

������ ������ �帣�� ���¶�� �׷������� �ش� ������ ������ ������ �帣�� ��θ� ã�Ƴ��� �� ����� ������
��� ���� ���� ������ ����� �ȴ�. ���� �� �������� ��ü ������ 1 �پ��� �ȴ�.
�ش� ��θ� ã�� ����� 1���� �ش� ������ ���������� �帣�� ��θ� BFS�� ã�� ����,
�ش� ������ �������� N���� �帣�� ��θ� �� BFS�� ã�� ���⿡ �ش� �������� �߰����� ���� �̵��� �����Ű�� �ȴ�.
������ ���� �������� �ٸ� ��η� ������ �带 ���� �����Ƿ� �ٽ� 1���� ������ �ѹ� ����ش�.

�̷��� �ϸ� �� �������� 1 ~ 3ȸ�� BFS������ ������ ó���� �� �����Ƿ� ��� ������ �ð� ���� ������ ����������.

�ֿ� �˰��� : �׷��� �̷�, �ִ� ����

��ó : JAG 2011SP4 D��
*/

char inl[256], outl[256];
int cap[512][512], flow[512][512], pre[512], res[1024];
vector<int> v[512];
queue<int> q;
int tf;

void makeflow(int n) {
    //BFS�� ���� 1���� N���� �̵��ϴ� ������ ������ ��ŭ �기��.
    int x = 1;
    while (1) {
        q.push(1);
        pre[1] = -1;
        for (int i = 2; i <= n; i++) pre[i] = 0;
        while (q.size()) {
            x = q.front();
            q.pop();
            for (int i : v[x]) {
                if (pre[i]) continue;
                if (cap[x][i] > flow[x][i]) {
                    pre[i] = x;
                    q.push(i);
                }
            }
        }

        if (!pre[n]) break;
        for (int i = n; i > 1; i = pre[i]) {
            flow[pre[i]][i] += 1;
            flow[i][pre[i]] += -1; //������ ������ ������ �긮�� �͵� ���� �ʴ´�
        }
        tf++;
    }
}

void findflow(int n, int a, int b) {
    //1���� A -> B ������ ���� N���� �帣�� ��θ� ã�� ������ ���� ���� ��ü ������ 1 ���δ�.
    int x = 1;
    q.push(1);
    pre[1] = -1;
    for (int i = 2; i <= n; i++) pre[i] = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : v[x]) {
            if (pre[i]) continue;
            if (flow[x][i] > 0) {
                pre[i] = x;
                q.push(i);
            }
        }
    }

    for (int i = a; i > 1; i = pre[i]) {
        flow[pre[i]][i] -= 1; //1���� A�� �帣�� ���� ����
        flow[i][pre[i]] -= -1;
    }

    for (int i = 1; i <= n; i++) pre[i] = 0;
    pre[b] = a;
    q.push(b);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : v[x]) {
            if (pre[i]) continue;
            if (flow[x][i] > 0) {
                pre[i] = x;
                q.push(i);
            }
        }
    }

    for (int i = n; i != b; i = pre[i]) {
        flow[pre[i]][i] -= 1; //B���� N���� �帣�� ���� ����
        flow[i][pre[i]] -= -1;
    }
    flow[a][b] -= 1; //A���� B�� �帣�� ���� ����
    flow[b][a] -= -1;
    tf -= 1; //��ü ���� 1 ����
}

int main(void) {
    int n, e, q, m, a, b;
    for (int fn = 1; fn <= 1; fn++) {
        //sprintf(inl, "E:\\PS\\Contest\\JAG\\2011SP\\summer-camp-2011-day4\\D\\in%d.txt", fn);
        //freopen(inl, "r", stdin);
        
        tf = 0;
        scanf("%d %d %d", &n, &e, &q);
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            cap[a][b] = 1;
            cap[b][a] = 1;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        makeflow(n);
        
        for (int i = 0; i < q; i++) {
            scanf("%d %d %d", &m, &a, &b);
            if (m == 1) {
                //�״�� ������ �߰��� �ϸ� �ȴ�.
                cap[a][b] += 1;
                cap[b][a] += 1;
                v[a].push_back(b);
                v[b].push_back(a);
            }
            else if (m == 2) {
                cap[a][b] -= 1;
                cap[b][a] -= 1;
                if (flow[a][b] > 0) findflow(n, a, b); //A -> B�� ������ �帣�� ���
                else if (flow[b][a] > 0) findflow(n, b, a); //B -> A�� ������ �帣�� ���

                for (int j = 0; j < v[a].size(); j++) {
                    if (v[a][j] == b) {
                        v[a].erase(v[a].begin() + j); //�ش��ϴ� ������ ���Ϳ��� �����Ѵ�. O(N)�� �ð��� ������ ������.
                        break;
                    }
                }
                for (int j = 0; j < v[b].size(); j++) {
                    if (v[b][j] == a) {
                        v[b].erase(v[b].begin() + j); //�ش��ϴ� ������ ���Ϳ��� �����Ѵ�.
                        break;
                    }
                }
            }
            else return 1;

            makeflow(n); //�ٽ� �ѹ� ������ �기��.
            res[i] = tf; //���� ������ ������ �ᱣ���� �����Ѵ�.
        }

        /*
        sprintf(outl, "E:\\PS\\Contest\\JAG\\2011SP\\summer-camp-2011-day4\\D\\out%d.txt", fn);
        freopen(outl, "r", stdin);
        b = 1;
        for (int i = 0; i < q; i++) {
            scanf("%d", &a);
            if (a != res[i]) b = 0;
        }
        
        printf("File %d: ", fn);
        if (b) printf("OK\n");
        else printf("ERROR!!\n");
        */
        for (int i = 0; i < q; i++) {
            printf("%d\n", res[i]); //�ᱣ���� ����Ѵ�.
        }

        for (int i = 0; i <= n; i++) {
            v[i].clear();
            for (int j = 0; j <= n; j++) {
                cap[i][j] = 0;
                flow[i][j] = 0;
            }
        }
    }
    return 0;
}
