#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
문제 : 휴대폰 자판을 통해 문자열을 입력할 때 첫 글자를 입력한 이후로는 해당 글자로 시작하는 모든 단어가 다음 글자도 똑같은 글자로 시작하는 경우 자동으로 입력하 준다고 한다.
이 때 단어의 목록이 주어지면 단어를 입력하는데 누르는 키의 수의 평균을 소숫점 아래 둘째 자리까지 출력한다.

해결 방법 : 트라이 구조를 이용해 해당 문자열로 시작하는 단어들의 수와 단어의 종료 지점을 저장한다. 이후 트라이를 순회하며 단어의 종료 지점이거나 해당 문자열로
시작하는 단어의 수가 1개인 경우 해당 지점까지의 키의 입력 횟수를 반환한다. 나머지 경우에는 다음 글자를 살펴보며 다음 글자까지 포함하더라도 시작하는 단어의 수가 같은 경우
키의 입력 횟수를 그대로 가져가고, 다르다면 1회 늘린다. 순회가 끝나면 전체 키의 입력 횟수가 반환된다.

전체 키의 입력 횟수가 반환되면 이를 단어의 수로 나누어 출력한다.

주요 알고리즘 : 자료구조, 문자열, 트리, 트라이
*/

typedef struct wtree {
     int words;
     int ends;
     struct wtree* next[26];
} wtree;

int types(wtree* root, int d) {
     int c = 0;
     if (root->ends) {
          c += d;
     }
     if (d && root->words == 1) {
          return d;
     }
     for (int i = 0; i < 26; i++) {
          if (root->next[i]) {
               if (d && root->next[i]->words == root->words) {
                    c += types(root->next[i], d);
               }
               else c += types(root->next[i], d + 1);
          }
     }
     return c;
}

void freetree(wtree* root) {
     for (int i = 0; i < 26; i++) {
          if (root->next[i]) freetree(root->next[i]);
     }
     free(root);
}

int main(void) {
     char b[128];
     int n, c;
     while (scanf("%d", &n) != EOF) {
          wtree* root, *pt, *tmp;
          root = calloc(1, sizeof(wtree));
          for (int i = 0; i < n; i++) {
               scanf("%s", b);
               pt = root;
               for (int j = 0; j < strlen(b); j++) {
                    pt->words++;
                    tmp = pt->next[b[j] - 'a'];
                    if (tmp) pt = tmp;
                    else {
                         tmp = calloc(1, sizeof(wtree));
                         pt->next[b[j] - 'a'] = tmp;
                         pt = tmp;
                    }
               }
               if (pt) {
                    pt->words++;
                    pt->ends = 1;
               }
          }
          c = types(root, 0);
          printf("%.2lf\n", (double)c / n);
          freetree(root);
     }
     return 0;
}