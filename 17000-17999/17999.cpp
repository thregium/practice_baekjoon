#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : R * C(R, C <= 1000) ũ���� ���ڰ� �ִ�. �� ���ڿ��� /�� \ ��ȣ���� �ִµ�, /�� \�� ���� X�� Y��ǥ�� ���� Ȧ��, ¦��
�Ǵ� �� �ݴ��� ĭ���� �����Ѵ�.(���� Ȧ¦���� �ٸ���.) �� ���ڿ��� /�� \�� �ο��� ������ ����� �� ���ٸ�,
��� ĭ���� �ٱ��� ���ϱ� ���� �����ؾ� �� /�� \�� ���� ���Ѵ�.

�ذ� ��� : /�� \�� �ο��� ������ ���̶�� �ϸ�, /�� \�� �����ϸ� ���� �ٸ� �� 2���� ���� �����ϴ�.
�ٱ��� ��� �����Ѵٰ� �����ϸ� �����ؾ� �� /�� \�� ���� ���� ������ ����.
���� ������ ���� ����� �� ĭ�� ���������� �������� ���� BFS�� �����ϴ� ���̴�. �̶�, /�� \�� Ȧ¦���� �ٸ��Ƿ�
/�� ¦���� ĭ�� ��Ÿ���� ��ǥ�� ���� ¦��, /�� Ȧ���� ĭ�� ��Ÿ���� Ȧ���� ��츸 ���� �ȴ�.
BFS�� ������ ������ �ٱ��� ����� ĭ���� ���� ���� ��ǥ ��� �������� ���� �ٱ��� �Ǵ� ��� �ٱ��� �ִ� ������ ����
���� ���� ������Ű�� �ʴ´�. ���� �ٱ��� �Ǵ� ��찡 ���� ������ ������Ű�� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ����

��ó : PacNW 2019 M��/Z�� // SEUSA 2019D1 I��
*/

char maze[1024][1024];
int vis[1024][1024];
int dxy[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
int r, c, odd = 0, cellcnt = 0;
queue<pair<int, int>> q;

int blocking(int x, int y, int d) {
    //�ش� ĭ���� ���µ� ��ֹ��� �����ϴ��� Ȯ���Ѵ�.
    if (d == 0 && maze[x + 1][y + 1] == '/') return 1;
    if (d == 1 && maze[x + 1][y] == '\\') return 1;
    if (d == 2 && maze[x][y] == '/') return 1;
    if (d == 3 && maze[x][y + 1] == '\\') return 1;
    return 0;
}

int isvalid(int x, int y) {
    //�ش� ĭ�� ������ ĭ���� ���Ѵ�.
    if (x < 0 || y < 0 || x > r || y > c) return -1; //�ٱ����� ������ ���� ������ ������ �����Ѵ�.
    if ((odd == -1 && ((x + y) & 1)) || (odd == 1 && !((x + y) & 1))) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void bfs(int x, int y) {
    int v, isout = 0;
    q.push(pair<int, int>(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (blocking(x, y, i)) continue;
            v = isvalid(x + dxy[i][0], y + dxy[i][1]);
            if (v == -1) {
                isout = 1; //�ٱ����� ������ ��� �ٱ����� ���� üũ�Ѵ�.
                continue;
            }
            if (v == 0) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
        }
    }
    if (isout == 0) cellcnt++;
    while (q.size()) q.pop();
}

int main(void) {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", maze[i] + 1);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (maze[i][j] == '/') {
                if ((i + j) % 2 == 0) odd = -1;
                else odd = 1;
            }
            else if (maze[i][j] == '\\') {
                if ((i + j) % 2 == 0) odd = 1;
                else odd = -1;
            }
        }
    }
    if (odd == 0) {
        printf("0");
        return 0;
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            if (!isvalid(i, j)) continue; //�̹� �湮�߰ų� �湮�� �ʿ䰡 ���� ĭ�� ���
            bfs(i, j);
        }
    }
    printf("%d", cellcnt);
    return 0;
}