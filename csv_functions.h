#ifndef CSV_FUNCTIONS_H
#define CSV_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include <Eigen/Dense>
#include <lazycsv.hpp>

Eigen::MatrixXd loadMatrix(std::string& fileName);

void generateMatrix(std::string& fileName);

void writeAnswer(std::string& fileName, Eigen::VectorXd&);

void writeAnswer(std::string&, std::string&);

#endif