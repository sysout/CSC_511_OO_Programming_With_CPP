#include <iostream>
#include <string>
using namespace std;

/*
 The program should prompt the user for the year and the month of the beginning
 month, and the number of months to be printed. Then it should figure out
 (a) whether the year is a leap-year and
 (b) what day of the week the chosen year starts on.

Sample Execution
                        MONTHLY CALENDAR

Please enter year of the beginning month:- 2009
Please enter month of the beginning month:- January
Please enter the number of months to print:- 6


  ***    CALENDAR for 2009   ***

January 2009

Sun  Mon  Tue  Wed  Thu  Fri  Sat
                      1    2    3
  4    5    6    7    8    9   10
 11   12   13   14   15   16   17
 18   19   20   21   22   23   24
 25   26   27   28   29   30   31

February 2009

Sun  Mon  Tue  Wed  Thu  Fri  Sat
  1    2    3    4    5    6    7
  8    9   10   11   12   13   14
                 .
                 .
                 .
(output continues for all 6 months)
*/

// January, February, March, April, May, June, July, August, September, October, November, December

bool isleap(int year){
  // In the modern calendar, years that are divisible by 4 are leap years,
  // except that years divisible by 100 are not leap years unless they are also
  // divisible by 400. That is, there are 97 leap years every four centuries.
  return (year%4==0)&&((year%100!=0)||(year%400==0));
}

/*
  month start from 0
*/
int daysinmonth(int year, int month){
  switch (month+1) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
          return 31;
      case 2:
          if(isleap(year)){
            return 29;
          }else{
            return 28;
          }
      case 4:
      case 6:
      case 9:
      case 11:
          return 30;
    }
    return -1;
}

/*
  month start from 0
*/
int daysofyear(int year, int month){
  int sum(0);
  for(int i(0);i<month;i++){
      // cout<<" daysofyear sum: "<<sum<<" month "<<i <<" of "<<month<<endl;
      sum+=daysinmonth(year, i);
  }
  return sum;
}

/*
  year start from 0 which means 1 BC
  month start from 0 which means January
  day start from 1
  return range from 0~6
*/
int weekday(int year, int month, int day){
  int leaps(0); // how many leap years before this year
  if(year>0){
    int before(year-1);
    leaps = 1+before/4-before/100+before/400;
  }
  int pastdays=year*365+leaps+daysofyear(year, month)+day+5;
  // cout<<"pastdays "<<pastdays<<endl;
  return pastdays%7;
}

void print_month(int year, int month, int day){
  string ss[7]={"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

  // cout<<year<<" "<<month<<" "<<ss[day]<<endl;
}

/*
*/
void print_calender(int year, int month, int duration){
  int start_weekday = weekday(year, month, 1);
  int days_passed(0);
  for (size_t i = 0; i < duration; i++) {
    int cur_year = year+(month+i)/12;
    int cur_month = (month+i)%12;
    int cur_weekday = (start_weekday+days_passed)%7;
    cout<<cur_year<<" "<<cur_month<<" "<<cur_weekday<<" days passed "<<days_passed<<endl;
    print_month(cur_year, cur_month, cur_weekday);
    days_passed+=daysinmonth(cur_year, cur_month);
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  cout<<" 0001, January (Mo) "<<weekday(1, 0, 1) <<endl;
  cout<<" 0002, January (Tu) "<<weekday(2, 0, 1) <<endl;
  cout<<" 0003, January (We) "<<weekday(3, 0, 1) <<endl;
  cout<<" 0004, January (Th) "<<weekday(4, 0, 1) <<endl;
  cout<<" 0005, January (Sa) "<<weekday(5, 0, 1) <<endl;
  cout<<" 2016, January (Fr) "<<weekday(2016, 0, 1) <<endl;
  cout<<" 2016, September (Th)"<<weekday(2016, 8, 1) <<endl;
  cout<<" 2016, October (Sa) "<<weekday(2016, 9, 1) <<endl;
  print_calender(2016,7,5);
  return 0;
}
