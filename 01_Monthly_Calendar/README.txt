This "MONTHLY CALENDAR" implementation requires:
1, year lows non-negative integer
2, month must be in english such as January, February, March, April, May, June,
July, August, September, October, November, December.
3, duration must be a positive integer

isleap is a helper function check whether a year is a leap year or not.
daysinmonth is a helper function to calculate how many days in a given month
daysofyear is a helper function to calculate how many days before a given month
in that given year
weekday first calculate the accumulated days between the given date and
January 1, year 0. Then plus offset and divided by 7, the remainder is the weekday

print_month will print out the calendar of a given month

print_calender will print out the calendars for several months
