#include <iostream>

//проверка части адреса
bool checkSection(std::string text, std::string verificationString) {
    for (int i = 1; i < text.length(); i++) {
        if (verificationString.find(text[i - 1]) == std::string::npos) {
            return false;
        } else if (text[i] == '.' && text[i - 1] == '.') {
            return false;
        }
    }
    return true;
}

//проверка всего адреса на общие требования к обеим частям, затем вызов checkSection для проверки каждой части
void checkEmail(std::string email) {
    //допустимые символы в первой части
    std::string verificationFirstSection = "abcdefghijklmnopqrstuvwxyz!#$%&'*+-/=?^_`{|}~.";
    //допустимые символы во второй части
    std::string verificationSecondSection = "abcdefghijklmnopqrstuvwxyz-.";

    //получение индекса @
    int at = email.find("@");

    //проверка первой части
    bool chFrSec = checkSection(email.substr(0, at + 1), verificationFirstSection);
    //проверка второй части
    bool chScSec = checkSection(email.substr(at + 1), verificationSecondSection);

    if (at != std::string::npos
        && email[0] != '@'
        && email[0] != '.'
        && at <= 64 //первая часть должна быть не более 64 символов
        && email.length() - at - 1 <= 63 //вторая часть должна быть не более 63 символов
        && email[email.length() - 1] != '.'
        && chFrSec
        && chScSec) {

        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

//проверить все примеры из задачи
void checkingAllExp() {
    std::string corEmail[] = {
            "simple@example.com",
            "very.common@example.com",
            "disposable.style.email.with+symbol@example.com",
            "other.email-with-hyphen@example.com",
            "fully-qualified-domain@example.com",
            "user.name+tag+sorting@example.com",
            "x@example.com",
            "example-indeed@strange-example.com",
            "admin@mailserver1",
            "example@s.example",
            "mailhost!username@example.org",
            "user%example.com@example.org"
    };

    std::string uncorEmail[] = {
            "John..Doe@example.com",
            "Abc.example.com",
            "A@b@c@example.com",
            "a\"b(c)d,e:f;g<h>i[j\\k]l@example.com",
            "1234567890123456789012345678901234567890123456789012345678901234+x@example.com",
            "i_like_underscore@but_its_not_allow_in _this_part.example.com"
    };

    std::cout << "** Checking correct emails ************** " << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << i + 1 << ". " << corEmail[i] << " - ";
        checkEmail(corEmail[i]);
    }

    std::cout << std::endl;

    std::cout << "** Checking uncorrect emails ************** " << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << i + 1 << ". " << uncorEmail[i] << " - ";
        checkEmail(uncorEmail[i]);
    }
}

int main() {
    std::string email = "x@example.com]";

    std::cout << "Enter email:" << std::endl;
    std::cin >> email;
    checkEmail(email);

//    checkingAllExp(); //проверить все примеры из задачи
}
