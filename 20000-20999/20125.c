#include <stdio.h>

/*
���� : N * N(N <= 1000) ũ���� �迭�� ��� ����� �־��� ��, ������ ��ġ�� ����, ������, �㸮, �޴ٸ�, �����ٸ��� ���̸�
���� ���Ѵ�.

�ذ� ��� : �����¿�� '*'�� �ִ� ���� ã���� �װ��� ������ ��ġ�̴�. �� ���ķδ� ������ ��ġ�� �̿���
����, ������, �㸮, �޴ٸ�, �����ٸ��� ���̸� ���� �� �ִ�.

�ֿ� �˰��� : ����, �ֵ� Ȥ

��ó : ������ 2020 B��
*/

char s[1024][1024];

int main(void) {
    int n, x = -1, y = -1, la = 0, ra = 0, w = 0, ll = 0, rl = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (s[i][j] == '*' && s[i + 1][j] == '*' && s[i][j + 1] == '*' && s[i - 1][j] == '*' && s[i][j - 1] == '*') {
                if (x >= 0) return 1;
                x = i;
                y = j;
            }
        }
    }
    if (x < 0) return 2;
    printf("%d %d\n", x + 1, y + 1);
    for (int i = 0; i < y; i++) {
        if (s[x][i] == '*') la++;
    }
    for (int i = y + 1; i < n; i++) {
        if (s[x][i] == '*') ra++;
    }
    for (int i = x + 1; i < n; i++) {
        if (s[i][y] == '*') w++;
    }
    for (int i = x + 1; i < n; i++) {
        if (s[i][y - 1] == '*') ll++;
    }
    for (int i = x + 1; i < n; i++) {
        if (s[i][y + 1] == '*') rl++;
    }
    printf("%d %d %d %d %d", la, ra, w, ll, rl);
    return 0;
}