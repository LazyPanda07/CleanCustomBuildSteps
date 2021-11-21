#pragma once

#include "ICommand.h"

namespace commands
{
	class EraseFilesByTypeCommand : public ICommand
	{
	public:
		EraseFilesByTypeCommand() = default;

		void run(std::string_view path) const override;

		~EraseFilesByTypeCommand() = default;
	};
}
