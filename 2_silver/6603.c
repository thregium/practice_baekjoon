#include <stdio.h>

/*
���� : �־��� �� K�� ��� 6���� �� ������ ������������ ����Ѵ�.

�ذ� ��� : ��Ʈ��ŷ�� ���� 6���� �����Ѵ�.

�ֿ� �˰��� : ��Ʈ��ŷ
*/

int s[16], t[6];

void track(int k, int c) {
     if (c == 6) {
          for (int i = 0; i < 6; i++) {
               printf("%d ", t[i]);
          }
          printf("\n");
          return;
     }
     for (int i = 0; i < k; i++) {
          if (c > 0 && s[i] <= t[c - 1]) continue;
          t[c] = s[i];
          track(k, c + 1);
          t[c] = 0;
     }
}

int main(void) {
     int k;
     while (1) {
          scanf("%d", &k);
          if (k == 0) break;
          for (int i = 0; i < k; i++) {
               scanf("%d", &s[i]);
          }
          track(k, 0);
          printf("\n");
     }
     return 0;
}