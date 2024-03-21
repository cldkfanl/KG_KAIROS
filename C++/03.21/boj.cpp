#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int N, M, K;
int arr[101][101] = {};
bool flag[101][101] = {};
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};
int maxsize = 0;
int nowsize = 0;
void check(int x, int y){
    flag[x][y] = true;
    nowsize++;
    for(int i=0; i<4; i++){
        int nx = x + fx[i];
        int ny = y + fy[i];
        if(nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 1 && !flag[nx][ny]){
            check(nx,ny);
        }
    }
}
void dfs(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            flag[i][j] = false;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 1 && !flag[i][j]){
                nowsize = 0;
                check(i,j);
                maxsize = max(maxsize, nowsize);
            }
        }
    }
}
int main(){
    cin>>N>>M>>K;

    for(int i=0; i<K; i++){
        int x, y;
        cin >> x >> y;
        arr[x-1][y-1] = 1;
    }
    dfs();    
    cout<<maxsize<<endl;
    return 0;
}