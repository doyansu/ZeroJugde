/*
https://66lemon66.blogspot.com/2020/09/zerojudge-f260-c.html

https://home.gamer.com.tw/creationDetail.php?sn=4919118

https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86



查找 找到該點的根節點 //search

	int findParnent(int a){
    		return parent[a] == a ? a : (parent[a] = findParnent(parent[a]));
	}

	(parent[a] = findParnent(parent[a])) <- 最佳化下次查找可直接找到根節點



合併 (a, b要合併)//merge

	   a = findParnent(a);
           b = findParnent(b);
           if(a != b){
               if(groupSIZE[a] > groupSIZE[b]){
                   parent[b] = a;
                   groupSIZE[a] += groupSIZE[b];
               }
               else {
                   parent[a] = b;
                   groupSIZE[b] += groupSIZE[a];
               }
           }

先找到 a , b 的根節點 
相同代表已在同一集合
不同則根據樹的大小決定合併到哪邊
*/

#include <stdio.h>
#define SIZE 100000

int parent[SIZE], groupSIZE[SIZE], group;

int findParnent(int a){//search
    return parent[a] == a ? a : (parent[a] = findParnent(parent[a]));
}

static inline void solve(){
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        group = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            groupSIZE[i] = 1;
        }
        while(m--){
            int a, b;
            scanf("%d%d", &a, &b);
            a = findParnent(a);
            b = findParnent(b);
            if(a != b){
                group--;
                if(groupSIZE[a] > groupSIZE[b]){//merge
                    parent[b] = a;
                    groupSIZE[a] += groupSIZE[b];
                }
                else {
                    parent[a] = b;
                    groupSIZE[b] += groupSIZE[a];
                }
            }
        }
        printf("%d\n", group);
    }
}

int main(){
    solve();
    return 0;
}
