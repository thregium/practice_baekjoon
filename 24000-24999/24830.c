#include <stdio.h>

/*
���� : ���峭 ���Ⱑ �ִ�. �� ���꿡 ���� �ᱣ���� �ٸ��� ���ǵǾ��� ��, �����ڿ� ������
�� ��(<= 100000, ���� �ƴ� ����)�� �־����� �Ź� �ᱣ���� ���Ѵ�.

�ذ� ��� : �����ڿ� ���� ��츦 ������ ���� ���ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, ���̽� ��ũ

��ó : VTTH 2019 M��
*/

int main(void) {
    int n;
    long long a, b, l = 1, r;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %c %lld", &a, &c, &b);
        if (c == '*') r = (a * b) * (a * b);
        else if (c == '+') r = a + b - l;
        else if (c == '-') r = (a - b) * l;
        else if (c == '/') r = ((a + 1) >> 1);
        else return 1;
        l = r;
        printf("%lld\n", r);
    }
    return 0;
}