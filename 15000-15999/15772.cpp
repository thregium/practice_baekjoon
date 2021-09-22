#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : �� ������� ���� ����� ���� N(N <= 100000)���� ������ �����Ѵ�.
1. �־��� �̸��� ����ڰ� �����Ѵ�.
2. �־��� �̸��� ������� �ֱ� ���� �ð��� ���� Ƚ���� �̿��Ͽ� �ش� ����ڰ� ��� �ش��ϴ��� ����Ѵ�. (�з� ����)
��� ������� �̸��� ���� 10 ������ �ҹ��ڷ� �̷���� �ִ�.

�ذ� ��� : �� ����ڰ� ������ �� ���� �ش� ������� ���� ���θ� �ؽøʿ� ����Ǿ������� ���� Ȯ���Ѵ�.
������ ���� �ִٸ� ���� ����� ������Ʈ�ϰ�, ���ٸ� �ش��ϴ� ������ �ؽøʿ� �߰��Ѵ�.
2�� ������ ���� ��쿡�� ���������� �ؽø��� ���� ���� ���θ� Ȯ���Ѵ�. ������ ���� ���ٸ� "None"�� ����ϸ� �ǰ�,
������ ���� �ִٸ� �ؽøʿ��� ������ ã�� �ֱ� ���� �ð��� ���� Ƚ���� ��� ���ϴ����� ã��,
���ϴ� ���� �з��� ã�� ����ϸ� �ȴ�. �з��� �迭���� ���������� �̸� �����صδ� ���� ����.

�ֿ� �˰��� : ����, �ؽø�

��ó : KAIST 2018 S��
*/

char buff[16];
int freq[4], rec[4];
int cat[5][5] = { {1, 2, 3, 5, 5}, {6, 6, 3, 4, 5}, {6, 6, 7, 8, 8}, {10, 10, 10, 8, 8}, {9, 10, 10, 8, 11} };
const char* cats[] = { "None", "New Customer", "Promising", "About to Sleep", "Hibernating", "Lost", "Potential Loyalist",
"Need Attention", "About to Leave", "Champion", "Loyal Customer", "Can't Lose Them" };
unordered_map<string, pair<int, int>> um;

int main(void) {
    int n, o, f, r, fc, rc;
    string name;
    for (int i = 0; i < 4; i++) scanf("%d", &rec[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &freq[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %s", &o, buff);
        name.assign(buff);
        if (o == 1) {
            if (um.find(name) == um.end()) {
                um.insert(pair<string, pair<int, int>>(name, pair<int, int>(1, i)));
            }
            else {
                (um.find(name)->second.first)++;
                um.find(name)->second.second = i;
            }
        }
        else {
            if (um.find(name) == um.end()) {
                printf("None\n");
            }
            else {
                f = um.find(name)->second.first;
                r = i - (um.find(name)->second.second);
                fc = -1, rc = -1;
                for (int j = 0; j < 4; j++) {
                    if (f <= freq[j]) {
                        fc = j;
                        break;
                    }
                }
                if (fc < 0) fc = 4;
                for (int j = 0; j < 4; j++) {
                    if (r <= rec[j]) {
                        rc = j;
                        break;
                    }
                }
                if (rc < 0) rc = 4;
                printf("%s\n", cats[cat[fc][rc]]);
            }
        }
    }
    return 0;
}