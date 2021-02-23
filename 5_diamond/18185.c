#include <stdio.h>

/*
���� : N���� ��� ���忡�� ��Ȯ�� A[i]���� ����� ��� �Ѵ�. ����� ��� ����� 7���� �ְ� i, i + 1, i + 2�� ���忡�� ����� �ϳ��� ��ų�
5���� �ְ� i, i + 1�� ���忡�� �ϳ��� ��ų� 3���� �ְ� i�� ���忡�� ����� �ϳ� ��� ����� �ִ�. �� ����� ���� ����� �� �� ��� �ּ� ����� ����Ѵ�.

�ذ� ��� : �ѹ��� �ִ��� ���� ����� ��� ���� ��κ��� ��Ȳ���� �����ϴ�. ��, i + 1�� ���忡�� �� ����� i���� i + 2�� ���忡�� �� ��麸�� ���� ��쿡��
���� 2������ ��� ������ 3������ ��� ���� �� �� ���� �� �� �ִ�. �׷��Ƿ� �׸��� �˰����� ����ؼ� �� ��ġ���� ���� ���� �� �� �ִ� ����� �����ϵ�
i + 1�� ���忡�� �ʿ��� ���� i���� i + 2������ �ʿ��� ������ ���� ��� 2�� + 3���� �� �� �ֵ��� ���ܸ� �ξ�� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���
*/

int a[10240];
int arr[10] = { 1, 5, 25, 125, 625 };
int t = 0;

long long int small(long long int a, long long int b) {
     return a < b ? a : b;
}

int small3(int a, int b, int c) {
     return small(small(a, b), c);
}

long long int bf(int n, long long x, long long rr) {
     for (int i = 0; i < n; i++) {
          if (i < n - 2 && a[i] && a[i + 1] && a[i + 2]) {
               a[i]--;
               a[i + 1]--;
               a[i + 2]--;
               rr = small(rr, bf(n, x + 7, rr));
               a[i]++;
               a[i + 1]++;
               a[i + 2]++;
          }
          if (i < n - 1 && a[i] && a[i + 1]) {
               a[i]--;
               a[i + 1]--;
               rr = small(rr, bf(n, x + 5, rr));
               a[i]++;
               a[i + 1]++;
          }
          if (a[i]) {
               a[i]--;
               rr = small(rr, bf(n, x + 3, rr));
               a[i]++;
          }
     }
     for (int i = 0; i < n; i++) {
          if (a[i]) return rr;
     }
     if (x < rr) {
          rr = x;
          x = 0;
          return rr;
     }
     else {
          x = 0;
          return rr;
     }
}

int main(void) {
     int n, s, f = 0;
     long long int rr = 0, r = 0;
     long long int sum = 0;
     while (t < 625) {
          //scanf("%d", &n);
          n = 4;
          for (int i = 0; i < n; i++) {
               //scanf("%d", &a[i]);
               a[i] = (t / arr[i]) % 5;
               sum += a[i];
          }
          //printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);

          //brute-force

          rr = bf(n, 0, 999999999999);
          r = 0;


          for (int i = 0; i < n; i++) {
               if (i < n - 2 && a[i] && a[i + 1] && a[i + 2]) {
                    if (f) {
                         s = small(a[i], a[i + 1]);
                         a[i] -= s;
                         a[i + 1] -= s;
                         r += s * 5;
                         f = 0;
                         //printf("(i = %d) #+5 * %d\n", i, s);
                    }
                    else {
                         s = small3(a[i], a[i + 1], a[i + 2]);
                         if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) {
                              f = 1;
                              s -= small(small(a[i], a[i + 2]), small(a[i + 1] - a[i], a[i + 1] - a[i + 2]));
                         }
                         a[i] -= s;
                         a[i + 1] -= s;
                         a[i + 2] -= s;
                         r += s * 7;
                         //printf("(i = %d) +7 * %d\n", i, s);
                         i--;
                         continue;
                    }
               }
               if (i < n - 1 && a[i] && a[i + 1]) {
                    s = small(a[i], a[i + 1]);
                    a[i] -= s;
                    a[i + 1] -= s;
                    r += s * 5;
                    //printf("(i = %d) +5 * %d\n", i, s);
               }
               if (a[i]) {
                    s = a[i];
                    a[i] -= s;
                    r += s * 3;
                    //printf("(i = %d) +3 * %d\n", i, s);
               }
          }

          //printf("rr = %lld, r = %lld\n\n", rr, r);
          if (rr != r) {
               for (int i = 0; i < n; i++) {
                    a[i] = (t / arr[i]) % 5;
                    printf("%d ", a[i]);
               }
               printf("\nrr = %lld, r = %lld\n", rr, r);
               printf("!!!!RR != R!!!!\n");
          }

          t++;
     }
     return 0;
}