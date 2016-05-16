#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button : public sf::Drawable, public sf::Transformable
{
    public:
        Button();
        void setCallback(const std::function<void(void)>& func);
        void run(){onClick();}
        bool check(sf::Vector2f ray); //Checks wether the button should be enabled, and do it if required


    private:
        std::function<void(void)> onClick;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::RectangleShape rect;


};

#endif // BUTTON_H
