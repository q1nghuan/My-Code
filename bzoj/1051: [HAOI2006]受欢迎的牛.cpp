/**************************************************************
    Problem: 1051
    User: q1nghuan
    Language: C++
    Result: Accepted
    Time:80 ms
    Memory:2312 kb
****************************************************************/
 
#include<bits/stdc++.h>
using namespace std;
 
const int Maxn = 5e4 + 5;
const int maxn = 1e4 + 5;
 
int n, m, ans, flag;
int cnt, col, top, num;
int head[maxn], co[maxn];
int dfn[maxn], low[maxn];
int rd[maxn], fls[maxn];
int st[maxn];
 
struct node {
    int nxt;
    int to;
}edge[Maxn];
 
inline void add_edge(int x, int y) {
    edge[++cnt].nxt = head[x];
    edge[cnt].to = y;
    head[x] = cnt;
} 
 
void tarjan(int u) {
    dfn[u] = low[u] = ++num;
    st[++top] = u;
    for(int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else
            if(!co[v])
                low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        co[u] = ++col;
        ++fls[col];
        while(st[top] != u) {
            ++fls[col];
            co[st[top]] = col;
            top--;
        }
        top--;
    }
}
 
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= m; i++) {
        int t1, t2;
        scanf("%d %d",&t1,&t2);
        add_edge(t2, t1);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
     
    for(int i = 1; i <= n; i++)
        for(int j = head[i]; j; j = edge[j].nxt) {
            int v = edge[j].to;
            if(co[i] != co[v]) 
                rd[co[v]]++;
        }
     
    for(int i = 1; i <= col; i++) {
        if(!rd[i])
            ans = fls[i], flag++;
    }   
    if(flag == 1)
        printf("%d\n",ans);
    else
        printf("0\n");  
     
    return 0;   
} 
