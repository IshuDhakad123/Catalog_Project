# Shamir's Secret Sharing Algorithm

## Overview

This project is a simplified implementation of the Shamir's Secret Sharing algorithm. The goal is to find the constant term (c) of an unknown polynomial using the provided roots.

## Files

- `src/main.cpp`: Main C++ program that decodes input from a JSON file and performs Lagrange Interpolation to find the constant term.
- `input/input.json`: Sample input file containing the encoded polynomial roots.
- `include/json/`: JSONCPP library files for parsing JSON in C++.
- `Makefile`: Compilation instructions.

## Prerequisites

- C++17 or later.
- JSONCPP Library (`json/json.h`), for JSON parsing.

## How to Compile

Use the provided `Makefile` to compile the project:

```bash
make
