/*
How the Single-Index Hack Works

When you write mat[r][c], the compiler parses it from
left to right as (mat[r])[c].mat[r] triggers your
overloaded operator[](size_t row), which performs
bounds checking on the row and returns a memory address
(T*) pointing exactly to the first element of that row.
The remaining [c] evaluates natively against that
returned pointer using standard C++ pointer arithmetic
(pointer + c), shifting right to the correct column.
Note: While elegant, a downside to this raw-pointer
method is that the secondary [c] step bypasses your
class logic, meaning column-level bounds checking cannot
be safely handled at runtime.
*/

#include "ArrayMatrix.h"
int main() {
    try {
        // Create two 2x2 matrices
        ArrayMatrix<int> A(2, 2);
        A[0][0] = 1; A[0][1] = 2;
        A[1][0] = 3; A[1][1] = 4;

        ArrayMatrix<int> B(2, 2);
        B[0][0] = 5; B[0][1] = 6;
        B[1][0] = 7; B[1][1] = 8;

        std::cout << "Matrix A:\n"; A.print();
        std::cout << "\nMatrix B:\n"; B.print();

        // 1. Test Addition
        ArrayMatrix<int> sum = A + B;
        std::cout << "\nResult of A + B:\n"; sum.print();

        // 2. Test Multiplication
        ArrayMatrix<int> product = A * B;
        std::cout << "\nResult of A * B:\n"; product.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    // Use streams to init and output
    // Create a 2x3 matrix
    ArrayMatrix<int> mat(2, 3);

    // Prompt user input using standard stream extraction
    std::cout << "Enter 6 integer values for a 2x3 matrix (separated by spaces or newlines):\n";
    std::cin >> mat;

    // Output the matrix formatting cleanly via custom insertion stream
    std::cout << "\nYou entered the following matrix:\n";
    std::cout << mat;

    return 0;
}