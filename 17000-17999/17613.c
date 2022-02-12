#include <stdio.h>

/*
���� : [X, Y](1 <= X <= Y <= 10^9)���� ���� ū ���� ���� ���Ѵ�.
���� ���� 0���� 1, 2, 4, 8, ... ������ �����ϸ� �� ĭ�� ���� ������ �ּ� ���� Ƚ���̴�.
���� ���� ������ ���� �Ÿ��� 1�� �ǵ��� �� �ִ�.

�ذ� ��� : �� ������ ���� Ƚ���� �׸��� �˰����� �����Ѵ�. �Ѿ�� �� �κб���
������ ���� �Ÿ��� �ʱ�ȭ�ϴ� ���� �ݺ��ϸ� �ּ� ���� Ƚ���� �Ǳ� �����̴�.
�̸� �̿��� ������ ���� ū ���� �� ���� �������� ���� �� �ִ�.
������ ��ġ x���� �� �� �ִ� ���� ū 2^i - 1�� �� ���� i + (jump(x - (2^i - 1)))�� ���ٴ� ���� �̿��Ѵ�.
���ʰ� ������ ������ �� ������ �Ǵµ�, �̶� (2^i - 1) * 2�� x���� ���� ���
�߰��� ���� ���������� ����ϰ� �� ���� ���� ���� ������ Ǯ�� �ð� ���� Ǫ�� ���� �����ϴ�.
�߰��� ���� i�� 1�� �ƴ϶�� sum(1, i - 1) + 1�� ����.

�ֿ� �˰��� : ����, ���� ����, �׸��� �˰���?

��ó : ���� 2019_1 ��2��
*/

int mem[103000][32], res[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int gethighest(int s, int e, int n) {
    if (s > e) return -1;
    if (s == e && s == 0) return n;
    int r = -1;
    for (int i = 30; i >= 1; i--) {
        if (s <= (1LL << i) - 1 && (1LL << i) - 1 <= e) {
            r = big(r, gethighest(s, (1LL << i) - 2, n));
            if (((1LL << i) - 1) * 2 <= e) {
                //r = big(r, gethighest(0, ((1LL << i) - 1), n + i));
                if (i > 1) r = big(r, n + i + (((i - 1) * i) >> 1) + 1);
                r = big(r, gethighest(0,
                    e - ((1LL << i) - 1) * 2, n + i * 2));
            }
            else {
                r = big(r, gethighest(0, e - (1LL << i) + 1, n + i));
            }
            break;
        }
        else if ((1LL << i) - 1 < s) {
            r = big(r, gethighest(s - (1LL << i) + 1, e - (1LL << i) + 1, n + i));
            break;
        }
    }
    return r;
}

int main(void) {
    int n, m, c = 0, t, a, b;
    //scanf("%d", &n);
    n = 1000;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 32; j++) mem[i][j] = 1012345678;
    }
    mem[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 25; j++) {
            mem[i + 1][1] = small(mem[i + 1][1], mem[i][j] + 1);
            if (i + (1 << j) <= n) {
                mem[i + (1 << j)][j + 1] = small(mem[i + (1 << j)][j + 1], mem[i][j] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        m = 103000;
        for (int j = 0; j < 25; j++) {
            if (mem[i][j] < m) m = mem[i][j];
        }
        if (((i + 1) & (-(i + 1))) == i + 1) c++;
        //printf("%d: %d %d\n", i, m, m - c);
        res[i] = m;
        if (res[i] - c != res[i - (1 << c) + 1]) {
            printf("%d != %d\n", res[i] - c, res[i - (1 << c) + 1]);
            return 1;
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            printf("%d-%d: %d\n", i, j, gethighest(i, j, 0, 3));
            m = -1;
            for (int k = i; k <= j; k++) {
                m = big(m, res[k]);
            }
            if (gethighest(i, j, 0, 3) != m) {
                printf("%d != %d", gethighest(i, j, 0, 3), m);
                return 1;
            }
        }
    }
    */
    
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", gethighest(a, b, 0));
    }
    
    return 0;
}