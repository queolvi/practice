#include <iostream>

class Day {
    int d;
public:
    Day(int day = 1);
    int GetDay() const;
};
class Year {
    int y;
public:
    Year(int year = 1970);
    int GetYear() const;
    bool is_leap() const;
};

class Month {
private:
    int m;
    explicit Month(int month);
public:
    static Month Jan();
    static Month Feb();
    static Month Mar();
    static Month Apr();
    static Month May();
    static Month Jun();
    static Month Jul();
    static Month Aug();
    static Month Sep();
    static Month Oct();
    static Month Nov();
    static Month Dec();
    void dump(std::ostream& os) const;
    bool operator==(const Month& rhs) const;
    bool operator!=(const Month& rhs) const;
    const Month& operator++();
    const Month& operator--();
    int GetMaxDays(const Year& year) const;
};

class Date {
    Day day_;
    Month month_;
    Year year_;
public: 
    Date(Day day, Month month, Year year);
    void dump(std::ostream& os) const;
    const Date& AddDays(int days);
    const Date& AddMonths(int months);
    const Date& AddYears(int years);
};

std::ostream& operator<<(std::ostream& os, const Date& d);