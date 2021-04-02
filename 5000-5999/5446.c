#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
���� : ���� �ȿ� ���� �̸��� ���ϵ��� �ִ�. �� ���ϵ� ��� ���ϴ� ���� �����ϴ� ����� 2������ �ִµ�, ù ��°�� ���� �����ϴ� ���̰�,
�� ��°�� ���� �̸��� �Ϻ�(�Ǵ� �� �Է�)�� �Է� �� �� �Է����� �����ϴ� ��� ���ϵ��� �����ϴ� ���̴�.
�����ؾ� �� ���ϵ��� ��ϰ� �����ؼ��� �� �Ǵ� ���ϵ��� ����� �־��� �� �����ؾ� �� ��� ������ �����ϴ� �� ��� �ּ����� ��� Ƚ���� ���Ͽ���.

�ذ� ��� : Ʈ���� ������ ���ؼ� �Էµ��� �����Ѵ�. ��ȸ�� �ؾ� �ϹǷ� �迭�� ���� �ߺ��� ���ϸ鼭 ���� ���ڵ��� ��ϵǴ� ������� �����Ѵ�.
�����ؾ� �� ���ϵ��� ����� �Է¹��� ������ ��������� ���ڿ��� �����ϴ� �����ؾ� �� ������ �ִ��� ���ο� �����ؾ� �� ���� ��� ��������� ���ڿ��� ���ϸ��� ������ �ִ��� ���θ� 1�� �����ϰ�
�����ؼ��� �� �� ���ϵ��� ����� �Է¹��� ������ ��������� ���ڿ��� �����ϴ� ���� ��� �����ؼ��� �� �Ǵ� ������ �ִ��� ���θ� 1�� �ٲ۴�.

�Էµ��� ��� ������ �������� Ʈ���� ���� ��ȸ�ϸ鼭 ������� ���ڿ��� �����ϴ� ���� ��� �����ؾ� �� ������ ������ �����ؼ��� �ȵ� ������ ���� ���
�ش� ���ڿ��� �����ϴ� ��� ������ �����ϰ� ���� Ƚ���� 1 �ø���. �Ǵ� ���� ���ڿ��� ���ϸ����� ���� ������ ������ �ش� ���ڿ��� �����ϴ� �����ؼ��� �ȵ� ������ �ִٸ�
�ش� ������ �����ϰ� ���� Ƚ���� 1 �ø���. ��ȸ�� �Ϸ�Ǹ� ���� Ƚ���� ����Ѵ�.
�׽�Ʈ ���̽��� ���� ���̹Ƿ� �׽�Ʈ ���̽��� �Ϸ�Ǹ� Ʈ���� ���� ��ȸ ������� ���� ������� Ȯ���ϰ� �޸� ��ȯ ������ ���� �޸𸮸� Ȯ���Ѵ�.

�ֿ� �˰��� : ���ڿ� ó��, Ʈ��, Ʈ����
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