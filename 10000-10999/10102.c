#include <stdio.h>

/*
���� : ���� V(V <= 15)�� A�� B�� �̷���� ���ڿ����� A�� B �� ������ �� ������ ���Ѵ�.

�ذ� ��� : �� ���ڵ��� ����.

�ֿ� �˰��� : ���ڿ�

��ó : CCC 2014J 2��
*/

char vote[32];

int main(void) {
    int v, a = 0, b = 0;
    scanf("%d%s", &v, vote);
    for (int i = 0; i < v; i++) {
        if (vote[i] == 'A') a++;
        else b++;
    }
    printf("%s", a > b ? "A" : a == b ? "TIE" : "B");
    return 0;
}