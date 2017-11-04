#include <iostream>
#include <SFML/Graphics.hpp>

class Player {
    private:
        sf::RectangleShape player;

    public:
        Player() {
            player.setSize({10, 10});
            player.setFillColor(sf::Color(0, 153, 76));
        }

        void draw(sf::RenderWindow &window) {
            window.draw(player);
        }

        void move(sf::Vector2f vec) {
            player.move(vec);
        }

        void setPos(sf::Vector2f pos) {
            player.setPosition(pos);
        }

        int getX() {
            return player.getPosition().x;
        }

        int getY() {
            return player.getPosition().y;
        }

};


int main() {

    sf::RenderWindow window(sf::VideoMode(400, 400), "Gravity");
    Player player;

    player.setPos({200, 390});

    const int groundHeight = 390;
    const float gravity = 12.81;
    bool jumping = false;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;

        sf::Time dt = clock.restart();

        const float speed = 12.0;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
                jumping = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move({-speed * dt.asSeconds(), 0});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move({speed * dt.asSeconds(), 0});
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move({0, -speed * dt.asSeconds()});
            jumping = true;
        }

        if (player.getY() < groundHeight && jumping == false) {
            player.move({0, gravity * dt.asSeconds()});
        }

        if (player.getX() < 0)
            player.setPos({390, 390});
        if (player.getX() > 400)
            player.setPos({0, 390});                       

        window.clear(sf::Color(43, 43, 43));
        player.draw(window);
        window.display();
    }
    return 0;
}