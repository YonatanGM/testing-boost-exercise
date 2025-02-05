#define BOOST_TEST_MODULE SideMadeTests
#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "MatrixSolver.hpp"

using namespace Eigen;

struct MatrixSolverFixture {
  MatrixSolverFixture()
  {
    A = MatrixXd(3, 3);
    A << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    b = VectorXd(3);
    b << 3.5, 11, 18.5;

    expectedX = VectorXd(3);
    expectedX << 2, 0, 0.5;
  }

  MatrixXd A;
  VectorXd b;
  VectorXd expectedX;
};

BOOST_FIXTURE_TEST_SUITE(MatrixSolverTests, MatrixSolverFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(LU)
{
  MatrixSolver solver(MatrixSolver::LU);
  VectorXd     x(3);
  solver.solve(A, b, x);

  BOOST_TEST(x(0) == expectedX(0));
  BOOST_TEST(x(1) == expectedX(1));
  BOOST_TEST(x(2) == expectedX(2));
}

BOOST_AUTO_TEST_CASE(QR)
{
  MatrixSolver solver(MatrixSolver::QR);
  VectorXd     x(3);
  solver.solve(A, b, x);

  BOOST_TEST(x(0) == expectedX(0));
  BOOST_TEST(x(1) == expectedX(1));
  BOOST_TEST(x(2) == expectedX(2));
}

BOOST_AUTO_TEST_CASE(LU2)
{
  MatrixSolver solver(MatrixSolver::LU2);
  VectorXd     x(3);
  solver.solve(A, b, x);

  BOOST_TEST(x(0) == expectedX(0));
  BOOST_TEST(x(1) == expectedX(1));
  BOOST_TEST(x(2) == expectedX(2));
}

BOOST_AUTO_TEST_SUITE_END()
