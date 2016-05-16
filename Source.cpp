#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int count = 0;  // счетчик для количества единиц подряд
	int max = 0;    // переменная для хранения максимального количества единиц подряд
	char symb;      // переменная для хранения считаного символа

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
				if (count > max)  // если последовательность единиц больше, чем уже существующая
					max = count;  // то устанавливаем новое максимальное количество единиц подряд
			}
			
			if (symb == '0')   // если встретился ноль, 
				count = 0;     // то обнуляем счетчик
			
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