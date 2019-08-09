/*
 *PAT 准考证号由 4 部分组成：

第 1 位是级别，即 T 代表顶级；A 代表甲级；B 代表乙级；
第 2~4 位是考场编号，范围从 101 到 999；
第 5~10 位是考试日期，格式为年、月、日顺次各占 2 位；
最后 11~13 位是考生编号，范围从 000 到 999。
现给定一系列考生的准考证号和他们的成绩，请你按照要求输出各种统计信息。

输入格式：
输入首先在一行中给出两个正整数 N（≤10
​4
​​ ）和 M（≤100），分别为考生人数和统计要求的个数。

接下来 N 行，每行给出一个考生的准考证号和其分数（在区间 [0,100] 内的整数），其间以空格分隔。

考生信息之后，再给出 M 行，每行给出一个统计要求，格式为：类型 指令，其中

类型 为 1 表示要求按分数非升序输出某个指定级别的考生的成绩，对应的 指令 则给出代表指定级别的字母；
类型 为 2 表示要求将某指定考场的考生人数和总分统计输出，对应的 指令 则给出指定考场的编号；
类型 为 3 表示要求将某指定日期的考生人数分考场统计输出，对应的 指令 则给出指定日期，格式与准考证上日期相同。
输出格式：
对每项统计要求，首先在一行中输出 Case #: 要求，其中 # 是该项要求的编号，从 1 开始；要求 即复制输入给出的要求。随后输出相应的统计结果：

类型 为 1 的指令，输出格式与输入的考生信息格式相同，即 准考证号 成绩。对于分数并列的考生，按其准考证号的字典序递增输出（题目保证无重复准考证号）；
类型 为 2 的指令，按 人数 总分 的格式输出；
类型 为 3 的指令，输出按人数非递增顺序，格式为 考场编号 总人数。若人数并列则按考场编号递增顺序输出。
如果查询结果为空，则输出 NA。

输入样例：
8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 180908
2 999
输出样例：
Case 1: 1 A
A107180908108 100
A107180908021 98
A112180318002 98
Case 2: 2 107
3 260
Case 3: 3 180908
107 2
123 2
102 1
Case 4: 2 999
NA
 */


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
    string t;
    int value;
};
bool cmp(const node &a, const node &b) {
    return a.value != b.value ? a.value > b.value : a.t < b.t;
}
int main() {
    int n, k, num;
    string s;
    cin >> n >> k;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].t >> v[i].value;
    for (int i = 1; i <= k; i++) {
        cin >> num >> s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        vector<node> ans;
        int cnt = 0, sum = 0;
        if (num == 1) {
            for (int j = 0; j < n; j++)
                if (v[j].t[0] == s[0]) ans.push_back(v[j]);
        } else if (num == 2) {
            for (int j = 0; j < n; j++) {
                if (v[j].t.substr(1, 3) == s) {
                    cnt++;
                    sum += v[j].value;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
        } else if (num == 3) {
            unordered_map<string, int> m;
            for (int j = 0; j < n; j++)
                if (v[j].t.substr(4, 6) == s) m[v[j].t.substr(1, 3)]++;
            for (auto it : m) ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(),cmp);
        for (int j = 0; j < ans.size(); j++) printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
        if (((num == 1 || num == 3) && ans.size() == 0) || (num == 2 && cnt == 0)) printf("NA\n");
    }
    return 0;
}


/* 自己写的，有错
 *
 * #include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct student {
    string no;
    int grade;
};

bool cmp1(student s1, student s2) {
    if (s1.grade == s2.grade) {
        return s1.no < s2.no;
    } else {
        return s1.grade > s2.grade;
    }
}

bool cmp3(pair<string, int> p1, pair<string, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<student> vb, va, vt, v;
    map<string,vector<student>> mp;
    map<string,vector<student>>::iterator it;
    for (int i = 0; i < n; ++i) {
        student s;
        cin >> s.no >> s.grade;
        string t=s.no.substr(4, 6);
        it = mp.find(t);
        if (it != mp.end()) {
            it->second.emplace_back(s);
        }else{
            vector<student> st;
            st.emplace_back(s);
            mp.insert(pair<string, vector<student>>(t, st));
        }
        if (s.no[0] == 'B') {
            vb.emplace_back(s);
        } else if (s.no[0] == 'A') {
            va.emplace_back(s);
        } else {
            vt.emplace_back(s);
        }
        v.emplace_back(s);
    }

    sort(vb.begin(), vb.end(), cmp1);
    sort(va.begin(), va.end(), cmp1);
    sort(vt.begin(), vt.end(), cmp1);

    for (int i = 0; i < m; ++i) {
        int opt;
        cin >> opt;
        cout << "Case " << i + 1 << ": " << opt << " ";
        switch (opt) {
            case 1: {
                char c;
                cin >> c;
                cout << c << endl;
                if (c == 'B') {
                    for (int j = 0; j < vb.size(); ++j) {
                        cout << vb[j].no << " " << vb[j].grade << endl;
                    }
                    if (vb.size() == 0) {
                        cout << "NA" << endl;
                    }
                } else if (c == 'A') {
                    for (int j = 0; j < va.size(); ++j) {
                        cout << va[j].no << " " << va[j].grade << endl;
                    }
                    if (va.size() == 0) {
                        cout << "NA" << endl;
                    }
                } else {
                    for (int j = 0; j < vt.size(); ++j) {
                        cout << vt[j].no << " " << vt[j].grade << endl;
                    }
                    if (vt.size() == 0) {
                        cout << "NA" << endl;
                    }
                }
                break;
            }
            case 2: {
                string t;
                cin >> t;
                cout << t << endl;
                int cnt = 0, sum = 0;
                bool f1 = 1;
                for (int j = 0; j < v.size(); ++j) {
                    if (v[j].no.substr(1, 3) == t) {
                        cnt++;
                        sum += v[j].grade;
                        f1 = 0;
                    }
                }
                if (f1) {
                    cout << "NA" << endl;
                    break;
                }
                cout << cnt << " " << sum << endl;
                break;
            }
            case 3: {
                string t;
                cin>>t;
                cout<<t<<endl;
                it = mp.find(t);
                vector<student> s=it->second;
                if (s.size()==0) {
                    cout << "NA" << endl;
                    break;
                }
//                int cnt[1000]={0};
//                for (int j = 0; j < s.size(); ++j) {
//                    int ind=stoi(s[j].no.substr(1, 3));
//                    cnt[ind]++;
//                }
                map<string,int> m;
                map<string,int>::iterator it;
                for (int j = 0; j < s.size(); ++j) {
                    string r=s[j].no.substr(1, 3);
                    it = m.find(r);
                    if (it != m.end()) {
                        it->second++;
                    }else{
                        m.insert(pair<string, int>(r, 1));
                    }
                }

                vector<pair<string, int>> tmp;
                for (it = m.begin(); it != m.end(); ++it) {
                    tmp.emplace_back(pair<string, int>(it->first, it->second));
                }
                sort(tmp.begin(), tmp.end(), cmp3);
                for (int k = 0; k < tmp.size(); ++k) {
                    cout << tmp[k].first << " " << tmp[k].second << endl;
                }
                break;

                *//* 这么写后两个例子会超时
                 * string t;
                cin >> t;
                cout << t << endl;
                map<string, int> m;
                map<string, int>::iterator it;
                bool f2 = 1;
                for (int j = 0; j < v.size(); ++j) {
                    if (v[j].no.substr(4, 6) == t) {
                        f2 = 0;
                        it = m.find(v[j].no.substr(1,3));
                        if (it != m.end()) {
                            it->second++;
                        } else {
                            m.insert(pair<string, int>(v[j].no.substr(1,3), 1));
                        }
                    }
                }
                if (f2) {
                    cout << "NA" << endl;
                    break;
                }
                vector<pair<string, int>> tmp;
                for (it = m.begin(); it != m.end(); ++it) {
                    tmp.emplace_back(pair<string, int>(it->first, it->second));
                }
                sort(tmp.begin(), tmp.end(), cmp3);
                for (int k = 0; k < tmp.size(); ++k) {
                    cout << tmp[k].first << " " << tmp[k].second << endl;
                }
                break;*//*
            }
        }
    }
}*/
