#include <stdio.h>

/*
���� : �ڿ��� N(3 <= N <= 10101)�� �־��� ��, 1 + K + K * K�� N�� �ڿ��� K�� ���Ѵ�. K�� �׻� �����ϵ��� �־�����.

�ذ� ��� : N�� 10101�� �� K�� 100�̴�. ����, 1���� 100������ ���� Ȯ���ϸ� K�� �ش� ���� �� N���� Ȯ���ϰ�
N�� �Ǹ� �׶��� K�� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����, ���Ʈ ����

��ó : ������ 2018 A��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 100; i++) {
        if (1 + i + i * i == n) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}