#include<iostream>
using namespace std;
struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
Point operator + (const Point &A, const Point &B)
{
    return Point(A.x + B.x, A.y + B.y);
}
int main()
{
    Point a,b(1,2);
    a.x = 3;
    a = a + b;
    cout<<a.x<<' '<<a.y<<endl;
    return 0;
}
