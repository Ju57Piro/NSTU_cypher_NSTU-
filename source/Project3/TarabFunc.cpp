#include <iostream>
#include "TarabFunc.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>


std::string tarabar_decr(std::string S3)
{
    setlocale(LC_ALL, "Russian");
    std::vector<char>Case = {  '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    std::vector<char>Symbol = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
    std::string S2;
    for (int i = 0; i < S3.length(); i++) {
        std::pair<bool, int> result = findInVector(Symbol, S3[i]);
        if (result.first) {
            S2.push_back(Case[result.second]);
        }
        else {
            S2.push_back(S3[i]);
        }

    }

    return S2;

}
std::string tarabar_encr(std::string S1)
{
    setlocale(LC_ALL, "Russian");
    std::vector<char>Case = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
    std::vector<char>Symbol = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
    std::string S2;
    for (int i = 0; i < S1.length(); i++) {
        std::pair<bool, int> result = findInVector(Case, S1[i]);
        if (result.first) {
            S2.push_back(Symbol[result.second]);
        }
        else {
            S2.push_back(S1[i]);
        }

    }

    return S2;
}