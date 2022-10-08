#include "bits/stdc++.h"
using namespace std;

char s[105], ch;
int C_a, C_c, idx, Len, f, g;

void Count() {
    while (idx < Len) {
        f = 0;
        if (s[idx] == '+') { f = 0; idx += 1; }
        else if (s[idx] == '-') { f = 1; idx += 1; }
        else if (s[idx] == '=') { g = 1; idx += 1; }
        int Num = 0;
        while (isdigit(s[idx]))
            Num = Num * 10 + s[idx++] - '0';
        if (isalpha(s[idx])) {
            ch = s[idx++];
            Num = max(Num, 1);
            if (g ^ f) C_a -= Num;  // g 异或 f
            else C_a += Num, 1;
            continue;
        }
        if (g ^ f) C_c -= Num;
        else C_c += Num;
    }
}

int main() {
    scanf("%s", s);
    Len = strlen(s);
    Count();
    printf("%c=%.3lf\n", ch, (double)C_c/(-C_a));
    return 0;
}