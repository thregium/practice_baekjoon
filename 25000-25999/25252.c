#include <stdio.h>
#include <malloc.h>

/*
���� : N + 1(N <= 400000)���� ���� �� ���̷� �׿� �ִ�. 1������ ���ʷ� ������ ���� ���� ��,
�����鼭 0�� ���� �� ���� ���� �Ǵ� ���� �� �� �ִ� �� ���Ѵ�.

�ذ� ��� : ���� ����Ʈ�� ����Ͽ� �� ���̸� �����صд�. �� ��° ���̴� ���������� �����ؾ� �Ѵ�.
�� �� 1������ ������ �����鼭 �� ���� 0�� ������ Ƚ���� ���� �� ���� ����Ʈ���� �����ϴ� ����
�ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ���� ����Ʈ

��ó : GCPC 2021 H��
*/

typedef struct node {
    int x;
    struct node* prev;
    struct node* next;
} node;

int a[409600];
node* nnum[409600];

int main(void) {
    int n, s1, s2, res = 0;
    scanf("%d %d %d", &n, &s1, &s2);
    for (int i = 0; i < s1; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = s1 + s2 - 1; i >= s1; i--) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < s1 + s2; i++) {
        nnum[a[i]] = calloc(1, sizeof(node));
        nnum[a[i]]->x = a[i];
        if (i > 0) {
            nnum[a[i]]->prev = nnum[a[i - 1]];
            nnum[a[i - 1]]->next = nnum[a[i]];
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((nnum[i]->prev && nnum[i]->prev->x == 0) || (nnum[i]->next && nnum[i]->next->x == 0)) res++;
        if (nnum[i]->prev && nnum[i]->next) {
            nnum[i]->prev->next = nnum[i]->next;
            nnum[i]->next->prev = nnum[i]->prev;
        }
        else if (nnum[i]->prev) nnum[i]->prev->next = NULL;
        else if (nnum[i]->next) nnum[i]->next->prev = NULL;
        free(nnum[i]);
    }
    printf("%d", res);
    return 0;
}