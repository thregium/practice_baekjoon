#include <stdio.h>
#include <malloc.h>

/*
º¸·ù
*/

typedef struct swich {
     int start;
     int end;
     long long int count;
     long long int plus;
     struct swich* left;
     struct swich* right;
} swich;

void maketree(swich* root) {
     if (root->start == root->end) return;

     swich* left, * right;
     left = calloc(1, sizeof(swich));
     right = calloc(1, sizeof(swich));
     left->start = root->start;
     left->end = root->start + (root->end - root->start) / 2;
     right->start = left->end + 1;
     right->end = root->end;
     root->left = left;
     root->right = right;
     maketree(left);
     maketree(right);
}

void flip(swich* root, int s, int t) {
     
}

int swichcount(swich* root, int s, int t) {
     return 0;
}

int main(void) {
     int n, o, s, t;
     swich* root;
     root = calloc(1, sizeof(swich));
     root->end = 131071;
     maketree(root);
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d %d %d", &o, &s, &t);
          if (o) {
               printf("%d\n", swichcount(root, s, t));
          }
          else {
               flip(root, s, t);
          }
     }
     return 0;
}