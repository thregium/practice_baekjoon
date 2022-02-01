#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 10)���� ��Ģ�� ���� ���ڿ��� �ٲپ� ���� ��, ���ڿ� c�� d�� �ٲٱ� ����
�ʿ��� �ּ� ���� Ƚ���� ���Ѵ�. �� ��Ģ�� �κ� ���ڿ� a�� b�� �ٲٴ� ���·�, �Ϻΰ� ��ġ�� ���
��ġ�� �ʴ� ���� �� �κ� ���ڿ� a�� ������ �ٲ� ��ġ�� �Ѵ�. a�� ���̴� b���� ª����,
��� ���ڿ��� 10�� �̳���. d�� �ٲ� �� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : BFS�� ���� ó�� ���ڿ����� ��Ģ���� ���� ���� �� �ִ� ��� ���ڿ�����
����� ����. �� ���ڿ����� �� ��Ģ�� ���� �ٲ�� ���ڿ��� ���� ����, �̹� �湮�ߴ� �� ���θ� Ȯ���Ѵ�.
�湮���� �ʾҴٸ� �ش� ���ڿ������� �Ÿ��� 1 �ø��� ť�� �ִ´�.
�ٲ�� ���ڿ��� ���ڿ��� ���̰� ª���Ƿ� ���̺��ϰ� ���ϸ� �ȴ�.
��� ���ڿ��� Ȯ��������, d�� �湮�ߴ� �� Ȯ���ϰ� �湮�ߴٸ� �Ÿ���, �湮���� �ʾҴٸ� -1�� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���ڿ�

��ó : Tokyo 2009 B��
*/

char rule[16][2][16], buff[16], res[128], goal[16];
queue<string> q;
unordered_map<string, int> dist;

void bfs(string s, int n) {
    int alen, t, d;
    string r;
    q.push(s);
    dist.insert(pair<string, int>(s, 0));
    while (q.size()) {
        s = q.front();
        d = dist[s];
        q.pop();
        for (int i = 0; i < n; i++) {
            strcpy(buff, s.c_str());
            alen = strlen(rule[i][0]);
            memset(res, 0, 128);
            for (int j = 0; buff[j]; j++) {
                t = 1;
                for (int k = 0; k < alen; k++) {
                    if (buff[j + k] != rule[i][0][k]) {
                        t = 0;
                        break;
                    }
                }
                if (t) {
                    strcat(res, rule[i][1]);
                    j += alen - 1;
                }
                else res[strlen(res)] = buff[j];
            }
            if (strlen(res) > 10) continue;

            r.assign(res);
            if (dist.find(r) == dist.end()) {
                q.push(r);
                dist.insert(pair<string, int>(r, d + 1));
            }
        }
    }
}

int main(void) {
    int n;
    string s;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s %s", rule[i][0], rule[i][1]);
        }
        scanf("%s", buff);
        scanf("%s", goal);
        s.assign(buff);
        bfs(s, n);
        s.assign(goal);
        if (dist.find(s) == dist.end()) printf("-1\n");
        else printf("%d\n", dist[s]);
        
        dist.clear();
    }
    return 0;
}