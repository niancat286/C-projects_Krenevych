#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


std::string Capital_1_letter(std::string word) {
    if (!word.empty()) {
        // toupper перетворює символ на велику літеру
        word[0] = std::toupper(static_cast<unsigned char>(word[0]));
    }
    return word;
}


bool is_article(const std::string& word) {
    return word == "die" || word == "der" || word == "das";
}

int main() {

    const std::string in_fname = "input2.txt";
    const std::string out_fname = "output2.txt";

    std::ifstream input_file(in_fname);
    if (!input_file.is_open()) {
        std::cerr << "error. can't open '" << in_fname << "'" << std::endl;
        return -1;
    }

    std::ofstream output_file(out_fname);
    if (!output_file.is_open()) {
        std::cerr << "error. can't open '" << out_fname << "'" << std::endl;
        input_file.close();
        return -1;
    }

    std::string current_word;
    std::string previous_word = ""; //for fixing 1st word
    bool first_word = true;


    while (input_file >> current_word) {
        if (is_article(previous_word)) {
            current_word = Capital_1_letter(current_word);
        }

        if (!first_word) {  //add space if not 1st
            output_file << " ";
        }

        output_file << current_word;

        previous_word = current_word;
        first_word = false;
    }

    input_file.close();
    output_file.close();

    std::cout << "Look result in " << out_fname << std::endl;

    return 0;
}