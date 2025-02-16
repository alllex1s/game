#include "labyrinth.h"
#include "controll.h"


int main()
{
    int n = 2, m = 2, x = 50, y = 50, X = 100, Y = 100, n1 = 10, m1 = 5;
    /*
    cout << "размер игры: ";
    cin >> n >> m;
    cout << "размер клетки: ";
    cin >> x >> y;
    cout << "размер лабиринта: ";
    cin >> n1 >> m1;
    cout << "левый верхний угол: ";
    cin >> X >> Y;
    */
    vector<vector<labyrinth>> a(n, vector<labyrinth>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j].init(X + j * (X + x * m1), Y + i * (Y + y * n1), n1, m1, x, y);
            a[i][j].randomfill(0.3);
        }
    }
    int sz = (Y + y * n1) * n - Y;
    int h = 50;
    int bet = 10;
    int w = 100;
    
    controller cc;
    int X1 = (X + x * m1) * m + X;
    int Y1 = Y + sz / 2 - (bet + 2 * h) / 2;
    sf::Font f;
    f.loadFromFile("font.ttf");
    cc.init(X1, Y1, h, w, bet, f);
    cc.up.setButtonLabel(26.f, "UP");
    cc.up.setButtonFont(f);
    cc.down.setButtonLabel(26.f, "DOWN");
    cc.down.setButtonFont(f);
    cc.left.setButtonLabel(26.f, "LEFT");
    cc.left.setButtonFont(f);
    cc.right.setButtonLabel(26.f, "RIGHT");
    cc.right.setButtonFont(f);
    int xx = 0, yy = 0, r = 10;
    while (mainwindow.isOpen())
    {   
        sf::Event event;
        char c = cc.poll();
        if(c != 'X'){
            cout << c << endl;
            for(auto &i : a){
                for(auto &j : i){
                    j.move(c);
                    cout << "xxxxx " << j.px << " " << j.py << endl;
                }
            }
        }
        mainwindow.clear();
        
        for(auto i : a){
            for(auto j : i){
                j.draw();
            }
        }
        
        cc.draw();
        mainwindow.display();
    }
    return 0;
}