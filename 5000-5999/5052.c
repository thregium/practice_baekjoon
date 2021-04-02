#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 여러 휴대전화 번호들을 입력받은 후 그 번호들이 일관적(한 번호가 다른 번호를 포함하는 경우가 없음)인지 여부를 출력한다.

해결 방법 : 10진 트리를 이용해 전화번호를 저장받는다. 전화번호의 끝에 도달한 경우 전화번호가 있다는 표시를 해두고 다음 번호를 입력받는다.
그러다가 전화번호가 끝났을 때 트리의 중간에 있거나 전화번호를 저장하는 도중 전화번호가 있다는 표시를 발견한 경우 일관적이지 않다는 결과를 저장한 후 입력의 끝에 출력하고,
입력의 끝까지 일관적이지 않은 예시가 없는 경우 일관적이라는 결과를 출력한다.

주요 알고리즘 : 트리, 트라이
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