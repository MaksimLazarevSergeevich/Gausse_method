#include "gausse_metod.h"

// Solves a system of linear equations using Gaussian elimination
// Takes an augmented matrix 'mat' and writes the result to 'csvAns'
void solveGause(Eigen::Matrix<double, -1, -1, Eigen::RowMajor>& mat, std::string& csvAns)
{
    std::cout << "Initial matrix:\n" << mat << "\n\n";

    int count_rows = mat.rows();

    // Forward elimination phase: convert matrix to triangular form
    for (int i = 0; i < count_rows; i++)
    {
        int best_row = i;
        
        // find the row with the largest absolute value in column. Also getting rid of the zero 
        for (int k = i + 1; k < count_rows; k++)
        {
            if (std::abs(mat(k, i)) > std::abs(mat(best_row, i)))
            {
                best_row = k;
            }
        }

        // Swap rows if a better number is found or if here was zero
        if (best_row != i)
        {
            mat.row(i).swap(mat.row(best_row));
        }

        // We skip the zero column, otherwise we zeroize the values 
        if (std::abs(mat(i, i)) != 0)
        {
            for (int k = i + 1; k < count_rows; k++)
            {
                if (std::abs(mat(k, i)) != 0)
                {
                    // Row operation to zero out the k-th row, i-th column
                    mat.row(k) = mat(i, i) * mat.row(k) - mat(k, i) * mat.row(i);
                }
            }
        }
    }

    std::cout << "Triangular shape:\n";
    std::cout << mat << "\n\n";

    Eigen::VectorXd x(count_rows); // Solution vector

    // Back substitution phase: solve from bottom up
    for (int i = count_rows - 1; i >= 0; i--)
    {
        double b = mat(i, count_rows); // Right-hand side value

        // Subtract known values from b
        for (int j = i + 1; j < count_rows; j++)
        {
            b -= mat(i, j) * x(j);
        }

        // Check for special cases: no solution or infinite solutions
        if (std::abs(mat(i, i)) == 0)
        {
            if (std::abs(b) == 0)
            {
                // Row of zeros with 0 on the right - infinite solutions
                std::string ans("infinite number of solutions");
                writeAnswer(csvAns, ans);
                return; 
            }
            else
            {
                // Row of zeros with non-zero on the right - no solution
                std::string ans("There are no solutions");
                writeAnswer(csvAns, ans);
                return;
            }
        }

        // Compute the variable value
        x(i) = b / mat(i, i);
    }

    std::cout << "Answers:\n" << x << "\n\n";

    // Write the solution to a CSV file
    writeAnswer(csvAns, x);
}
