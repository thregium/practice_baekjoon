#include <stdio.h>
#include <malloc.h>

/*
���� : N���� �л����� Ű�� M�� ������ ��, �л����� Ű ������� ������ ���� �� �� �ִ� ��� ��� �ƹ��ų� �ϳ��� ����Ѵ�. (N <= 32000, M <= 100000)

�ذ� ��� : ���� ������ �̿��� �л����� Ű�� ���� ���� ������� Ȯ���Ѵ�. N�� ũ�� ������ �켱���� ť�� ���� ����Ʈ�� Ȱ���Ѵ�.
�켱���� ť�� ���ο� ���Ҹ� ���� ������ �� ������ ���� ������ ���ٸ� ���߿� ���� ���Ұ� ���� ������ �ؾ� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����, �켱���� ť, ���� ����Ʈ
*/

typedef struct ilist {
     int n;
     struct ilist* l;
} ilist;

ilist* hcmp[32768]; //��ũ(���� ����Ʈ ��)
int hent[32768]; //���� ����

int hh[131072]; //��
int hs = 0; //�� ������
int chk[32768]; //�湮 üũ

void hpush(int x) {
     int t = ++hs;

     for (; t > 1; t /= 2) {
          if (hent[x] <= hent[hh[t / 2]]) hh[t] = hh[t / 2]; //���ο� ������ ���� ������ ���ϴ� ������ ���� ������ ���� ��� ���ο� ���Ҹ� ���� �÷�����
          else break;
     }
     hh[t] = x;
}

int hpop(void) {
     int r = hh[1], t = hh[hs--];
     int p = 1, c = 2;

     while (c <= hs) {
          if (c < hs && hent[hh[c]] > hent[hh[c + 1]]) c++; //�������� �� ���� ���
          if (hent[t] <= hent[hh[c]]) break; //�� �Ʒ� �ִ� ��尡 �� ������ ����
          hh[p] = hh[c];
          p = c;
          c *= 2;
     }
     hh[p] = t;

     return r;
}

int main(void) {
     int n, m, a, b, x;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < m; i++) {
          scanf("%d %d", &a, &b);
          ilist* ab;
          ab = calloc(1, sizeof(ilist));
          ab->n = b;
          ab->l = hcmp[a];
          hcmp[a] = ab;
          hent[b]++;
     }
     for (int i = 1; i <= n; i++) {
          hpush(i);
     }
     for (int i = 0; i < n; i++) {
          while (1) {
               x = hpop();
               if (!chk[x]) {
                    chk[x] = 1; //�湮 üũ�� ������ �� ��
                    break;
               }
          }
          if (hent[x]) break;
          else {
               printf("%d ", x);
               for (ilist* hl = hcmp[x]; hl; hl = hl->l) {
                    hent[hl->n]--;
                    hpush(hl->n);
                    //if (hs > 120000) return 1;
               }
          }
     }
     return 0;
}