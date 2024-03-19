#pragma once
#include "Particle.h"

class Wire : public Particle
{
public:
	Wire(const Position& position, double current) : Particle(position, Color(255, 255, 255)), _current(current) {};
	void draw() const;
	double getcurrent() { return _current; }
	void setCurrent(double current) { _current = current; }

private:
	double _current;

	void drawX() const;
	void drawO() const;


};

