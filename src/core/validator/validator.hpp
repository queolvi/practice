#include "/../tables/Tables.hpp"

class Validator{
    public:
    std::string class_name;
    Validator(std::string class_name) : class_name(class_name) {}
    ~Validator() = default;
    virtual bool is_valide() {};
};
class UserValidator : public Validator, private User {
      
};

class UserValidator : public Validator, private User {
      
};