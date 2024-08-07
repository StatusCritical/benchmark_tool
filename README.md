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

5. **Pi Calculation**
    - Calculates the value of pi.

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
=======
Benchmarking tool for windows, uses a multicore load and stress spikes to test system performance.\
Results may vary, but the tool is designed to give a general idea of how well a system can handle stress from some more common processes.\
Results may vary up to 1.5% between tests due to background programs.

Test 1: Matrix Multiplication\
    Multiplies two 250x250 matrices together.\
Test 2: Matrix Logic\
    Compares two 250x250 matrices together and writes result to a third matrix.\
Test 3: Console Print\
    Prints out a series of characters to the console to test print speed.\
Test 4: String Concatenation\
    Concatenates two strings together many times.\
Test 5: PI\
    Calculates PI.\
Test 6: Fibonacci\
    Calculates The Fibonacci Sequence.\
Test 7: Matrix Division\
    Divides two 250x250 matrices together.\
Test 8: Doubling\
 Takes a number and doubles it many times.\
Test 9: File Writing\
    Writes a matrix to a file on the disk.\
Test 10: Fibonacci The Second\
    Calculates The Fibonacci Sequence in the other direction.

Logs:\
Each test will have it's own log, stored in an auto created file called scoresN.txt, N being the test number.\
In case of a missing file, you may create the file yourself and store it in the same directory as the executable.
