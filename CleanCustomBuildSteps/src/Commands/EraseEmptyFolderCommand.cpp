#include "EraseEmptyFolderCommand.h"

#include <filesystem>

using namespace std;

namespace commands
{
	void EraseEmptyFolderCommand::run(string_view path) const
	{
		if (filesystem::is_empty(path))
		{
			filesystem::remove(path);
		}
	}
}
