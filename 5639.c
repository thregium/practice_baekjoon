#include <stdio.h>
#include <malloc.h>

/*
���� : ���� Ž�� Ʈ���� ���� ��ȸ�� ����� �Է����� ��, �� Ʈ���� ���� ��ȸ�� ����� ����Ѵ�.

�ذ� ��� : ������ȸ�̹Ƿ� ù ���� ��Ʈ ����� ���̴�. ���� ù �Է��� ��Ʈ ���� �����ϰ�,
���� �Է¶����� Ʈ���� ���󰡸� �Է°��� ��Ʈ�� Ű���� ������ ����, ũ�� ���������� ���󰡴ٰ� NULL ��ũ�� �߰��ϸ� ���� �Է°��� ���� ����� �����Ѵ�.
Ʈ���� �ϼ��Ǹ� Ʈ���� ���� ��ȸ�� ����Ѵ�.

�ֿ� �˰��� : ����Ʈ��
*/

typedef struct btree {
     int key;
     struct btree* left;
     struct btree* right;
} btree;

int preorder[10240];

void postorder(btree* root) {
     if (!root) return;
     postorder(root->left);
     postorder(root->right);
     printf("%d\n", root->key);
}

int main(void) {
     int t;
     scanf("%d", &t);
     btree* root;
     root = malloc(sizeof(btree));
     root->key = t;
     root->left = NULL;
     root->right = NULL;
     btree* now;
     while (scanf("%d", &t) != EOF) {
          if (t < 0) break;
          btree* n;
          n = malloc(sizeof(btree));
          n->key = t;
          n->left = NULL;
          n->right = NULL;
          now = root;
          while (1) {
               if (t < now->key) {
                    if (now->left == NULL) {
                         now->left = n;
                         break;
                    }
                    else now = now->left;
               }
               else {
                    if (now->right == NULL) {
                         now->right = n;
                         break;
                    }
                    else now = now->right;
               }
          }
     }
     postorder(root);
     return 0;
}