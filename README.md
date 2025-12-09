# CPTester
### A command line program that automatically tests another program
### Please note that CPTester currently only works on Windows
## What exactly is CPTester?
This project is intended to be used to automate the testing of another program.
It is acomplished using `.in`-files and `.ans`-files that contain the expected input and output of the program in plain-text format.
The program expects these files to be named `x.in` and `x.ans` where x is the number of the testcase (starting with 1).
This is usefull in scenarios like some compeditive programming exercises where the code needs to pass predefined public tests.

## How to install CPTester
To install the project simply fork it to a local drive, navigate to its src-folder and compile it using g++ with the following command
```
g++ cptester.cpp -o cptester
```

## How to use CPTester
To use cptester simply type the following command
```
cptester <file to test> <total number of testcases>
```
For each testcase the program executes the file that is supposed to be tested and pipes in the input (as `<number of testcase>.in`-file) and pipes the output (to a `<number of testcase>.out`-file). Afterwards it compares the `<number of testcase>.out`-file to a `<number of testcase>.ans`-file notifying the user if there are discrepancies.

## How to contribute
Contribution to this project is not possible at the current point in time.

## Known Issues
This project currently only works on windows. If you find issues feel free to report them [here](https://github.com/KILI-BC/CPTester/issues). I might fix them if I get arround to it.
