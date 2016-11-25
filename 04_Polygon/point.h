#ifndef POINT_H
#define POINT_H

class Point{
public:
  int x;
  int y;
  Point(int x=0,int y=0):x(x),y(y){}
  int getX() const {return x;};
  int getY() const {return y;};
  void setX(const int new_x) {x=new_x;};
  void setY(const int new_y) {x=new_y;};
};

#endif
