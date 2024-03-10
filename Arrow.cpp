#include "Arrow.h"
#include <GLFW/glfw3.h>
#include <cstdlib>

#define M_PI 3.14159265358979323846

void Arrow::drawArrow(GLFWwindow* window, double maxLen) const
{
    Position newEnd = draw(maxLen);
    int windowWidth = 0, windowHeight = 0;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    const double arrowHeadSize = 0.02;

    // Calculate the coordinates of the arrow head
    double arrowHeadX = newEnd.x;
    double arrowHeadY = newEnd.y;

    // Calculate the direction of the arrow
    double arrowDirectionX = newEnd.x - _start.x;
    double arrowDirectionY = newEnd.y - _start.y;

    // Normalize the direction vector
    double length = sqrt(arrowDirectionX * arrowDirectionX + arrowDirectionY * arrowDirectionY);
    arrowDirectionX /= length;
    arrowDirectionY /= length;

    // Calculate the angle of the arrow direction
    double angle = atan2(arrowDirectionY, arrowDirectionX);

    // Calculate the coordinates of the arrow head aligned with the direction
    double alignedArrowHeadX = arrowHeadX - arrowHeadSize * cos(angle);
    double alignedArrowHeadY = arrowHeadY - arrowHeadSize * sin(angle);


    // Draw the arrow head
    glBegin(GL_TRIANGLES);
    glVertex2f(arrowHeadX, arrowHeadY);
    glVertex2f(alignedArrowHeadX - arrowHeadSize * cos(angle + M_PI / 4), alignedArrowHeadY - arrowHeadSize * sin(angle + M_PI / 4));
    glVertex2f(alignedArrowHeadX - arrowHeadSize * cos(angle - M_PI / 4), alignedArrowHeadY - arrowHeadSize * sin(angle - M_PI / 4));
    glEnd();
}