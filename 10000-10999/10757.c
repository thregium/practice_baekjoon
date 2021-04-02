#include <stdio.h>
#include <string.h>

/*
���� : �ִ� 10000�ڸ��� �ڿ��� A, B�� �Էµ� �� A + B�� ���� ����Ѵ�.

�ذ� ��� : ������ �ڸ����� �迭�� ����� �� �� �ڸ����� ������� ���� ���Ѵ�. �ڸ����� ���� 10 �̻��� ��쿡�� ĳ���� �����Ͽ� ���ڸ��� 1�� �߰��ؾ� �Ѵ�.
��½ÿ��� �� �� �ڸ��� ���� ������ Ȯ���� �ʿ��ϴ�.

�ֿ� �˰��� : ����?
*/

char a[10240], b[10240], c[10240];

int big(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int digits = 0, carry = 0, temp;

     scanf("%s %s", a, b);

     digits = big(strlen(a), strlen(b)) + 1;
     for (int i = 0; i < digits; i++) {
          temp = (i < strlen(a) ? a[strlen(a) - 1 - i] - 48 : 0) + (i < strlen(b) ? b[strlen(b) - 1 - i] - 48 : 0) + carry;
          c[digits - 1 - i] = temp % 10;
          if (temp >= 10) carry = 1;
          else carry = 0;
     }
     for(int i = !c[0]; i < digits; i++) printf("%d", c[i]);
     return 0;
}