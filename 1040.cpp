/*
 * 字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10
​5
​​ ，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT
输出样例：
2
 */

#include <iostream>
#define lim 1000000007

using namespace std;

int main() {
    string s;
    cin>>s;
    int cntAT=0,cntPAT=0,cnt=0;
    for (int i = s.length()-1; i >=0; --i) {
        if (s[i] == 'T') {
            cntAT++;
        } else if (s[i] == 'A') {
            cntPAT+=cntAT;
        }else{
            cnt+=cntPAT;
            if (cnt >= lim) {
                cnt %= lim;
            }
        }
    }
    cout<<cnt;
}