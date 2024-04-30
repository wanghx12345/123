#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// 生成随机数
int generateRandomNumber(int max) {
    return rand() % max + 1;
}

// 生成运算符
char generateOperator(const vector<char>& operators) {
    int index = rand() % operators.size();
    return operators[index];
}

// 生成单个题目
string generateProblem(int maxNumber, const vector<char>& operators, bool hasParentheses, bool hasDecimal) {
    int number1 = generateRandomNumber(maxNumber);
    int number2 = generateRandomNumber(maxNumber);
    char oper = generateOperator(operators);

    if (hasParentheses) {
        // 添加括号逻辑
    }
    if (hasDecimal) {
        // 添加小数逻辑
    }

    // 生成题目字符串
    return to_string(number1) + " " + oper + " " + to_string(number2);
}

int main() {
    srand(time(NULL));

    int numProblems, maxNumber;
    vector<char> operators;
    bool hasParentheses, hasDecimal;
    string outputMethod;

    cout << "输入题目数量: ";
    cin >> numProblems;
    cout << "选择运算符 (+, -, *, /)，多个运算符之间无需分隔: ";
    string temp;
    cin >> temp;
    for (char ch : temp) {
        operators.push_back(ch);
    }
    cout << "设置最大数值: ";
    cin >> maxNumber;
    cout << "是否包含括号 (1 = 是, 0 = 否): ";
    cin >> hasParentheses;
    cout << "是否包含小数 (1 = 是, 0 = 否): ";
    cin >> hasDecimal;
    cout << "输出方式 (控制台 = console, 文件 = file): ";
    cin >> outputMethod;

    vector<string> problems;
    for (int i = 0; i < numProblems; ++i) {
        problems.push_back(generateProblem(maxNumber, operators, hasParentheses, hasDecimal));
    }

    if (outputMethod == "console") {
        for (const auto& problem : problems) {
            cout << problem << endl;
        }
    }
    else if (outputMethod == "file") {
        ofstream outFile("problems.txt");
        for (const auto& problem : problems) {
            outFile << problem << endl;
        }
        outFile.close();
    }

    return 0;
}