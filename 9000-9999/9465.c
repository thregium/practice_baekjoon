#include <stdio.h>

/*
���� : ���Ʒ� 2������ �� ��ƼĿ���� �ִ�. �� ��ƼĿ���� ���� ������ ���� �ִµ�, ��ƼĿ �ϳ��� ����� �� ���� �� �Ǵ� �Ʒ��� ��ƼĿ�� ����� �� ����.
�̶� �� ��ƼĿ������ ���� �� �ִ� �ִ� ������ ���Ѵ�.

�ذ� ��� : ��ƼĿ������ ���ٰ� �Ʒ����� ���� ���� ������ ������ ���� �����Ѵ�. �ٷ� ���� ���� �ݴ��� �ٰ� 2ĭ ���� ���� ��, �Ʒ����� ���� ���ؼ�
���� ū ���� ���� ��ƼĿ�� ���� ���� ������ ���ϸ� �� ��ƼĿ�� ���� ���� �ְ� ������ �ȴ�.

�ֿ� �˰��� : ���̳��� ���α׷���
*/

int sticker[102400][2], mem[102400][2];

int big(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int t, n;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          scanf("%d", &n);
          for (int i = 0; i < n; i++) {
               scanf("%d", &sticker[i][0]);
          }
          for (int i = 0; i < n; i++) {
               scanf("%d", &sticker[i][1]);
          }
          mem[0][0] = sticker[0][0];
          mem[0][1] = sticker[0][1];
          for (int i = 1; i < n; i++) {
               if (i >= 2) {
                    mem[i][0] = big(big(big(mem[i - 2][0], mem[i - 2][1]), mem[i - 1][1]) + sticker[i][0], mem[i - 1][0]);
                    mem[i][1] = big(big(big(mem[i - 2][1], mem[i - 2][0]), mem[i - 1][0]) + sticker[i][1], mem[i - 1][1]);
               }
               else {
                    mem[i][0] = big(mem[i - 1][1] + sticker[i][0], mem[i - 1][0]);
                    mem[i][1] = big(mem[i - 1][0] + sticker[i][1], mem[i - 1][1]);
               }
          }
          if (n >= 1) printf("%d\n", big(mem[n - 1][0], mem[n - 1][1]));
     }
     return 0;
}