#pragma once

#include "ICommand.h"

namespace commands
{
	class EraseEmptyFolderCommand : public ICommand
	{
	public:
		EraseEmptyFolderCommand() = default;

		void run(std::string_view command) const override;

		~EraseEmptyFolderCommand() = default;
	};
}
