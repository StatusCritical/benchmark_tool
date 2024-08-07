# **Benchmarking Tool for Windows**

This benchmarking tool for Windows uses a multicore load and stress spikes to test system performance. While results can vary due to background programs, the tool provides a general idea of how well a system can handle stress from common processes.

## **Tests**

1. **Matrix Multiplication**
    - Multiplies two 250x250 matrices together.

2. **Matrix Logic**
    - Compares two 250x250 matrices and writes the result to a third matrix.

3. **Console Print**
    - Prints a series of characters to the console to test print speed.

4. **String Concatenation**
    - Concatenates two strings together many times.

5. **PI Calculation**
    - Calculates the value of π.

6. **Fibonacci Sequence**
    - Calculates a Fibonacci sequence.

7. **Matrix Division**
    - Divides two 250x250 matrices together.

8. **Doubling**
    - Takes a number and doubles it many times.

9. **File Writing**
    - Writes a matrix to a file on disk.

10. **Fibonacci The Second**
    - Calculates a Fibonacci sequence in the other direction.

## **Logs**

Each test generates its own log, stored in an automatically created file named `scoresN.txt`, where `N` is the test number. If a log file is missing, you can create it manually and place it in the same directory as the executable.
