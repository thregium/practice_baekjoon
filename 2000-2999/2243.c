#include <stdio.h>
#include <malloc.h>

/*
문제 : 입력에 따라 사탕 상자에 b만큼의 맛을 가진 사탕을 c개 넣거나 b번째로 맛있는 사탕을 꺼낸다. 맛은 1~1000000 사이의 값을 가진다.

해결 방법 : 세그먼트 트리를 이용해 일정한 범위 내의 맛을 가진 사탕의 수를 저장한다. 사탕을 넣을 때에는 원하는 맛을 가진 곳까지 범위를 확인해가며 들어가고,
뺄 때에는 왼쪽에 있는 사탕의 수가 찾고자 하는 순위 이상이라면 왼쪽, 아니라면 오른쪽으로 움직여 사탕을 찾아낸다.

주요 알고리즘 : 자료구조, 세그먼트 트리
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