#include "Date.hpp"

Day::Day(int day) : d(day) {}

int Day::GetDay() const { return d; }

Year::Year(int year) : y(year) {}

int Year::GetYear() const { return y; }

bool Year::is_leap() const { 
    return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
}

Month Month::Jan() { return Month{1}; }
Month Month::Feb() { return Month{2}; }
Month Month::Mar() { return Month{3}; }
Month Month::Apr() { return Month{4}; }
Month Month::May() { return Month{5}; }
Month Month::Jun() { return Month{6}; }
Month Month::Jul() { return Month{7}; }
Month Month::Aug() { return Month{8}; }
Month Month::Sep() { return Month{9}; }
Month Month::Oct() { return Month{10}; }
Month Month::Nov() { return Month{11}; }
Month Month::Dec() { return Month{12}; }
bool Month::operator==(const Month& rhs) const { return m == rhs.m; }
bool Month::operator!=(const Month& rhs) const { return !(*this == rhs); }
const Month& Month::operator++() {
    ++m;
    if (m > 12) m = 1;
    return *this;
}
const Month& Month::operator--() {
    for (int i = 0; i < 11; ++i) ++*this;
    return *this;
}
Month::Month(int month) : m(month) {}

int Month::GetMaxDays(const Year& year) const {
    if (*this == Jan()) return 31;
    if (*this == Feb()) return year.is_leap() ? 29 : 28;
    if (*this == Mar()) return 31;
    if (*this == Apr()) return 30;
    if (*this == May()) return 31;
    if (*this == Jun()) return 30;
    if (*this == Jul()) return 31;
    if (*this == Aug()) return 31;
    if (*this == Sep()) return 30;
    if (*this == Oct()) return 31;
    if (*this == Nov()) return 30;
    if (*this == Dec()) return 31;
    return 0;
}

Date::Date(Day day, Month month, Year year) : 
  day_(day), month_(month), year_(year) {}

const Date& Date::AddDays(int days) {
    Day current{days + day_.GetDay()};
    if (current.GetDay() > 0) {
      while (current.GetDay() > month_.GetMaxDays(year_)) {
          current = Day{current.GetDay() - month_.GetMaxDays(year_)};
          ++month_;
          if (month_ == Month::Jan()) year_ = Year{year_.GetYear() + 1};
      }
      day_ = current;
    } else if (current.GetDay() < 0) {
        do {
            --month_;
            if (month_ == Month::Dec()) year_ = Year{year_.GetYear() - 1};
            current = Day{current.GetDay() + month_.GetMaxDays(year_)};
        } while (current.GetDay() < 0); 
    }
    return *this;
}

const Date& Date::AddMonths(int months) {
    if (months > 0) {
        year_ = Year(year_.GetYear() + months / 12);
        months %= 12;
        for (int i = 0; i < months; ++i) {
            ++month_;
            if (month_ == Month::Jan()) year_ = Year(year_.GetYear() + 1);
        }
    }
    else if (months < 0) {
        months = -months;
        year_ = Year(year_.GetYear() - months / 12);
        months %= 12;
        for (int i = 0; i < months; ++i) {
            --month_;
            if (month_ == Month::Dec()) year_ = Year(year_.GetYear() - 1);
             
        }
    }
    if (day_.GetDay() > month_.GetMaxDays(year_))
        day_ = Day(month_.GetMaxDays(year_));
    return *this;
}

const Date& Date::AddYears(int years) {
    year_ = Year(year_.GetYear() + years);
    return *this;
}

void Month::dump(std::ostream& os) const {
    os << m;
}

void Date::dump(std::ostream& os) const {
    os << day_.GetDay() << '/';
    month_.dump(os);
    os << '/' << year_.GetYear();
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    d.dump(os);
    return os;
}