#include <bits/stdc++.h>
using namespace std;

class coordinates_198
{
    double x_198;
    double y_198;
    double dis_198;

public:
    void getData_198(double a_198, double b_198)
    {
        x_198 = a_198;
        y_198 = b_198;
    }
    double dist_198(coordinates_198 p1_198)
    {
        double diS_198 = sqrt(((x_198 - p1_198.x_198) * (x_198 - p1_198.x_198)) + ((y_198 - p1_198.y_198) * (y_198 - p1_198.y_198)));
        return diS_198;
    }
};
int main()
{
    double x1_198, y1_198;
    double x2_198, y2_198;

    cout << "Enter the coordinates of two points" << endl;

    cin >> x1_198 >> y1_198 >> x2_198 >> y2_198;

    coordinates_198 p1_198, p2_198;
    p1_198.getData_198(x1_198, y1_198);
    p2_198.getData_198(x2_198, y2_198);

    double distance_198 = p1_198.dist_198(p2_198);

    cout<<"Distance between two points is :- "<<distance_198;

    return 0;
}