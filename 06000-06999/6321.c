#include <stdio.h>

/*
���� : ���� 50 ������ �빮�ڷ� �̷���� ���ڿ��� �־��� ��, �� ������ ���� ���ڷ� �̷���� ���ڿ��� ����Ѵ�.
Z�� ���� ���ڴ� A�� �����Ѵ�.

�ذ� ��� : ���ڿ��� Ȯ���ϸ� Z�� ������ A�� ����ϰ� �� �ܿ��� �ƽ�Ű ���� 1�� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : SWERC 1997 PA��
*/

char s[64];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        printf("String #%d\n", i);
        for (int j = 0; s[j]; j++) {
            if (s[j] == 'Z') printf("A");
            else printf("%c", s[j] + 1);
        }
        printf("\n\n");
    }
    return 0;
}