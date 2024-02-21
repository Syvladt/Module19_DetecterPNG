#include <iostream>
#include <fstream>
#include <string>

int main()
{
	char beg[4];
	std::string fileName;
	std::ifstream src;
	std::cout << "Enter file name: ";
	std::getline(std::cin, fileName);
	if (fileName.substr(fileName.length() - 4, fileName.length()) == ".png")
	{
		src.open(fileName, std::ios::binary);
		if (src.is_open())
		{
			src.read(beg, 4);
			if (beg[0] == -119 && beg[1] == 'P' && beg[2] == 'N' && beg[3] == 'G')
				std::cout << "It PNG file.\n";
			else
				std::cout << "It no PNG file.\n";
		}
		else
			std::cout << "File " << fileName << " is not exist.\n";
		src.close();
	}
	else
		std::cout << "It no PNG file.\n";
}