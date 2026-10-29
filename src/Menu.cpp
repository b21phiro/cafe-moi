#include "Menu.h"
#include "Cafemoi.h"
#include "Color.h"

Menu::Menu(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
    , m_backgroundColor(SkyBlue)
{
    auto& window = m_cafemoi.getWindow();
    auto& assets = cafemoi.getAssets();
    auto& texture = assets.getTexture("sprite-atlas");
    auto& font = assets.getFont("cafemoi-regular");

    m_playButtonRect.setSize({ 200.f, 48.f });
    m_playButtonRect.setTexture(&texture);
    m_playButtonRect.setTextureRect({{ 62 * 16 , 61 * 16},  { 16, 16 }});
    m_playButtonRect.setPosition({
        (static_cast<float>(window.getSize().x) - m_playButtonRect.getSize().x) / 2.f,
        (static_cast<float>(window.getSize().y) - m_playButtonRect.getSize().y) / 2.f
    });

    m_playButtonText = std::make_unique<sf::Text>(font, "PLAY");
    m_playButtonText->setCharacterSize(128);
    const sf::FloatRect playTextBounds = m_playButtonText->getLocalBounds();
    m_playButtonText->setOrigin(
        (playTextBounds.size + playTextBounds.position) / 2.f
    );
    m_playButtonText->setPosition(m_playButtonRect.getGlobalBounds().getCenter());
    m_playButtonText->move({ 0, -56.f });
    m_playButtonText->setFillColor(VeryDarkPurple);

    m_playButtonRectTopLeft.setSize({ 32, 32 });
    m_playButtonRectTopLeft.setTexture(&texture);
    m_playButtonRectTopLeft.setTextureRect({{ 986, 970 },  { 6, 6 }});
    m_playButtonRectTopLeft.setPosition({
        m_playButtonRect.getGlobalBounds().position.x - m_playButtonRectTopLeft.getLocalBounds().size.x,
        m_playButtonRect.getGlobalBounds().position.y - m_playButtonRectTopLeft.getLocalBounds().size.y
    });

    m_playButtonRectTopRight.setSize({ 32, 32 });
    m_playButtonRectTopRight.setTexture(&texture);
    m_playButtonRectTopRight.setTextureRect({{ 1008, 970 },  { 6, 6 }});
    m_playButtonRectTopRight.setPosition({
        (m_playButtonRect.getGlobalBounds().position.x + m_playButtonRect.getLocalBounds().size.x),
        m_playButtonRect.getGlobalBounds().position.y - m_playButtonRectTopRight.getLocalBounds().size.y
    });

    m_playButtonRectTop.setSize({ 200, 32 });
    m_playButtonRectTop.setTexture(&texture);
    m_playButtonRectTop.setTextureRect({{ 992, 970 },  { 16, 6 }});
    m_playButtonRectTop.setPosition({
        m_playButtonRect.getGlobalBounds().position.x,
        m_playButtonRect.getGlobalBounds().position.y - m_playButtonRectTop.getLocalBounds().size.y
    });

    m_playButtonRectLeft.setSize({ 32, 32 });
    m_playButtonRectLeft.setTexture(&texture);
    m_playButtonRectLeft.setTextureRect({{ 986, 976 },  { 6, 16 }});
    m_playButtonRectLeft.setPosition({
        m_playButtonRect.getGlobalBounds().position.x - 32,
        m_playButtonRect.getGlobalBounds().position.y
    });

    m_playButtonRectRight.setSize({ 32, 32 });
    m_playButtonRectRight.setTexture(&texture);
    m_playButtonRectRight.setTextureRect({{ 1008, 976 },  { 6, 16 }});
    m_playButtonRectRight.setPosition({
        m_playButtonRect.getGlobalBounds().position.x + m_playButtonRect.getLocalBounds().size.x,
        m_playButtonRect.getGlobalBounds().position.y
    });

    m_playButtonRectBottom.setSize({ 200, 32 });
    m_playButtonRectBottom.setTexture(&texture);
    m_playButtonRectBottom.setTextureRect({{ 992, 992 },  { 16, 8 }});
    m_playButtonRectBottom.setPosition({
        m_playButtonRect.getGlobalBounds().position.x,
        (m_playButtonRect.getGlobalBounds().position.y + m_playButtonRectBottom.getLocalBounds().size.y)
    });

    m_playButtonRectBottomLeft.setSize({ 32, 32 });
    m_playButtonRectBottomLeft.setTexture(&texture);
    m_playButtonRectBottomLeft.setTextureRect({{ 986, 992 },  { 6, 8 }});
    m_playButtonRectBottomLeft.setPosition({
        m_playButtonRect.getGlobalBounds().position.x - m_playButtonRectBottomLeft.getLocalBounds().size.x,
        (m_playButtonRect.getGlobalBounds().position.y + m_playButtonRectBottomLeft.getLocalBounds().size.y)
    });

    m_playButtonRectBottomRight.setSize({ 32, 32 });
    m_playButtonRectBottomRight.setTexture(&texture);
    m_playButtonRectBottomRight.setTextureRect({{ 1008, 992 },  { 6, 8 }});
    m_playButtonRectBottomRight.setPosition({
        m_playButtonRect.getGlobalBounds().position.x + m_playButtonRect.getLocalBounds().size.x,
        (m_playButtonRect.getGlobalBounds().position.y + m_playButtonRectBottomRight.getLocalBounds().size.y)
    });

}


void Menu::update()
{

}

void Menu::draw()
{
    auto& window = m_cafemoi.getWindow();
    window.clear(m_backgroundColor);
    drawPlayButton();
    window.display();
}

void Menu::initPlayButton()
{
}

void Menu::drawPlayButton()
{
    auto& window = m_cafemoi.getWindow();
    window.draw(m_playButtonRect);
    window.draw(m_playButtonRectTopLeft);
    window.draw(m_playButtonRectTopRight);
    window.draw(m_playButtonRectTop);
    window.draw(m_playButtonRectBottom);
    window.draw(m_playButtonRectBottomLeft);
    window.draw(m_playButtonRectBottomRight);
    window.draw(m_playButtonRectLeft);
    window.draw(m_playButtonRectRight);
    window.draw(*m_playButtonText);
}
