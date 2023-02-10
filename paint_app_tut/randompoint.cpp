/*#include "randompoint.h"

randomPoint::randomPoint(int x1, int y1)
{
    srand(time(NULL));
    radius = 30;
    x = x1;
    y = y1;
}

double randomPoint::uniform()
{
    return (double)rand() / RAND_MAX;
}

vector<int> randomPoint::rPoint() {
    double theta =  2 * 3.14159265358979323846264 * uniform();
    double r = sqrt(uniform());
    int ranX = x + r * radius * cos(theta);
    int ranY = y + r * radius * sin(theta);
    return vector<int>{ranX,ranY};
}
*/
