#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <set>
using namespace std;

/*
���� : 100�� ������ ���ڿ�(�ҹ���, 6�� ����)�� �־�����. �׸��� "XXXXXX"�� �־��� ��, �ٽ� ���ڿ����� �־�����.
���ڿ����� �ش� ���ڿ��� ������ �ٲپ� ���� �� �ִ� ���� ���ڿ����� ���� ������ ����Ѵ�.
���� ��� "NOT A VALID WORD"�� ����Ѵ�.

�ذ� ��� : ���ڿ��� ���ڵ��� ������ �Ͱ� ���� ���ڿ����� ���� ������ ����� �����ϰ� �ִ´�.
�־��� ���ڿ����� ������ �� �ʿ��� �ش� ���ĵ� ���ڿ����� ���� ���ڿ����� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ڷ� ����, ��, ��, ����

��ó : MidC 1998 F��
*/

char buff[16], sorted[16];
map<string, set<string>> dict;

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    string a, b;
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, "XXXXXX")) break;
        strcpy(sorted, buff);
        qsort(sorted, strlen(sorted), sizeof(char), cmp1);
        a.assign(buff);
        b.assign(sorted);
        if (dict.find(b) == dict.end()) dict.insert(pair<string, set<string>>(b, set<string>()));
        dict[b].insert(a);
    }
    while (1) {
        scanf("%s", sorted);
        if (!strcmp(sorted, "XXXXXX")) break;
        qsort(sorted, strlen(sorted), sizeof(char), cmp1);
        a.assign(sorted);
        if (dict.find(a) == dict.end()) printf("NOT A VALID WORD\n");
        else {
            for (auto i : dict[a]) {
                printf("%s\n", i.c_str());
            }
        }
        printf("******\n");
    }
    return 0;
}