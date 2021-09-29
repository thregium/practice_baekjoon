#include <stdio.h>

/*
���� : N(N <= 10)���� ������ �־��� ��, (0, 0)���� �� �������� ��� ���� (0, 0)���� ���� ����� �������� ���Ѵ�.
��, �� ������ ���̸� �� ������ �����¿� �������θ� �� �� �ְ�, �� �����鿡���� �ݵ�� �ٸ� �������� �̵��ؾ� �Ѵ�.
�� ������ ��ǥ ������ +- 1000 ���ϸ� ��ΰ� ������ ������ �ٸ��ٸ� ���� �ٸ� ��η� ó���Ѵ�.

�ذ� ��� : (0, 0)���� ������ ��Ʈ��ŷ�� �Ѵ�. X��ǥ�� Y��ǥ�� ��� �ٸ� ���� �����¿츦 ���� �̵� �Ұ����ϹǷ�
�̵��� �� ����, �� �� �ϳ��� ���� ���� ������ �������� �������� �̵��� ����� ���� ��츦 �����ϰ� �̵��ϸ� �ȴ�.
���� �߰��� �湮�� �� ���� �̵� �Ұ����ϴ�. ��� �����鿡 �����ߴٸ� (0, 0)���� ���ư��� ���� ������ ��
�ᱣ���� 1�� �߰��Ѵ�. ��� ��θ� Ž���� ���� �ᱣ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : USACO 2012M B2��
*/

int point[16][2], chk[16];
int res = 0;

int getdir(int a, int b) {
    if (point[a][0] != point[b][0] && point[a][1] != point[b][1]) return -1;
    else if (point[a][0] == point[b][0]) {
        if (point[a][1] > point[b][1]) return 0;
        else return 2;
    }
    else {
        if (point[a][0] > point[b][0]) return 1;
        else return 3;
    }
}

void track(int n, int r, int x, int d) {
    if (n == r) {
        if (getdir(x, 10) != d && getdir(x, 10) >= 0) res++;
        return;
    }

    chk[x] = 1;
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        if (getdir(x, i) != d && getdir(x, i) >= 0) track(n, r + 1, i, getdir(x, i));
    }
    chk[x] = 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    track(n, 0, 10, -1);
    printf("%d", res);
    return 0;
}