#include <stdio.h>
#include <ctype.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : N * M(N, M <= 50) ũ���� �̷ο��� Ż���Ϸ��� �Ѵ�. '0'���� ����ϰ�, '1'���� ���µ� �ɸ��� �ִܽð��� ���Ѵ�.
'#'�� ������ �� ����, ���ĺ� �빮��(A - F)�� �������� ���ؼ��� ���� ���ĺ� �ҹ���(a - f)�� ������ �Ѵ�.

�ذ� ��� : �� ���ĺ� �ҹ��ڸ� ������� ���θ� ��Ʈ����ŷ�� ���� ������ ������ �����Ѵ�.
�湮 �迭���� �̸� ���� ������ �� �ְ�, XY��ǥ�� �Բ� BFS�� �ϸ� �ȴ�.
���� ����(���ĺ� �ҹ���)�� �ִ� ĭ�� ������ ��� ��Ʈ or ������ ���� ������ ���踦 ����ٴ� ������ �߰��ϴ� ���� �����ϰ�,
��(���ĺ� �빮��)�� �ִ� ĭ�� ���� �ϴ� ��� ���� ��Ʈ and ������ ���� ���踦 ������� ������ Ȯ���� �� �ִ�.
1�� ������ ���� �����ϹǷ� 1�� ������ ���� Ž���� �����ϰ� �׶��� �Ÿ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : 
*/

char maze[64][64], vis[64][64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;
queue<tuple<int, int, int, int>> q; //x, y, ����, �Ÿ�

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y][z] || maze[x][y] == '#') return 0;
    else if (isupper(maze[x][y])) {
        //���� ��� ���踦 ������� ���θ� �߰��� Ȯ���Ѵ�.
        if (z & (1 << (maze[x][y] - 'A'))) return 1;
        else return 0;
    }
    else return 1;
}

int bfs(int x, int y) {
    int z, d;
    q.push(make_tuple(x, y, 0, 0));
    vis[x][y][0] = 1;
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        d = get<3>(q.front());
        q.pop();
        if (maze[x][y] == '1') return d; //Ž�� ����
        else if (islower(maze[x][y])) z |= (1 << (maze[x][y] - 'a')); //���谡 �ִٸ� ���� ����
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], z)) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], z, d + 1));
                vis[x + dxy[i][0]][y + dxy[i][1]][z] = 1;
            }
        }
    }
    return -1;
}

int main(void) {
    int x = -1, y = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '0') {
                x = i;
                y = j;
            }
        }
    }
    if (x < 0) return 1;
    printf("%d", bfs(x, y));
    return 0;
}