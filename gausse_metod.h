#ifndef GAUSSE_METOD_H
#define GAUSSE_METOD_H
#include "csv_functions.h"

// Performs forward and reverse Gauss runs
void solveGause(Eigen::Matrix<double, -1, -1, Eigen::RowMajor>&, std::string&);

#endif