#include <stdio.h>
#define MAXI 2147483647

/*
���� : ���� �̿��� ���ϵ鳢�� ���ĳ����� ������� K���� ���ϵ��� ��ġ���� �Ѵ�. �� �� ��� �ð��� �� �ӽ� ���ϵ��� ũ��� ��ü ������ ũ�⸦ ���� ���̶�� �� ��,
�� ���ϵ��� ũ�Ⱑ �־����� �� ������ �ϳ��� ��ġ�µ� ��� �ּ� �ð��� ���Ѵ�.

�ذ� ��� : i������ j�������� ������ ��ġ�µ� ��� ������ �ּڰ��� i������ i+l�������� �ּڰ��� i+l+1������ j�������� �ּڰ��� ���� ���� �ּڰ���
i������ j�������� ���� ũ���� �հ� ����. ��, i�� j�� ���ٸ� ��ĥ �ʿ䰡 �����Ƿ� ���� ũ�⸦ ������ �ʴ´�.
j - i�� 1�� �ͺ��� �����ؼ� k - 1�� �ͱ��� ������� ����ϸ� �ᱣ���� i������ k - 1������ ������� ����� �Ͱ� ����.

�ֿ� �˰����� : ���̳��� ���α׷���
*/

int c[512], s[512], mem[512][512];

int small(int a, int b) {
     return a < b ? a : b;
}

int sumc(int a, int b) {
     return s[b] - (a == 0 ? 0 : s[a - 1]);
}

int main(void) {
     int t, k, b;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          scanf("%d", &k);
          for (int i = 0; i < k; i++) {
               scanf("%d", &c[i]);
               s[i] = (i == 0 ? 0 : s[i - 1]) + c[i];
          }
          for (int i = 1; i < k; i++) {
               for (int j = 0; j < k - i; j++) {
                    if (i == 0) {
                         mem[j][j] = 0;
                         continue;
                    }
                    b = MAXI;
                    for (int l = j; l < j + i; l++) {
                         b = small(b, mem[j][l] + mem[l + 1][j + i]);
                    }
                    mem[j][j + i] = b + sumc(j, j + i);
               }
          }
          printf("%d\n", mem[0][k - 1]);
     }
     return 0;
}