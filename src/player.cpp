#include "../include/player.h"

Player::Player()
{
    init();
}

void Player::init(int xPos, int yPos, int width, int height)
{
    m_body.x = xPos;
    m_body.y = yPos;
    m_body.w = width;
    m_body.h = height;
}

void Player::moveLeft()
{
    m_body.x -= 50;
}

void Player::moveRight()
{
    m_body.x += 50;
}

void Player::moveDown()
{
    m_body.y += 50;
}

void Player::moveUp()
{
    m_body.y -= 50;
}

SDL_Rect& Player::getPlayer()
{
    return m_body;
}