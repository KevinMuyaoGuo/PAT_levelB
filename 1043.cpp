/**
 * 给定一个长度不超过 10
​4
​​  的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 10
​4
​​  的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
 */

#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int P = 0, A = 0, T = 0, e = 0, s = 0, t = 0;
    for (int i = 0; i < str.length(); ++i) {
        switch (str[i]) {
            case 'P':
                P++;
                break;
            case 'A':
                A++;
                break;
            case 'T':
                T++;
                break;
            case 'e':
                e++;
                break;
            case 's':
                s++;
                break;
            case 't':
                t++;
                break;
        }
    }
    while (P != 0 || A != 0 || T != 0 || e != 0 || s != 0 || t != 0) {
        if (P != 0) {
            P--;
            cout << "P";
        }
        if (A != 0) {
            A--;
            cout << 'A';
        }
        if (T != 0) {
            T--;
            cout << 'T';
        }
        if (e != 0) {
            e--;
            cout << 'e';
        }
        if (s != 0) {
            s--;
            cout << 's';
        }
        if (t != 0) {
            t--;
            cout << 't';
        }
    }
    return 0;
}