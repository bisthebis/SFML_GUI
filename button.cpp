#include "button.h"


Button::Button() : rect(sf::Vector2f(80, 30))
{

}

void Button::setCallback(const std::function<void(void)>& func)
{
    this->onClick = func;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect, sf::RenderStates(getTransform()));
}

bool Button::check(sf::Vector2f ray)
{
    if(ray.x > getPosition().x && ray.x < (getPosition().x + rect.getSize().x) && ray.y > getPosition().y && ray.y < (getPosition().y + rect.getSize().y))
    {
        onClick();
        return true;
    }

    return false;

}
