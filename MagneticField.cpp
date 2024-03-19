#include "MagneticField.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

#define M_PI 3.14159265358979323846
#define M0 4 * M_PI * 1e-7


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
        // Calculate the distance between the particle and the given point
        double dx = x - particle.getPosition().x;
        double dy = y - particle.getPosition().y;
        double distance = sqrt(dx * dx + dy * dy);

        // Calculate the magnetic field at the given point
        double B = M0 * particle.getcurrent() / (2 * M_PI * distance);

        // Calculate the angle between the particle and the given point
        double angle = atan2(dy, dx);

        // Rotate the angle by 90 degrees
        angle += M_PI / 2;

        // Calculate the magnetic field angle
        double fieldAngle = 0;

        // Calculate the magnetic field components
        double fieldX = B * cos(angle);
        double fieldY = B * sin(angle);

        field.x += fieldX;
        field.y += fieldY;
    }

    field.x = field.x * 1e5;
    field.y = field.y * 1e5;

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
            double normalizedDistance = distance / 0.5;

            // Calculate the color based on the normalized distance
            int blue = static_cast<int>(255 * (1 - normalizedDistance));
            int red = static_cast<int>(255 * normalizedDistance);



            Arrow arrow(Position(x, y), endPoint, Color(red, 0, blue), normalizedDistance);

            _fieldArrows.push_back(arrow);
        }
    }
}

void MagneticField::drawField() const
{
    for (const Arrow& arrow : _fieldArrows)
    {
        arrow.drawArrow(0.9 * _step);
    }

    for (const Particle& particle : _particles)
    {
		particle.draw();
	}
}
