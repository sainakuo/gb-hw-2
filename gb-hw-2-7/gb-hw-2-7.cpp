#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public: 
    Date() : day(0), month(0), year(0) {};
    Date(int inDay, int inMonth, int inYear) : day(inDay), month(inMonth), year(inYear) {};
    int getDay() const {
        return day;
    }
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }

    void setDay(int inDay) {
        day = inDay;
    }

    void setMonth(int inMonth) {
        month = inMonth;
    }

    void setYear(int inYear) {
        year = inYear;
    }

    friend ostream& operator<<(ostream& out, const Date& date);
    
};
ostream& operator<<(ostream& out, const Date& date) {
    out << date.day << "." << date.month << "." << date.year << endl;
    return out;
}

Date later(const unique_ptr<Date>& d1, const unique_ptr<Date>& d2) {
    Date newDate;

    if (d1->getYear() < d2->getYear())
    {
        newDate = *d1;
    }
    else if (d1->getYear() > d2->getYear())
    {
        newDate = *d2;
    }
    //если равны year
    else 
    {
        if (d1->getMonth() < d2->getMonth())
        {
            newDate = *d1;
        }
        else if (d1->getMonth() > d2->getMonth())
        {
            newDate = *d2;
        }
        //если равны month
        else
        {
            if (d1->getDay() < d2->getDay())
            {
                newDate = *d1;
            }
            else if (d1->getDay() > d2->getDay())
            {
                newDate = *d2;
            }
            //если равны day
            else
            {
                newDate = *d1;
            }
        }
    }

    return newDate;
}

void change(unique_ptr<Date>& d1, unique_ptr<Date>& d2) {
    unique_ptr<Date> temp = make_unique<Date>(d1->getDay(), d1->getMonth(), d1->getYear());
    d1->setDay(d2->getDay());
    d1->setMonth(d2->getMonth());
    d1->setYear(d2->getYear());

    d2->setDay(temp->getDay());
    d2->setMonth(temp->getMonth());
    d2->setYear(temp->getYear());
}

int main()
{
    cout << "task 1: " << endl;
    unique_ptr<Date> today = make_unique<Date>(10, 11, 2021);
    today->getDay();
    today->getMonth();
    today->getYear();
    cout << *today;
    unique_ptr<Date> date = move(today);

    if (today == nullptr)
        cout << "today is nullptr" << endl;
    if (date == nullptr)
        cout << "date is nullptr" << endl;

    cout << "task 2: " << endl;
    unique_ptr<Date> date1 = make_unique<Date>(11, 10, 2000);
    unique_ptr<Date> date2 = make_unique<Date>(12, 10, 2001);
 
    cout << "later date: " << later(date1, date2) << endl;

    cout << *date1 << *date2 << endl;
    change(date1, date2);
    cout << *date1 << *date2 << endl;

    return 0;
};

