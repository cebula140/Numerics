#pragma once
#include <dependencies/my_dynamic_array.hpp>
template <typename T, size_t rows, size_t columns>
class Matrix {
private:
	my_dynamic_array<T> data;
public:
	Matrix() {
		data = my_dynamic_array<T>(rows * columns, 0);
	}

    T& operator()(size_t i, size_t j) {
        return data[i * columns + j];
    }

    const T& operator()(size_t i, size_t j) const {
        return data[i * columns + j];
    }

    Matrix operator+(const Matrix& B) const {
        Matrix result;

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                result(i, j) = (*this)(i, j) + B(i, j);
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& B) const {
        Matrix result;

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                result(i, j) = (*this)(i, j) - B(i, j);
            }
        }

        return result;
    }

    Matrix operator*(T scalar) const {
        Matrix result;

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                result(i, j) = (*this)(i, j) * scalar;
            }
        }

        return result;
    }

    template <size_t C>
    Matrix<T, rows, C> operator*(const Matrix<T, columns, C>& B) const {
        Matrix<T, rows, C> result;

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < C; j++) {
                for (size_t k = 0; k < columns; k++) {
                    result(i, j) += (*this)(i, k) * B(k, j);
                }
            }
        }

        return result;
    }
};