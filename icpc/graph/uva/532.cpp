#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)

int born, dead;
int L, R, C;
char dun[40][40][40];
int d[40][40][40];
int arrx[64000], arry[64000], arrz[64000];

void play(int x, int y, int z, int t){
    if (x >= R || y >= L || z >= C || x < 0 || y < 0 || z < 0) return;
    if (dun[x][y][z] == '#') return;
    if (d[x][y][z] != -1 ) return; //TQ XXX Donot visit the marked vertex
    arrx[born] = x; arry[born] = y; arrz[born] = z; born++; //TQ XXX Mark all the path vertex. Move along the each vertex later.
    d[x][y][z] = t + 1;
}

void bfs(){
    int x, y, z, dd;
    born=dead=0;
    memset(d, -1, sizeof d);
    REP(x,0,L)
        REP(y,0,R)
            REP(z,0,C)
                if (dun[x][y][z] == 'S'){
                    arrx[born] = x; arry[born] = y; arrz[born] = z; born++;
                    d[x][y][z] = 0;
                }
    while (born > dead){
        x = arrx[dead], y = arry[dead], z = arrz[dead]; dead++;
        dd = d[x][y][z];
        if (dun[x][y][z] == 'E'){
            cout << "Escaped in " << dd << " minute(s)." << endl; return; }
        play(x-1,y,z,dd); play(x+1,y,z,dd);
        play(x,y-1,z,dd); play(x,y+1,z,dd);
        play(x,y,z+1,dd); play(x,y,z-1,dd);
        }
        cout << "Trapped!\n";
}

int main(){
    while (cin >> R >> L >> C && R){
    //REP(i,0,C)
        REP(j,0,R)
            REP(k,0,L)
                cin >> dun[j][k];
        bfs();
    }
    return 0;
}
