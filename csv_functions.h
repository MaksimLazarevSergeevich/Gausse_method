#ifndef CSV_FUNCTIONS_H
#define CSV_FUNCTIONS_H

#include <iostream> // For work with console
#include <fstream> // For work with files
#include <string> // For read csv file
#include <random> // For generate matrix

#include <Eigen/Dense> // Includes Eigen library for matrix and vector operations
#include <lazycsv.hpp> // Includes lazycsv library for CSV parsing

// Read matrix from scv
Eigen::MatrixXd loadMatrix(std::string& fileName);

// Generate matrix and write it in csv
void generateMatrix(std::string& fileName);

// Write answer in csv (Vector)
void writeAnswer(std::string& fileName, Eigen::VectorXd&);

// Write answer in csv (Infinity and no solution)
void writeAnswer(std::string&, std::string&);

// Check second line in csv for tests
bool checkCsv(std::string&, const std::string&);

#endif