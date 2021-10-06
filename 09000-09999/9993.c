#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * M(N, M <= 1000) ũ���� ���ڰ� �־�����. �� ������ �� ĭ���� �밢������ ���� �ſ���� �ִ�. �̶�, ������ �ٱ�����
������ ���� �Ǵ� �������� ��ٸ� �ſ��� �ִ� �� �� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : �ſ� �ٱ����� �� ������ ������ ��� �� ������ �ٸ� �� �ٱ����� ���� ���̴�. �װ����� ���� ��θ� ���󰡸�,
�� ��ο� ��ġ�� ��δ� ���ٴ� ����� �߰��� �� �ִ�. ����, ��� ĭ�� ���� ��ġ�� ��ΰ� ���� ������
��� ������ �����ϴ� ����� ���� �ִ� N * M * 2�̰�, ��� ��θ� ã�ƺ����� �ð� ���� ���ư� �� �ִ�.

�ֿ� �˰��� : ���Ʈ ����, �׷��� �̷�

��ó : USACO 2014F B1��
*/

char mirror[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int reflect(int x, int y, int d) {
    int st = 0;
    while (x >= 0 && x < n && y >= 0 && y < m) {
        if (mirror[x][y] == '/') d = 3 - d;
        else d += ((d & 1) ? -1 : 1);
        x += dxy[d][0];
        y += dxy[d][1];
        st++;
    }
    return st;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("mirror.in", "r");
        fo = fopen("mirror.out", "w");
    }
    int r = 0, step;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", mirror[i]);
    }

    for (int i = 0; i < n; i++) {
        step = reflect(i, 0, 0);
        if (step > r) r = step;
        step = reflect(i, m - 1, 2);
        if (step > r) r = step;
    }
    for (int i = 0; i < m; i++) {
        step = reflect(0, i, 1);
        if (step > r) r = step;
        step = reflect(n - 1, i, 3);
        if (step > r) r = step;
    }
    printf("%d", r);
    return 0;
}