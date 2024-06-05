# SE4HPCproject - Step 1 Testing

This part of the assignement involves the dynamic analysis of the matrix multiplication library, through **googletest**.

## Overview 
The test suite is composed of two parts:
- **Fixed input tests**, in which we were able to trigger all the errors based on the multiplication of canonical matrices structures and ad hoc inputs.
-  **Randomized input tests**, to get an initial overview of the problem and triggering errors through basic structures with randomized values (with respect to a generator and a seed).

## Compiling
```bash
chmod a+x build.sh
./build.sh
```
## Running 
Here it is a command to run the tests, showing only googletest outputs, and printing out the number of errors.

```bash
./build/test_multiplication 2> program.stderr 
#./build/seed_test_multiplication 2> program.stderr 
./count_errors.sh program.stderr
```
