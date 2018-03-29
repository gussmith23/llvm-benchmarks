#include <iostream>
#include <cassert>

template<typename T, unsigned int R, unsigned int C>
class Matrix;

template<typename T, unsigned int R, unsigned int C>
std::ostream& operator<<(std::ostream& os, const Matrix<T,R,C>& rhs);

template<typename T, unsigned int R, unsigned int C>
class Matrix {
  public:
    
    template<unsigned int C2> 
    Matrix<T,R,C2> operator*(Matrix<T,C,C2> rhs) {
      Matrix<T,R,C2> out;
      for (size_t row_i = 0; row_i < R; row_i++) {
        for (size_t col_i = 0; col_i < C2; col_i++) {
          T accumulator = 0;
          for (size_t elem_i = 0; elem_i < C; elem_i++) {
            accumulator += data[row_i*C + elem_i] * rhs.data[elem_i*C2 + col_i];
          }
          out.data[row_i*C2+col_i] = accumulator;
        }
      }
      return out;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T,R,C>& rhs) {
      for (size_t row_i = 0; row_i < R; row_i++) {
        for (size_t col_i = 0; col_i < C; col_i++) {
          os << rhs.data[row_i*C+col_i] << " ";
        }
        os << std::endl;
      }
      return os;
    }

    T data[R*C];
};

int main() {
  Matrix<int,2,2> A;
  A.data[0] = 1;
  A.data[1] = 2;
  A.data[2] = 3;
  A.data[3] = 4;
  Matrix<int,2,2> B;
  B.data[0] = 1;
  B.data[1] = 0;
  B.data[2] = 0;
  B.data[3] = 1;
  Matrix<int,2,2> C = A*B;
  std::cout << A << "*" << std::endl << B << "=" << std::endl << C;
}

