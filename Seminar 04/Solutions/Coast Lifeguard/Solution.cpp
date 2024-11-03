
#define e 0.00001

double xGuard, xDrowner, yGuard, yDrowner, vSand, vWater;

// SQRT((x1-xTARGET)^2 + (y1-0)^2) / vSand = TimeOnSand
// SQRT((x2-xTARGET)^2 + (y2-0)^2) / vWater = TimeInWater
double ans(double xCrossing)
{
    return (sqrt((xGuard-xCrossing)*(xGuard-xCrossing)+yGuard*yGuard)/vSand +
            sqrt((xDrowner-xCrossing)*(xDrowner-xCrossing)+yDrowner*yDrowner)/vWater);
}

double ternary(double left, double right)
{
    if(abs(left - right) < e)
    {
        return left;
    }

    double mid1 = left + (right - left) / 3;
    double mid2 = left + 2 * (right - left) / 3;

    if(ans(mid1) < ans(mid2))
    {
        return ternary(left, mid2);
    }
    else
    {
        return ternary(mid1, right);
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; ++i)
    {
        cin >> xGuard >> yGuard >> xDrowner >> yDrowner >> vSand >> vWater;

        if(xGuard > xDrowner)
        {
            swap(xGuard, xDrowner);
        }
        
        cout << fixed << setprecision(5) << ans(ternary(xGuard, xDrowner)) << endl;
    }
}