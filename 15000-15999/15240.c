#include <stdio.h>

/*
���� : �׸��ǿ��� ĭ ���� ���� ĥ���� ���� ��, Ư���� ĭ���� ����Ʈ�� ������ ����� ���� �׸����� ���¸� ����Ѵ�.

�ذ� ��� : ���� �� ���̸� �����ҷ� ���� �� ��ġ���� �÷������� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : AIPO 2017F 3��
*/

char image[1024][1024], image2[1024][1024];
int r, c;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (image[x][y] != d || image2[x][y]) return 0;
    return 1;
}

void dfs(int x, int y, int k1, int k2) {
    image2[x][y] = k2;
    if (isvalid(x, y + 1, k1)) dfs(x, y + 1, k1, k2);
    if (isvalid(x, y - 1, k1)) dfs(x, y - 1, k1, k2);
    if (isvalid(x + 1, y, k1)) dfs(x + 1, y, k1, k2);
    if (isvalid(x - 1, y, k1)) dfs(x - 1, y, k1, k2);
}

int main(void) {
    int x, y, k;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", image[i]);
    }
    scanf("%d %d %d", &x, &y, &k);
    dfs(x, y, image[x][y], k + '0');
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (image2[i][j]) printf("%c", image2[i][j]);
            else printf("%c", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}
