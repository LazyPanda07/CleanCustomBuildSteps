#include "EraseFileCommand.h"

#include <filesystem>

using namespace std;

namespace commands
{
	void EraseFileCommand::run(string_view path) const
	{
		if (filesystem::exists(path))
		{
			filesystem::remove(path);
		}
	}
}
