#include "func.h"
#include <cctype>

std::string between_coma_semicolon(const std::string& s){
    size_t colon_pos = s.find(':');      // шукаємо першу двокрапку
    if (colon_pos == std::string::npos)
        return s;                        // якщо нема двокрапки — повертаємо рядок без змін

    size_t comma_pos = s.find(',', colon_pos + 1);  // шукаємо кому після неї
    if (comma_pos == std::string::npos)
        return s.substr(colon_pos);      // якщо коми після двокрапки нема — від двокрапки до кінця

    return s.substr(colon_pos + 1, comma_pos - colon_pos - 1); // між двокрапкою і комою
}



std::string erase_between_stops(std::string& s) {
    size_t first = s.find('.');
    size_t last  = s.rfind('.');

    if (first == std::string::npos) {
        size_t pos = s.find_first_not_of(' ');
        return (pos == std::string::npos) ? "" : s.substr(pos);
    }

    if (first == last) {
        return s.substr(first + 1);
    }

    return s.substr(0, first + 1) + s.substr(last);
};

void remove_last_letter_from_words(std::string& s) {
    for (int i = 0; i < (int)s.length() - 1; i++) {
        if (std::isalpha((unsigned char)s[i]) && std::isspace((unsigned char)s[i + 1])) {
            s.erase(i, 1);
            i--; // щоб не перескочити після видалення
        }
    }

    // якщо останній символ — літера, теж видаляємо її
    if (!s.empty() && std::isalpha((unsigned char)s.back())) {
        s.pop_back();
    }
}