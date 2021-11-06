#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N < 100)���� �ٿ� ���� 100�� �̸��� 2^31���� ���� ������ �־�����. �� �ٿ� ���� �� �ٿ� �ִ�
���� �ٸ� ������ �ֿ��� ���� �� �ִ� �ִ����� ��� ���� ū ���� ���� ����Ѵ�.

�ذ� ��� : �켱 �� ���� ���ڿ� ���·� �Է¹޴´�. �� ��������, strtoll �Լ��� �̿��� �� ������ �Ľ��Ѵ�.
0�� ������ ������ End �����Ϳ��� �ݺ��ؼ� Ȯ���ϸ� �ȴ�.
�� ������ �Ľ��� �������� ��� �ֿ� ���� �ִ������� Ȯ���ϰ� ���� ū ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����, �Ľ�

��ó : Thai 2010N J��
*/

char buff[4096];
int num[128];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, m, x, r;
    char* p;
    scanf("%d\n", &n);
    for (int nn = 0; nn < n; nn++) {
        fgets(buff, 4000, stdin);
        m = 0;
        p = buff;
        while (1) {
            x = strtoll(p, &p, 10); //�Ľ��� ���� �� �ٿ� �ִ� ���� ���Ѵ�.
            if (x == 0) break;
            num[m] = x;
            m++;
        }
        
        r = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (gcd(num[i], num[j]) > r) r = gcd(num[i], num[j]);
            }
        }
        printf("%d\n", r);
    }
    return 0;
}