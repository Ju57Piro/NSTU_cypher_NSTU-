#include "Caesar's_cipher.h"

std::string Encryption(std::string text, int n)
{
	setlocale(LC_ALL, "Russian");
	char d1[33] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	char d2[33] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	size_t length = text.length();
	int p = length - 1;
	int k = -1;
	int u;
	char sym;
	std::string result;

	while (k < p) {
		k += 1;

		for (int s = 0; s < 33; s++) {
			sym = text.at(k);
			u = s + n;

			while (u >= 33) {
				u = u - 33;
			}

			if (sym == d1[s]) {

				result.push_back(d1[u]);
				break;
			}

			if (sym == d2[s]) {
				result.push_back(d2[u]);
				break;
			}
			if ((sym != d1[s] || sym != d2[s]) && s == 32) {
				result.push_back(sym);
				break;
			}
		}

	}
	return result;
}


std::string Decryption(std::string text, int n) {
	char d1[33] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	char d2[33] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	size_t length = text.length();
	int p = length - 1;
	int k = -1;
	int u;
	char sym;
	std::string result;
	while (k < p) {
		k += 1;

		for (int s = 0; s < 33; s++) {
			sym = text.at(k);
			u = s - n;
			while (u < 0) {
				u = u + 33;
			}
			if (sym == d1[s]) {

				result.push_back(d1[u]);
				break;
			}

			if (sym == d2[s]) {
				result.push_back(d2[u]);
				break;
			}

			if ((sym != d1[s] || sym != d2[s]) && s == 32) {
				result.push_back(sym);
				break;
			}
		}
	}
	return result;
}