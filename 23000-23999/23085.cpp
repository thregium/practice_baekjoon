#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 3000)���� ������ �ִ�. K(K <= N)������ ������ ������ ����
��� ������ �޸����� �ϱ� ���� �ʿ��� ������ Ƚ���� �ּڰ��� ���Ѵ�. �Ұ����� ��� -1�� ����Ѵ�.

�ذ� ��� : N�� �����Ƿ� BFS�� ���� �ո��� ������ �ٲ㰡�� 0�� �Ǵ� �������� �ִ� �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ���ϴ� 2021 I��
*/

char s[3072];
int vis[3072], dist[3072];
queue<int> q;

int main(void) {
    int n, k, head = 0;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'H') head++;
    }
    q.push(head);
    vis[head] = 1;
    while (q.size()) {
        head = q.front();
        q.pop();
        for (int i = 0; i <= k; i++) {
            if (head < i || n - head < k - i) continue;
            if (vis[head + k - i * 2]) continue;
            vis[head + k - i * 2] = 1;
            dist[head + k - i * 2] = dist[head] + 1;
            q.push(head + k - i * 2);
        }
    }

    if (vis[0]) printf("%d", dist[0]);
    else printf("-1");
    return 0;
}