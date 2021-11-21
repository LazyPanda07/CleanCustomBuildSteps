#include <iostream>
#include <unordered_map>
#include <memory>

#include "Global.h"

#include "Commands/EraseEmptyFolderCommand.h"
#include "Commands/EraseFileCommand.h"
#include "Commands/EraseFilesByTypeCommand.h"

using namespace std;

int main(int argc, char** argv)
{
	unordered_map<string_view, unique_ptr<commands::ICommand>> cleanCommands;

	if (argc == 1)
	{
		cout << "Undefined command" << endl;

		return -1;
	}

	cleanCommands["erase_empty_folder"sv] = make_unique<commands::EraseEmptyFolderCommand>();
	cleanCommands["erase_file"sv] = make_unique<commands::EraseFileCommand>();
	cleanCommands["erase_files_by_type"sv] = make_unique<commands::EraseFilesByTypeCommand>();

	if (argc > 2)
	{
		for (size_t i = 3; i < argc; i++)
		{
			globals::arguments.push_back(argv[i]);
		}
	}

	cleanCommands.at(argv[1])->run(argv[2]);

	return 0;
}
