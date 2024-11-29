#include "TestLinear.h"

int main()
{
    //using Point = Point1D<double>;
    //using Point = Point2D<double>;
    using Point = Point3D<double>;

    
    //TestLinear<Point>::searchKNN_Vizualization(10, 1);

    TestLinear<Point>::searchKNN_Speed(5000,50);

    //TestLinear<Point>::searchNNInZone_Vizualization(100, 20.0);

    //TestLinear<Point>::searchNNInZone_Speed(100, 20.0);

    return 0;
}