#include "DateManipulation.h"

Date createDateByText(char *text_){
    Date d;
    
    d.day = atoi(strtok(text_, "/ .-"));
    d.month = atoi(strtok(NULL, "/ .-"));
    d.year = atoi(strtok(NULL, "/ .-"));

    if (!isDateValid(d)){
        d.day = 0; 
        d.month = 0; 
        d.year = 0;
    }

    return d;
}

Date createDate(int day_, int month_, int year_){
    Date d;

    d.day = day_;
    d.month = month_;
    d.year = year_;

    if (!isDateValid(d)){
        d.day = 0; 
        d.month = 0; 
        d.year = 0;
    }

    return d;
}

bool isDateValid(Date date_){
    bool valid = false;

    if(date_.day > 0)
        switch (date_.month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(date_.day <= 31)
                valid = true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(date_.day <= 30)
                valid = true;
            break;
        case 2:
            if(isLeapYear(date_.year)){
                if(date_.day <= 29)
                    valid = true;
            }
            else
                if(date_.day <= 28)
                    valid = true;
            break;
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
    int daysBetw;
    
    if (isDateValid(date1) && isDateValid(date2)){
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