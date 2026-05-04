#include "Validator.hpp"

bool StudentValidator::is_valide() {
    bool first_check = check_email(), second_check = check_first_name(), third_check = check_second_name(), fourth_check = check_student_id();
    if (first_check == true && second_check == true && third_check == true && fourth_check == true) return true;
    return false;
}

bool StudentValidator::check_email() {
    std::string user_email_ = student_.get_email();  
    size_t len_email = user_email_.length();
    std::string email_pre_domain = "", email_after_domain = "";
    
    for (size_t i = 0; i < len_email; ++i) {
        char c = user_email_[i]; 
        if (c == '@') { 
            email_pre_domain = user_email_.substr(i, size_t(len_email - i));std::cout << email_pre_domain << std::endl; /// 12345@gmail.com 6 15 - 6 = 9 
            email_after_domain = user_email_.substr(i + 1, i); std::cout << email_after_domain << std::endl;  
            break; 
        }
    }
    return true;
}
bool StudentValidator::check_first_name() {}
bool StudentValidator::check_second_name() {}
bool StudentValidator::check_student_id() {}