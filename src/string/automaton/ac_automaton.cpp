#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
struct Tree//字典树 
{
    int fail;//失配指针
    int vis[26];//子节点的位置
    int end;//标记以这个节点结尾的单词编号
} AC[100000];//Trie树
int cnt = 0;//Trie的指针
struct Result {
    int num;
    int pos;

    bool operator<(const Result &b) const {
        if (num != b.num)
            return num > b.num;
        else
            return pos < b.pos;
    }
} Ans[100000];//所有单词的出现次数

string text[100000];

inline void Clean(int x) {
    memset(AC[x].vis, 0, sizeof(AC[x].vis));
    AC[x].fail = 0;
    AC[x].end = 0;
}

void Build(const string &s, int Num) {
    int now = 0;//字典树的当前指针
    for (int i = 0; i < s.length(); ++i)//构造Trie树
    {
        if (AC[now].vis[s[i] - 'a'] == 0)//Trie树没有这个子节点
        {
            AC[now].vis[s[i] - 'a'] = ++cnt;//构造出来
            Clean(cnt);
        }
        now = AC[now].vis[s[i] - 'a'];//向下构造
    }
    AC[now].end = Num;//标记单词结尾
}

//构造fail指针
void get_fail() {
    queue<int> q;//队列
    for (int i = 0; i < 26; ++i)//第二层的fail指针提前处理一下
    {
        if (AC[0].vis[i] != 0) {
            AC[AC[0].vis[i]].fail = 0;//指向根节点
            q.push(AC[0].vis[i]);//压入队列
        }
    }
    //BFS求fail指针
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i)//枚举所有子节点
        {
            if (AC[u].vis[i] != 0)//存在这个子节点
            {
                AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i];
                //子节点的fail指针指向当前节点的fail指针所指向的节点的相同子节点
                q.push(AC[u].vis[i]);//压入队列
            } else//不存在这个子节点
                AC[u].vis[i] = AC[AC[u].fail].vis[i];
            //当前节点的这个子节点指向当前节点fail指针的这个子节点
        }
    }
}

int AC_Query(const string &s)//AC自动机匹配
{
    int l = s.length();
    int now = 0, ans = 0;
    for (int i = 0; i < l; ++i) {
        now = AC[now].vis[s[i] - 'a'];//向下一层
        for (int t = now; t; t = AC[t].fail)//循环求解
            Ans[AC[t].end].num++;
    }
    return ans;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0)break;
        cnt = 0;
        Clean(0);
        for (int i = 1; i <= n; ++i) {
            cin >> text[i];
            Ans[i].num = 0;
            Ans[i].pos = i;
            Build(text[i], i);
        }
        AC[0].fail = 0;//结束标志
        get_fail();//求出失配指针
        cin >> text[0];//文本串
        AC_Query(text[0]);
        sort(&Ans[1], &Ans[n + 1]);
        cout << Ans[1].num << endl;
        cout << text[Ans[1].pos] << endl;
        for (int i = 2; i <= n; ++i) {
            if (Ans[i].num == Ans[i - 1].num)
                cout << text[Ans[i].pos] << endl;
            else
                break;
        }
    }
    return 0;
}