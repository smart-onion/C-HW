#include <iostream> 
#include <windows.h>
#include <io.h>
#include <bitset>
using namespace std;

int k = 0;

void all_files(string path, string mask)
{
	string temp = path;
	temp += mask;

	_finddata_t fileinfo;

	long long shapshot_number = _findfirst(temp.c_str(), &fileinfo);
	long long success = shapshot_number;

	while (success != -1)
	{
		// если папка:
		if (fileinfo.attrib & 16 &&
			string(fileinfo.name) != "." &&
			string(fileinfo.name) != "..")
		{
			string new_path = path;
			new_path += fileinfo.name;
			new_path += "\\";
			all_files(new_path, mask); // <<< recursive call
		}

		// если файл:
		else
		{
			if (string(fileinfo.name) != "." &&
				string(fileinfo.name) != ".." &&
				string(fileinfo.name).substr(string(fileinfo.name).find_last_of(".") + 1) == "txt")
			{
				bitset<32> set = fileinfo.attrib;
				cout << set << " - " << fileinfo.name << " " << string(fileinfo.name).find_last_of(".") << "\n";
				k++;
			}
		}

		success = _findnext(shapshot_number, &fileinfo);
	}

	_findclose(shapshot_number);
}

int main()
{
	system("title File Search");
	system("mode con cols=150 lines=50");
	setlocale(0, "");

	all_files("D:\\StepC++\\", "*.*");

	cout << "Total files count: " << k << "\n";
	system("pause");
}
