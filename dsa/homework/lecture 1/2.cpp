#include <iostream>
using namespace std;

struct line {
	double x;
	double y;
};

int main() {
	line a,b,c,d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;

	double cp_ab_x = a.x - b.x;
	double cp_ab_y = a.y - b.y;
	double cp_cd_x = c.x - d.x;
	double cp_cd_y = c.y - d.y;

	double pt_ab_x = cp_ab_y;
	double pt_ab_y = -cp_ab_x;
	double pt_cd_x = cp_cd_y;
	double pt_cd_y = -cp_cd_x;


	double c_ab = -(pt_ab_x*b.x + pt_ab_y*b.y);
	double c_cd = -(pt_cd_x*c.x + pt_cd_y*c.y);	


	double t = pt_ab_x;
	pt_ab_x *= pt_cd_x;
	pt_ab_y *= pt_cd_x;
	c_ab *= pt_cd_x;

	pt_cd_x *= t;
	pt_cd_y *= t;
	c_cd *= t;

	if(pt_ab_x == pt_cd_x && pt_ab_y == pt_cd_y && c_ab != c_cd) {
		cout << "NO";
	}
	else if(pt_ab_x == pt_cd_x && pt_ab_y == pt_cd_y && c_ab == c_cd) {
		cout << "MANY";
	}
	else {
		// (b1-b2)y + (c1-c2) = 0
		double y = -(double)(c_cd-c_ab)/(double)(pt_cd_y-pt_ab_y);
		double x = -c_ab - pt_ab_y*y;
		x /= pt_ab_x;

		cout << x << ' ' << y;
	}
}