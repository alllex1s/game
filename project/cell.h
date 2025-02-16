#include "MainWindow.h"

struct cell{
    int X;
    int Y;
    int szx;
    int szy;
    bool wall;
    sf::Color c;
    sf::RectangleShape r;
    void init(int x1, int y1, int szx1, int szy1){
        X = x1;
        Y = y1;
        szx = szx1;
        szy = szy1;
        wall = 0;
        c = sf::Color::Black;
        r.setSize(sf::Vector2f(szx, szy));
        r.setFillColor(c);
        r.setPosition(X, Y);
    }
    void pick(){
        if(!wall){
            wall = 1;
            c = sf::Color::White;
        }else{
            wall = 0;
            c = sf::Color::Black;
        }
        r.setFillColor(c);
    }
    bool isWall(){
        return wall;
    }
    void draw(){
        mainwindow.draw(r);
    }
};

struct pos{
    int x;
    int y;
};

struct dp{
    pos up;
    pos down;
    pos left;
    pos right;
};
