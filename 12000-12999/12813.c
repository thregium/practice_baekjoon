#include <stdio.h>

/*
���� : ���� 10���� ��Ʈ ���ڿ� A, B�� �־��� ��, A & B, A | B, A ^ B, ~A, ~B�� �� ������ ���� ���Ѵ�.

�ذ� ��� : �� �ᱣ������ ���� ���� 10���� ���̴�. ����, 10������ �ݺ��ϸ� �� ��Ʈ���� ������ ����ϰ�
�����ϴ� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����
*/

const int n = 100000;
char a[103000], b[103000];

int main(void) {
    scanf("%s%s", a, b);
    for (int i = 0; i < n; i++) printf("%c", ((a[i] - '0') & (b[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", ((a[i] - '0') | (b[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", ((a[i] - '0') ^ (b[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", (!(a[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", (!(b[i] - '0')) + '0');
    printf("\n");
    return 0;
}