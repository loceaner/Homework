#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-8;
double ax, ay, bx, by, cx, cy, dx, dy, p, q, r;

double dis(double x1, double y1, double x2, double y2) {
	double xdis = x1 - x2, ydis = y1 - y2;
	return sqrt(xdis * xdis + ydis * ydis);
}

double f(double x1, double y1, double x2, double y2) {
	return dis(x1, y1, x2, y2)/r + dis(x2, y2, dx, dy)/q;
}

double calc1(double x, double y) {
	double lx = cx, ly = cy, rx = dx, ry = dy;
	while(dis(lx, ly, rx, ry) > eps) {
		double kl = (rx - lx) / 3.0, ky = (ry - ly) / 3.0;
		double lmidx = lx + kl, rmidx = rx - kl, lmidy = ly + ky, rmidy = ry - ky;
		double ans1 = f(x, y, lmidx, lmidy), ans2 = f(x, y, rmidx, rmidy);
		if(ans2 - ans1 > eps) rx = rmidx, ry = rmidy;
		else lx = lmidx, ly = lmidy;
	}
	return f(x, y, lx, ly);
}

double calc() {
	double lx = ax, ly = ay, rx = bx, ry = by;
	while(dis(lx, ly, rx, ry) > eps) {
		double kl = (rx - lx) / 3.0, ky = (ry - ly) / 3.0;
		double lmidx = lx + kl, rmidx = rx - kl, lmidy = ly + ky, rmidy = ry - ky;
		double ans1 = calc1(lmidx, lmidy) + dis(ax, ay, lmidx, lmidy)/p, ans2 = calc1(rmidx, rmidy) + dis(ax, ay, rmidx, rmidy)/p;
		if(ans2 - ans1 > eps) rx = rmidx, ry = rmidy;
		else lx = lmidx, ly = lmidy;
	}
	return calc1(lx, ly) + dis(ax, ay, lx, ly)/p;
}

int main() {
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, & bx, &by, &cx, &cy, &dx, &dy);
	scanf("%lf%lf%lf", &p, &q, &r);
	printf("%.2lf", calc());
}
