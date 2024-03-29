/*
 * 本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
 */

#include <iostream>

using namespace std;

int main() {
    string a;
    int b;
    cin >> a>>b;
    int tmp = 0, t = 0;
    t = (a[0] - '0') / b;
    if ((t != 0 && a.length() > 1) || a.length() == 1) {
        cout<<t;
    }
    tmp = (a[0] - '0') % b;
    for (int i = 1; i < a.length(); ++i) {
        t=(tmp*10+a[i]-'0')/b;
        cout<<t;
        tmp=(tmp*10+a[i]-'0')%b;
    }
    cout<<" "<<tmp;
}