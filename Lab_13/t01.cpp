#include "func.h"
#include <iostream>
#include <string>

int main() {
    std::string arr[] = {
        "lkdgsj",
        "lk:d,gsj",
        "lkd,gs:j",
        "lk:d:j",
        "lk,d,j"
    };

    for (int i = 0; i < 5; i++) {
        std::cout << "\"" << arr[i] << "\" -> \""
                  << between_coma_semicolon(arr[i]) << "\"" << std::endl;
    }


    std::string tests[] = {
        "  hello world",       // немає крапок → прибрати пробіли на початку
        "start.middle.end",    // видалити все між першою і останньою крапкою → "start..end"
        "one.dot",             // лише одна крапка → видалити все до неї → "dot"
        "no.dots here",        // одна крапка → видалити до неї → "dots here"
        "a.b.c.d",             // між першою і останньою → "a.d"
        "   ...abc..."         // між першою і останньою → "   ...."
    };

    for (auto &t : tests) {
        std::cout << "\"" << t << "\" -> \"" << erase_between_stops(t) << "\"\n";
    }

    std::string examples[] = {
        "Hello world",
        "Hi   there",
        "One two three ",
        "SingleWord",
        "   Leading spaces  test "
    };

    for (auto& s : examples) {
        std::string copy = s;
        remove_last_letter_from_words(copy);
        std::cout << "\"" << s << "\" -> \"" << copy << "\"" << std::endl;
    }

    return 0;
}