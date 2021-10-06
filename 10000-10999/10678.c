#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 16)���� ������ �ְ�, �� ���� ���̿��� M���� ��ΰ� �ִ�. �� ��δ� ���� ��ȣ�� �����ϴ� �������� �Ϲ������̴�.
�̶�, ��κ��� �� ���� �̵��ϴ� �ð��� ���� �־��� ��, 1�� ��ο��� ����� N�� ��ο� ���ÿ� �����ϴ� ����� �ִ���
Ȯ���ϰ� �ִٸ� �� �� ���� ���� ���� �ҿ�ð��� ���Ѵ�. ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : 1�� �������� ��������� �̵� ������ ��� ��θ� �̿��غ���. N�� ������ �����ϸ� �ش� ������ ������
�� ���� �ҿ� �ð��� ���� �����Ѵ�. ��� ��θ� Ȯ���ϸ� �� ���� �ҿ� �ð� �� ��ġ�� ���� �ִ��� Ȯ���ϰ�
�ִٸ� �׷��� �� ��� ���� ���� ���� ����ϰ� ���ٸ� -1�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2015J B4��
*/

int bessie[32][32], elsie[32][32];
char bchk[16384], echk[16384];
int best = INF;

void track(int n, int s, int x, int b, int e) {
    if (x == n) {
        bchk[b] = 1;
        echk[e] = 1;
    }
    for (int i = x + 1; i <= n; i++) {
        if (bessie[x][i]) {
            track(n, s, i, b + bessie[x][i], e + elsie[x][i]);
        }
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("meeting.in", "r");
        fo = fopen("meeting.out", "w");
    }
    //freopen("meeting.in", "r", stdin);
    //freopen("meeting.out", "w", stdout);
    int n, m, a, b, c, d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bessie[a][b] = c;
        elsie[a][b] = d;
    }
    track(n, 1, 1, 0, 0);
    for (int i = 1; i <= 16000; i++) {
        if (bchk[i] && echk[i]) {
            best = i;
            break;
        }
    }
    if (best == INF) printf("%s", "IMPOSSIBLE");
    else printf("%d", best);
    return 0;
}