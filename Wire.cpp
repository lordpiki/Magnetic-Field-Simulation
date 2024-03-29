#include "Wire.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1125

#define M_PI 3.14159265358979323846


void Wire::draw() const
{
    glPointSize(_radius);
    //glBegin(GL_TRIANGLE_FAN);
    glColor3f(_color.getR(), _color.getG(), _color.getB());

    // Center of the circle
    glVertex2f(_position.getX(), _position.getY());

    // Number of segments in the circle (adjust for smoothness)
    const int numSegments = 30;

    double aspectRatio = static_cast<double>(WINDOW_WIDTH) / static_cast<double>(WINDOW_HEIGHT);

    glBegin(GL_LINES);
    for (int i = 0; i <= numSegments; ++i) {
        double theta = (2.0f * M_PI * static_cast<double>(i)) / static_cast<double>(numSegments);
        double dx = _radius * std::cos(theta);
        double dy = _radius * std::sin(theta) * aspectRatio;  // Adjust for aspect ratio
        glVertex2f(_position.getX() + dx, _position.getY() + dy);
    }
    glEnd();

	if (_current <= 0)
	{
		drawX();
	}
	else
	{
		drawO();
	}
}

void Wire::drawX() const
{
    glLineWidth(2.0f);
    glColor3f(_color.getR(), _color.getG(), _color.getB());

    // Top-left to bottom-right line

    double length = 0.5 * _radius;

    glBegin(GL_LINES);
    glVertex2f(_position.getX() - length, _position.getY() - length);
    glVertex2f(_position.getX() + length, _position.getY() + length);
    glEnd();

    // Bottom-left to top-right line
    glBegin(GL_LINES);
    glVertex2f(_position.getX() - length, _position.getY() + length);
    glVertex2f(_position.getX() + length, _position.getY() - length);
    glEnd();
}

void Wire::drawO() const
{
    glPointSize(_radius);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(_color.getR(), _color.getG(), _color.getB());

    // Center of the circle
    glVertex2f(_position.getX(), _position.getY());

    // Number of segments in the circle (adjust for smoothness)
    const int numSegments = 30;

    double aspectRatio = static_cast<double>(WINDOW_WIDTH) / static_cast<double>(WINDOW_HEIGHT);

    for (int i = 0; i <= numSegments; ++i) {
        double theta = (2.0f * M_PI * static_cast<double>(i)) / static_cast<double>(numSegments);
        double dx = _radius * 0.5 * std::cos(theta);
        double dy = _radius * 0.5 * std::sin(theta) * aspectRatio;  // Adjust for aspect ratio
        glVertex2f(_position.getX() + dx, _position.getY() + dy);
    }
    glEnd();
}
