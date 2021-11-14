#include <stdio.h>

/*
���� : 2019����� N(N <= 100000)����� �����Ǵ� 13���� �ݿ����� ������ ���Ѵ�.

�ذ� ��� : �� ������ �޸��� 13���� ���� �������� Ȯ���ϰ� �ݿ����� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : �Ѿ�� 5ȸB E��
*/

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int isleap(int x) {
    if (x & 3) return 0;
    else if (x % 400 == 0) return 1;
    else if (x % 100 == 0) return 0;
    else return 1;
}

int main(void) {
    int n, r = 0, stt = 2;
    scanf("%d", &n);
    for (int i = 2019; i <= n; i++) {
        if (isleap(i)) {
            for (int j = 1; j <= 12; j++) {
                if ((days[j] + (j > 2) + stt + 12) % 7 == 5) r++;
            }
            stt = (stt + 2) % 7;
        }
        else {
            for (int j = 1; j <= 12; j++) {
                if ((days[j] + stt + 12) % 7 == 5) r++;
            }
            stt = (stt + 1) % 7;
        }
    }
    printf("%d", r);
    return 0;
}