/*
 * 火星人是以 13 进制计数的：

地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
 */

#include<iostream>
#include <sstream>

using namespace std;

string zero = "tret";
string one_to_twelve[12]={"jan", "feb", "mar", "apr", "may", "jun",
                          "jly", "aug", "sep", "oct", "nov", "dec"};
string top_digits[12]={"tam", "hel", "maa", "huh", "tou", "kes",
                       "hei", "elo", "syy", "lok", "mer", "jou"};

void earth_to_mars(int n){
    int q, r;
    q = n / 13;
    r = n % 13;
    if (q != 0&&r!=0) {
        cout<<top_digits[q-1]<<" "<<one_to_twelve[r - 1];
    } else if (q != 0 && r == 0) {
        cout<<top_digits[q-1];
    }else{
        cout << one_to_twelve[r - 1];
    }
}

void mars_to_earth(string s){
    istringstream iss(s);
    string inp[2];
    for (int i = 0; iss >> inp[i]; ++i);
    int sum=0;
    if (inp[1] == "") {
        for (int i = 0; i < 12; ++i) {
            if (inp[0] == one_to_twelve[i]) {
                sum+=i+1;
                break;
            } else if (inp[0] == top_digits[i]) {
                sum += 13 * (i + 1);
                break;
            }
        }
    }else{
        for (int i = 0; i < 12; ++i) {
            if (inp[0] == top_digits[i]) {
                sum += 13 * (i + 1);
            }
        }
        for (int i = 0; i < 12; ++i) {
            if (inp[1] == one_to_twelve[i]) {
                sum+=i+1;
                break;
            }
        }
    }
    cout << sum;
}

int main() {
    int n;
    cin>>n;
    cin.ignore();   //等价于  string a; getline(cin, a);  读掉cin>>n之后的\n

    string s[n];
    for (int i = 0; i < n; ++i) {       // 或scanf("%[^\n]", &s[i])
        getline(cin, s[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (s[i][0] >= '0' && s[i][0] <= '9') {
            if (s[i] == "0") {
                cout << "tret";
            }else{
                earth_to_mars(stoi(s[i]));
                /* 这样也可以string to int
                 * stringstream ss;
                ss << s[i];
                int e;
                ss >> e;*/
            }
        }else{
            if (s[i] == "tret") {
                cout<<0;
            }else{
                mars_to_earth(s[i]);
            }
        }
        cout<<endl;
    }
}
