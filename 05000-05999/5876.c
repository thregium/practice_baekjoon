#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * N(N <= 5) ũ���� '('�� ')'�� �̷���� �迭�� �ִ�. �̶�, �� �迭���� ���� �� ĭ���� �����̸�
�̷�� ���ڿ��� �Ϻ��� ��ȣ�� �̷�� ���� �� ����� ���̸� ���Ѵ�. �� �� ������ ĭ�� �ٽ� ���ư� �� ����.
�Ϻ��� ��ȣ�� ��� '('�� ���ʿ� ������ ��� ')'�� �����ʿ� �����鼭 '('�� ')'�� ���� ���ڿ��̴�.

�ذ� ��� : (0, 0)�������� ��Ʈ��ŷ�� ���� ���� �� ����� ���̸� ���Ѵ�.
���� ')'�� �� ���̶� ���� ���� '('�� ������ ��� Ž���� �ٷ� �����Ѵ�. '('�� ')'�� �������� ����������
'(' + ')'�� ������ �ᱣ������ ���� ��� �ᱣ���� �����ϰ� Ž���� �����Ѵ�. (���ķ� �Ϻ��� ��ȣ�� ���� �� ������ �� �� �ִ�.)

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : USACO 2012N B3��
*/

char hshoe[8][8], vis[8][8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, res = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void track(int x, int y, int p, int q) {
    if (hshoe[x][y] == '(') {
        if (q > 0) return;
        else p++;
    }
    else if (hshoe[x][y] == ')') q++;

    if (p == q) {
        if (p + q > res) res = p + q;
        return;
    }
    else if (p < q) return;

    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) track(x + dxy[i][0], y + dxy[i][1], p, q);
    }
    vis[x][y] = 0;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hshoe.in", "r");
        fo = fopen("hshoe.out", "w");
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", hshoe[i]);
    }
    track(0, 0, 0, 0);
    printf("%d", res);
    return 0;
}