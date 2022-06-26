#include <stdio.h>

/*
���� : ���� �ƴ� ���� T(T <= 2^50)�� �־��� ��, �������� T�� �ķ� �������� ������ ����
��� �ϴ� �ּ� �ð��� ���Ѵ�. ������ ó���� �������� ������
�� �ʸ��� 3��� �Ǵ� 1/3��� ��ư�� ���� �� �ִ�. �� ��ư�� ������ ������ �ش� ����� �ӵ��� ���Ѵ�.

�ذ� ��� : �������� �������� ���ƿ;� �ϹǷ� �� 3�� �ŵ������� ���� �ش� �ӵ��� �� �� �ִ�
�ּ� T�� �� ���� N�̶� �� �� 2 * N - 2�̴�. ����, �� �ӵ� ������ ��� 3�� �ŵ����� �ӵ���
������ �ʸ�ŭ ���ϴ� ���� �����ϹǷ� ���� �ð��� ū �������� �� ������ ���� ã�� �� �ִ�.

�ֿ� �˰����� : ����, �׸��� �˰�����

��ó : Yokohama 2019 A�� // Petro 2020W2 A��
*/

long long b3[64];

int main(void) {
    long long t, r = 0;
    scanf("%lld", &t);
    b3[0] = 1;
    for (int i = 1; i < 64; i++) b3[i] = b3[i - 1] * 3;
    for (int i = 0; i < 64; i++) {
        if (b3[i + 1] * 2 - 2 > t) {
            t -= b3[i] * 2 - 2;
            r = i * 2;
            for (int j = i; j >= 0; j--) {
                while (t >= b3[j]) {
                    t -= b3[j];
                    r++;
                }
            }
            break;
        }
    }
    printf("%lld\n", r);
    return 0;
}