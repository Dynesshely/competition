#include <bits/stdc++.h>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
int read(){
    int rt = 0, fl = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-')fl = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9'){ rt = rt * 10 + ch - '0'; ch = getchar(); }
    return rt * fl;
}
const int maxn = 2000000;
int h[maxn], nx[maxn], to[maxn], cnt, chudu[maxn], pr[maxn], af[maxn],
    cnt_winner, n, q[maxn], l, r;
bool isWinner[maxn];
void add_edge(int u,int v){
    cnt ++; to[cnt] = v; nx[cnt] = h[u]; h[u] = cnt;
}
void del(int nd){
    af[pr[nd]] = af[nd]; pr[af[nd]] = pr[nd];
}
void bfs(){
    while(l < r){
        int t = q[l ++ ];
        t = h[t];
        int x = pr[n + 1];
        while(x != 0){
            while(x < to[t]  && t != 0){
                t = nx[t];
            }
            if(x != to[t]){
                isWinner[x] = 1;
                del(x);
                cnt_winner ++ ;
                q[r ++ ] = x;
            }
            x = pr[x];
        }
    }
}
int main(){
    int max_chudu = 0;
    n = read();
    for(int i = 1;i <= n + 1;i ++ ){
        pr[i] = i - 1; af[i] = i + 1;
    }
    for(int i = 1;i <= n;i ++ ){
        chudu[i] = read();
        max_chudu = max(max_chudu,chudu[i]);
        for(int j = chudu[i];j > 0;j -- ){
            int a = read();
            add_edge(i,a);
        }
    }
    for(int i = 1;i <= n;i ++ ){
        if(chudu[i] == max_chudu){
            q[r ++ ] = i,isWinner[i] = 1; del(i);cnt_winner ++ ;
        }
    }
    bfs();
    printf("%d",cnt_winner);
    for(int i = 1;i <= n;i ++ ) if(isWinner[i]) printf(" %d",i);
    printf("\n");
    return 0;
}

/* 
const int maxn  =  1000005;
int que[maxn  +  5], next[maxn], prev[maxn], pre[maxn], last[maxn], other[maxn], cd[maxn], l, n, m, cnt;
bool flag[maxn], ans[maxn];

int read(void){
    char ch  =  getchar(); int x  =  0;
    while (ch  <  '0'  ||  ch  >  '9') ch  =  getchar();
    while (ch  >=  '0'  &&  ch  <=  '9') { x  =  x  *  10  +  c  -  '0'; ch  =  getchar(); }
    return x;
}

void connect(int x,int y){ l ++ ; pre[l]  =  last[x]; last[x]  =  l; other[l]  =  y; }

int main(){
    n  =  read();
    for (int i  =  1; i  <=  n; i  ++ ){
        cd[i]  =  read();
        for (int j  =  1; j  <=  cd[i]; j  ++ ){
            int a; a  =  read(); connect(i, a);
        }
        if (cd[i] > cd[que[1]]) que[1] = i;
    }
    for (int i  =  0; i  <=  n; i  ++ ) { prev[i]  =  i  -  1; next[i]  =  i  +  1; }
    next[n]  =  0; pre[0]  =  0;
    int h  =  0, t  =  1;
    while (h  !=  t){
        h  =  h % maxn  +  1; int u  =  que[h];
        for (int p  =  last[u]; p; p  =  pre[p]){
            int v  =  other[p]; flag[v]  =  1;
        }
        int w  =  next[0];
        while (w){
            if (!flag[w]){
                ans[w]  =  1;	 cnt  ++ ;
                next[prev[w]]  =  next[w];
                prev[next[w]]  =  prev[w];
                t  =  t % maxn  +  1; que[t]  =  w;
            }
            w  =  next[w];
        }
        for (int p  =  last[u]; p; p  =  pre[p]){
            int v  =  other[p]; flag[v]  =  0;
        }
    }
    printf("%d", cnt);
    for (int i  =  1 ; i  <=  n; i  ++ )
        if (ans[i]) printf(" %d", i);
    printf("\n");
    return 0;
}
*/ 

/*  ???????????? ??????
const int MAXN  =  1000001;
int n, k, x, indegree[MAXN], outdegree[MAXN];
int max_outdegree  =   - 1, max_outdegree_index  =   - 1;
bool vis[MAXN];

struct node{
    int id;
    vector < int >  indegr, outdegr;
}nodes[MAXN];

queue < int >  pro_arr, ans;

void win(int a, int b){
    nodes[a].outdegr.push_back(b);
    nodes[b].indegr.push_back(a);
     ++  outdegree[a];
     ++  indegree[b];
}

void updateMax(int i){
    if(outdegree[i]  >  max_outdegree){
        max_outdegree  =  outdegree[i];
        max_outdegree_index  =  i;
    }
}

int main(){
    scanf("%d", &n);
    for(int i  =  1; i  <=  n;  ++  i){
        nodes[i].id  =  i;
        scanf("%d", &k);
        for(int j  =  0; j  <  k;  ++  j){
            scanf("%d", &x);
            win(i, x);  //  i  -  >  x
            updateMax(i);  //  update max_outdegree_index
        }
    }
    pro_arr.push(max_outdegree_index);
    while(!pro_arr.empty()){
         //  ??????????????????????????????????????????????????????
        int cur  =  pro_arr.front();  //  ???????????????
        ans.push(cur);  //  ????????????
        pro_arr.pop();  //  ???????????????
        vis[cur]  =  true;  //  ??????????????????????????????
        bool flag[MAXN]  =  {false};
        for(int i  =  0; i  <  outdegree[cur];  ++  i){
            flag[nodes[cur].outdegr[i]]  =  true;
        }
         //  ???????????????????????????????????????????????????
        for(int i  =  1; i  <=  n;  ++  i)
            if(!vis[i]  &&  !flag[i])
                pro_arr.push(i);
    }
    int size  =  ans.size();
    printf("%d ", size);
    int ans_arr[size];
    for(int i  =  1; i  <=  size;  ++  i)
        ans_arr[i]  =  ans.front(), ans.pop();
    sort(ans_arr  +  1, ans_arr  +  size  +  1);
    for(int i  =  1; i  <=  size;  ++  i)
        printf("%d ", ans_arr[i]);
    printf("\n");
    return 0;
}
*/ 

/*  ????????????
const int MAXN  =  1000001;
int n, k, x;

struct outdegr_id{
    int outdegree, id;
}outdegrs[MAXN];

queue < int >  ans_queue, dfs_queue;

struct node{
    unsigned int id, indegree  =  0, outdegree  =  0;
    vector < int >  fa, son;
}nodes[MAXN];

bool cmp (outdegr_id a, outdegr_id b){
    return a.outdegree  >  b.outdegree;
}

void dfs(int src){
    ans_queue.push(src);
    int son_num  =  nodes[src].son.size();
    for(int i  =  0; i  <  son_num;  ++  i){
        dfs_queue.push(nodes[src].son[i]);
    }
}

int main(){
    scanf("%d", &n);
    for(int i  =  1; i  <=  n;  ++  i){
        nodes[i].id  =  i;
        scanf("%d", &k);
        for(int j  =  0; j  <  k;  ++  j){
            scanf("%d", &x);  //  i ?????? x
             ++  nodes[i].outdegree;
            nodes[i].son.push_back(x);
             ++  nodes[x].indegree;
            nodes[x].fa.push_back(i);
            outdegrs[i].outdegree  =  nodes[i].outdegree;
            outdegrs[i].id  =  i;
        }
    }
    sort(outdegrs  +  1, outdegrs  +  n  +  1, cmp);
    dfs(outdegrs[n].id);
     //  for(int i  =  n; i  >=  1;  --  i){
     //      if(nodes[outdegrs[i].id].outdegree  >  0)
     //          dfs_queue.push(outdegrs[i].id);
     //  }
    while(!dfs_queue.empty()){
        int cur  =  dfs_queue.front();
        dfs_queue.pop();
        ans_queue.push(cur);
        dfs(cur);
    }
    printf("%ld ", ans_queue.size());
    return 0;
}
*/ 

/* 
    1. ????????? 0 ????????????????????????
    2. ???????????? 0 ?????????????????? 0 ????????????????????????
    3. ????????? 0 ??????????????????
*/ 

/*  ?????? 1  -  >  failed
const int maxn  =  1000001;
int n, k, i_win, tmp, ans_arr[maxn];
queue < int >  ans;

struct node{
    int id, inedge  =  0, outedge  =  0;
    vector  < int >  father;
    vector  < int >  sons;
}nodes[maxn];

bool contain(int f, int s, int *  index){
    int size  =  nodes[f].sons.size();
    for(int i  =  0; i  <  size;  ++  i)
        if(nodes[f].sons[i]  ==  s){
             * index  =  i; return true;
        }
    return false;
}

bool dfs(int src){  //  src  -  >  ???????????????  -  >  ??????????????????
    int fnum  =  nodes[src].father.size();  //  ????????????????????????
    for(int i  =  0; i  <  fnum;  ++  i){  //  ???????????????
        node *  r1  =  &nodes[nodes[src].father[i]];  //  r1  -  >  ???????????????
        int fr1  =  r1 -  > father.size();  //  ??????????????????????????????
        for(int j  =  0; j  <  fr1;  ++  j){  //  ???????????????
            node *  r2  =  &nodes[r1 -  > father[j]];  //  r2  -  >  ???????????????
            if(contain(r2 -  > id, src, &tmp))  //  ????????????????????????????????????????????????
                continue;
            else{
                bool eaten  =  false;  //  ?????????????????????????????????????????????
                for(int k  =  0; k  <  fnum  &&  !eaten;  ++  k){  //  ???????????????
                    node *  r1_1  =  &nodes[nodes[src].father[k]];  //  r1_1  -  >  ???????????????
                    int fr1_1  =  r1_1 -  > sons.size();  //  ??????????????????????????????
                    for(int u  =  0; u  <  fr1_1;  ++  u)
                        if(r1_1 -  > sons[u]  ==  r1 -  > father[j])  //  ???????????????????????????????????????
                            eaten  =  true; break;
                }
                if(!eaten)  //  ????????????????????????????????????????????????
                    return true;
            }
        }
    }
    return false;
}

//  bool dfs(int src){  //  ???????????? true , ???????????? false
//      int fnum  =  nodes[src].father.size();
//      bool pass  =  false;
//      for(int i  =  0; i  <  fnum;  ++  i){  //  ??????????????????
//          int ffnum  =  nodes[nodes[src].father[i]].father.size();
//          for(int j  =  0, l  =  0; j  <  ffnum;  ++  j){  //  ??????????????????
//              if(contain(nodes[nodes[src].father[i]].father[j], src, &l))
//                  continue;
//              else{  //  ???????????????????????????????????????????????????
//                  bool eaten  =  false;
//                  for(int k  =  0; k  <  fnum;  ++  k){  //  nodes[src].father[k]  -  >  ???????????????
//                      if(eaten) break;
//                      int ssnum  =  nodes[nodes[src].father[k]].sons.size();
//                      for(int u  =  0; u  <  ssnum;  ++  u){  //  ???????????????????????????
//                          if(nodes[nodes[src].father[k]].sons[u]  == 
//                              nodes[nodes[src].father[i]].father[j]){
//                              pass  =  false;
//                              eaten  =  true;
//                              break;
//                          }
//                      }
//                  }
//              }
//          }
//      }
//      return pass;
//  }

int main(){
    for(int i  =  1; i  <=  maxn;  ++  i)
        nodes[i].id  =  i;
    scanf("%d", &n);
    for(int i  =  1; i  <=  n;  ++  i){
        scanf("%d", &k);
        for(int j  =  1, index  =   - 1; j  <=  k;  ++  j){  //  ??? j ??????
            scanf("%d", &i_win);  //  ????????????
            if(contain(i_win, i, &index)){
                nodes[i_win].outedge  -- ;
                nodes[i_win].sons.erase(nodes[i_win].sons.begin()  +  index);
                continue;
            }
            nodes[i].sons.push_back(i_win);
            nodes[i].outedge  ++ ;
            nodes[i_win].father.push_back(i);
            nodes[i_win].inedge  ++ ;
        }
    }

    for(int i  =  1; i  <=  n;  ++  i){
        if(nodes[i].inedge  ==  0)  //  ????????? 0 ????????????????????????
            ans.push(i);
        else if(nodes[i].inedge  >=  1  &&  nodes[i].outedge  >=  1)
            if(dfs(i)) ans.push(i);
            else continue;
        else{  //  ????????? 0 ??????????????????
            if(dfs(i)) ans.push(i);
            else continue;
        }
    }

    int size  =  ans.size();
    printf("%d ", size);
    for(int i  =  0; i  <  size;  ++  i){
        ans_arr[i]  =  ans.front();
        ans.pop();
    }
    sort(ans_arr, ans_arr  +  size);
    for(int i  =  0; i  <  size;  ++  i)
        printf("%d ", ans_arr[i]);
    printf("\n");
    return 0;
}

*/ 
