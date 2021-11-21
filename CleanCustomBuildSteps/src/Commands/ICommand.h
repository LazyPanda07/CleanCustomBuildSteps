#pragma once

#include <string_view>

namespace commands
{
	class ICommand
	{
	public:
		ICommand() = default;

		virtual void run(std::string_view path) const = 0;

		virtual ~ICommand() = default;
	};
}
