#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : ���� 10 ������ �� �������� �־��� ��, �־��� �������� ù ��° ��������
�� ��° �������� �ٲٱ� ���� �ʿ��� ������ �ּ� Ƚ���� ���Ѵ�.
0 �̻��� ���������� 1�� ���ҽ�Ű�� ����, ���������� 1�� ������Ű�� ����,
MSB�� �ƴ� ��Ʈ�� ������Ű�� ������ �����ϴ�.

�ذ� ��� : �� ������� ����, �� �������� �������� �����Ͽ� BFS�� ������ �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ������ 2019M D��
*/

char buff[16], vis[1024];
int dist[1024];
queue<int> q;

int bfs(int st, int ed) {
    int x = st, d;
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        d = dist[x];
        if (x == ed) return d;
        if (x < 1023 && !vis[x + 1]) {
            q.push(x + 1);
            dist[x + 1] = d + 1;
            vis[x + 1] = 1;
        }
        if (x > 0 && !vis[x - 1]) {
            q.push(x - 1);
            dist[x - 1] = d + 1;
            vis[x - 1] = 1;
        }
        for (int i = 1; (i << 1) <= x; i <<= 1) {
            if (!vis[x ^ i]) {
                q.push(x ^ i);
                dist[x ^ i] = d + 1;
                vis[x ^ i] = 1;
            }
        }
    }
}

int main(void) {
    int st, ed;
    scanf("%s", buff);
    st = strtoll(buff, NULL, 2);
    scanf("%s", buff);
    ed = strtoll(buff, NULL, 2);
    printf("%d", bfs(st, ed));
    return 0;
}