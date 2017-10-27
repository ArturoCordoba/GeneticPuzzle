//
// Created by fabian on 21/10/17.
//

#ifndef GENETICPUZZLE_PIECE_H
#define GENETICPUZZLE_PIECE_H

#include <SFML/Graphics.hpp>
#include <iostream>

///Class of Piece
class Piece
{
public:

    sf::Sprite piece;
    float bottom,left,right,top;

    ///Constructor method of Piece class
    Piece(sf::Vector2f position, sf::Texture &texture, sf::Vector2f rect, sf::Vector2f posRect)
    {
        piece.setTexture(texture);
        piece.setPosition(position);
        piece.setTextureRect(sf::IntRect(posRect.y,posRect.x,rect.x,rect.y));
    }

    ///Method that updates the position of the object on screen
    void Update()
    {
        bottom = piece.getPosition().y + piece.getTextureRect().height;
        left = piece.getPosition().x;
        right = piece.getPosition().x + piece.getTextureRect().width;
        top = piece.getPosition().y;
    }
};

#endif //GENETICPUZZLE_PIECE_H
