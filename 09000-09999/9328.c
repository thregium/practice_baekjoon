#include <stdio.h>
#include <ctype.h>

/*
���� : H * W(H, W <= 100) ũ���� �ǹ����� �ִ� �� ���� ����($)�� ���� �� �ִ��� ���Ѵ�. ���� ������ �ǹ��� ���� �ٱ�����
�� ����(.)�̳� ��(�빮��)�̰�, �� ������ ���� �ش��ϴ� ����(�ҹ���)�� �־�� �Ѵ�. ��(*)�� ����� �� ������,
ó���� �Ϻ� ���踦 ���� �ִ� ������ ���� �ִ�. �̵��� �����¿�θ� �� �� �ִ�.

�ذ� ��� : ���踦 ���� �ִ� ���´� ���ĺ� ���ڰ� 26���̹Ƿ� ��Ʈ����ŷ�� ���� ������ �� �ִ�. ���� ���¸� ���� ������ �����س���
�ٱ��� �������� ���� ������ ĭ�� �ִٸ� �ش� ĭ���� ���� �÷������� ������. �� �������� ���ο� ���踦 ����ٸ�
����� �������� �ٽ� �ѹ� ��������. �̸� ���ο� ���踦 ���� �� ���� �� ����(��ѱ����� ������ ���� �ִ� 26ȸ) �ݺ��Ѵ�.
�������� ���� ����� ���� �� �ִ� �ִ� ���� ���̴�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ��Ʈ����ŷ, ���Ʈ����, ����

��ó : BAPC 2013P K��
*/

char building[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w, key, newkey = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    else if (vis[x][y] || building[x][y] == '*') return 0;
    else if (building[x][y] == '.')  return 1;
    else if (isupper(building[x][y])) {
        if (key & (1 << (building[x][y] - 'A'))) return 2;
        else return 0;
    }
    else if (islower(building[x][y])) {
        if (key & (1 << (building[x][y] - 'a'))) return 3;
        else {
            key |= 1 << (building[x][y] - 'a');
            newkey++;
            return 4;
        }
    }
    else if (building[x][y] == '$') return 9;
    else return -1;
}

int dfs(int x, int y, int docs) {
    vis[x][y] = 1;
    if (building[x][y] == '$') docs++;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) docs += dfs(x + dxy[i][0], y + dxy[i][1], 0);
    }
    return docs;
}

int main(void) {
    int t, r;
    char keys[32] = { 0, };
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            scanf("%s", building[i]);
        }
        key = 0;
        scanf("%s", keys);
        for (int i = 0; keys[i]; i++) {
            if (keys[i] == '0') break;
            else key += (1 << (keys[i] - 'a'));
        }

        newkey = 1;
        while (newkey) {
            r = 0;
            newkey = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) vis[i][j] = 0;
            }

            for (int i = 0; i < h; i++) {
                if (isvalid(i, 0)) r += dfs(i, 0, 0);
                if (isvalid(i, w - 1)) r += dfs(i, w - 1, 0);
            }
            for (int i = 0; i < w; i++) {
                if (isvalid(0, i)) r += dfs(0, i, 0);
                if (isvalid(h - 1, i)) r += dfs(h - 1, i, 0);
            }
        }

        printf("%d\n", r);
    }
    return 0;
}