#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// ���������
int generateRandomNumber(int max) {
    return rand() % max + 1;
}

// ���������
char generateOperator(const vector<char>& operators) {
    int index = rand() % operators.size();
    return operators[index];
}

// ���ɵ�����Ŀ
string generateProblem(int maxNumber, const vector<char>& operators, bool hasParentheses, bool hasDecimal) {
    int number1 = generateRandomNumber(maxNumber);
    int number2 = generateRandomNumber(maxNumber);
    char oper = generateOperator(operators);

    if (hasParentheses) {
        // ��������߼�
    }
    if (hasDecimal) {
        // ���С���߼�
    }

    // ������Ŀ�ַ���
    return to_string(number1) + " " + oper + " " + to_string(number2);
}

int main() {
    srand(time(NULL));

    int numProblems, maxNumber;
    vector<char> operators;
    bool hasParentheses, hasDecimal;
    string outputMethod;

    cout << "������Ŀ����: ";
    cin >> numProblems;
    cout << "ѡ������� (+, -, *, /)����������֮������ָ�: ";
    string temp;
    cin >> temp;
    for (char ch : temp) {
        operators.push_back(ch);
    }
    cout << "���������ֵ: ";
    cin >> maxNumber;
    cout << "�Ƿ�������� (1 = ��, 0 = ��): ";
    cin >> hasParentheses;
    cout << "�Ƿ����С�� (1 = ��, 0 = ��): ";
    cin >> hasDecimal;
    cout << "�����ʽ (����̨ = console, �ļ� = file): ";
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