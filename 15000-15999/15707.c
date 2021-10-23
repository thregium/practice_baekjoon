#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : �� ���� �ƴ� ���� A, B(A, B <= 10^20)�� �־��� ��, R(0 <= R < 2^63)���� ū ���̶�� "overflow"��,
�� ���϶�� A * B�� ����� ����Ѵ�.

�ذ� ��� : ����, A�� B�� ���ڿ��� �Է¹޴´�. ���� �ٸ� �� ���� 0�� �ƴѵ� ������ 20�ڸ� �̻�(> 2^63)�̶��
���� �翬�� 2^63���� Ŭ ���̹Ƿ� overflow�� ����ϸ� �ȴ�. 20�ڸ� �̸��̶�� 10^19 - 1�� 2^64���ٴ� �����Ƿ�
unsigned long long�� ����ϸ� ���� �����ϴ�. �� ���� strtoull�Լ��� ����� unsigned long long���� ��ȯ�� ��,
�� ���� 0���� Ȯ���Ѵ�. �ϳ��� 0�̸� ���� 0�̴�. �׷��� �ʴٸ� r / bl�� ���� al�� ���ؼ�
�� ���� �� �۴ٸ� overflow�� ����ϰ�, �� �ܿ��� r ������ ���̹Ƿ� ���� ���غ��� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : �׺��� 1ȸ A��
*/

char a[32], b[32];

int main(void) {
    unsigned long long al, bl, r;
    scanf("%s %s %llu", a, b, &r);
    if ((strlen(a) > 19 || strlen(b) > 19) && !(a[0] == '0' && a[1] == '\0') && !(b[0] == '0' && b[1] == '\0')) {
        printf("overflow");
        return 0;
    }
    al = strtoull(a, NULL, 10);
    bl = strtoull(b, NULL, 10);
    if (al != 0 && bl != 0 && r / bl < al) printf("overflow");
    else printf("%lld", al * bl);
    return 0;
}