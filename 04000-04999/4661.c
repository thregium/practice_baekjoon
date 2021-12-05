#include <stdio.h>
#include <string.h>

/*
문제 : 키값으로 대문자 알파벳을 가지는 이진 탐색 트리에서 리프 노드들을 차례로 떼어낸 결과가 주어진다.
이때, 원래 이진 탐색 트리를 전위 순회한 결과를 출력한다.

해결 방법 : 리프 노드를 떼어낸 것을 역순으로 가져오면 루트 노드부터의 순서를 알 수 있다.
따라서, 역순으로 이진 탐색 트리를 만들면 원래의 이진 탐색 트리가 되므로 이를 다시 전위 순회해서 출력하면 된다.

주요 알고리즘 : 구현, 트리

출처 : MidC 2000 D번
*/

char s[32][32], child[32][2];

void printtree(char c) {
    printf("%c", c);
    if (child[c - 'A'][0]) printtree(child[c - 'A'][0]);
    if (child[c - 'A'][1]) printtree(child[c - 'A'][1]);
}

int main(void) {
    int line = 0, e = 0;
    char root;
    while (1) {
        line = 0;
        while (1) {
            scanf("%s", s[line++]);
            if (!strcmp(s[line - 1], "*")) break;
            else if (!strcmp(s[line - 1], "$")) {
                e = 1;
                break;
            }
        }
        line--;
        root = s[line - 1][0];
        for (int i = line - 2; i >= 0; i--) {
            for (int j = 0; s[i][j]; j++) {
                for (char k = root;;) {
                    if (s[i][j] < k) {
                        if (child[k - 'A'][0]) k = child[k - 'A'][0];
                        else {
                            child[k - 'A'][0] = s[i][j];
                            break;
                        }
                    }
                    else if (s[i][j] > k) {
                        if (child[k - 'A'][1]) k = child[k - 'A'][1];
                        else {
                            child[k - 'A'][1] = s[i][j];
                            break;
                        }
                    }
                    else return 1;
                }
            }
        }
        printtree(root);
        printf("\n");
        for (int i = 0; i < 32; i++) {
            child[i][0] = '\0';
            child[i][1] = '\0';
        }
        if (e) break;
    }
    return 0;
}