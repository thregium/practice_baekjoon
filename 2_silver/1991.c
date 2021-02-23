#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

/*
문제 : 트리들 사이의 연결 관계가 주어질 때 트리의 전위, 중위, 후위 순회 결과를 각각 출력한다.

해결 방법 : 루트 노드와 연결되지 않은 노드들 사이의 연결 관계가 주어질 수도 있으므로 미리 가능한 노드들을 배열 형태로 저장한 후 사이의 연결관계는 나중에 설정한다.
연결한 다음에는 전위, 중위, 후위 순회 결과를 각각 실행 후 결과를 각각 출력한다.

주요 알고리즘 : 트리, 트리의 순회
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