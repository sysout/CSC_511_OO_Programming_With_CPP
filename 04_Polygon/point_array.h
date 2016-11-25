#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "point.h"
#include <cstddef>

class PointArray{
  Point* p;
  int size;
  int n;
public:
  PointArray():size(0),n(0),p(NULL){};
  PointArray(const Point points[], const int size);
  PointArray(const PointArray& pv);
  void resize(int n);
  void push_back(const Point &p);
  void insert(const int position, const Point &p);
  void remove(const int pos);
  const int getSize() const;
  void clear();
  Point *get(const int position);
  const Point *get(const int position) const;
  ~PointArray();
};

#endif
