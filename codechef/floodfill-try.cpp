#include<iostream>
using namespace std;

#define M 8
#define N 8

void floodFillUntil(int screen[][N], int x, int y, int prevC, int newC){

    if(x < 0 || x >= M || y < 0 || y >= N)
        return;
    if(screen[x][y] != prevC)
        return;

    screen[x][y] = newC;

    floodFillUntil(screen, x+1, y, prevC, newC);
    floodFillUntil(screen, x-1, y, prevC, newC);
    floodFillUntil(screen, x, y+1, prevC, newC);
    floodFillUntil(screen, x, y-1, prevC, newC);
    return;
}

void floodFill(int screen[][N], int x, int y, int newC){
    int prevC = screen[x][y];
    floodFillUntil(screen, x, y, prevC, newC);
    return;
}

int main(){
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    
    int x, y;
    int newC = 3;
    cin>>x>>y;
    cin>>newC;

    floodFill(screen, x, y, newC);

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }

}