#include <stdio.h>

/*
���� : N * M(N, M <= 1000) ũ���� ����� �־��� ��, ��� ĭ�� 1�� ���� ū �κ� ���簢���� �� ���� ���̸� ���Ѵ�.

�ذ� ��� : ����� �� ĭ�� ���� �ش� ĭ���� ������ ���� ū ���簢���� �� ���� ���̸� �����ϴ� �迭�� �ΰ�
���̳��� ���α׷����� �Ѵ�. ���� �ش� ĭ�� ����ٸ� �� ĭ�� ���� 0�� ���̰�, 1�̶�� �� ĭ�� ����
��ó ĭ���� ���� ���� �˾Ƴ� �� �ִ�. �ش� ĭ�� ��, ����, ���� �� �� ��� ���� ���� �Ϳ��� 1�� ���ϸ� �ȴ�.
�̸� �ݺ��ϸ� ���� ���� ��� ���� ū ���� ã���� ���� �ȴ�.

�ֿ� �˰����� : DP

��ó : SEUSA 2010 E��
*/

int mem[1024][1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, x, r;
    //freopen("E:\\PS\\ICPC\\North America\\Southeast USA\\2010\\maximumsquare.judge", "r", stdin);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &x);
                if (x) mem[i][j] = small(mem[i - 1][j - 1], small(mem[i - 1][j], mem[i][j - 1])) + 1;
                else mem[i][j] = 0;
                if (mem[i][j] > r) r = mem[i][j];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}