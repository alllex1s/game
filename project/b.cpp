#include <SFML/Graphics.hpp>
#include "button/src/RectButton.cpp"
#include "player.h"

int main()
{
    RectButton button(sf::Vector2f(150.f, 50.f), sf::Vector2f(325.f, 275.f));
    button.setButtonLabel(26.f, "ZHOPA");
    sf::Font f;
    f.loadFromFile("font.ttf");
    button.setButtonFont(f);
    player p;
    int x = 0, y = 0;
    int r = 50;
    p.init(x, y, r);
    p.setColor(sf::Color::Red);
    cell c;
    c.init(x, y, r, r);
    while (mainwindow.isOpen())
    {
        sf::Event event;
        while (mainwindow.pollEvent(event))
        {
            button.getButtonStatus(mainwindow, event);

            if (event.type == sf::Event::Closed)
                mainwindow.close();
            
            if (button.isPressed){
                x += 50;
                y += 50;
                p.go(x, y);
                c.pick();
                cout << c.isWall() << endl;
                std::cout << "Button was pressed!" << std::endl;
            }
                
        }
        mainwindow.clear();

        button.draw(mainwindow);
        p.draw();
        c.draw();
        mainwindow.display();
    }

    return 0;
}