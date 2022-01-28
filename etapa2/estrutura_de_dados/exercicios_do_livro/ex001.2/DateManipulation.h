#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Date{
    int day;
    int month;
    int year;
} Date;

enum NameMonths {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

Date createDataInvalidFlag();
/* Returns a flag for a invalid date */

Date createDateByText(char* text_);
/* Returns a date, if date is invalid, returns 00/00/0000 */

Date createDate(int day_, int month_, int year_);
/* Returns a date, if date is invalid, returns 00/00/0000 */

bool isDateValid(Date date_);
/* Returns true if date is valid, else, return false */

bool isLeapYear(int year_);
/* Returns true if the year is a leap year, else, return false */

int daysBetween(Date date1, Date date2);
/* Returns the number of days between two dates, ignoring the years*/

Date easterDay(int year_);
/* Returns the date of easter for a year */

void displayDateStdin(Date date_);
/* Prints in the console a date */
