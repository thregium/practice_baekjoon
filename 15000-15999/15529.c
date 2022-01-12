#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 1000)���� ���� �ٸ� �ڿ���(<= 10000)�� �־��� ��, ���� ���� ���ڰ� ������ 1�� ���������� �Ǵ�
���� ū ���� ���� ���Ѵ�. �׷��� ���� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ��� �ֿ� ���� ���� ���س����� ������ 1�� ������������ Ȯ���ϰ� ���� ū ���� ã���� �ȴ�.
������ 1�� �������� ���δ� sprintf() �Լ��� �̿��� ���ڿ��� �ٲپ� ������ �ذ� �����ϴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : JAG 2016P A��
*/

int a[1024];
char buff[16];

int main(void) {
    int n, r = -1, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] * a[j] <= r) continue;
            sprintf(buff, "%d", a[i] * a[j]);
            t = 1;
            for (int k = 1; buff[k]; k++) {
                if (buff[k] != buff[k - 1] + 1) t = 0;
            }
            if (t) r = a[i] * a[j];
        }
    }
    printf("%d", r);
    return 0;
}