#include "MagneticField.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

#define M_PI 3.14159265358979323846

MagneticField::MagneticField(double xmin, double ymin, double xmax, double ymax, double step)
    : _xmin(xmin), _ymin(ymin), _xmax(xmax), _ymax(ymax), _step(step) {}

void MagneticField::addParticle(const Particle& particle)
{
    _particles.push_back(particle);
}

Position MagneticField::calculateFieldAtPoint(double x, double y) const
{
    Position field(0, 0);

    for (Particle particle : _particles)
    {
        double dx = x - particle.getPosition().getX();
        double dy = y - particle.getPosition().getY();
        double distanceSquared = dx * dx + dy * dy;

        double factor = particle.getCharge() / (4 * M_PI * distanceSquared);
        double direction = atan2(dy, dx);

        double fieldX = factor * cos(direction);
        double fieldY = factor * sin(direction);

        field.setX(field.getX() + fieldX);
        field.setY(field.getY() + fieldY);

    }

    return field;
}

void MagneticField::calculateField()
{
    _fieldArrows.clear();


    for (double x = _xmin; x <= _xmax; x += _step)
    {
        for (double y = _ymin; y <= _ymax; y += _step)
        {
            Position field = calculateFieldAtPoint(x, y);
            Position endPoint(x + field.getX(), y + field.getY());

            double distance = sqrt(field.getX() * field.getX() + field.getY() * field.getY());
            double normalizedDistance = distance / 0.5; // Normalize the distance to the range [0, 1]

            // Calculate the color based on the normalized distance
            int blue = static_cast<int>(255 * (1 - normalizedDistance));
            int red = static_cast<int>(255 * normalizedDistance);

            Arrow arrow(Position(x, y), endPoint, Color(red, 0, blue), 0.02f);

            _fieldArrows.push_back(arrow);
        }
    }
}

void MagneticField::drawField(GLFWwindow* window) const
{
    for (const Arrow& arrow : _fieldArrows)
    {
        arrow.drawArrow(window, 0.9 * _step);

    }
}
