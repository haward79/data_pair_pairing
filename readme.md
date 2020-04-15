# What's this ?
This program converts data in following format to more tiny format.

Each data is splitted to a pair of (Id, Value) pair.
Order identifies the order(nth of the field).

    +------------------------+
    |   Id  | Value  | Order |
    +-------+--------+-------+
    | David | dog    |   1   |
    | David | banana |   2   |
    | David | four   |   3   |
    | Amy   | apple  |   2   |
    | Amy   | pig    |   1   |
    | Amy   | one    |   3   |
    +-------+--------+-------+

formatted by this program:

    +-------+--------+--------+-------+
    |   Id  | Col 1  | Col 2  | Col 3 |
    +-------+--------+--------+-------+
    | David | dog    | banana | four  |
    | Amy   | pig    | apple  | one   |
    +-------+--------+--------+-------+

# Requirements
* C++ compiler

# How to use ?
1. Compile source code.

        $ g++ src/main -o bin/main

2. Prepare data.

   * Remove header.
   * Reserve column in this order: id, value, order.
   * Order the rows by the columns according to the following order: id, order.
   * Replace half comma to other character or string.
   * Save original file as csv file. (Columns are separated by half comma. Rows are separated by LF)

* Warning : Max column = 24 per data.

3. Run the program to fetch data.
4. Adjust unwanted data or columns.

