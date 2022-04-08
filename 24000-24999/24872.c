#include <stdio.h>
#include <stdlib.h>
#define INF 1234567890987654321

/*
���� : 10^17 ������ �ڿ��� X�� 0 �Ǵ� 1�� K�� �־��� ��, X �̻��̸鼭 �ִ� K�� ������ ���� �����ϸ�
��� ���� ������ ���� ���� ���� ���Ѵ�.

�ذ� ��� : 1�� ������ ���ڸ� ������ ��� ���� ���ڷ� �̷���� ���� ���� �ʱ� ������
�̷��� ������ ���Ʈ ������ ���� ã�Ƴ� ���� �� ���� ��ο� ���ϴ� ������� ���� ã�Ƴ� �� �ִ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : ROI 2021R 6��
*/

char s[32];
long long k0[2048], k1[16384];

int main(void) {
    int p0 = 0, p1 = 0;
    long long x, k, r = INF;
    for (int i = 1; i <= 18; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < i; k++) s[k] = j + '0';
            for (int k = 0; k < i; k++) {
                for (int l = 0; l <= 9; l++) {
                    if (k + l == 0 || (j == 0 && k != 0)) continue;
                    s[k] = l + '0';
                    if (l == j) k0[p0++] = strtoll(s, NULL, 10);
                    else k1[p1++] = strtoll(s, NULL, 10);
                }
                s[k] = j + '0';
            }
        }
    }
    scanf("%lld%lld", &x, &k);
    for (int i = 0; i < p0; i++) {
        if (k0[i] < r && k0[i] >= x) r = k0[i];
    }
    if (k == 1) {
        for (int i = 0; i < p1; i++) {
            if (k1[i] < r && k1[i] >= x) r = k1[i];
        }
    }
    printf("%lld", r);
    return 0;
}