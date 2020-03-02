#ifndef RushHourSolver_Table_HPP
#define RushHourSolver_Table_HPP

#include "Enums.hpp"
#include "Printing.hpp"

#include <array>

namespace RushHourSolver
{
struct Table
{
	// clang-format off
	/*
		The cells below represents this table:
		╔╗╔══╗╔╗
		║║║  ║║║
		║║║  ║║║
		╚╝╚══╝╚╝
		░░╔══╗░░
		░░╚══╝░░
		╔╗╔╗╔╗╔╗
		║║╚╝╚╝║║
		║║╔╗╔╗║║
		╚╝╚╝╚╝╚╝
		The solver will try to find a way to have the big block on top at the bottom.
	*/
	std::array<CellType, 4 * 5> cells{
		CellType::VLong1Top, CellType::BigTopLeft, CellType::BigTopRight, CellType::VLong2Top,
		CellType::VLong1Bot, CellType::BigBotLeft, CellType::BigBotRight, CellType::VLong2Bot,
		CellType::Empty,     CellType::HLongLeft,  CellType::HLongRight,  CellType::Empty,
		CellType::VLong3Top, CellType::Small1,     CellType::Small2,      CellType::VLong4Top,
		CellType::VLong3Bot, CellType::Small3,     CellType::Small4,      CellType::VLong4Bot,
	};
	// clang-format on

	inline CellType* at(int x, int y) noexcept;

	inline const CellType* at(int x, int y) const noexcept;

	inline bool swapUp(int x, int y);
	inline bool swapDown(int x, int y);
	inline bool swapLeft(int x, int y);
	inline bool swapRight(int x, int y);

	inline CellType& boundedAt(int x, int y) noexcept;
	inline CellType boundedAt(int x, int y) const noexcept;

	inline std::pair<int, int> findCell(CellType cell) const noexcept;

	inline void printSelf(std::ostream& os = std::cout) const;
};

inline bool operator==(const Table& lhs, const Table& rhs);
}  // namespace RushHourSolver

template <>
struct std::hash<RushHourSolver::Table>
{
	inline size_t operator()(const RushHourSolver::Table& key) const;
};

#include "Table.inl"

#endif	// RushHourSolver_Table_HPP
