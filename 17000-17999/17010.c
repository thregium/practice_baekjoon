#include <stdio.h>

/*
���� : ���ڿ� �ݺ� Ƚ���� �־��� ��, �� ���ڸ� �ش� Ƚ����ŭ �ݺ��Ѵ�.

�ذ� ��� : ������ ���δ�� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : CCC 2019J 2��
*/

int main(void) {
    int l, n;
    char c;
    scanf("%d", &l);
    for (int tt = 0; tt < l; tt++) {
        scanf("%d %c", &n, &c);
        for (int i = 0; i < n; i++) {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}