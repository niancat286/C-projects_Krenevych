//
// Created by Yaroslava Krenevych on 03.12.2025.
//


#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


struct Point {
    int x;
    int y;
};

struct Segment {
    Point p1;
    Point p2;
    double length;
};


double calc_distance(const Point& p1, const Point& p2) {
    double dx = static_cast<double>(p2.x - p1.x);
    double dy = static_cast<double>(p2.y - p1.y);
    return sqrt(dx * dx + dy * dy);
}


vector<Segment> parse_Segments(const char* fname) {
    vector<Segment> segments;
    ifstream fin(fname);

    if (!fin.is_open()) {
        cerr << "open error" << endl;
        return segments;
    }

    string full_content((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();


    stringstream ss(full_content);
    char trash;

    while (true) {
        Segment current_segment;

        if (!(ss >> trash) || trash != '(') break;

        if (!(ss >> current_segment.p1.x)) break;

        if (!(ss >> trash) || trash != ',') break;

        if (!(ss >> current_segment.p1.y)) break;

        if (!(ss >> trash) || trash != ')') break;

        if (!(ss >> trash) || trash != '(') break;

        if (!(ss >> current_segment.p2.x)) break;

        if (!(ss >> trash) || trash != ',') break;

        if (!(ss >> current_segment.p2.y)) break;

        if (!(ss >> trash) || trash != ')') break;

        current_segment.length = calc_distance(current_segment.p1, current_segment.p2);
        segments.push_back(current_segment);

        if (!(ss >> trash)) break;
        if (trash != ',') break;
    }
    return segments;
}



void sort_segments(const char* input_filename, const char* output_filename) {
    vector<Segment> segments = parse_Segments(input_filename);

    if (segments.empty()) return;

    sort(segments.begin(), segments.end(),
         [](const Segment& a, const Segment& b) {
             return a.length < b.length;
         });

    ofstream fout(output_filename);
    if (!fout.is_open()) return;

    fout << fixed << setprecision(3); // Форматування виводу

    for (const auto& seg : segments) {
        // Вивід у форматі: (x1, y1) (x2, y2) | Довжина: L
        fout << "(" << seg.p1.x << ", " << seg.p1.y << ") ("
             << seg.p2.x << ", " << seg.p2.y << ") | Len: "
             << seg.length << "\n";
    }

    fout.close();
    cout << "sorted " << segments.size() << " segments. res in file: " << output_filename << endl;
}


int main() {
    const char* input_file = "input_segments.txt";
    const char* output_file = "output_sorted_segments.txt";
    ofstream test_input(input_file);
    test_input << "(0, 0) (3, 4), (0, 0) (10, 0), (1, 1) (2, 2)";
    test_input.close();

    sort_segments(input_file, output_file);

    return 0;
}