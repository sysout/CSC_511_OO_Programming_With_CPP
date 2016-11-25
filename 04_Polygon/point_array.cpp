#include "point_array.h"
#include <algorithm>
using namespace std;

PointArray::PointArray(const Point points[], const int size):size(size),n(size){
  if(size<=0){
    PointArray();
    return;
  }
  p = new Point[size];
  for(int i=0; i<size; i++){
    p[i]=points[i];
  }
}

PointArray::PointArray(const PointArray& pv):size(pv.size),n(pv.n){
  if(pv.n==0){
    PointArray();
    return;
  }
  p = new Point[n];
  for(int i=0; i<size; i++){
    p[i]=pv.p[i];
  }
}

void PointArray::resize(int n){
  if(n<=size){
    size=n;
    return;
  }
  if(n<=this->n){
    return;
  }
  Point * new_p = new Point[n];
  int new_size = min(n, size);
  for(int i=0; i<new_size; i++){
    new_p[i]=p[i];
  }
  if(p!=NULL){
    delete[] p;
  }
  p=new_p;
  size=new_size;
  this->n=n;
}

// Add a Point to the end of the array
void PointArray::push_back(const Point &p){
  if(n<=size){
    this->resize(n*2+1);
  }
  this->p[size++]=p;
}

// Insert a Point at some arbitrary position (subscript) of the array, shifting the elements past position to the right
void PointArray::insert(const int position, const Point &p){
  if( position<0 || position>=size ){
    return;
  }
  if(n<=size){
    this->resize(n*2+1);
  }
  for (int i = size; i > position; i--) {
    this->p[i]=this->p[i-1];
  }
  this->p[position]=p;
  size++;
}

// Remove the Point at some arbitrary position (subscript) of the array, shifting the remaining elements to the left
void PointArray::remove(const int pos){
  if(pos>=0&&pos<size){
    for (int i(pos+1); i < size; i++) {
      p[i-1]=p[i];
    }
    size--;
  }
}

// Get the size of the Point array
const int PointArray::getSize() const{
  return size;
}

// Remove everything from the array and sets its size to 0
void PointArray::clear(){
  size=0;
}

// Get a pointer to the element at some arbitrary position in the array, where positions start at 0 as w ith arrays
Point *PointArray::get(const int position){
  if(position>=0&&position<size){
    return &(this->p[position]);
  }
  return NULL;
}

const Point *PointArray::get(const int position) const{
  if(position>=0&&position<size){
    return &(this->p[position]);
  }
  return NULL;
}

PointArray::~PointArray(){
  if(NULL!=p){
    delete[] p;
    p=NULL;
    size=0;
    n=0;
  }
}
