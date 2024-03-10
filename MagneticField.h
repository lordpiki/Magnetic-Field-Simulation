#pragma once
#include "Particle.h"
#include "Arrow.h"
#include <vector>

class MagneticField
{
public:
    MagneticField(double xmin, double ymin, double xmax, double ymax, double step);

    void addParticle(const Particle& particle);
    void calculateField();
    void drawField() const;

private:
    double _xmin;
    double _ymin;
    double _xmax;
    double _ymax;
    double _step;

    std::vector<Particle> _particles;
    std::vector<Arrow> _fieldArrows;

    Position calculateFieldAtPoint(double x, double y) const;
};
