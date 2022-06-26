#include <stdio.h>

/*
���� : N(N <= 100000)���� ������� �Ϸķ� �ִ�. �� ����� c_i(c_i <= 3)���� ������ ���� �ִ�.
������ ���� ����� �ڽ� �Ǵ� �� �� ������� ��ǰ�� ���ļ� �ִ� ���� ����ŭ �� �� �ִ�.
�̶�, ��ǰ�� ���� �� �ִ� ����� �ִ� ���� ���Ѵ�.

�ذ� ��� : �� ����� ��ǰ�� ���� ���ϴ� ���� ���� ������� ��ǰ�� �ִ��� ������ �ִ� ���� �ݺ��ϸ�
��ǰ�� �ִ��� �й��� �� �ִ�. �� ������� �й��� ��ǰ ���� ���ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����

��ó : INC 2020 M��
*/

int c[103000], chk[103000];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        for (int j = i - 1; j <= i + 1; j++) {
            if (j < 1 || j > n || chk[j]) continue;
            if (c[i] <= 0) break;
            chk[j] = 1;
            r++;
            c[i]--;
        }
    }
    printf("%d", r);
    return 0;
}