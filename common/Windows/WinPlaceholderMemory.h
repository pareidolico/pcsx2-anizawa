// SPDX-FileCopyrightText: 2002-2026 PCSX2 Dev Team
// SPDX-License-Identifier: GPL-3.0+

#pragma once

#include "common/RedtapeWindows.h"

// The placeholder memory APIs only exist on Windows 10 1803 and newer. They're resolved at runtime
// instead of being imported, otherwise the executable won't even load on Windows 8.1.
namespace WinPlaceholderMemory
{
	struct Functions
	{
		decltype(&::VirtualAlloc2) VirtualAlloc2;
		decltype(&::MapViewOfFile3) MapViewOfFile3;
		decltype(&::UnmapViewOfFile2) UnmapViewOfFile2;
	};

	/// Returns nullptr if the OS doesn't support placeholders.
	const Functions* Get();
} // namespace WinPlaceholderMemory
