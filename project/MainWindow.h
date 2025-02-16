#pragma once
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace std;

sf::RenderWindow mainwindow(sf::VideoMode({2000, 1500}), "game");
void drawline(sf::Vector2f a, sf:: Vector2f b){
    sf::Vertex line[] = {a, b};
    mainwindow.draw(line, 2, sf::Lines);
}