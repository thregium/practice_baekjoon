#include <stdio.h>
#include <string.h>

/*
���� : ���� 200000 ������ �ҹ��ڷ� �̷���� �� ���ڿ��� �־��� ��, ������ ���ڿ��� ���� �� ���ڿ��� �κ� ���ڿ����� ���Ѵ�.

�ذ� ��� : strstr()�Լ��� O(A + B)�̱� ������ strstr �Լ��� �̿��ϸ� �ð� ���� Ǯ �� �ִ�.

�ֿ� �˰��� : ���ڿ�
*/

char a[204800], b[204800], c[204800];

int main(void) {
    scanf("%s%s%s", a, b, c);
    if (strstr(a, c) && strstr(b, c)) printf("YES");
    else printf("NO");
    return 0;
}