#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N * M(N * M <= 100000) ũ���� ���ڿ� 1, 2�� �����ִ�. 1�� 2�� üũ ���̸� �̷�� ���� ����.
�̶�, 1�� ĭ�� �̹� �湮�� ĭ���θ� �̵� ������ �Ͱ� 2�� ĭ�� �̹� �湮�� ĭ���θ� �̵� ������ ����
�ִٸ�, ��� ĭ�� �湮�ϱ� ���� ���� �� �� �ٲ�Ÿ�� �ϴ� �� ���Ѵ�. ó�� Ÿ�� �͵� �����Ѵ�.

�ذ� ��� : 1�� ����� 2�� ����� ���� ã�Ƽ� ������ �� �ش�. 1�� ����� 2�� ��� ���
�� ���� ���� �̸� ���� �����ְ� ���� �������� �� ���� ó�� �����ϱ� ������ �� �� �� ���� �� + 1��
���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : Tehran 2012 G��
*/

char s[103000];
string grain[103000];
vector<int> vis[103000];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, wheat, corn;

void dfs(int x, int y) {
    int xt, yt;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        xt = x + dxy[i][0];
        yt = y + dxy[i][1];
        if (xt < 0 || yt < 0 || xt >= n || yt >= m) continue;
        if (grain[xt][yt] != grain[x][y] || vis[xt][yt]) continue;
        dfs(xt, yt);
    }
}

int main(void) {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            grain[i].assign(s);
            vis[i].clear();
            for (int j = 0; j < m; j++) vis[i].push_back(0);
        }

        wheat = 0, corn = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    dfs(i, j);
                    if (grain[i][j] == '1') wheat++;
                    else corn++;
                }
            }
        }
        if (wheat < corn) printf("%d\n", wheat + 1);
        else printf("%d\n", corn + 1);
    }
    return 0;
}