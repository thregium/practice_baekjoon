#include <stdio.h>
#include <malloc.h>

/*
문제 : 이진 탐색 트리를 전위 순회한 결과를 입력했을 때, 이 트리를 후위 순회한 결과를 출력한다.

해결 방법 : 전위순회이므로 첫 노드는 루트 노드일 것이다. 따라서 첫 입력을 루트 노드로 설정하고,
이후 입력때마다 트리를 따라가며 입력값이 노트의 키보다 작으면 왼쪽, 크면 오른쪽으로 따라가다가 NULL 링크를 발견하면 현재 입력값을 노드로 만들어 연결한다.
트리가 완성되면 트리를 후위 순회로 출력한다.

주요 알고리즘 : 이진트리
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