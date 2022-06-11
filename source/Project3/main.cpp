#include "cypher.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    bool check = false;
    while (check == false) {
        std::cout << "������� ������ ��� ������� � ���������: ";
        std::string pas = "1111";
        std::string user_pas;
        std::cin >> user_pas;
        if (user_pas == pas) {
            check = true;
        }
    }
    std::cout << std::endl;
    std::string text, tem_str, file_name1, file_name2, result;
    std::vector<std::string> matr;
    std::ifstream file; //������� ���� ��� �����
    std::ofstream out; //��� ������
    int user_input, n;
    bool check2 = false;
    while (check) {
        while (true) {
            do {
                std::cout << "������� ��� ����� ��� ������: ";
                std::cin >> file_name1;
                std::cout << std::endl;
                file.open(file_name1);
                if (!file.is_open()) { // ���� ���� �� ������
                    std::cout << "���� �� ����� ���� ������!\n \n";
                }
                else { //���� ������
                    while (true) {
                        getline(file, tem_str);
                        text += tem_str;
                        if (!file == '\0') {
                            text.push_back('\n');
                        }
                        if (file.eof()) {
                            break;
                        }
                    }
                } //���������� ����� � ������
            } while (!file.is_open());

            do
            {
                std::cout << "������� ��� ����� ��� ������: ";
                std::cin >> file_name2;
                std::cout << std::endl;
                out.open(file_name2);
                if (!file.is_open()) {// ���� ���� �� ������
                    std::cout << "���� �� ����� ���� ������!\n \n";
                }
            } while (!file.is_open());
            std::cout << "�������� ����� ������: \n 1.���������� ����� \n 2.��������������� ����� \n 3. ��������� ������" << std::endl;
            std::cout << "����: ";
            std::cin >> user_input;
            std::cout << std::endl;
            switch (user_input) {
            case 1:
                std::cout << "�������� ��� ����������: \n";
                std::cout << "1.���������� ������� ������ \n";
                std::cout << "2.���������� ��������� ������� \n";
                std::cout << "3.���������� ��������� �������" << std::endl;
                std::cout << "����: ";
                std::cin >> user_input;
                std::cout << std::endl;
                int size;
                switch (user_input)
                {
                case 1:
                    do {
                        std::cout << "������� ����� ��� ����� ������ ������ 0:";
                        std::cin >> n;
                        std::cout << std::endl;
                        if (n >= 0) {
                            check2 = true;
                        }
                    } while (check2 == false);
                    result = Encryption(text, n);
                    out << result;
                    std::cout << "���������� ������� ��������� �: " << file_name2 << "\n \n";
                    break;
                case 2:
                    result = Tabl(text);
                    out << result;
                    std::cout << "���������� ������� ��������� �: " << file_name2 << "\n \n";
                    break;
                case 3:
                    matr = matrix(&text);
                    size = size_of_matrix(text);
                    result = matrix_to_string(matr, size);
                    out << result;
                    std::cout << "���������� ������� ��������� �: " << file_name2 << "\n \n";
                    break;
                default:
                    std::cout << "������������ ������" << std::endl;
                }
                break;
            case 2:
                std::cout << "�������� ��� ����������: \n";
                std::cout << "1.���������� ������� ������ \n";
                std::cout << "2.���������� ��������� ������� \n";
                std::cout << "3.���������� ��������� �������" << std::endl;
                std::cout << "����: ";
                std::cin >> user_input;
                std::cout << std::endl;
                switch (user_input) {
                case 1:
                    do {
                        std::cout << "������� ����� ��� ����� ������ ������ 0" << std::endl;
                        std::cin >> n;
                        if (n >= 0) {
                            check2 = true;
                        }
                    } while (check2 == false);
                    result = Decryption(text, n);
                    out << result;
                    std::cout << "������������ ������� ��������� �: " << file_name2 << "\n \n";
                    break;
                case 2:
                    result = DecShif(text);
                    out << result;
                    std::cout << "������������ ������� ��������� �: " << file_name2 << "\n \n";
                    break;
                case 3:
                    result = decrypt_matrix(text);
                    out << result;
                    std::cout << "������������ ������� ��������� �: " << file_name2 << "\n \n";
                    break;
                default:
                    std::cout << "������������ ������" << std::endl;
                }
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