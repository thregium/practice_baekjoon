#include <stdio.h>

/*
���� : N!�� ���� �ٴ� 0�� ������ M(1 <= M <= 10^8)���� ���� ���� N�� ���Ѵ�.

�ذ� ��� : M�� ũ�Ⱑ �ణ ũ�Ƿ� M�� 6�� ����(N ���� 25 ����)�� ����� ������.

�ֿ� �˰��� : ����, ������
*/

int main(void) {
    int m, c = 0, l = 0;
    scanf("%d", &m);
    for (int i = 1;; i++) {
        l = c;
        c += 6;
        for (int j = i; j % 5 == 0; j /= 5) c++;
        if (m <= l + 4) {
            printf("%d", (i - 1) * 25 + (m - l) * 5);
            break;
        }
        else if (m < c) {
            printf("-1");
            break;
        }
    }
    return 0;
}