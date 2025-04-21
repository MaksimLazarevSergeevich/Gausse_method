#include "csv_functions.h"

Eigen::MatrixXd loadMatrix(std::string& filename)
{
    std::vector<std::vector<double>> rows;
    lazycsv::parser parser(filename);

    // add rows in vector rows
    for (const auto& row: parser)
    {
        std::vector<double> r;
        for (const auto& cell: row)
        {
            r.push_back(std::stod(std::string(cell.raw())));
        }
        rows.push_back(r);
    }

    // Create Matrix
    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(rows.size(), rows[0].size());

    for (size_t i = 0; i < rows.size(); i++)
    {
        for (size_t j = 0; j < rows[0].size(); j++)
        {
            mat(i, j) = rows[i][j];
        }
    }

    return mat;
}

void generateMatrix(std::string& fileName)
{
    std::ofstream csvFile(fileName);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> numbers_in_matrix(-10, 10);
    std::uniform_int_distribution<> quantity_rows(1, 6);

    int rows = quantity_rows(gen);

    for (int i = 0; i < rows + 1; ++i)
    {
        for (int j = 0; j < rows + 1; ++j) // add 1 col for gausse
        {
            int number;
            // lazycsv don't read the first row, so i add it
            if (i == 0)
            {
                number = j;
            }
            else
            {
                number = numbers_in_matrix(gen);
            }

            if (j == rows)
            {
                csvFile << number << '\n'; 
            }
            else
            {
                csvFile << number << ',';
            }
        }
    }

    csvFile.close();
}

void writeAnswer(std::string& fileName, Eigen::VectorXd& x)
{
    std::ofstream csvFile(fileName);

    csvFile << "A\n";

    for (int i = 0; i < x.rows(); i++)
    {
        csvFile << x(i) << '\n';
    }

    csvFile.close();
}

void writeAnswer(std::string& fileName, std::string& stringAns)
{
    std::ofstream csvFile(fileName);

    csvFile << "A\n" << stringAns;

    csvFile.close();
}