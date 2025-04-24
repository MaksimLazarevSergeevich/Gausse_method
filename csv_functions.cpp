#include "csv_functions.h"

// Loads a matrix from a CSV file into an Eigen matrix
Eigen::MatrixXd loadMatrix(std::string& filename)
{
    std::vector<std::vector<double>> rows;
    lazycsv::parser parser(filename);

    // Read rows and convert strings to doubles
    for (const auto& row: parser)
    {
        std::vector<double> r;
        for (const auto& cell: row)
        {
            r.push_back(std::stod(std::string(cell.raw())));
        }
        rows.push_back(r);
    }

    // Create an Eigen matrix with the appropriate size
    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(rows.size(), rows[0].size());

    // Fill the Eigen matrix with values from the parsed CSV
    for (size_t i = 0; i < rows.size(); i++)
    {
        for (size_t j = 0; j < rows[0].size(); j++)
        {
            mat(i, j) = rows[i][j];
        }
    }

    return mat;
}

// Generates a random augmented matrix and saves it as a CSV file
void generateMatrix(std::string& fileName)
{
    std::ofstream csvFile(fileName);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> numbers_in_matrix(-10, 10); // random values from -10 to 10
    std::uniform_int_distribution<> quantity_rows(1, 6); // matrix size between 1 and 6

    int rows = quantity_rows(gen);

    for (int i = 0; i < rows + 1; ++i)
    {
        for (int j = 0; j < rows + 1; ++j) // one extra column for augmented matrix
        {
            int number;
            // lazycsv skips the first row, so we fill it with headers (index values)
            if (i == 0)
            {
                number = j;
            }
            else
            {
                number = numbers_in_matrix(gen);
            }

            // Last column — no comma at the end
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

// Writes the solution vector into a CSV file (second row onward)
void writeAnswer(std::string& fileName, Eigen::VectorXd& x)
{
    std::ofstream csvFile(fileName);

    csvFile << "A\n"; // Header row

    for (int i = 0; i < x.rows(); i++)
    {
        csvFile << x(i) << '\n';
    }

    csvFile.close();
}

// Writes a string result (e.g. "Infinity" or "No solution") into a CSV file
void writeAnswer(std::string& fileName, std::string& stringAns)
{
    std::ofstream csvFile(fileName);

    csvFile << "A\n" << stringAns; // Header + string result in second row

    csvFile.close();
}

// Checks whether the second line of a CSV file matches the expected value
bool checkCsv(std::string& fileName, const std::string& expected)
{
    std::ifstream file(fileName);
    std::string line;
    std::getline(file, line); // Skip the header
    std::getline(file, line); // Read the second line
    file.close();
    return (line == expected); // Compare with expected string
}
