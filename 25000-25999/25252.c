#include <stdio.h>
#include <malloc.h>

/*
문제 : N + 1(N <= 400000)개의 짐이 두 더미로 쌓여 있다. 1번부터 차례로 짐들을 꺼내 나갈 때,
꺼내면서 0번 짐이 맨 위에 오게 되는 경우는 몇 번 있는 지 구한다.

해결 방법 : 연결 리스트를 사용하여 두 더미를 연결해둔다. 두 번째 더미는 역방향으로 연결해야 한다.
그 후 1번부터 짐들을 꺼내면서 양 옆에 0이 나오는 횟수를 세고 그 짐을 리스트에서 삭제하는 것을
반복하면 된다.

주요 알고리즘 : 자료 구조, 연결 리스트

출처 : GCPC 2021 H번
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