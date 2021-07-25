#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : ��ǥ��� ���� N(N <= 5000)���� ���̳밡 �ִ�. ��� ���̳� ���κп� ���� �ֺ� ĭ�� �� �ϳ����� ���� ���� �κ��� �ֵ���
���̳뿡 ������ �������� �Ѵ�. �� ������ �ִ� 2ȸ���� ���� �� �ְ�, �� ���̳뿡 ���� ���� ���� ���� ���ٸ�
�׷��� ������ ���� ����� �ִ��� Ȯ���ϰ� �ִٸ� �׷��� ��� �� �ϳ��� ����Ѵ�.

�ذ� ��� : ������ �������� �����غ���. �̶� ��ǥ����� ü���� ���·� �����ϸ� �� ���򳢸��� �̺� �׷��� ���°� �ȴ�.
����, �̵��� �̺� ��Ī�� ���� ¦������ ���� ¦�� ���� ���� ĭ�� �ִٸ� ����� ���� ���̰�,
�ִٸ� ¦���� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : �̺� ��Ī

��ó : GCPC 2020 D��
*/

int grid[10240][10240], dominos[5120], left[5120], right[5120], vis[5120], res[5120];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<int> ed[5120];

int match(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (right[i] == 0 || (!vis[right[i]] && match(right[i]))) {
            left[x] = i;
            right[i] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, x1, y1, x2, y2, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        grid[x1][y1] = i;
        grid[x2][y2] = i;
        if ((x1 + y1) & 1) {
            for (int d = 0; d < 4; d++) {
                if (grid[x1 + dxy[d][0]][y1 + dxy[d][1]] > 0 && grid[x1 + dxy[d][0]][y1 + dxy[d][1]] != i) {
                    ed[grid[x1 + dxy[d][0]][y1 + dxy[d][1]]].push_back(i);
                }
                if (grid[x2 + dxy[d][0]][y2 + dxy[d][1]] > 0 && grid[x2 + dxy[d][0]][y2 + dxy[d][1]] != i) {
                    ed[i].push_back(grid[x2 + dxy[d][0]][y2 + dxy[d][1]]);
                }
            }
            dominos[i] = 1;
        }
        else {
            for (int d = 0; d < 4; d++) {
                if (grid[x1 + dxy[d][0]][y1 + dxy[d][1]] > 0 && grid[x1 + dxy[d][0]][y1 + dxy[d][1]] != i) {
                    ed[i].push_back(grid[x1 + dxy[d][0]][y1 + dxy[d][1]]);
                }
                if (grid[x2 + dxy[d][0]][y2 + dxy[d][1]] > 0 && grid[x2 + dxy[d][0]][y2 + dxy[d][1]] != i) {
                    ed[grid[x2 + dxy[d][0]][y2 + dxy[d][1]]].push_back(i);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!left[i]) {
            for (int j = 1; j <= n; j++) vis[j] = 0;
            if (match(i)) r++;
        }
    }
    if (r < n) printf("impossible");
    else {
        for (int i = 1; i <= n; i++) {
            res[left[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (dominos[i]) printf("%d %d\n", res[i], i);
            else printf("%d %d\n", i, res[i]);
        }
    }
    return 0;
}