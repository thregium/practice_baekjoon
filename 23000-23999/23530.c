#include <stdio.h>

/*
���� : �ڿ��� A, B(A, B <= 50)�� �־��� ��, A + B�� �ƴ� �ڿ��� C(C <= 50)�� ����Ѵ�. �̸� T(T <= 1000)ȸ �ݺ��Ѵ�.

�ذ� ��� : 50 ������ Ư���� �ڿ����� ���ϰ� �� ���� A + B�� ��� �ٸ� Ư���� ���� ����Ѵ�.
�� ���� ��쿡�� ������ Ư���� ���� ����Ѵ�.

�ֿ� �˰����� : ����, ������

��ó : Petro 18/19_18 H��
*/

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        if (a + b == 39) printf("41\n");
        else printf("39\n");
    }
    return 0;
}