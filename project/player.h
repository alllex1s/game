#include <bits/stdc++.h>
#include "cell.h"

using namespace std;

struct player{
    sf::CircleShape p;
    void init(float x, float y, int r){
        p.setPosition({x, y});
        p.setRadius(r);
    }
    void go(float x, float y){
        p.setPosition({x, y});
        cout << "player " << x << " " << y << endl;
    }
    void setColor(sf::Color c){
        p.setFillColor(c);
        p.setOutlineColor(c);
    }
    void draw(){
        auto x = p.getPosition();
        mainwindow.draw(p);
    }
};