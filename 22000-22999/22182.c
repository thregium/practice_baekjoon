#include <stdio.h>
#define PI 3.141592653589793

/*
���� : N(N <= 100)���� ��(<= 100)�� ������ R(R <= 100)�� �־��� ��,
�� ����� �̷���� ���׷����� �� ���� �����ϴ� ������ ���� ���Ѵ�.

�ذ� ��� : ��ü ���� ���� ���� ����, �� ���� ���� ���� ���̿� ��ü������ ������ ���� ����
�Ź� ����ϸ� �ȴ�. ���� ���̴� 2pir^2�̰� ��ü������ ������ a_i / sum�̴�.

�ֿ� �˰����� : ����, ������

��ó : RCC 2011Q2 A��
*/

int a[128];

int main(void) {
    int n, r, sum = 0;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%.9f\n", a[i] / (double)sum * r * r * PI);
    }
    return 0;
}