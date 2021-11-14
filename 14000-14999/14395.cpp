#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#define MX 1000000000
using namespace std;

/*
���� : 10�� ������ �� �ڿ��� S�� T�� �־��� ��, ���� ������ ���� S���� T�� �̵��� �������� ���ϰ�, ������ ��쿡��
���� �̵� Ƚ���� ���� �� ��� ���������� ���� �ռ� ���� ������ ����Ѵ�.
1. x * x, 2. x + x, 3. x - x, 4. x / x

�ذ� ��� : BFS�� ���� S���� �� ������ �̵� �Ÿ��� �̵� ������ �����Ѵ�. ť�� �ʿ� �̵� ������ ���� ������ �ȴ�.
�׿� �Բ� �� ������� �ĵ��� ������ ���� �̹� �湮�� ��츦 ������ ���� ���� ���� ��� ���� �ռ� ������
���� �̵� ������ ���� �ȴ�. ����, T�� ������ ��� ���� ���� ������ �Ǵ� ���̴�.
�ʿ� T�� ���ٸ� �׷��� ������ ���� ���̴�. ���� �����ϴ� ������ �ּ� 2�� �̻��� ������ ���ϱ� ������
S�� T�� ������ �ſ� ũ���� ���� �ð� ���� ���� �� �ִ�. �߰����� 10���� �Ѿ�� ���� �� �ʿ䰡 ���� �����̴�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ������?
*/

queue<pair<int, string>> q;
map<int, string> mp;

void bfs(int s, int e) {
    int x;
    string ss;
    ss.assign("");
    q.push(pair<int, string>(s, ss));
    mp.insert(pair<int, string>(s, ss));
    while (q.size()) {
        x = q.front().first;
        ss = q.front().second;
        q.pop();
        if (x == e) return;
        
        if ((long long)x * x <= MX && mp.find(x * x) == mp.end()) {
            q.push(pair<int, string>(x * x, ss + "*"));
            mp.insert(pair<int, string>(x * x, ss + "*"));
        }
        if (x + x <= MX && mp.find(x + x) == mp.end()) {
            q.push(pair<int, string>(x + x, ss + "+"));
            mp.insert(pair<int, string>(x + x, ss + "+"));
        }
        if (mp.find(0) == mp.end()) {
            q.push(pair<int, string>(0, ss + "-"));
            mp.insert(pair<int, string>(0, ss + "-"));
        }
        if (mp.find(1) == mp.end()) {
            q.push(pair<int, string>(1, ss + "/"));
            mp.insert(pair<int, string>(1, ss + "/"));
        }
    }
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == b) {
        printf("0");
        return 0;
    }
    bfs(a, b);
    if (mp.find(b) == mp.end()) printf("-1");
    else printf("%s", (mp.find(b)->second).c_str());
    return 0;
}