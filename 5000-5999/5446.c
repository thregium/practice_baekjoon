#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
문제 : 폴더 안에 여러 이름의 파일들이 있다. 이 파일들 가운데 원하는 것을 삭제하는 방법은 2가지가 있는데, 첫 번째는 직접 삭제하는 것이고,
두 번째는 파일 이름의 일부(또는 빈 입력)를 입력 후 그 입력으로 시작하는 모든 파일들을 삭제하는 것이다.
삭제해야 할 파일들의 목록과 삭제해서는 안 되는 파일들의 목록이 주어질 때 삭제해야 할 모든 파일을 삭제하는 데 드는 최소한의 명령 횟수를 구하여라.

해결 방법 : 트라이 구조를 통해서 입력들을 저장한다. 순회를 해야 하므로 배열을 통해 중복을 피하면서 다음 글자들이 등록되는 순서대로 저장한다.
삭제해야 할 파일들의 목록을 입력받을 때에는 현재까지의 문자열로 시작하는 삭제해야 할 파일이 있는지 여부와 삭제해야 할 파일 가운데 현재까지의 문자열이 파일명인 파일이 있는지 여부를 1로 저장하고
삭제해서는 안 될 파일들의 목록을 입력받을 때에는 현재까지의 문자열로 시작하는 파일 가운데 삭제해서는 안 되는 파일이 있는지 여부를 1로 바꾼다.

입력들을 모두 저장한 다음에는 트리를 전위 순회하면서 현재까지 문자열로 시작하는 파일 가운데 삭제해야 할 파일은 있지만 삭제해서는 안될 파일은 없는 경우
해당 문자열로 시작하는 모든 파일을 삭제하고 삭제 횟수를 1 늘린다. 또는 현재 문자열을 파일명으로 갖는 파일이 있지만 해당 문자열로 시작하는 삭제해서는 안될 파일이 있다면
해당 파일을 삭제하고 삭제 횟수를 1 늘린다. 순회가 완료되면 삭제 횟수를 출력한다.
테스트 케이스가 여러 개이므로 테스트 케이스가 완료되면 트리를 후위 순회 방식으로 리프 노드인지 확인하고 메모리 반환 과정을 통해 메모리를 확보한다.

주요 알고리즘 : 문자열 처리, 트리, 트라이
*/

char thisfile[32];
int del = 0;

typedef struct filename {
     char havefile;
     char lastname;
     char notdelete;
     char nextchr[64];
     struct filename* next[64];
} filename;

void deletefile(filename* root) {
     if (!root->havefile) return;
     else if (root->havefile && !root->notdelete) {
          //printf("  delete\n");
          root->havefile = 0;
          del++;
          return;
     }
     else if (root->lastname) {
          //printf(" delete\n");
          del++;
     }
     for (int i = 1; i <= root->nextchr[0]; i++) {
          //printf("%c", root->nextchr[i]);
          deletefile(root->next[i]);
     }
}

void freetree(filename* root) {
     char c = root->nextchr[0];
     for (int i = 1; i <= c; i++) {
          freetree(root->next[i]);
          root->nextchr[0]--;
     }
     if (!root->nextchr[0]) {
          free(root);
          return;
     }
}

int main(void) {
     int t, n1, n2, x;

     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          del = 0;
          filename* folder;
          folder = calloc(1, sizeof(filename));
          scanf("%d", &n1);
          if (n1) folder->havefile = 1;
          for (int i = 0; i < n1; i++) {
               scanf("%s", &thisfile);
               filename* nm = folder;
               for (int j = 0; j < strlen(thisfile); j++) {
                    x = 0;
                    for (int k = 1; k <= nm->nextchr[0]; k++) {
                         if (nm->nextchr[k] == thisfile[j]) {
                              x = k;
                              break;
                         }
                    }
                    if (x == 0) {
                         filename* node;
                         node = calloc(1, sizeof(filename));
                         node->havefile = 1;
                         nm->nextchr[0]++;
                         nm->nextchr[nm->nextchr[0]] = thisfile[j];
                         nm->next[nm->nextchr[0]] = node;
                         x = nm->nextchr[0];
                    }
                    nm = nm->next[x];
                    if (j == strlen(thisfile) - 1) nm->lastname = 1;
               }

          }
          scanf("%d", &n2);
          if (n2) folder->notdelete = 1;
          for (int i = 0; i < n2; i++) {
               scanf("%s", &thisfile);
               filename* nm = folder;
               for (int j = 0; j < strlen(thisfile); j++) {
                    x = 0;
                    for (int k = 1; k <= nm->nextchr[0]; k++) {
                         if (nm->nextchr[k] == thisfile[j]) {
                              x = k;
                              break;
                         }
                    }
                    if (x == 0) {
                         filename* node;
                         node = calloc(1, sizeof(filename));
                         node->notdelete = 1;
                         nm->nextchr[0]++;
                         nm->nextchr[nm->nextchr[0]] = thisfile[j];
                         nm->next[nm->nextchr[0]] = node;
                         x = nm->nextchr[0];
                    }
                    nm = nm->next[x];
                    nm->notdelete = 1;
               }
          }
          deletefile(folder);
          printf("%d\n", del);
          freetree(folder);
     }
     return 0;
}