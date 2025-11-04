#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
        if (argc != 3) {
                cerr << "You entered the wrong number of arguments" << endl;
                cerr << "Use this program like this:" << endl;
                cerr << argv[0] << " <file to test> <number of testcases>" << endl;
                return 1;
        }

        string cmd;
        int n;
        try {
                n = stoi(argv[2]);
        }
        catch (invalid_argument e) {
                cerr << "The second parameter must be a positive integer (the number of testcases)" << endl;
                return 1;
        }

        for (int i = 1; i <= n; ++i) {
                cmd = argv[1];
                cmd.append(" < ");
                cmd.append(to_string(i));
                cmd.append(".in > ");
                cmd.append(to_string(i));
                cmd.append(".out");

                int ret = system(cmd.c_str());

                if (ret != 0) {
                        cerr << "Error executing '" << argv[1] << "'" << endl;
                        return 1;
                }

                ifstream ans(to_string(i) + ".ans");
                if (!ans.is_open()) {
                        cerr << "Error opening ans file on test" << i << endl;
                        return 1;
                }
                ifstream out(to_string(i) + ".out");
                if (!out.is_open()) {
                        cerr << "Error opening out file on test" << i << endl;
                        return 1;
                }

                string line, line2;
                while (getline(ans, line)) {
                        getline(out, line2);
                        if (line != line2) {
                                cout << "Discrepancies on test" << i << endl;
                                cout << "got: " << line2 << endl;
                                cout << "expected: " << line << endl;
                                return 2;
                        }
                }

                getline(out, line2);
                if (!out.eof()) {
                        cout << "Discrepancies on test" << i << endl;
                        cout << "got more output than expected" << endl;
                        return 2;
                }

                ans.close();
                out.close();
        }

        cout << "All tests successful" << endl;
        return 0;
}
