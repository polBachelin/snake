/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** ObjectRectangle.cpp
*/

#include "ObjectRectangle.hpp"

using namespace raylib;

ObjectRectangle::ObjectRectangle(const MyVector2 origin, const MyVector2 size) : _origin(origin), _size(size)
{
}

ObjectRectangle::~ObjectRectangle()
{
}

void ObjectRectangle::setRectangle(const MyVector2 origin, const MyVector2 size)
{
    this->_origin = origin;
    this->_size = size;
}

MyVector2 ObjectRectangle::getRectangleOrigin() const
{
    return this->_origin;
}

MyVector2 ObjectRectangle::getRectangleSize() const
{
    return this->_size;
}

bool ObjectRectangle::checkCollisionWith(const ObjectCircle &circle)
{
    return Collision::checkCollision(circle, *this);
}

bool ObjectRectangle::checkCollisionWith(const ObjectRectangle &rectangle)
{
    return Collision::checkCollision(*this, rectangle);
}

bool ObjectRectangle::boxCollider([[maybe_unused]] const ObjectBox &box)
{
    throw std::bad_function_call();
    return false;
}