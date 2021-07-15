#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : ���� �ٸ� ���ĺ� �빮�ڷ� ǥ�õ� N(N <= 26)���� �༺�� �ִ�. �༺ ���̿��� �����ΰ� �ְ�, �����η� �����
�༺ ���̿��� 5%�� �����Ḧ ���� ������ �� �� �ִ�. ��Ż�� �ִ� �༺�̶�� ������ ������ ���� ������ �� �ִ�.
�� �༺�� �����ο� �����ᰡ ���ٸ� ������ ���� �� �ִ� ������ �־��� ��, ��� �༺�� �����ϴ� ���� ���� ������ ���Ѵ�.

�ذ� ��� : �� �༺�� ������ ���� �� �ִ� ������ ���� ���� * 0.95^(���ľ� �ϴ� �༺ ��)�̴�. ����, BFS�� ����
���ľ� �ϴ� �༺ ���� ���� �� �� �༺�� ������ ���� ���� ���� ������ ū �༺�� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ����

��ó : MidC 1995 4��
*/

int vis[32], dist[32];
double value[32], mul[32], trade[32];
char buff[32];
vector<int> ed[26];
queue<int> q;

void bfs(void) {
    int x;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            q.push(i);
            dist[i] = dist[x] + 1;
        }
    }
}

int main(void) {
    int n, b;
    char c;
    double d;
    mul[0] = 1;
    for (int i = 1; i < 32; i++) {
        mul[i] = mul[i - 1] * 0.95;
    }
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf(" %c %lf %s", &c, &d, buff);
            value[c - 'A'] = d;
            for (int j = 0; buff[j]; j++) {
                if (buff[j] == '*') {
                    q.push(c - 'A');
                    vis[c - 'A'] = 1;
                }
                else if (isupper(buff[j])) ed[c - 'A'].push_back(buff[j] - 'A');
            }
        }
        
        bfs();

        b = 0;
        for (int i = 0; i < 26; i++) {
            if (!vis[i]) trade[i] = 0;
            else trade[i] = value[i] * mul[dist[i]];
            if (trade[i] > trade[b]) b = i;
            ed[i].clear();
            vis[i] = 0;
            dist[i] = 0;
        }
        printf("Import from %c\n", b + 'A');
    }
    return 0;
}