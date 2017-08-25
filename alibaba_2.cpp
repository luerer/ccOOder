#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point
{
    int value;
    int num;
    double ratio;
};

void input(vector<Point>* points);

double calculateExpectation(const vector<Point>& points, const int total, const int min);

int main()
{
    int total = 0;
    cin >> total;
    int min = 0;
    cin >> min;

    vector<Point> points;
    input(&points);

    double res = calculateExpectation(points, total, min);
    cout << setiosflags(ios::fixed) << setprecision(6) << res << endl;                                                                                                                                                                                          
    return 0;
}

void input(vector<Point>* points)
{
    int n = 0;
    cin >> n;
    points->resize(n);

    double sum = 0;
    for (int i = 0; i < n; ++i)
    {   
        Point& point = (*points)[i];
        cin >> point.value;
        cin >> point.num;
        sum += point.num;
    }

    for (int i = 0; i < n; ++i)
    {   
        Point& point = (*points)[i];
        point.ratio = point.num / sum;
    }
}

bool camp(Point& a, Point& b){
    return a.value<b.value;
}
double C(int m, int n){
    n = (n>m/2)?(m-n):n;
    int a = 1, b = 1;
    double res = 1.0;
    for (int i = 0; i < n; i++) {
        res *= (double) (m-i)/ (double) (i+1);
    }
 return res;
}
double calculateExpectation(const vector<Point>& points, const int total, const int min)
{
    sort(points.begin(), points.end(),camp);
    double prev = 0;
    double e = 0;
    double accRatio = 0;

    for (int i = 0; i < total; i++) {
    double p = 0;
    double cur = points[i].ratio;
    accRatio += cur;
    for (int j = min; j <= total; j++) {
        double c = C(total, j);
        p += c * pow(accRatio, j) * pow(1.0 - accRatio, total - j);
    }
    e += (p - prev) * points[i].value;
    prev = p;
    }

    return e;
}
