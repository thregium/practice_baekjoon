#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * N(N <= 10) ũ���� �ǿ� ���� �ٸ� ���簢�� 9���� ���� �׷��� ��, �� �ؿ� ���� �� �ִ� ���簢���� �ִ� ������ ���Ѵ�.

�ذ� ��� : ������ ��� ������ ���簢������ �׷�����. �׸��� ���� �ٸ� ���簢�� ���� ���� �׸��� �ʾҴٸ� �� �ؿ� ���� �� �ִ� ���簢���̴�.
���� �׸� ���� �׸��� �־��� �׸��� ���ٸ� ��Ȯ�� �׸� �׸��̹Ƿ�, ������ �� �� ���� ���簢�� ���� �ִ񰪰� ���ؼ� �ִ��� ������Ʈ�Ѵ�.
�̸� ��� ������ ���� �ݺ��� �ִ� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2017O B3��
*/

char paint[16][16], temp[16][16];
int rect[10][4], perm[9], vis[10];
int n, best = 0;

void npaint(void) {
    int p = 0, t, r = 1;
    for (int i = 0; i < 9; i++) {
        if (rect[perm[i]][1] < 0) continue;
        t = 0;
        for (int j = rect[perm[i]][0]; j <= rect[perm[i]][1]; j++) {
            for (int k = rect[perm[i]][2]; k <= rect[perm[i]][3]; k++) {
                if (temp[j][k] - '0') t++; //�̹� �ٸ� ���簢���� �Ʒ� �ִ� ���
                temp[j][k] = perm[i] + '0'; //���ο� �׸� �׸���
            }
        }
        if (!t) p++; //�� ���� ���簢���� �� �� �ִ� ���
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] != paint[i][j]) r = 0; //�׸��� �ٸ� ���
            temp[i][j] = '0';
        }
    }
    if (r && p > best) {
        best = p; //��� ������Ʈ
    }
}

void track(int x, int r) {
    //���� Ʈ��ŷ
    if (r == x) {
        npaint();
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        perm[r] = i;
        track(x, r + 1);
        vis[i] = 0;
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("art.in", "r");
        fo = fopen("art.out", "w");
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", paint[i]);
    }
    for (int i = 1; i <= 9; i++) {
        rect[i][0] = 11;
        rect[i][1] = -1;
        rect[i][2] = 11;
        rect[i][3] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (paint[i][j] - '0' > 0) {
                //��ó��(�� ���簢���� ũ��)
                if (i < rect[paint[i][j] - '0'][0]) rect[paint[i][j] - '0'][0] = i;
                if (i > rect[paint[i][j] - '0'][1]) rect[paint[i][j] - '0'][1] = i;
                if (j < rect[paint[i][j] - '0'][2]) rect[paint[i][j] - '0'][2] = j;
                if (j > rect[paint[i][j] - '0'][3]) rect[paint[i][j] - '0'][3] = j;
            }
            temp[i][j] = '0'; //��ó��(�ӽ� �׸�)
        }
    }
    track(9, 0);
    printf("%d", best);
    return 0;
}