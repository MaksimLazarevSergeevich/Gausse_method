#include "gausse_metod.h"

int main()
{
    std::string csvName = "matrix.csv"; // Where the system will be generated
    std::string csvAns = "answer.csv"; // Where the answer will be recorded
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName)); // Load matrix to mat
    solveGause(mat, csvAns);
    return 0;
}
