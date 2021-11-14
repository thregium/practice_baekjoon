#include <stdio.h>

/*
���� : N(N <= 300000)���� �������� �� ���д� Ʈ������ �� ������ �������� ��, �ٽ� ���д� Ʈ���� ���� �� �ִ�
���� ��� �ϳ��� ����Ѵ�.

�ذ� ��� : �������� �� Ʈ���� ������ ���Ͽ� ���ε�� ���ϰ�, 1�� �������� 1���� �ٸ� �������� ����Ǵ�
������ ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �ڷ� ����, ���Ͽ� ���ε�, Ʈ��

��ó : ���� 3ȸ D��
*/

int g[327680];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        scanf("%d %d", &a, &b);
        uni(a, b);
    }
    for (int i = 2; i <= n; i++) {
        if (find(1) != find(i)) {
            printf("%d %d", 1, i);
            return 0;
        }
    }
    return 1;
}