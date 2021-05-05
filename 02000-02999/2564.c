#include <stdio.h>
#include <math.h>

/*
���� : H * W ũ���� ���簢�� �׵θ��� ���� N��(N, H, W <= 100) �ִ�. ���簢�� ���η� ���� ���� �Ұ����ϴٸ�,
���� �־��� ������ N���� ������ �̵��ϴµ� �ɸ��� �ִܰŸ��� ���� ���Ѵ�.

�ذ� ��� : �� ������ �����ϴ� ������ ����� ���� ������ Ǭ��.

�ֿ� �˰��� : ���̽� ��ũ

��ó : ���� 2007�� ��3��
*/

int pos[128][2];
int w, h, n;

int small(int a, int b) {
    return a < b ? a : b;
}

int dist(int x) {
    if (pos[x][0] == pos[n][0]) {
        return abs(pos[x][1] - pos[n][1]); //���� ���� ���
    }
    if ((pos[x][0] == 1 && pos[n][0] == 2) || (pos[x][0] == 2 && pos[n][0] == 1)) {
        return small(pos[x][1] + pos[n][1], w * 2 - (pos[x][1] + pos[n][1])) + h; //���� ��, �Ʒ� ������ ���
    }
    if ((pos[x][0] == 3 && pos[n][0] == 4) || (pos[x][0] == 4 && pos[n][0] == 3)) {
        return small(pos[x][1] + pos[n][1], h * 2 - (pos[x][1] + pos[n][1])) + w; //���� ����, ������ ������ ���
    }
    if ((pos[x][0] == 1 && pos[n][0] == 3) || (pos[x][0] == 3 && pos[n][0] == 1)) return pos[x][1] + pos[n][1]; //���� ����, ���� ���
    if (pos[x][0] == 1 && pos[n][0] == 4) return w - pos[x][1] + pos[n][1]; //���簢���� ���� ��, �־��� ���� �������� ���
    if (pos[x][0] == 2 && pos[n][0] == 3) return pos[x][1] + h - pos[n][1]; //���簢���� ���� �Ʒ�, �־��� ���� ������ ���
    if ((pos[x][0] == 2 && pos[n][0] == 4) || (pos[x][0] == 4 && pos[n][0] == 2)) return w - pos[x][1] + h - pos[n][1]; //���� ������, �Ʒ��� ���
    if (pos[x][0] == 3 && pos[n][0] == 2) return pos[n][1] + h - pos[x][1]; //���簢���� ���� ����, �־��� ���� �Ʒ��� ���
    if (pos[x][0] == 4 && pos[n][0] == 1) return w - pos[n][1] + pos[x][1]; //���簢���� ���� ������, �־��� ���� ���� ���
    return -7654321;
}

int main(void) {
    int d = 0;
    scanf("%d %d%d", &w, &h, &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        d += dist(i);
    }
    if (d < 0) return 1;
    printf("%d", d);
    return 0;
}