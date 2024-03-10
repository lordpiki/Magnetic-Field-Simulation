#include <GLFW/glfw3.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Particle.h"
#include "Line.h"
#include "Arrow.h"
#include <iostream>
#include "MagneticField.h"

using std::cout;
using std::endl;


#define M_PI 3.14159265358979323846

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

int main(void) {

    srand(time(NULL));

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    int windowWidth = 1000, windowHeight = 750;

    window = glfwCreateWindow(windowWidth, windowHeight, "Particle Simulation", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    MagneticField field(-1, -1, 1, 1, 0.1);

    Particle p1(Position(-0.5, -0.5), Color(255, 255, 255));
    p1.setCharge(-1);
    Particle p2(Position(0.5, 0.5), Color(255, 255, 255));
    p2.setCharge(1);
    Particle p3(Position(-0.5, 0.5), Color(255, 255, 255));
    p3.setCharge(0.1);
    Particle p4(Position(0, 0), Color(255, 255, 255));
    p4.setCharge(-0.5);


    field.addParticle(p1);
    field.addParticle(p2);
    field.addParticle(p3);
    field.addParticle(p4);

    field.calculateField();


        
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        //drawCoordinateSystem(window);
          
        field.drawField();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
