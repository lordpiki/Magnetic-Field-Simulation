#include "Line.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

Position Line::draw(double maxLen) const
{
    glLineWidth(1.0f);
    glColor3f(_color.getR(), _color.getG(), _color.getB()); // Set the color of the line

    // Calculate the length of the line
    double lineLength = sqrt(pow(_end.x - _start.x, 2) + pow(_end.y - _start.y, 2));

    // Check if the length is bigger than maxLen
    if (lineLength > maxLen)
    {
        // Calculate the ratio to scale the line
        double ratio = maxLen / lineLength;

        // Calculate the new end point based on the ratio
        double newX = _start.x + (_end.x - _start.x) * ratio;
        double newY = _start.y + (_end.y - _start.y) * ratio;

        // Draw line from _start to the new end point
        glBegin(GL_LINES);
        glVertex2f(_start.x, _start.y);
        glVertex2f(newX, newY);
        glEnd();
        return Position(newX, newY);
    }
    else
    {
        // Draw line from _start to _end
        glBegin(GL_LINES);
        glVertex2f(_start.x, _start.y);
        glVertex2f(_end.x, _end.y);
        glEnd();
        return _end;
    }
}
