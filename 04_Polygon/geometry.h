#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cstddef>
#include "point.h"
#include "point_array.h"

using namespace std;

class Polygon{
protected:
  PointArray pa;
  static int total;
public:
  Polygon(const Point * point_array, const int len):pa(point_array, len){total++;};
  Polygon(const PointArray& pv):pa(pv){total++;};
  virtual double area()=0;
  ~Polygon(){total--;};
  static int getNumPolygons(){return total;};
  virtual int getNumSides(){return pa.getSize();};
  const PointArray * getPoints(){return &pa;};
};

int Polygon::total=0;

class Rectangle: public Polygon{
public:
  Rectangle(const Point &lowerleft, const Point &upperright);
  Rectangle(const Point &p1, const Point &p2 ,const Point &p3 , const Point & p4);
  virtual double area();
};

class Triangle: public Polygon{
public:
  Triangle(const Point &p1, const Point &p2 ,const Point &p3);
  virtual double area();
};

#endif
