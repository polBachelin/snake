/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Input.cpp
*/

#include "Input.hpp"

using namespace raylib;

Input::Input() : _previousMousePos(getMousePos())
{
}

bool Input::isKeyPressed(KeyBoard key) const
{
    auto keyLine = this->_keyList.find(key);

    if (keyLine == this->_keyList.end())
        throw std::invalid_argument("isKeyPressed: key not found.");
    return IsKeyPressed(keyLine->second);
}

bool Input::isKeyReleased(KeyBoard key) const
{
    auto keyLine = this->_keyList.find(key);

    if (keyLine == this->_keyList.end())
        throw std::invalid_argument("isKeyPressed: key not found.");
    return IsKeyReleased(keyLine->second);
}

MyVector2 Input::getMousePos() const
{
    Vector2 pos = GetMousePosition();

    return MyVector2(pos.x, pos.y);
}

bool Input::isMouseLeftPressed() const
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool Input::isMouseRightPressed() const
{
    return IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);
}

bool Input::isMouseMiddlePressed() const
{
    return IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE);
}

bool Input::isMouseMoved()
{
    MyVector2 mouse_pos = this->getMousePos();
    MyVector2 previous_mouse_pos = this->_previousMousePos;
    this->_previousMousePos = mouse_pos;

    return !(mouse_pos == previous_mouse_pos);
}

float Input::getMouseWheel() const
{
    return GetMouseWheelMove();
}

bool Input::MouseIsOver(MyVector2 pos, MyVector2 size) const
{
    MyVector2 mouse_pos = this->getMousePos();

    if (mouse_pos.a >= pos.a && mouse_pos.b >= pos.b) {
        if (mouse_pos.a <= pos.a + size.a && mouse_pos.b <= pos.b + size.b) {
            return true;
        }
    }
    return false;
}

bool Input::MouseIsOverClicked(MyVector2 pos, MyVector2 size) const
{
    bool isOver = this->MouseIsOver(pos, size);
    bool isPressed = this->isMouseLeftPressed();

    return isOver && isPressed;
}

bool Input::MouseIsOverRightClicked(MyVector2 pos, MyVector2 size) const
{
    bool isOver = this->MouseIsOver(pos, size);
    bool isPressed = this->isMouseRightPressed();

    return isOver && isPressed;
}