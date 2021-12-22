#include <stdio.h>

/*
���� : N * N(N < 100) ũ���� ���ڿ� 'v'�� �ִ��� ���� ��ġ�ϵ�, 'v'������ ���� �����¿�� �������� �ʵ���
��ġ�Ϸ��� �Ѵ�. �̶� (R, C)�� 'v'�� ��ġ�ߴٸ� ������ 'v'�� ��ġ�� ���¸� ����Ѵ�. 'v'�� ��ġ���� ���� ���� '.'���� ǥ���Ѵ�.

�ذ� ��� : 'v'�� �ִ��� ��ġ�ϱ� ���ؼ� 'v'�� ü���� ���·� ��ġ�ؾ� �Ѵ�. �̷��� ��ġ�ϴ� ���� �� 2���� ������,
(R + C)�� (�� + ��)�� 2�� ���� �������� ���� ���� ĭ�� ��ġ�ϸ� ���� ���·� ��ġ�� �����ϴ�.

�ֿ� �˰����� : ����

��ó : ��ϴ� 2018 �䳢��
*/

int main(void) {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((i + j) & 1) == ((r + c) & 1)) printf("v");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}