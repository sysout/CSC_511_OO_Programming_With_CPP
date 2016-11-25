#include "geometry.h"
#include <cmath>
#include <iostream>
using namespace std;


Point constructorPoints [4];

Point *updateConstructorPoints ( const Point &p1, const Point &p2 ,const Point &p3 , const Point & p4 = Point(0 ,0)) {
  constructorPoints [0] = p1;
  constructorPoints [1] = p2;
  constructorPoints [2] = p3;
  constructorPoints [3] = p4;
  return constructorPoints ;
}

Rectangle::Rectangle(const Point &lowerleft, const Point &upperright):
  Polygon(updateConstructorPoints(Point(lowerleft.getX(),upperright.getY()),
            lowerleft,
            Point(upperright.getX(),lowerleft.getY()),
            upperright),
          4){
}

Rectangle::Rectangle(const Point &p1, const Point &p2 ,const Point &p3 , const Point & p4):
  Polygon(updateConstructorPoints(p1,p2,p3,p4),4){
}

double Rectangle::area(){
  return (pa.get(0)->getY()-pa.get(1)->getY())*(pa.get(2)->getX()-pa.get(1)->getX());
}

Triangle::Triangle(const Point &p1, const Point &p2 ,const Point &p3):
  Polygon(updateConstructorPoints(p1,p2,p3),3){
}

double side_length(const Point* p1, const Point* p2){
  return sqrt(1.0*(pow(p1->getX()-p2->getX(), 2)+pow(p1->getY()-p2->getY(), 2)));
}

double Triangle::area(){
  double a = side_length(pa.get(0),pa.get(1));
  double b = side_length(pa.get(2),pa.get(1));
  double c = side_length(pa.get(0),pa.get(2));
  double s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

void printAttributes(Polygon *p){
  cout<<"Area: "<<p->area()<<endl;
  const PointArray * pa(p->getPoints());
  for (int i(0); i < p->getNumSides(); i++) {
    const Point * point = pa->get(i);
    cout<<"("<<point->getX()<<", "<<point->getY()<<") ";
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int a,b,c,d,e,f;
  cout<<"Please input the coordinates of lowerleft and the upperright of a rectangle:";
  cin >> a >> b >> c >> d;
  Rectangle r(Point(a,b),Point(c,d));
  printAttributes(&r);

  cout<<"Please input the three coordinates of the triangle:";
  cin >> a >> b >> c >> d >> e >> f;
  Triangle t(Point(a,b),Point(c,d),Point(e,f));
  printAttributes(&t);
  cout<<"Total Polygon: "<<Polygon::getNumPolygons()<<endl;
  return 0;
}
