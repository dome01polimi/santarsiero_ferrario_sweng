# SE4HPCproject - Step 1 Testing

The goal is to test a specific buggy implementation of the matrix
multiplication software. Your objectives are:

-   To identify test cases able to spot the errors and

-   To automate the execution of tests through Google Test.

The implementation to be tested is a matrix multiplication function made
available as a compiled object code. The function has the following
signature:

void multiplyMatrices(const std::vector\<std::vector\<int\>\>& A,
const std::vector\<std::vector\<int\>\>& B,
std::vector\<std::vector\<int\>\>& C, int rowsA, int colsA, int colsB);

Use the template available here
<https://github.com/SimoneReale/SE4HPC_project_part1> to create your own
github repository. The project includes:

-   The matrix multiplication object code in the library
    libmatrix_multiplication.a under the lib folder.

-   The header defining the matrix multiplication signature under the
    include folder.

-   The file test_matrix_multiplication.cpp under folder test that
    contains a simple example of test case.

-   The makefile you can use for building the software.

-   The file matrix_mult.cpp under folder src that includes a correct
    implementation of the matrix multiplication you can use as a
    reference

Your task is extending the file test_matrix_multiplication.cpp with your
test cases. Please insert proper comments in the code to explain why you
have selected that specific test case and the behaviour you expect from
it. Push the result of your work in your repo. If your local environment
does not allow you to create a correct build, consider using the GitHub
actions and their runners. This will be useful also for your next task.
