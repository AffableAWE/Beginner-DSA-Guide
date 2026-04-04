#include<iostream>
#include<vector>
#include<string>

using namespace std;

class solution {
    public: 
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            backtrack(n, 0, 0, "", result);
            return result;
        }
    private:
        void backtrack(int n, int openN, int closedN, string current, vector<string>& result) {
            // Base Case
            if(openN == closedN && openN == n) {
                result.push_back(current);
                return;
            }

            // If we can still add an open parenthesis
            if(openN < n) {
                // Recursive call to add an open parenthesis and increase 'openN' count
                backtrack(n, openN + 1, closedN, current + "(", result);
            }

            // If we can add a closing parenthesis (only if there are more open parentheses)
            if(closedN < openN) {
                // Recursive call to add a closing parenthesis and increase 'closedN' count
                backtrack(n, openN, closedN + 1, current + ")", result);
            }
        }
};

int main() {
    solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    cout<< "Generated Parenthesis for  " << n << " : " << endl;
    for(const string&s : result) {
        cout<<s<<endl;
    }
}




