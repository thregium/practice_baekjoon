#include <stdio.h>

/*
���� : ��Ģ���� ���� �־��� ��, �� ���� �´��� ���Ѵ�.

�ذ� ��� : ���� �����ڿ� ���� ��츦 ������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : ���δ� 2016 H��
*/

int main(void) {
    int t;
    long long a, b, r;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %c %lld = %lld", &a, &c, &b, &r);
        if (c == '+') printf("%s\n", a + b == r ? "correct" : "wrong answer");
        else if (c == '-')printf("%s\n", a - b == r ? "correct" : "wrong answer");
        else if (c == '*')printf("%s\n", a * b == r ? "correct" : "wrong answer");
        else if (c == '/')printf("%s\n", a / b == r ? "correct" : "wrong answer");
        else return 1;
    }
    return 0;
}