#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../include/json/json.h" // Use the correct path to JSONCPP library
#include "../include/json/json-forwards.h"
#include <json/json.h>

#include <cmath>

using namespace std;

// Structure to store each root's data after decoding
struct Point {
    int x;
    long long y;
};

// Function to convert a string from a given base to decimal
long long decodeValue(const string &value, int base) {
    long long decimalValue = 0;
    for (char digit : value) {
        decimalValue = decimalValue * base + (isdigit(digit) ? digit - '0' : toupper(digit) - 'A' + 10);
    }
    return decimalValue;
}

// Function to read JSON input and decode points
vector<Point> parseAndDecodeJson(const string &filename, int &k) {
    ifstream file(filename, ifstream::binary);
    Json::Value root;
    file >> root;

    vector<Point> points;
    k = root["keys"]["k"].asInt();

    for (const auto &key : root.getMemberNames()) {
        if (key == "keys") continue;

        int x = stoi(key); // key is treated as the x-coordinate
        int base = root[key]["base"].asInt();
        string value = root[key]["value"].asString();

        // Decode the y-value from given base to decimal
        long long y = decodeValue(value, base);
        points.push_back({x, y});
    }
    return points;
}

// Function to apply Lagrange Interpolation to find the constant term (c)
long long findConstantTerm(const vector<Point> &points, int k) {
    long long constantTerm = 0;

    for (int i = 0; i < k; i++) {
        long long term = points[i].y;

        for (int j = 0; j < k; j++) {
            if (i != j) {
                term = term * (0 - points[j].x) / (points[i].x - points[j].x);
            }
        }
        constantTerm += term;
    }
    return constantTerm;
}

int main() {
    int k;
    vector<Point> points = parseAndDecodeJson("../input/input.json", k);

    // Calculate the constant term of the polynomial
    long long constantTerm = findConstantTerm(points, k);
    cout << "The constant term (c) of the polynomial is: " << constantTerm << endl;

    return 0;
}
