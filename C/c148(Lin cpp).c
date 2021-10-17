#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct point{
    int x;//x座標
    int y;//y座標
    int last;//last上個方向
    int turn;//turn轉向次數
};
int n, m;//n行數; m列數
int a[1000][100];//a地圖

bool bound(int x, int y){//判斷是否在界內; x, y座標
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}
int main(){//機器人障礙賽
    int b, e, k, x, y;//b起點y座標; e終點y座標; k障礙物數; x, y障礙物座標
    queue<struct point> poi_list;//poi_list待處理座標點
    struct point poi1, poi2;//poi1, poi2現處理座標點
    int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//dir方向
    int i;//i旗標

    memset(a, 0x6f, sizeof(a));//設定極大值

    while(cin>>n>>m>>b>>e>>k){
        a[0][b]=0;

        for(i=0; i<k; ++i){
            cin>>x>>y;
            a[x][y]=-1;
        }
        poi1.x=0, poi1.y=b;
        poi1.last=1;
        poi1.turn=0, poi2.turn=0;//初始化
        poi_list.push(poi1);

        while(!poi_list.empty()){//廣度優先搜尋
            poi1=poi_list.front();
            poi_list.pop();

            if(a[poi1.x][poi1.y]>=poi1.turn)//poi1的路徑可以用更少的轉彎次數到達(poi1.x, poi1.y)
                for(i=0; i<3; ++i)
                    if(bound(poi1.x+dir[i][0], poi1.y+dir[i][1])==true){
                        poi2.x=poi1.x+dir[i][0], poi2.y=poi1.y+dir[i][1];//更新座標
                        poi2.last=i;//更新方向
                        poi2.turn=poi1.turn;//更新轉彎次數
                        if(poi1.last!=i)//跟上一個動作不同方向
                            ++poi2.turn;
                        if(a[poi2.x][poi2.y]>poi2.turn){//是最少轉彎次數
                            a[poi2.x][poi2.y]=poi2.turn;//更新最少轉彎次數
                            poi_list.push(poi2);//可以繼續走
                        }
                    }
        }
        cout<<a[n-1][e]<<endl;//輸出最少轉彎次數

        poi_list=queue<struct point>();
        memset(a, 0x6f, sizeof(a));//初始化

    }
    return 0;
}
