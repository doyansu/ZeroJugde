#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct point{
    int x;//x�y��
    int y;//y�y��
    int last;//last�W�Ӥ�V
    int turn;//turn��V����
};
int n, m;//n���; m�C��
int a[1000][100];//a�a��

bool bound(int x, int y){//�P�_�O�_�b�ɤ�; x, y�y��
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}
int main(){//�����H��ê��
    int b, e, k, x, y;//b�_�Iy�y��; e���Iy�y��; k��ê����; x, y��ê���y��
    queue<struct point> poi_list;//poi_list�ݳB�z�y���I
    struct point poi1, poi2;//poi1, poi2�{�B�z�y���I
    int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//dir��V
    int i;//i�X��

    memset(a, 0x6f, sizeof(a));//�]�w���j��

    while(cin>>n>>m>>b>>e>>k){
        a[0][b]=0;

        for(i=0; i<k; ++i){
            cin>>x>>y;
            a[x][y]=-1;
        }
        poi1.x=0, poi1.y=b;
        poi1.last=1;
        poi1.turn=0, poi2.turn=0;//��l��
        poi_list.push(poi1);

        while(!poi_list.empty()){//�s���u���j�M
            poi1=poi_list.front();
            poi_list.pop();

            if(a[poi1.x][poi1.y]>=poi1.turn)//poi1�����|�i�H�Χ�֪����s���ƨ�F(poi1.x, poi1.y)
                for(i=0; i<3; ++i)
                    if(bound(poi1.x+dir[i][0], poi1.y+dir[i][1])==true){
                        poi2.x=poi1.x+dir[i][0], poi2.y=poi1.y+dir[i][1];//��s�y��
                        poi2.last=i;//��s��V
                        poi2.turn=poi1.turn;//��s���s����
                        if(poi1.last!=i)//��W�@�Ӱʧ@���P��V
                            ++poi2.turn;
                        if(a[poi2.x][poi2.y]>poi2.turn){//�O�̤����s����
                            a[poi2.x][poi2.y]=poi2.turn;//��s�̤����s����
                            poi_list.push(poi2);//�i�H�~��
                        }
                    }
        }
        cout<<a[n-1][e]<<endl;//��X�̤����s����

        poi_list=queue<struct point>();
        memset(a, 0x6f, sizeof(a));//��l��

    }
    return 0;
}
