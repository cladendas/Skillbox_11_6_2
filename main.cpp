#include <iostream>

//проверка части адреса
bool checkSection(std::string text, std::string verificationString) {
//    std::string verificationString = "-.";
    for (int i = 0; i < text.length(); i++) {
        if (verificationString.find(text[i]) != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }
}

//проверка всего адреса на общие требования к обеим частям, затем вызов checkSection для проверки каждой части
void checkEmail(std::string email) {
    std::string verificationFirstSection = "abcdefghijklmnopqrstuvwxyz!#$%&'*+-/=?^_`{|}~.";
    std::string verificationSecondSection = "abcdefghijklmnopqrstuvwxyz-.";

    int at = email.find("@");

    if (at != std::string::npos
        && email[0] != '@'
        && email[0] != '.'
        && at <= 64
        && email.length() - at - 1 <= 63
        && email[email.length() - 1] != '.') {

        checkSection(email.substr(0, at), verificationFirstSection);
        checkSection(email.substr(at + 1), verificationSecondSection);

    } else {
        std::cout << "No";
    }

}

int main() {
    std::string email = "simple@example.com";

    std::cout << "Enter email:" << std::endl;
//    std::cin >> email;

    checkEmail(email);

    return 0;
}
