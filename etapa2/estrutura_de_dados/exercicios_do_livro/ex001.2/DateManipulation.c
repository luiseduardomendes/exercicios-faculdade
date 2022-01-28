#include "DateManipulation.h"

Date createDateByText(char *text_){
    Date d;
    
    d.day = atoi(strtok(text_, "/ .-"));
    d.month = atoi(strtok(NULL, "/ .-"));
    d.year = atoi(strtok(NULL, "/ .-"));

    if (!isDateValid(d))
        d = createDataInvalidFlag();

    return d;
}

Date createDataInvalidFlag(){
    Date d;

    d.day = 0; 
    d.month = 0; 
    d.year = 0;

    return d;
}

Date createDate(int day_, int month_, int year_){
    Date d;

    d.day = day_;
    d.month = month_;
    d.year = year_;

    if (!isDateValid(d))
        d = createDataInvalidFlag();

    return d;
}

bool isDateValid(Date date_){
    bool valid = false;
    const int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(date_.day > 0){
        if (date_.month != FEB){
            if(date_.day <= monthDays[date_.month]){
                valid = true;
            }
        }
        else{
            if(isLeapYear(date_.year)){
                if(date_.day <= monthDays[date_.month] + 1){
                    valid = true;
                }
            }   
            else{
                if(date_.day <= monthDays[date_.month]){
                    valid = true;    
                }
            }
        }
    }
    
    return valid;
}

bool isLeapYear(int year_){
    if ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0)
        return true;
    else
        return false;
}

int daysBetween(Date date1, Date date2){
    const int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Date first, last;
    int daysBetw = -1;
    
    if (isDateValid(date1) && isDateValid(date2)){
        /* different years */
        if(date1.year != date2.year){
            if (date1.year < date2.year){
                first = date1;
                last = date2;
            }
            else{
                first = date2;
                last = date1;
            }

            daysBetw = monthDays[first.month] - first.day + last.day;

            for (int i = first.month + 1; i <= DEC; i ++){  
                daysBetw += monthDays[i];
                if (i == FEB && isLeapYear(first.year))
                    daysBetw ++;
            }
            
            for (int i = first.year + 1; i < last.year; i ++){
                if (isLeapYear(i))
                    daysBetw += 366;
                else
                    daysBetw += 365;
            }

            for (int i = JAN; i < last.month; i ++){  
                daysBetw += monthDays[i];
                if (i == FEB && isLeapYear(first.year))
                    daysBetw ++;
            }
        }
        /* same year */
        else{
            /* different months */
            if (date1.month != date2.month){
                
                if (date1.month > date2.month){
                    first = date2;
                    last = date1;
                }
                else{
                    first = date1;
                    last = date2;
                }

                daysBetw = monthDays[first.month] - (first.day) + last.day;

                for (int i = first.month + 1; i < last.month; i ++){  
                    daysBetw += monthDays[i];
                    if (i == FEB && isLeapYear(first.year))
                        daysBetw ++;
                }
            }
            /* same month */
            else{
                if(date1.day < date2.day){
                    first = date1;
                    last = date2;
                }
                else if(date1.day > date2.day){
                    first = date2;
                    last = date1;
                }
                else{
                    return 0;
                }

                daysBetw = last.day - first.day;
            }
        }
    }    

    return daysBetw;
}

Date easterDay(int year_){
    int c, i, j, k, l, m, n, d;
    
    c = year_/100;
    n = year_ - (19 * (year_/19));
    k = (c - 17)/25;
    i = c - c/4 - ((c-k)/3) +(19 * n) + 15;
    i = i - (30 * (i/30));
    i = i - ((i/28) * (1-(i/28)) * (29/(i+1)) * ((21 - n) / 11));
    j = year_ + year_/4 + i + 2 -c + c/4;
    j = j - (7*(j/7));
    l = i - j;
    m = 3 + ((l+40)/44);
    d = l + 28 - (31*(m/4));

    Date data;
    data.day = d;
    data.month = m;
    data.year = year_;

    return data;
}

void displayDateStdin(Date date_){
    printf("%2.d/%2.d/%2.d\n", date_.day, date_.month, date_.year);
}