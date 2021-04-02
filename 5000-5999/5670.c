#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
���� : �޴��� ������ ���� ���ڿ��� �Է��� �� ù ���ڸ� �Է��� ���ķδ� �ش� ���ڷ� �����ϴ� ��� �ܾ ���� ���ڵ� �Ȱ��� ���ڷ� �����ϴ� ��� �ڵ����� �Է��� �شٰ� �Ѵ�.
�� �� �ܾ��� ����� �־����� �ܾ �Է��ϴµ� ������ Ű�� ���� ����� �Ҽ��� �Ʒ� ��° �ڸ����� ����Ѵ�.

�ذ� ��� : Ʈ���� ������ �̿��� �ش� ���ڿ��� �����ϴ� �ܾ���� ���� �ܾ��� ���� ������ �����Ѵ�. ���� Ʈ���̸� ��ȸ�ϸ� �ܾ��� ���� �����̰ų� �ش� ���ڿ���
�����ϴ� �ܾ��� ���� 1���� ��� �ش� ���������� Ű�� �Է� Ƚ���� ��ȯ�Ѵ�. ������ ��쿡�� ���� ���ڸ� ���캸�� ���� ���ڱ��� �����ϴ��� �����ϴ� �ܾ��� ���� ���� ���
Ű�� �Է� Ƚ���� �״�� ��������, �ٸ��ٸ� 1ȸ �ø���. ��ȸ�� ������ ��ü Ű�� �Է� Ƚ���� ��ȯ�ȴ�.

��ü Ű�� �Է� Ƚ���� ��ȯ�Ǹ� �̸� �ܾ��� ���� ������ ����Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ���ڿ�, Ʈ��, Ʈ����
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