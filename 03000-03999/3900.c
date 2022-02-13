#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� �������� �̷���� ����ġ(<= 10000) �׷����� �ִ�. �� �׷����� ���д� Ʈ�� ���
���� ����ġ�� ū ������ ���� ���� ������ ���̰� ���� ���� ���д� Ʈ���� ����ġ ���̸� ���Ѵ�.
���д� Ʈ���� ���� �� ���� ��� -1�� ����Ѵ�.

�ذ� ��� : �׷����� ��� ������ ũ�� ������ ������ ����, ������ �����ϰ� MST�� ����� ������.
���д� Ʈ���� ��������� ������ ����ġ ���̸� Ȯ���ϰ� �ᱣ���� �����Ѵ�.
�̸� MST�� ��������� ���� �� ���� �ݺ��Ѵ�. MST�� ��������� �ʴ´ٸ� ������ �� ū ���
MST�� ������� �� �����Ƿ� Ž���� ������ �� �ִ�.
�� �������� ����ġ ���̰� ���� ���� ���� �� ���� ���ϰ� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST, �� ������

��ó : Tokyo 2007 F��
*/

int ed[5120][3], g[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, r, e, c;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &ed[i][1], &ed[i][2], &ed[i][0]);
        }
        qsort(ed, m, sizeof(int) * 3, cmp1);
        r = 103000;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) g[j] = 0;
            c = 0, e = i - 1;
            for (int j = i; j < m; j++) {
                e = j;
                if (find(ed[j][1]) != find(ed[j][2])) {
                    uni(ed[j][1], ed[j][2]);
                    c++;
                }
                if (c == n - 1) {
                    if (ed[j][0] - ed[i][0] < r) r = ed[j][0] - ed[i][0];
                    break;
                }
            }
            if (e == m - 1 && c < n - 1) break;
        }
        printf("%d\n", r == 103000 ? -1 : r);
    }
    return 0;
}