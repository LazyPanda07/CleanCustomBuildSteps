#pragma once

#include "ICommand.h"

namespace commands
{
	class EraseFileCommand : public ICommand
	{
	public:
		EraseFileCommand() = default;

		void run(std::string_view path) const override;

		~EraseFileCommand() = default;
	};
}
