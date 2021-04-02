#include <stdio.h>
#include <malloc.h>

/*
���� : �Է¿� ���� ���� ���ڿ� b��ŭ�� ���� ���� ������ c�� �ְų� b��°�� ���ִ� ������ ������. ���� 1~1000000 ������ ���� ������.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��� ������ ���� ���� ���� ���� ������ ���� �����Ѵ�. ������ ���� ������ ���ϴ� ���� ���� ������ ������ Ȯ���ذ��� ����,
�� ������ ���ʿ� �ִ� ������ ���� ã���� �ϴ� ���� �̻��̶�� ����, �ƴ϶�� ���������� ������ ������ ã�Ƴ���.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��
*/

typedef struct candy {
     int start;
     int end;
     int count;
     struct candy* left;
     struct candy* right;
} candy;

void maketree(candy* root) {
     if (root->start == root->end) return;

     candy* left, *right;
     left = calloc(1, sizeof(candy));
     right = calloc(1, sizeof(candy));
     left->start = root->start;
     left->end = root->start + (root->end - root->start) / 2;
     right->start = left->end + 1;
     right->end = root->end;
     root->left = left;
     root->right = right;
     maketree(left);
     maketree(right);
}

void putcandy(candy* root, int taste, int count) {
     root->count += count;
     if (root->start == root->end) return;
     if (root->left->end < taste) putcandy(root->right, taste, count);
     else putcandy(root->left, taste, count);
}

int getcandy(candy* root, int rank) {
     if (root->start == root->end) {
          return root->start;
     }
     if (root->left->count < rank) return getcandy(root->right, rank - root->left->count);
     else return getcandy(root->left, rank);
}

int main(void) {
     int n, a, b, c;
     candy* root;
     root = calloc(1, sizeof(candy));
     root->end = 1048575;
     maketree(root);
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a);
          if (a == 1) {
               scanf("%d", &b);
               c = getcandy(root, b);
               printf("%d\n", c);
               putcandy(root, c, -1);
          }
          else if (a == 2) {
               scanf("%d %d", &b, &c);
               putcandy(root, b, c);
          }
     }
     return 0;
}