#include <iostream>
#include <vector>
using namespace std;

int N;
double answer;
struct point{
    double x,y;
};
vector<point> points;

void init() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        point temp;
        cin >> temp.x >> temp.y;
        points.push_back(temp);
    }
}

double exProduct(const point& a, const point& b, const point& c) {
    return double(((a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y))/2);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    for(int i = 1; i < N-1; ++i) {
        answer += exProduct(points[0], points[i], points[i+1]);
    }
    printf("%.1f", abs(answer));

    return 0;
}