#include <stdio.h>

/*
���� : @�� �̷���� 'F'�� ����� N(N <= 100)�� �� ���¸� ����Ѵ�.

�ذ� ��� : ���μ��� ���μ� �κ��� ������ ����ϸ� �ȴ�. ���μ��� @�� �� �ٿ� N * 5���� ����ϰ�,
���μ��� @�� �� �ٿ� N���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int h = 0; h < 2; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n * 5; j++) printf("@");
            printf("\n");
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("@");
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    return 0;
}