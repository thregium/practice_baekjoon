#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 1000)���� �ҹ��ڷ� �̷���� 80�� ������ �ܾ���� �־�����.
ó�� �־��� �ܾ�� �� ���ھ� �����־�� ���� �� �ִ� ���� �� �ܾ ���Ѵ�.

�ذ� ��� : ��� ���ڿ� �ֿ� ���� �׸����ϰ� Ȯ���ϸ鼭 ���� ���ڿ� �� ���ڸ� �߰��� ���� Ȯ���ϰ�,
�� ���� �������� �����Ѵ�. ������ ������ �������� ã�� �ű⼭ �÷������� �� ��,
�湮�� �� �ִ� �� ��� ���� �� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �׷��� �̷�, �÷�����, �׸��� �˰���

��ó : USACO 2003F B3��
*/

char vis[1024];
char stt[96], res[96];
char word[1024][96];
vector<int> ed[1024];

void dfs(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) dfs(i);
    }
}

int main(void) {
    int n, pos, rlen = 0;
    scanf("%d %s", &n, stt);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strlen(word[i]) + 1 != strlen(word[j])) continue;
            pos = 0;
            for (int jj = 0; word[j][jj]; jj++) {
                if (word[j][jj] == word[i][pos]) pos++;
            }
            if (word[i][pos] == '\0') ed[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!strcmp(stt, word[i])) dfs(i);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] && strlen(word[i]) > rlen) {
            rlen = strlen(word[i]);
            strcpy(res, word[i]);
        }
    }
    printf("%s", res);
    return 0;
}