Benchmarking tool for windows, uses a multicore load and stress spikes to test system performance.\
Results can vary, but the tool is designed to give a general idea of how well a system can handle stress from some more common processes.\
Results can vary from 1.5% between tests due to background programs.

Test 1: Matrix Multiplication\
    Multiplies two 250x250 matrices together.\
Test 2: Matrix Logic\
    Compares two 250x250 matrices together and writes result to a third matrix.\
Test 3: Console Print\
    Prints out a series of characters t the console to test print speed.\
Test 4: String Concatenation\
    Concatenates two strings together many times.\
Test 5: Pi\
    Calculates pi.\
Test 6: Fibonacci\
    Calculates a fibonacci sequence.\
Test 7: Matrix Division\
    Divides two 250x250 matrices together.\
Test 8: Doubling\
 Takes a number and doubles it many times.\
Test 9: File Writing\
    Writes a matrix to a file on disk.\
Logs:\
Each test has its own log, stored in an auto created file called scoresN.txt, N being the test number.\