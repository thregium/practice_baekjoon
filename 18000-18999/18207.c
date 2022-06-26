#include <stdio.h>

/*
���� : N(N <= 200000)���� �ڿ���(<= 10^9)�� �̷���� �迭�� �־�����.
�̶�, �� �迭���� ���ӵ� ���� 2 �̻��� ���� ��� �̷�� �ڿ����� �հ� ���� ���� ���� ������ ���Ѵ�.

�ذ� ��� : �迭���� ���ӵ� 1���� ���� ����ٸ� �� �������� ���� ��ü ���� �Ѿ�� ��������
��� O(Nlog(sum)) �ð� ���� ���� �� �ִ�. 1���� ���� ���� �����Ƿ� ���ӵ� 1���� ���ÿ� Ȯ���Ѵ�.
���� 1�� �ƴ� ���� �̵��ϸ鼭 ���� �հ� �� + (���ӵ� 1�� ����) ���� ������ ������
�׷��� Ƚ���� ���� �� ������ �ȴ�. �׸��� �տ� ���ӵ� 1���� ���ϰ� ���� 1�� �ƴ� ����
�Ѿ�� ���� �ݺ��Ѵ�. �̶� ���� ��ü ���� �Ѿ���� Ȯ���ϴ� �������� �����÷ΰ� �� �� �����Ƿ�
���������� ������ش�.

�ֿ� �˰����� : ����, ��Ʈ��ŷ

��ó : MidC 2019 J��
*/

int a[204800], nn1[204800];

int main(void) {
    int n;
    long long sa = 0, m, s, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sa += a[i];
    }
    for (int i = n; i >= 0; i--) {
        if (a[i] == 1) continue;
        for (int j = i - 1; j >= 0; j--) {
            nn1[j] = i;
            if (a[j] != 1) break;
        }
    }
    for (int i = 0; i < n; i++) {
        m = 1, s = 0;
        for (int j = i; j < n; j = nn1[j]) {
            if (sa / a[j] < m) break;
            m *= a[j];
            s += a[j];
            if (j > i && s <= m && m <= s + nn1[j] - j - 1) r++;
            s += nn1[j] - j - 1;
        }
    }
    printf("%lld", r);
    return 0;
}