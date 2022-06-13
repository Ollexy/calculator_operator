#include<iostream>
#include<string>

using namespace std;

int calculate(string s);
void calculator();

int main() {

    calculator();
        
    return 0;
}

int calculate(string s) {

    /*Firstly we will need some variables like sum for storing the result,
    last_result for storing the tempresults , last_operator for storing the last operator we saw while traversing
    and the base case can be when size of s is 0 */
    double sum = 0;
    long long last = 0, lastResult = 1;
    char lastOperator = '+'; //we need to remember the last operator

    //base case
    if (s.size() < 1) return sum;
    
    int i = 0, sign = 1;

    //going throught whole string
    while (i < s.size()) {
        //if there is a space - ignore it and go to next array
        if (s[i] == ' ') {
            ++i; continue;
        }

        /*If there is '+' or '-' we will add this with the last_result
        else If there is '/' or '*' we will upadte the last_operator as that operator*/
        if (s[i] == '+' || s[i] == '-') {
            sum += lastResult * sign;
            sign = s[i++] == '+' ? 1 : -1;  //question mark is something like "if statment"(this comment is for my own :D)
            lastResult = 1;
            lastOperator = '+';
        }
        else if (s[i] == '/' || s[i] == '*') {
            lastOperator = s[i];
            ++i;
        }

        /*Now while traversing if we found digits, we will pick it up
        and if the last_operator was * do last_result *= last else if the operator will be / then do last_result /= last;*/  
        if (isdigit(s[i])) {
            last = 0;
            while (i < s.size() && isdigit(s[i])) {
                last = last * 10 + s[i] - '0';
                i++;
            }
            if (lastOperator == '*') lastResult *= last;
            else if (lastOperator == '/') lastResult /= last;

            else  lastResult = last;
        }
    }
    sum += lastResult * sign;
    return sum;
}

void calculator() {
    int result;
    string mathOperation;

    cout << "Enter mathematical operation: ";
    getline(cin, mathOperation);
    cout << "\n";
    result = calculate(mathOperation);
    cout << mathOperation << " = " << result << endl;
}