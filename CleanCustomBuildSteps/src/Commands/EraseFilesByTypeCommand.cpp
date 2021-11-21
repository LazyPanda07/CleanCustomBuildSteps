#include "EraseFilesByTypeCommand.h"

#include <filesystem>

#include "Global.h"

using namespace std;

namespace commands
{
	void EraseFilesByTypeCommand::run(string_view path) const
	{
		const string_view& fileType = globals::arguments.back();
		string extension = fileType.contains('.') ? fileType.data() : "."s + fileType.data();
		filesystem::directory_iterator it(path);
		vector<filesystem::path> filesToRemove;

		for (const auto& i : it)
		{
			if (i.path().extension() == extension)
			{
				filesToRemove.push_back(i);
			}
		}

		ranges::for_each(filesToRemove, [](const filesystem::path& file) { filesystem::remove(file); });
	}
}
