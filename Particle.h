#pragma once
#include "Color.h"

class Position
{
public:
    Position(double x, double y) : x(x), y(y) {};
    Position() : x(0), y(0) {};
    ~Position() {};

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double xToSet) { x = wrapAround(xToSet); }
    void setY(double yToSet) { y = wrapAround(yToSet); }

    void move(double x, double  y) { setX(x); setY(y); };

    double x;
    double y;
private:
    double wrapAround(double value) const
    {
        if (value > 1)
            return value - 2;
        else if (value < -1)
            return value + 2;
        else
            return value;
    }
};

class Particle
{
public:
	Particle(const Position& position, const Color& color) : _position(position), _color(color), _radius(0.02f), _mass(0), _vx(0), _vy(0) {};
	Particle(const Position& position, const Color& color, double radius, double vx, double vy, double mass) : _position(position), _color(color), _radius(radius), _mass(mass), _vx(vx), _vy(vy) {};
	Particle(const Position& position, const Color& color, double radius, double mass) : _position(position), _color(color), _radius(radius), _mass(mass), _vx(0), _vy(0) {};
	Particle() : _position(Position()), _color(Color()), _radius(0.02f), _mass(0), _vx(0), _vy(0) {};
	~Particle() {};

	Position& getPosition() { return _position; }
	Color& getColor() { return _color; }
	double& getRadius() { return _radius; }
	double& getMass() { return _mass; }
	double& getVx() { return _vx; }
	double& getVy() { return _vy; }

	void setPosition(const Position& position) { _position = position; }
	void setColor(const Color& color) { _color = color; }
	void setRadius(double radius) { _radius = radius; }
	void setMass(double mass) { _mass = mass; }
	void setVx(double vx) { _vx = vx; }
	void setVy(double vy) { _vy = vy; }

	void move(double x, double y) { _position.move(x, y); }

	void draw() const;

protected:
	double _radius;
	Position _position;
	Color _color;
	double _mass;
	double _vx;
	double _vy;


};