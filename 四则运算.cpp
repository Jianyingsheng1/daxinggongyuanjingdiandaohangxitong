#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_NUMBER = 100;

int random(int range) {
    return rand() % range + 1;
}

void generate_expression(int n, bool has_decimal, bool has_bracket, const string& operators,
                         int max_number, ostream& output) {
    for (int i = 0; i < n; i++) {
        int op_count = operators.size();
        int op_index = random(op_count) - 1;
        char op = operators[op_index];
        int a = random(max_number), b = random(max_number);
        if (has_decimal) {
            a += random(99) / 100.0;
            b += random(99) / 100.0;
        }
        output << a;
        if (has_bracket) {
            if (random(2) == 1) {
                output << " * (" << b;
                if (has_decimal) {
                    output << " + " << random(99) / 100.0;
                } else {
                    output << " + " << random(max_number);
                }
                output << ")";
            } else {
                output << " + (" << b;
                if (has_decimal) {
                    output << " + " << random(99) / 100.0;
                } else {
                    output << " + " << random(max_number);
                }
                output << ")";
            }
        } else {
            output << " " << op << " " << b;
        }
        output << " = " << endl;
    }
}

int main() {
    srand(time(nullptr));

    int n, max_number;
    bool has_decimal, has_bracket;
    string operators_str, output_file;

    cout << "��������Ŀ����: ";
    cin >> n;

    cout << "�����������: ";
    cin >> max_number;

    cout << "��Ŀ�Ƿ����С��(y/n)?: ";
    char ch;
    cin >> ch;
    has_decimal = (ch == 'y' || ch == 'Y');

    cout << "��Ŀ�Ƿ��������(y/n)?: ";
    cin >> ch;
    has_bracket = (ch == 'y' || ch == 'Y');

    cout << "��ѡ������������磺+-*/��: ";
    cin >> operators_str;

    cout << "��ѡ�������ʽ��1. �������Ļ    2. ������ļ�" << endl;
    int output_option;
    cin >> output_option;
    switch (output_option) {
        case 1: {
            generate_expression(n, has_decimal, has_bracket, operators_str, max_number, cout);
            break;
        }
        case 2: {
            cout << "����������ļ���: ";
            cin >> output_file;
            ofstream output(output_file);
            generate_expression(n, has_decimal, has_bracket, operators_str, max_number, output);
            output.close();
            break;
        }
        default: {
            cout << "��Ч��ѡ�" << endl;
            break;
        }
    }
	system("pause");
    return 0;
}