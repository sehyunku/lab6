#pragma once
#include <iostream>

namespace SehyunKu2693015
{
    class dayOfYear
    {
        int month{};
        int day{};
        void testMonth()
        {
            if ((month<1)||(month>12)){
                std::cout << "Illegal month value!\n";
                std::exit(1);
            }
        }
        void testDay()
        {
            if((day<1)||(day>31)){
                std::cout<< "Illegal day value!\n";
                std::exit(1);
            }
        }
    public:
        dayOfYear(int m=1, int d=1) : month{m}, day{d} 
        {
            testMonth();
            testDay();
        }

        void input()
        {
            std::cout << "Enter month: ";
            std::cin >> month; testMonth();
            std::cout << "Enter day: ";
            std::cin >> day; testDay();
        }

        friend std::istream& operator>> (std::istream& is, dayOfYear& d)
        {
            std::cout << "Enter month: ";
            is >> d.month; d.testMonth();
            std::cout << "Enter day: ";
            is >> d.day; d.testDay();
            return is;
        }
    
        void print() const { 
            switch(month)
            {
                case 1: std::cout << "Jan."; break;
                case 2: std::cout << "Feb."; break;
                case 3: std::cout << "Mar."; break;
                case 4: std::cout << "Apr."; break;
                case 5: std::cout << "May."; break;
                case 6: std::cout << "Jun."; break;
                case 7: std::cout << "Jul."; break;
                case 8: std::cout << "Aug."; break;
                case 9: std::cout << "Sep."; break;
                case 10: std::cout << "Oct."; break;
                case 11: std::cout << "Nov."; break;
                case 12: std::cout << "Dec."; break;
            } std::cout << day << "\n";
        }

        friend std::ostream& operator<< (std::ostream& os, const dayOfYear& d)
        {
             switch(d.month)
            {
                case 1: os << "Jan."; break;
                case 2: os << "Feb."; break;
                case 3: os << "Mar."; break;
                case 4: os << "Apr."; break;
                case 5: os << "May."; break;
                case 6: os << "Jun."; break;
                case 7: os << "Jul."; break;
                case 8: os << "Aug."; break;
                case 9: os << "Sep."; break;
                case 10: os << "Oct."; break;
                case 11: os << "Nov."; break;
                case 12: os << "Dec."; break;
            } os << d.day << "\n";
            return os;
        }
        int getMonth() const { return month; }
        int getDay() const { return day; }
        void setMonth(int newMonth) { month = newMonth; testMonth();}
        void setDay(int newDay) { day = newDay; testDay();}
        
        dayOfYear operator++()
        {
           ++day;
           if (day>31)
           {
            day = 1;
            ++month;
            if (month>12) {
            month=1;
           }
        }
            return dayOfYear(month, ++day);
        }
        dayOfYear operator++(int)
        {
            dayOfYear temp{month,day};
            operator++();
            return temp;
        }
        friend bool operator== (const dayOfYear& d1, const dayOfYear& d2)
        {
            return d1.month == d2.month && d1.day == d2.day;
        }
        friend dayOfYear operator+ (const dayOfYear& d1, const dayOfYear& d2)
        {
            return dayOfYear(d1.month + d2.month, d1.day + d2.day);
        }
    };
}