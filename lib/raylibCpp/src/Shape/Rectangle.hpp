/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../../include/object.hpp"

#include "IShape.hpp"

namespace raylib
{
    class Rectangle : public IShape {
      public:
        Rectangle(const MyVector2 position, const MyVector2 size, const RColor color = RColor::RWHITE, int i = -1);
        ~Rectangle() = default;

        void draw();

        void setPosition(const MyVector2 position);
        MyVector2 getPosition() const;
        void setSize(const MyVector2 size);
        MyVector2 getSize() const;
        void setColor(const RColor color);

      private:
        MyVector2 _position;
        MyVector2 _size;
        RColor _color;
    };
}; // namespace raylib

#endif // RECTANGLE_HPP