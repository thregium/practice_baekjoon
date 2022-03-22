#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <map>
using namespace std;

char buff[103000];
map<string, int> animal;

int main(void) {
    int n;
    string s;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(buff, 101300, stdin);
            if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
            for (int j = strlen(buff) - 1; j >= 0; j--) {
                buff[j] = tolower(buff[j]);
                if (j == 0 || buff[j - 1] == ' ') {
                    s.assign(&buff[j]);
                    if (animal.find(s) != animal.end()) animal[s]++;
                    else animal.insert({ s, 1 });
                    break;
                }
            }
        }
        printf("List %d:\n", tt);
        for (auto& i : animal) {
            printf("%s | %d\n", i.first.c_str(), i.second);
        }
        animal.clear();
    }
    return 0;
}
