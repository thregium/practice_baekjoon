#include <stdio.h>

/*
���� : N(N <= 100)���� �ڿ����� ���������� ���ĵ� ���¿��� �� ���� �� ��°�� ���� ������ �־�����.
�̶� �� ���� �� �� �ִ� ��� �� �ϳ��� �ƹ��ų� ����Ѵ�. �� ������ 10^1000 ���ϰ� �Ǿ�� �Ѵ�.

�ذ� ��� : �������� �� ������ ���� �ڸ� ������ ���ϱ� ������ ���� ���ڵ��� ���� �ڸ����� ���߾�� ä��
1�� �ø��� ������ ����ϸ� �ȴ�. �׸���, ���� ���� ������ �ڸ����� ũ�� ������ �� ū ���� �Ǳ� ������
�� ������ �ڿ� �������� �ƹ� �ڸ����� �߰��صθ� ���� ���� �� �ִ�.

�ֿ� �˰����� : ������, �ֵ� Ȥ

��ó : GCPC 2020 M��
*/

int main(void) {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%d", 100 + i);
        for (int j = 0; j < a; j++) printf("103000");
        printf(" ");
    }
    return 0;
}