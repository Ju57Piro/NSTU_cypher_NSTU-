#include "cypher.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    bool check = false;
    while (check == false) {
        check = pas();
    }
    std::cout << std::endl;
    std::string text, tem_str, result, file_name2;
    std::vector<std::string> matr;
    std::ifstream file; //������� ���� ��� �����
    std::ofstream out; //��� ������
    int user_input, n;
    bool check2 = false;
    while (check) {
        while (true) {
            file = readfile();//��������� ���� ��� ������
            while (true) {
                getline(file, tem_str);
                text += tem_str;
                if (!file == '\0') {
                    text.push_back('\n');
                }
                if (file.eof()) {
                    break;
                }
            } // ���� � ������
            out = printfile(file_name2);//��������� ���� ��� ������
            std::cout << "�������� ����� ������: \n 1.���������� ����� \n 2.��������������� ����� \n 3. ��������� ������" << std::endl;
            std::cout << "����: ";
            std::cin >> user_input;
            std::cout << std::endl;
            switch (user_input) {
            case 1:
                user_input = type_selection();
                encr(out, check2, result, text, user_input, file_name2); //�������� ������ ��� ��������� ��������
                break;
            case 2:
                user_input = type_selection();
                decr(out, check2, result, text, user_input, file_name2);
                break;
            case 3:
                std::cout << "������� �� ������������� ����� ���������." << std::endl;
                file.close();
                out.close();
                return 0;
            default:
                std::cout << "������������ ������" << std::endl;
            }
            text.clear();
            result.clear();
            file.close();
            out.close();
        }
    }
    return 0;
}