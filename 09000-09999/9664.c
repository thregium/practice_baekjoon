#include <stdio.h>

/*
���� : x - x / N(N <= 15)�� O(O <= 100)�� �Ǵ� x�� ������ ���Ѵ�.

�ذ� ��� : O�� ������ �۱� ������ 200 �̻���� ��� ���� Ȯ���ؼ� O�� �Ǵ� x�� ���� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : COCI 13/14#4 1��
*/

int main(void) {
    int n, o, l = 1000, h = 0;
    scanf("%d %d", &n, &o);
    for (int i = 1; i <= 300; i++) {
        if (i - i / n != o) continue;
        if (i > h) h = i;
        if (i < l) l = i;
    }
    printf("%d %d", l, h);
    return 0;
}