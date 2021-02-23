#include <stdio.h>

/*
���� : K���� ������ ������ ũ��� �߶� N�� �̻��� ������� �Ѵ�. �̶� N�� �̻��� ���� �� �ִ� ������ �ִ� ���� ���̸� ���Ѵ�.

�ذ� ��� : ������ ���� ��� ���� �� ���� �������� ��� ������ ������ ���� ����� ���� ���� N�� ���Ͽ� �̺� Ž���� ���� ���̸� ã�´�.

�ֿ� �˰��� : �̺� Ž��
*/

int lan[10240];

int main(void) {
     int k, n, b = 0;
     scanf("%d %d", &k, &n);
     for (int i = 0; i < k; i++) {
          scanf("%d", &lan[i]);
          if(lan[i] > b) b = lan[i];
     }

     long long int lo = 0, hi = (long long)b + 1, mid, ls;
     while (lo + 1 < hi) {
          mid = (lo + hi) / 2;
          ls = 0;
          for (int i = 0; i < k; i++) {
               ls += lan[i] / mid;
          }
          
          if (ls < n) {
               hi = mid;
          }
          else {
               lo = mid;
          }
     }
     printf("%lld", lo);
     return 0;
}