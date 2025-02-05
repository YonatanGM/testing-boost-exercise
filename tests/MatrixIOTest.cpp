#define BOOST_TEST_MODULE MatrixIOTest
#include <boost/test/unit_test.hpp>
#include <fstream>
#include "matrixIO.hpp"

// Helper function to create a test file
void createTestFile(const std::string &filename, const std::string &content)
{
  std::ofstream file(filename);
  file << content;
  file.close();
}

BOOST_AUTO_TEST_CASE(test_openData_valid)
{
  const std::string testFile = "test_valid.csv";
  createTestFile(testFile, "1.0,2.0,3.0\n4.0,5.0,6.0\n7.0,8.0,9.0\n");

  MatrixXd matrix = matrixIO::openData(testFile, 3);

  BOOST_CHECK_EQUAL(matrix.rows(), 3);
  BOOST_CHECK_EQUAL(matrix.cols(), 3);
  BOOST_CHECK_CLOSE(matrix(0, 0), 1.0, 1e-5);
  BOOST_CHECK_CLOSE(matrix(1, 1), 5.0, 1e-5);
  BOOST_CHECK_CLOSE(matrix(2, 2), 9.0, 1e-5);
}

BOOST_AUTO_TEST_CASE(test_openData_invalid_file)
{
  BOOST_CHECK_THROW(matrixIO::openData("nonexistent.csv", 3), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_openData_invalid_size)
{
  const std::string testFile = "test_invalid_size.csv";
  createTestFile(testFile, "1.0,2.0\n3.0,4.0\n5.0,6.0\n");

  BOOST_CHECK_THROW(matrixIO::openData(testFile, 3), std::runtime_error);
}
