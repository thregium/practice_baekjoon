#include <stdio.h>

/*
���� : N * M(N, M <= 14) ũ���� �����ǿ� 'A'���� 'F'������ �빮�ڰ� ���� �ִ�. �� �������� 1 * 2 ũ�� ������ �߶� ��,
�߶� ���� ���� ���� ū ��� �� ���� ���Ѵ�. �߶� ���� ������ �־��� ��Ĵ�� ���ĺ��� ���� �Ű�����.

�ذ� ��� : �� ���ĺ��� ���� ���� �̸� �Űܵд�. �� �ٸ��� ���� ���� ���¸� ���ܵθ� ���� �Ǵ� ���η� �߶󳻴� ����
�ݺ��� ������ �� ������ �ִ��� �����Ѵ�. �� ���� ��� ���� ū ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : DP, ��ƮDP
*/

char tofu[16][16];
int mem[16][16][32768];

int big(int a, int b) {
    return a > b ? a : b;
}

int getval(char a, char b) {
    if (a == 'A' && b == 'A') return 10;
    else if ((a == 'A' && b == 'B') || (a == 'B' && b == 'A')) return 8;
    else if ((a == 'A' && b == 'C') || (a == 'C' && b == 'A')) return 7;
    else if ((a == 'A' && b == 'D') || (a == 'D' && b == 'A')) return 5;
    else if ((a == 'B' && b == 'B')) return 6;
    else if ((a == 'B' && b == 'C') || (a == 'C' && b == 'B')) return 4;
    else if ((a == 'B' && b == 'D') || (a == 'D' && b == 'B')) return 3;
    else if ((a == 'C' && b == 'C')) return 3;
    else if ((a == 'C' && b == 'D') || (a == 'D' && b == 'C')) return 2;
    else if ((a == 'D' && b == 'D')) return 2;
    else if ((a == 'F' && b == 'F')) return 0;
    else return 1;
}

int main(void) {
    int n, m, x, ib, jb, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", tofu[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < (1 << (m + 1)); k++) {
                if (i == 0 && j == 0) {
                    x = 0;
                    continue;
                }
                ib = i - (j == 0); //���� ĭ
                jb = (j == 0 ? m - 1 : j - 1); //���� ĭ
                x = mem[ib][jb][k >> 1];
                x = big(x, mem[ib][jb][(k >> 1) + (1 << m)]);

                if (j > 0 && ((k & 3) == 3)) {
                    //���η� �߶󳻴� ���
                    x = big(x, mem[ib][jb][(k - 3) >> 1] + getval(tofu[i][j], tofu[i][j - 1]));
                    x = big(x, mem[ib][jb][((k - 3) >> 1) + (1 << m)] + getval(tofu[i][j], tofu[i][j - 1]));
                }
                if (i > 0 && (k & 1) && (k & (1 << m))) {
                    //���η� �߶󳻴� ���
                    x = big(x, mem[ib][jb][(k - (1 << m)) >> 1] + getval(tofu[i][j], tofu[i - 1][j]));
                    x = big(x, mem[ib][jb][((k - (1 << m)) >> 1) + (1 << m)] + getval(tofu[i][j], tofu[i - 1][j]));
                }

                mem[i][j][k] = x;
                if (x > r) r = x;
            }
        }
    }

    printf("%d\n", r);

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            x = 0;
            for (int k = 0; k < (1 << (m + 1)); k++) {
                if (mem[i][j][k] > x) x = mem[i][j][k];
            }
            printf("%d ", x);
        }
        printf("\n");
    }
    */
    return 0;
}