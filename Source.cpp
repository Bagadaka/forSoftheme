#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int count = 0;  // ������� ��� ���������� ������ ������
	int max = 0;    // ���������� ��� �������� ������������� ���������� ������ ������
	char symb;      // ���������� ��� �������� ��������� �������

	ifstream inputFile;
	inputFile.open("INPUT.TXT");

	if (inputFile.is_open())
	{
		inputFile.get(symb);
		while (!inputFile.eof())
		{
			if (symb == '1')
			{
				count++;
				if (count > max)  // ���� ������������������ ������ ������, ��� ��� ������������
					max = count;  // �� ������������� ����� ������������ ���������� ������ ������
			}
			
			if (symb == '0')   // ���� ���������� ����, 
				count = 0;     // �� �������� �������
			
			inputFile.get(symb);
		}
		inputFile.close();
	}
	else cout << "Unable to open file" << endl;

	ofstream outputFile;
	outputFile.open("OUTPUT.TXT");
	outputFile << max;
	outputFile.close();

	return 0;
}