#include "write_segment.h"

std::string write_segment(std::vector<std::string> matrix, int dir, int step, int& i, int& j)
{
	std::string res;
	switch (dir)
	{
	case 0: //�����
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			i--;
		}
		break;
	case 1: //�����
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			j--;
		}
		break;
	case 2: //����
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			i++;
		}
		break;
	case 3: //������
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			j++;;
		}
		break;
	}
	return res;
}
