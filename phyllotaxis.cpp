#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){

    int width = 800;
    int height = 800;
    int n = 0;
    int c = 6;
    float r;
    float a;
    float x;
    float y;

    vector<sf::CircleShape> vec;


    sf::RenderWindow window(sf::VideoMode(width, height), "Phyllotaxis", sf::Style::Default, sf::ContextSettings(24, 8, 4));
    sf::CircleShape shape(6.0f);
    sf::RectangleShape background(sf::Vector2f(800.0f, 800.0f));
    background.setFillColor(sf::Color(51, 51, 51));

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);

        a = n * 137.5;
        r = c * sqrt(n);
        x = r * cos(a) + width/2;
        y = r * sin(a) + height/2;

        shape.setPosition(sf::Vector2f(x, y));
        shape.setFillColor(sf::Color(((rand() % 15) + 235), ((rand() % 15) + 215), ((rand() % 15) + 87), 150));
        vec.push_back(shape);
        n++;

        for (unsigned int i = 0 ; i < vec.size(); i++){
            window.draw(vec[i]);
        }

        window.display();

    }

    return 0;
}
