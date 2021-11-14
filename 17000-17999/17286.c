#include <stdio.h>
#include <math.h>
#define INF 1012345678

/*
���� : 4���� ���� �־��� ��, ù ��° ������ ������ ��� ���� �湮�� �� �ִ� �Ÿ��� ���Ѵ�.
�Ҽ��� ���ϴ� ������. ����, �� ���� ��ǥ ������ ���� 10 ������ �����̴�.

�ذ� ��� : ��� ����� ���� �غ���. �Ź� ���� ��ġ���� �Ÿ��� ���س����� ������ ���� �������� ���� �Ÿ� ���
���� ���� ���� ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : ������ 2019 D��
*/

int pos[3][2], vis[3];
int r = INF;

int sqr(int x) {
    return x * x;
}

void track(int c, int x, int y, double t) {
    if (c == 3) {
        if (t < r) r = t;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        track(c + 1, pos[i][0], pos[i][1], t + sqrt(sqr(x - pos[i][0]) + sqr(y - pos[i][1])) + 0.00001);
        vis[i] = 0;
    }
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    track(0, x, y, 0);
    if (r >= INF) return 1;
    printf("%d", r);
    return 0;
}