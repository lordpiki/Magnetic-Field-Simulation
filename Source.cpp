#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Particle.h"
#include "Line.h"
#include "Arrow.h"
#include <iostream>
#include "MagneticField.h"
#include "Wire.h"

using std::cout;
using std::endl;


#define M_PI 3.14159265358979323846
MagneticField field(-1, -1, 1, 1, 0.08);


double getRandomValue(double min, double max)
{
    double random = ((double)rand()) / (double)RAND_MAX;
    double diff = max - min;
    double r = random * diff;
    return  min + r;
}

double getRandomValue()
{
	return getRandomValue(-1, 1);
}

void drawCoordinateSystem(GLFWwindow* window)
{
    Arrow xArrow(Position(-1, 0), Position(1, 0), Color(255, 255, 255));
    Arrow yArrow(Position(0, -1), Position(0, 1), Color(255, 255, 255));

    xArrow.drawArrow();
    yArrow.drawArrow();
}

void windowSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(void) {

    srand(time(NULL));

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    const int windowWidth = 1440, windowHeight = 810;

    window = glfwCreateWindow(windowWidth, windowHeight, "Particle Simulation", NULL, NULL);

    if (!window) {  
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetWindowSizeCallback(window, windowSizeCallback);

    field.setTimeStep(0.07);


    Wire p1(Position(-0.3, -0.3), -5);
    Wire p2(Position(0.3, 0.3), 5);
    Wire p3(Position(-0.7, 0.7), 4);
    Wire p4(Position(0, 0), 9);


    field.addWire(p1);
    field.addWire(p2);
    field.addWire(p3);
    //field.addWire(p4);

    Particle p1p(Position(0.9, 0.5), Color(255, 255, 255));
    field.addParticle(p1p);
    Particle p2p(Position(-0.9, -0.5), Color(255, 0, 255));
    field.addParticle(p2p);
    Particle p3p(Position(0.0, 0.05), Color(0, 255, 255));
    field.addParticle(p3p);


    field.calculateField();


        
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
  
        field.drawField();
        field.updateField();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
