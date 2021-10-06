#include <stdio.h>

/*
���� : A, B, C, D�� �̷���� ������ ������ 2ĭ ������ �ڷ� 1ĭ ������ ���� �ݺ����� �� N(N <= 10^9)��°�� ���� ���� ���Ѵ�.
ó������ A���� �����Ѵ�.

�ذ� ��� : 12������ A, B, C, B, C, D, C, D, A, D, A, B�� �ݺ��Ǵ� ���� �� �� �ִ�. ����, 12�� ���� �������� ����
��츦 ������ ó���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : HotSpot 2010 1-1��
*/

int main(void) {
    int z, n;
    scanf("%d", &z);
    for (int i = 0; i < z; i++) {
        scanf("%d", &n);
        switch (n % 12) {
        case 0:
        case 2:
        case 4:
            printf("B\n");
            break;
        case 1:
        case 9:
        case 11:
            printf("A\n");
            break;
        case 3:
        case 5:
        case 7:
            printf("C\n");
            break;
        case 6:
        case 8:
        case 10:
            printf("D\n");
            break;
        }
    }
    return 0;
}