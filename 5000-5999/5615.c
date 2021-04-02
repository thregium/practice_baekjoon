#include <stdio.h>
#define ULL unsigned long long
#define MAXI 2147483647

/*
���� : �־��� ���� ��� ������ A = 2xy + x + y�� ���� ������ �̷���� �ذ� ���� A�� ���� ���Ѵ�.

�ذ� ��� : 2xy + x + y�� 2�� ���ϸ� 4xy + 2x + 2y�� �ǰ�, (2x + 1)(2y + 1) = 4xy + 2x + 2y�� �ǹǷ� �� ������ A * 2 + 1�� 3 �̻��� �� Ȧ���� �̷����������
���� �Ͱ� ����. �׷��� 3 �̻��� �� Ȧ���� ���� ���� �� ���� Ȧ���� 3 �̻��� ���μ��� ���ٴ� �ǹ��̰�, Ȧ���̹Ƿ� 2�� ���μ��� ���� �ʴ´�.
�׷��Ƿ� �־��� �������� �ظ� ���� �� ���� ���� 2�� ���ϰ� 1�� ���� ���� �Ҽ��̴�.

�Ҽ� ������ �ؾ� �ϴ� ���� �ִ� 2^32 - 1�̹Ƿ� �Ϲ����� �Ҽ� ���������δ� �ظ� ���� �� ����, �з�-��� �������� �̿��� ���Ѵ�.
�з� ��� ������ ������ ���� 2^32 ������ ��쿡�� a���� 2, 7, 61�� ��� ������������ ����Ǿ����Ƿ� �� 3���� ��츸 �Ǵ��ϸ� �ȴ�.
�̶� �����ÿ��� ���� ������ ����ϰ�, 2^n�� ���� �޸������̼��� ���� �ð��� �����ؾ� �Ѵ�. ����, ���� �÷ο쿡 �����Ѵ�.

�ֿ� �˰��� : ����, ������, �з�-���
*/

int cal = 0;
ULL mem[32];

ULL sqrmul(ULL a, ULL b, ULL c) {
     if (c == 1) return (a * a) % b;
     ULL r = sqrmul(a, b, c - 1);
     //cal++;
     return mem[c] = (r * r) % b;
}

ULL powbig(ULL a, ULL b, ULL c) {
     if (c == 0) return 1;
     if (c == 1) return a % b;
     for (int i = 31; i > 0; i--) {
          //cal++;
          if (c >= 1LL << i) {
               return ((mem[i] ? mem[i] : sqrmul(a, b, i)) * powbig(a, b, c - (1LL << i)) % b);
          }
     }
}

int isprime(ULL n) {
     int a[] = { 2, 7, 61 };
     int s = 0, r = 0;
     ULL d = n - 1, t;
     for (ULL x = n - 1; x % 2 == 0; x /= 2) {
          s++;
          d = x / 2;
     }
     for (int i = 0; i < 3; i++) {
          if (a[i] >= n) break;
          //cal++;
          r = 0;
          for (int i = 0; i < 32; i++) mem[i] = 0;
          t = powbig(a[i], n, d);
          if (t == 1 || t == n - 1) {
               r = 1;
               continue;
          }
          for (int j = 0; j < s; j++) {
               //cal++;
               t = t * t % n;
               if (t == n - 1) {
                    r = 1;
                    continue;
               }
          }
          if (r == 0) {
               return 0;
          }
     }
     return 1;
}

int main(void) {
     int n, no = 0;
     ULL apt;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%lld", &apt);
          //apt = i + 1LL;
          //apt = i + 2100000000LL;
          //apt = (ULL)MAXI - i;
          if (isprime(apt * 2 + 1)) {
               //printf("%lld is prime\n", (ULL)apt * 2 + 1);
               no++;
               //if (cal > 150000000) return 1;
          }
     }
     printf("%d", no);
     return 0;
}