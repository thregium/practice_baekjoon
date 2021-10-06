#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 1���� N(N <= 1000)������ �������� ������ ���� ���� ���� ������� ���� N - 1�� ������ �־�����.
�̶�, ���� ������ �� �� �ִ� �� �� ���������� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �� �� ���� �������� ������ ��� ���� ���� �� ������ �� �� �ִ�.
����, �� �� ���� 1���� ���ʷ� �÷����� ���� �� �� �ִ� ������ ������ �� ������ ����ϰ� ���α׷��� �����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ģ����

��ó : USACO 2020J B2��
*/

int b[1024], a[1024], vis[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("photo.in", "r");
        fo = fopen("photo.out", "w");
    }
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) vis[j] = 0;
        a[0] = i;
        vis[i] = 1;
        t = 1;
        for (int j = 1; j < n; j++) {
            a[j] = b[j - 1] - a[j - 1];
            if (a[j] < 1 || a[j] > n || vis[a[j]]) {
                t = 0;
                break;
            }
            vis[a[j]] = 1;
        }
        if (t) {
            for (int j = 0; j < n; j++) {
                printf("%d", a[j]);
                if (j < n - 1) printf("%c", ' ');
            }
            return 0;
        }
    }
    return 1;
}