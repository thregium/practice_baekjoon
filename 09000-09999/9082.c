#include <stdio.h>

/*
���� : ���� N(N <= 100)�� �Ϸķ� ������ ĭ�� ���� ������ ���ڰ� Ȯ���� �ִ� ĭ���� �־��� ��,
������ �ִ� ������ ���Ѵ�. �Ұ����� ���� �־����� �ʴ´�.

�ذ� ��� : �� ���� ĭ�� ���� ���ΰ� �����Ǹ� ������ ĭ�� ���� ���θ� ��� �� �� �ֱ� ������,
�� ���� ĭ�� ���ڰ� �ִ� ���� ���� ��츦 ������ ������ ĭ�� ���� ���θ� ������ ����,
���� �´� �� Ȯ���غ��� �´� �� ��� �� ���� ������ ���� ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���?, ���Ʈ ����

��ó : Seoul 2003I D��
*/

char hint[128], mine[128], tmine[128];

int main(void) {
    int t, n, res, valid, minecnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        scanf("%s%s", hint + 1, mine + 1);
        res = -1;
        tmine[1] = '.';
        for (int i = 2; i <= n; i++) {
            if ((hint[i - 1] - '0') - (tmine[i - 2] == '*') - (tmine[i - 1] == '*')) tmine[i] = '*';
            else tmine[i] = '.';
        }
        valid = 1, minecnt = 0;
        for (int i = 1; i <= n; i++) {
            if (mine[i] == '*' && tmine[i] != '*') valid = 0;
            if ((hint[i] - '0') != (tmine[i - 1] == '*') + (tmine[i] == '*') + (tmine[i + 1] == '*')) {
                valid = 0;
            }
            if (tmine[i] == '*') minecnt++;
        }
        if (valid && minecnt > res) res = minecnt;

        tmine[1] = '*';
        for (int i = 2; i <= n; i++) {
            if ((hint[i - 1] - '0') - (tmine[i - 2] == '*') - (tmine[i - 1] == '*')) tmine[i] = '*';
            else tmine[i] = '.';
        }
        valid = 1, minecnt = 0;
        for (int i = 1; i <= n; i++) {
            if (mine[i] == '*' && tmine[i] != '*') valid = 0;
            if ((hint[i] - '0') != (tmine[i - 1] == '*') + (tmine[i] == '*') + (tmine[i + 1] == '*')) {
                valid = 0;
            }
            if (tmine[i] == '*') minecnt++;
        }
        if (valid && minecnt > res) res = minecnt;

        if (res < 0) return 1;
        printf("%d\n", res);

        for (int i = 0; i < 128; i++) tmine[i] = '\0';
    }
    return 0;
}