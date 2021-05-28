#include <stdio.h>

/*
���� : ���� M(M <= 10^6)�� ���ڿ����� (I �ڿ� OI�� nȸ ���� An(n * 2 - 1 <= M))�� �����ϴ� Ƚ���� ���Ѵ�.

�ذ� ��� : IOI�� �ݺ��Ǵ� ���� OI�� �� ȸ ���Դ��� ����. �ݺ��� ������ �� ���� �������� An�� �ش� �ݺ����� �� �� ���� �� �ִ��� �˾ƺ���.
���� �ݺ��� n���� �۴ٸ� �� ���� ���� �� ����, n �̻��̶�� (�ݺ� Ƚ��) - n + 1ȸ ���� �� �ִ�.
�̸� �ݺ��Ͽ� ���ڿ� ������ ������ An�� Ƚ���� �� ���� ���������� �ݺ��� �����ٰ� �����ϰ� �ٽ� Ƚ���� �� �� ���� ���ݱ����� ������ ��� �����ָ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : JOI 2009 1�� / 2013 P4�� / 2014 P4��
*/

char s[1048576];

int main(void) {
    int n, m, cnt = 0, counting = 0;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 2; i < m; i++) {
        if (counting == 0 && s[i] == 'I' && s[i - 1] == 'O' && s[i - 2] == 'I') {
            counting = 1;
            i++;
        }
        else if (counting && s[i] == 'I' && s[i - 1] == 'O') {
            counting++;
            i++;
        }
        else if (counting) {
            if (counting >= n) cnt += counting - n + 1;
            counting = 0;
        }
    }
    if (counting >= n) cnt += counting - n + 1;
    printf("%d", cnt);
    return 0;
}