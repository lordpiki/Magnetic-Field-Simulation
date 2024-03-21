#pragma once
#include "Particle.h"
#include "Arrow.h"
#include <vector>
#include "Wire.h"

class MagneticField
{
public:
    MagneticField(double xmin, double ymin, double xmax, double ymax, double step);

    void addParticle(const Particle& particle);
    void addWire(const Wire& wire);

    void setTimeStep(double timeStep) { _timeStep = timeStep; }

    std::vector <Particle>& getParticles() { return _particles; }
    std::vector <Wire>& getWires() { return _wires; }

    void calculateField();
    void drawField() const;
    void updateField();
    void setWindowDimentions(int width, int height) { _windowWidth = width; _windowHeight = height; }
    void setGeneralDimentions(double xmin, double ymin, double xmax, double ymax) { _xmin = xmin; _ymin = ymin; _xmax = xmax; _ymax = ymax; }

private:
    double _xmin;
    double _ymin;
    double _xmax;
    double _ymax;
    double _step;

    double _timeStep;

    int _windowWidth;
    int _windowHeight;

    std::vector<Particle> _particles;
    std::vector<Wire> _wires;
    std::vector<Arrow> _fieldArrows;

    Position calculateFieldAtPoint(double x, double y) const;
};
