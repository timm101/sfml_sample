#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    // 1
    sf::RectangleShape shape1(sf::Vector2f(200, 100));
    shape1.setFillColor(sf::Color::Cyan);
    shape1.setOrigin(100, 50);
    int shape1_y = 50;
    shape1.setPosition(150, shape1_y);

    // 2
    sf::RectangleShape shape2(sf::Vector2f(100, 300));
    shape2.setFillColor(sf::Color::Yellow);
    shape2.setOrigin(50, 150);
    int shape2_y = 150;
    shape2.setPosition(450, shape2_y);

    // 3
    sf::RectangleShape shape3(sf::Vector2f(250, 50));
    shape3.setFillColor(sf::Color::Magenta);
    shape3.setOrigin(125, 25);
    int shape3_y = 25;
    shape3.setPosition(825, shape3_y);

    int a = 1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //1
        shape1_y++;
        if (shape1_y > 550)
            shape1_y = 550;
        shape1.setPosition(150, shape1_y);

        //2
        if (a % 4 == 0)
        {
            shape2_y++;
            if (shape2_y > 450)
                shape2_y = 450;
            shape2.setPosition(450, shape2_y);
        }

        // 3
        if (a % 2 == 0)
        {
            shape3_y++;
            if (shape3_y > 575)
                shape3_y = 575;
            shape3.setPosition(825, shape3_y);
        }

        window.clear();
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();

        a++;

        std::this_thread::sleep_for(1ms);
    }

    return 0;
}