#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

using namespace std;

double calc_pi(int round){
  int count(0);
  srand(time(NULL));
  for(int i=0;i<round;i++){
    if((pow((double)rand()/RAND_MAX,2)+pow((double)rand()/RAND_MAX,2))<=1.0){
      count++;
    }
  }
  return (double)count/round*4;
}

int main(int argc, char const *argv[]) {
  /* code */
  for(int i=1;i<30;i++){
    cout<<(1<<i)<<" samples:\t"<<setprecision(8)<<calc_pi(1<<i)<<endl;
  }
  return 0;
}
