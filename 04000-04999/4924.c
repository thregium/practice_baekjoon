#include <stdio.h>

/*
���� : x�� 1�� �� 0, �Ҽ��� �� -1, �ռ����� �� (���μ��� ����)�� ���ǵǴ� �Լ� p(x)���� sum(p(x) - 1, s, e)�� ����
L <= S <= E <= U(L, U <= 10^6)�� sum(p(x) - 1, s, e)�� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� �� ���� �Ҽ� ���ο� ���μ��� ���������� ���� p(x)�� ���� �̸� ���صд�.
�� ����, p(x)���� 1���� �� ��, L�� U�� �־��� �� ���� �κ� �ִ��� ���̳��� ���α׷������� ���س����� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, DP

��ó : Arab 2006 F��
*/

int p[1048576];

int main(void) {
    int l, u, r = 0, last = 0;
   //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2006\\F. Johnny Hates Number Theory [prime]\\prime.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2006\\F. Johnny Hates Number Theory [prime]\\prime_t.out", "w", stdout);
    for (int i = 2; i <= 1000000; i++) {
        if (p[i]) continue;
        p[i] = -1;
        for (int j = i * 2; j <= 1000000; j += i) {
            for (int k = j; k % i == 0; k /= i) p[j]++;
        }
    }
    for (int i = 1; i <= 1000000; i++) p[i]--;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &l, &u);
        if (u < 0) break;
        r = -2, last = 0;
        for (int i = l; i <= u; i++) {
            if (last + p[i] > p[i]) last += p[i];
            else last = p[i];
            if (last > r) r = last;
        }
        printf("%d. %d\n", tt, r);
    }
    return 0;
}