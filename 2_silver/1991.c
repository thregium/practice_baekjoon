#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

/*
���� : Ʈ���� ������ ���� ���谡 �־��� �� Ʈ���� ����, ����, ���� ��ȸ ����� ���� ����Ѵ�.

�ذ� ��� : ��Ʈ ���� ������� ���� ���� ������ ���� ���谡 �־��� ���� �����Ƿ� �̸� ������ ������ �迭 ���·� ������ �� ������ �������� ���߿� �����Ѵ�.
������ �������� ����, ����, ���� ��ȸ ����� ���� ���� �� ����� ���� ����Ѵ�.

�ֿ� �˰��� : Ʈ��, Ʈ���� ��ȸ
*/

typedef struct btree {
     char a;
     struct btree* left;
     struct btree* right;
} btree;

btree* alpha[32];

void preorder(btree* root) {
     if (!root) return;
     printf("%c", root->a);
     preorder(root->left);
     preorder(root->right);
}

void inorder(btree* root) {
     if (!root) return;
     inorder(root->left);
     printf("%c", root->a);
     inorder(root->right);
}

void postorder(btree* root) {
     if (!root) return;
     postorder(root->left);
     postorder(root->right);
     printf("%c", root->a);
}

int main(void) {
     int n;
     char s1[2], s2[2], s3[2];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          btree* node;
          node = calloc(1, sizeof(btree));
          node->a = i + 'A';
          alpha[i] = node;
     }
     for (int i = 0; i < n; i++) {
          scanf("%s %s %s", s1, s2, s3);
          if (isalpha(s2[0])) alpha[s1[0] - 'A']->left = alpha[s2[0] - 'A'];
          if (isalpha(s3[0])) alpha[s1[0] - 'A']->right = alpha[s3[0] - 'A'];
     }
     preorder(alpha[0]);
     printf("\n");
     inorder(alpha[0]);
     printf("\n");
     postorder(alpha[0]);
     return 0;
}