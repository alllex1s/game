#include "player.h"
#include <bits/stdc++.h>

using namespace std;

random_device rd;

mt19937 rnd(rd());

double rnd01(){
    return ((double)rnd() / UINT32_MAX);
}

struct labyrinth{
    int X;//координата по X левого верхнего угла
    int Y;//координата по Y левого верхнего угла
    int n;//количество строк
    int m;//количество столбцов
    int x;//ширина клетки
    int y;//высота клетки
    vector<vector<cell>> p;
    vector<vector<dp>> go;
    player pl;
    int px = 0, py = 0;
    void calc(){
        for(int i = 0; i < m; i++){
            go[0][i].up = {0, i};
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(p[i - 1][j].isWall()){
                    go[i][j].up = {i, j};
                }else{
                    go[i][j].up = go[i - 1][j].up;
                }
            }
        }
        for(int i = 0; i < m; i++){
            go[n - 1][i].down = {n - 1, i};
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(p[i + 1][j].isWall()){
                    go[i][j].down = {i, j};
                }else{
                    go[i][j].down = go[i + 1][j].down;
                }
            }
        }
        for(int i = 0; i < n; i++){
            go[i][0].left = {i, 0};
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(p[i][j - 1].isWall()){
                    go[i][j].left = {i, j};
                }else{
                    go[i][j].left = go[i][j - 1].left;
                }
            }
        }
        for(int i = 0; i < n; i++){
            go[i][m - 1].right = {i, m - 1};
        }
        for(int i = 0; i < n; i++){
            for(int j = m - 2; j >= 0; j--){
                if(p[i][j + 1].isWall()){
                    go[i][j].right = {i, j};
                }else{
                    go[i][j].right = go[i][j + 1].right;
                }
            }
        }
    }
    void init(int X1, int Y1, int n1, int m1, int x1, int y1){
        X = X1;
        Y = Y1;
        n = n1;
        m = m1;
        x = x1;
        y = y1;
        p.resize(n, vector<cell>(m));
        go.resize(n, vector<dp>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                p[i][j].init(X + j * x, Y + i * y, x - 1, y - 1);
            }
        }
        pl.init(p[0][0].X, p[0][0].Y, x / 2 - 2);
        pl.setColor(sf::Color::Red);
    }
    void draw(){
        for(int i = X; i <= X + x * m; i += x){
            drawline(sf::Vector2f(i, Y), sf::Vector2f(i, Y + n * y));
        }
        for(int i = Y; i <= Y + y * n; i += y){
            drawline(sf::Vector2f(X, i), sf::Vector2f(X + m * x, i));
        }
        for(auto i : p){
            for(auto j : i){
                j.draw();
            }
        }
        pl.draw();
    }
    void randomfill(double probability){
        pl.go(p[0][0].X, p[0][0].Y);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0) && (j == 0)){
                    continue;
                }
                if(rnd01() < probability){
                    if(!p[i][j].isWall()){
                        p[i][j].pick();
                    }
                }else{
                    if(p[i][j].isWall()){
                        p[i][j].pick();
                    }
                }
            }
        }
        calc();
    }
    void move(char c){
        int npx, npy;
        if(c == 'U'){
            npx = go[px][py].up.x;
            npy = go[px][py].up.y;
        }else if(c == 'D'){
            npx = go[px][py].down.x;
            npy = go[px][py].down.y;
        }else if(c == 'L'){
            npx = go[px][py].left.x;
            npy = go[px][py].left.y;
        }else{
            npx = go[px][py].right.x;
            npy = go[px][py].right.y;
        }
        cout << px << " " << py << "   " << npx << " " << npy << endl;
        this->pl.go(p[npx][npy].X, p[npx][npy].Y);
        px = npx;
        py = npy;
    }
    void vivo(){
        for(auto i : p){
            for(auto j : i){
                cout << j.isWall();
            }
            cout << endl;
        }
    }
};