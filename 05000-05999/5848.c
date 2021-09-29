#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 1000)���� �ְ�, ������ F_i�� ������� ������ �Ѵ�. �̶�, ������ �̾���� ������ ������ �ʴ� ����� ���� ���Ѵ�.
F_i�� 0�� ���� �� ������� ������ ������ ���̴�.

�ذ� ��� : N���� ����� ���� �� ����� ������ �ϴٰ� �̹� ������ ������� �ٽ� �����ϴ��� Ȯ���Ѵ�. �������� �ʴ� ���
�ᱣ���� 1�� ���Ѵ�. �̸� �湮 �迭�� �ʱ�ȭ�ϸ� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : USACO 2013F B1��
*/

int mv[1024], vis[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("relay.in", "r");
        fo = fopen("relay.out", "w");
    }
    int n, x, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mv[i]);
    }
    for (int i = 1; i <= n; i++) {
        x = i;
        while (1) {
            vis[x] = 1;
            if (x == 0) {
                r += 1;
                break;
            }
            x = mv[x];
            if (vis[x]) break;
        }
        for (int j = 0; j <= n; j++) vis[j] = 0;
    }
    printf("%d", r);
    return 0;
}