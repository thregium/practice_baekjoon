#include <stdio.h>

/*
���� : 2^n ũ���� ��� ���Ұ� 1�� ���簢��Ŀ��� ��������� ������ �Ʒ�ĭ�� -1�� ���� ����� �ִٰ� �Ѵ�.
�� ����� r��° ���� s��°���� e��°���� ������ ���� ���Ѵ�. (N <= 60)

�ذ� ��� : r��° ���� s - 1��°�� e��°�� �������� ���� ���ؼ� �ذ��Ѵ�.
�������� r�� c�� ��Ʈ ������ ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ������, ��Ʈ����ŷ

��ó : Arab CPC 2008 I��
*/

long long presum(long long r, long long c) {
    long long lsb = r & -r; //lsb ���ϱ�
    long long t = r && ((c + 1) & (lsb * 2 - 1)) > lsb ? lsb - ((c + 1) & (lsb - 1)) : ((c + 1) & (lsb * 2 - 1));
    //r�� lsb * 2�� ���� �������� ������ ��. ��, �� ���� lsb���� ũ�ٸ� lsb * 2���� ���� ���� ��.
    for (int k = 0; k < 61; k++) {
        if ((1LL << k) <= lsb) continue;
        if ((1LL << k) & (c + 1) & r) t = -t; //lsb���� ū ��Ʈ ��� r�� c + 1���� ��� 1�� ��Ʈ�� ����ŭ ���� ������Ŵ
    }
    return t;
}

int main(void) {
    long long n, r, s, e;
    while (1) {
        scanf("%lld %lld %lld %lld", &n, &r, &s, &e);
        if (n < 0) break;
        printf("%lld\n", presum(r, e) - presum(r, s - 1)); //������ ���ϱ�
    }
    return 0;
}