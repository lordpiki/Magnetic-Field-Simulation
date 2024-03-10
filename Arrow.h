#pragma once
#include "Line.h"
#include <GLFW/glfw3.h>
#include <cstdlib>


class Arrow: public Line
{
public:
	Arrow(const Position& start, const Position& end, const Color& color, double width) : Line(start, end, color, width), _scale(1) {};
	Arrow(const Position& start, const Position& end, const Color& color) : Line(start, end, color), _scale(1) {};
	Arrow(const Position& start, const Position& end) : Line(start, end, Color()), _scale(1) {};
	Arrow() : Line(), _scale(1) {};
	
	void drawArrow(double maxLen = 100.0f) const;
	
private:
	double _scale;

};

