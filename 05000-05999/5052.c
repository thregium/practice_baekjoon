#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/*
���� : ���� �޴���ȭ ��ȣ���� �Է¹��� �� �� ��ȣ���� �ϰ���(�� ��ȣ�� �ٸ� ��ȣ�� �����ϴ� ��찡 ����)���� ���θ� ����Ѵ�.

�ذ� ��� : 10�� Ʈ���� �̿��� ��ȭ��ȣ�� ����޴´�. ��ȭ��ȣ�� ���� ������ ��� ��ȭ��ȣ�� �ִٴ� ǥ�ø� �صΰ� ���� ��ȣ�� �Է¹޴´�.
�׷��ٰ� ��ȭ��ȣ�� ������ �� Ʈ���� �߰��� �ְų� ��ȭ��ȣ�� �����ϴ� ���� ��ȭ��ȣ�� �ִٴ� ǥ�ø� �߰��� ��� �ϰ������� �ʴٴ� ����� ������ �� �Է��� ���� ����ϰ�,
�Է��� ������ �ϰ������� ���� ���ð� ���� ��� �ϰ����̶�� ����� ����Ѵ�.

�ֿ� �˰��� : Ʈ��, Ʈ����
*/

char phone[16];

typedef struct phonetree {
     char hasnum;
     struct phonetree* nextnum[10];
} phonetree;

int main(void) {
     int t, n, r;
     scanf("%d", &t);
     //t = 1;
     for (int i = 0; i < t; i++) {
          r = 0;
          phonetree* tel;
          tel = malloc(sizeof(phonetree));
          tel->hasnum = 0;
          for (int j = 0; j < 10; j++) tel->nextnum[j] = NULL;

          scanf("%d", &n);
          //n = 10000;
          for (int j = 0; j < n; j++) {
               scanf("%s", phone);
               //_itoa(j * 10000 + 100000000, phone, 10);

               phonetree* x = tel;
               for (int k = 0; k < strlen(phone); k++) {
                    if (x->hasnum) {
                         r = 1;
                         break;
                    }
                    if (x->nextnum[phone[k] - 48] == NULL) {
                         phonetree* now;
                         now = malloc(sizeof(phonetree));
                         now->hasnum = 0;
                         for (int l = 0; l < 10; l++) now->nextnum[l] = NULL;
                         x->nextnum[phone[k] - 48] = now;
                         x = x->nextnum[phone[k] - 48];
                         if (k == strlen(phone) - 1) {
                              now->hasnum = 1;
                              break;
                         }
                    }
                    else if (k == strlen(phone) - 1) {
                         x->hasnum = 1;
                         r = 1;
                         break;
                    }
                    else {
                         x = x->nextnum[phone[k] - 48];
                    }
               }
          }
          if (r) printf("NO\n");
          else printf("YES\n");
     }
     return 0;
}