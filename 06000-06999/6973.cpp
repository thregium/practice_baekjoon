#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : �־��� ���ڿ����� �̹� ���Դ� �ܾ��� �� ��° ������ �ܾ����� ��°���� ����,
������ ���� �ܾ��� �״�� �Ͽ� ����Ѵ�.

�ذ� ��� : �ؽø��� �̿��Ѵ�. �Է� ������ Ư���ϹǷ� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, �ؽø�

��ó : CCC 1997 4��
*/

char buff[128];
unordered_map<string, int> mp;

int main(void) {
    int n, wcnt;
    char* tok;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        wcnt = 0;
        mp.clear();
        while (1) {
            if (!fgets(buff, 100, stdin)) return 0;
            if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
            if (buff[0] == '\0') break;
            
            tok = strtok(buff, " ");
            while (tok) {
                if (mp.find(tok) != mp.end()) printf("%d ", mp[tok]);
                else {
                    printf("%s ", tok);
                    mp.insert({ tok, ++wcnt });
                }
                tok = strtok(NULL, " ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}