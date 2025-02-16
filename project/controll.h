#include "button/src/RectButton.cpp"
#include "MainWindow.h"


struct controller{
    int X, Y, h, w, bet;
    RectButton up, down, left, right;
    void init(int X1, int Y1, int h1, int w1, int bet1, sf::Font f){
        X = X1;
        Y = Y1;
        h = h1;
        w = w1;
        bet = bet1;
        up = RectButton(sf::Vector2f(w, h), sf::Vector2f(X + w + bet, Y));
        down = RectButton(sf::Vector2f(w, h), sf::Vector2f(X + w + bet, Y + (h + bet)));
        left = RectButton(sf::Vector2f(w, h), sf::Vector2f(X, Y + (h + bet)));
        right = RectButton(sf::Vector2f(w, h), sf::Vector2f(X + 2 * (w + bet), Y + (h + bet)));
    }
    void draw(){
        up.draw(mainwindow);
        down.draw(mainwindow);
        left.draw(mainwindow);
        right.draw(mainwindow);
    }
    char poll(){
        char c = 'X';
        sf::Event event;
        while (mainwindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainwindow.close();
            
            up.getButtonStatus(mainwindow, event);
            if (up.isPressed)
                c = 'U';

            down.getButtonStatus(mainwindow, event);
            if (down.isPressed)
                c = 'D';
            
            left.getButtonStatus(mainwindow, event);
            if (left.isPressed)
                c = 'L';

            right.getButtonStatus(mainwindow, event);
            if (right.isPressed)
                c = 'R';
        } 
        return c;
    }
};