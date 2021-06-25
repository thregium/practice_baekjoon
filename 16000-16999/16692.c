#include <stdio.h>

/*
���� : N(N <= 1000)���� ���밡 �ְ� C(C <= 1000)���� �մ��� �ִ�. �մԵ��� ���� ���� ������ ���� ���
���� ���� ����� ���ٰ� �� ��, �� �մ��� ��� �ð��� �־����� �� �մԵ��� ���� ������ ��ȣ�� ���Ѵ�.

�ذ� ��� : ���� �״�� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : PacNW 2018 S��
*/

int cashier[1024];

int main(void) {
    int n, c, t, fastest, fi;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &t);
        fi = -1;
        fastest = 987654321;
        for (int j = 0; j < n; j++) {
            if (cashier[j] < fastest) {
                fastest = cashier[j];
                fi = j;
            }
        }
        printf("%d ", fi + 1);
        cashier[fi] += t;
    }
    return 0;
}