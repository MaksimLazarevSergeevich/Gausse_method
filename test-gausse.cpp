#include <gtest/gtest.h>
#include "gausse_metod.h"

TEST(gausTest, OneAnswer)
{
    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(3, 4);
    mat << 2, 1, -1, 8,
           -3, -1, 2, -11,
           -2, 1, 2, -3;

    Eigen::MatrixXd initial_matrix = mat; // After the Gaussian method, the mat will change

    std::string csvAns("answer.csv");
    solveGause(mat, csvAns);

    Eigen::MatrixXd answerMatrix(loadMatrix(csvAns)); // A matrix that wrote from csv the answers 

    int rows = mat.rows();

    for (int i = 0; i < rows; i++)
    {
        double sum(0);
        for (int j = 0; j < rows; j++)
        {
            sum += initial_matrix(i, j) * answerMatrix(j, 0);
        }
        // The sum is calculated and then compared to the element b from the expanded matrix
        ASSERT_EQ(initial_matrix(i, rows), std::round(sum)); // Since double has an error, it is rounded off
    }
}

TEST(gausTest, InfinityAnswer)
{
    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(2, 3);
    mat << 1, -2, 1,
           2, -4, 2;

    std::string csvAns("answer.csv");
    std::string stringAns("infinite number of solutions");
    solveGause(mat, csvAns);

    ASSERT_TRUE(checkCsv(csvAns, stringAns));
}

TEST(gausTest, NoAnsTest)
{
    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(2, 3);
    mat << 1, -2, 3,
           2, -4, 7;
    
    Eigen::MatrixXd initial_matrix = mat;

    std::string csvAns("answer.csv");
    std::string stringAns("There are no solutions");
    solveGause(mat, csvAns);

    ASSERT_TRUE(checkCsv(csvAns, stringAns));
}

TEST(gausTest, RandomTest_1)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

TEST(gausTest, RandomTest_2)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

TEST(gausTest, RandomTest_3)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

TEST(gausTest, RandomTest_4)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

TEST(gausTest, RandomTest_5)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

TEST(gausTest, RandomTest_6)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

TEST(gausTest, RandomTest_7)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

TEST(gausTest, RandomTest_8)
{
    std::string csvName = "matrix.csv";
    std::string csvAns = "answer.csv";
    generateMatrix(csvName);

    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> mat(loadMatrix(csvName));
    Eigen::MatrixXd initial_matrix = mat;

    solveGause(mat, csvAns);

    if (checkCsv(csvAns, "Infinity"))
    {
        SUCCEED();
    }
    else if (checkCsv(csvAns, "There are no solutions"))
    {
        SUCCEED();
    }
    else
    {
        Eigen::MatrixXd answerMatrix(loadMatrix(csvAns));

        int rows = mat.rows();

        for (int i = 0; i < rows; i++)
        {
            double sum(0);
            for (int j = 0; j < rows; j++)
            {
                sum += initial_matrix(i, j) * answerMatrix(j, 0);
            }
            std::cout << initial_matrix(i, rows) << "  " << std::round(sum) << '\n';
            ASSERT_EQ(initial_matrix(i, rows), std::round(sum));
        }
    }
}

