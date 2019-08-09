/*
 * 给定两个字符串 A 和 B，本题要求你输出 A+B，即两个字符串的并集。要求先输出 A，再输出 B，但重复的字符必须被剔除。

输入格式：
输入在两行中分别给出 A 和 B，均为长度不超过 10
​6
​​ 的、由可见 ASCII 字符 (即码值为32~126)和空格组成的、由回车标识结束的非空字符串。

输出格式：
在一行中输出题面要求的 A 和 B 的和。

输入样例：
This is a sample test
to show you_How it works
输出样例：
This ampletowyu_Hrk
 */

#include<iostream>

using namespace std;

int main() {
    string a,b;
    getline(cin, a);
    getline(cin, b);
    int f[128]={0};
    for (int i = 0; i < a.length(); ++i) {
        f[a[i]]++;
    }
    for (int i = 0; i < b.length(); ++i) {
        f[b[i]]++;
    }

    for (int i = 0; i < a.length(); ++i) {
        if (f[a[i]] != 0) {
            cout << a[i];
            f[a[i]]=0;
        }
    }
    for (int i = 0; i < b.length(); ++i) {
        if (f[b[i]] != 0) {
            cout << b[i];
            f[b[i]]=0;
        }
    }
}