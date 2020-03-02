#ifndef RushHourSolver_Enums_HPP
#define RushHourSolver_Enums_HPP

#include <cstdint>
#include <utility>

namespace RushHourSolver
{
enum class CellKind : uint16_t
{
	Empty,
	VLongTop,
	VLongBot,
	HLongLeft,
	HLongRight,
	Small,
	BigTopLeft,
	BigTopRight,
	BigBotLeft,
	BigBotRight,
	MAX
};

enum class CellType : uint32_t
{
	Empty,
	VLong1Top,
	VLong1Bot,
	VLong2Top,
	VLong2Bot,
	VLong3Top,
	VLong3Bot,
	VLong4Top,
	VLong4Bot,
	HLongLeft,
	HLongRight,
	Small1,
	Small2,
	Small3,
	Small4,
	BigTopLeft,
	BigTopRight,
	BigBotLeft,
	BigBotRight,
	MAX
};

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

CellKind cellTypeToKind(CellType type) noexcept
{
	if (type == CellType::VLong1Top || type == CellType::VLong2Top ||
		type == CellType::VLong3Top || type == CellType::VLong4Top)
		return CellKind::VLongTop;

	else if (type == CellType::VLong1Bot || type == CellType::VLong2Bot ||
			 type == CellType::VLong3Bot || type == CellType::VLong4Bot)
		return CellKind::VLongBot;

	else if (type == CellType::HLongLeft)
		return CellKind::HLongLeft;

	else if (type == CellType::HLongRight)
		return CellKind::HLongRight;

	else if (type == CellType::Small1 || type == CellType::Small2 ||
			 type == CellType::Small3 || type == CellType::Small4)
		return CellKind::Small;

	else if (type == CellType::BigTopLeft)
		return CellKind::BigTopLeft;
	else if (type == CellType::BigTopRight)
		return CellKind::BigTopRight;
	else if (type == CellType::BigBotLeft)
		return CellKind::BigBotLeft;
	else if (type == CellType::BigBotRight)
		return CellKind::BigBotRight;

	else
		return CellKind::Empty;
}
}  // namespace RushHourSolver

template <>
constexpr void std::swap(RushHourSolver::Direction& l,
						 RushHourSolver::Direction& r) noexcept
{
	RushHourSolver::Direction t = l;
	l = r;
	r = t;
}

#endif	// !RushHourSolver_Enums_HPP
