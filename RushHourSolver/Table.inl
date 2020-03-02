#ifndef RushHourSolver_Table_INL
#define RushHourSolver_Table_INL

namespace RushHourSolver
{
inline CellType* Table::at(int x, int y) noexcept
{
	if (x >= 0 && x < 4 && y >= 0 && y < 5)
		return &cells[x + y * 4];
	else
		return nullptr;
}

inline const CellType* Table::at(int x, int y) const noexcept
{
	if (x >= 0 && x < 4 && y >= 0 && y < 5)
		return &cells[x + y * 4];
	else
		return nullptr;
}

inline bool Table::swapUp(int x, int y)
{
	CellType* cur = at(x, y);
	CellType* oth = at(x, y - 1);

	if (!cur || !oth)
		return false;

	std::swap(*cur, *oth);

	return true;
}

inline bool Table::swapDown(int x, int y)
{
	CellType* cur = at(x, y);
	CellType* oth = at(x, y + 1);

	if (!cur || !oth)
		return false;

	std::swap(*cur, *oth);

	return true;
}

inline bool Table::swapLeft(int x, int y)
{
	CellType* cur = at(x, y);
	CellType* oth = at(x - 1, y);

	if (!cur || !oth)
		return false;

	std::swap(*cur, *oth);

	return true;
}

inline bool Table::swapRight(int x, int y)
{
	CellType* cur = at(x, y);
	CellType* oth = at(x + 1, y);

	if (!cur || !oth)
		return false;

	std::swap(*cur, *oth);

	return true;
}

inline CellType& Table::boundedAt(int x, int y) noexcept
{
	if (x < 0)
		x = 0;
	if (x >= 4)
		x = 3;
	if (y < 0)
		y = 0;
	if (y >= 5)
		y = 4;

	return cells[x + y * 4];
}

inline CellType Table::boundedAt(int x, int y) const noexcept
{
	if (x < 0)
		x = 0;
	if (x >= 4)
		x = 3;
	if (y < 0)
		y = 0;
	if (y >= 5)
		y = 4;

	return cells[x + y * 4];
}

inline std::pair<int, int> Table::findCell(CellType cell) const noexcept
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (boundedAt(x, y) == cell)
				return std::make_pair(x, y);
		}
	}

	exit(1);
}

inline void Table::printSelf(std::ostream& os) const
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 4; x++)
			printRow1(boundedAt(x, y));

		os << "\n";

		for (int x = 0; x < 4; x++)
			printRow2(boundedAt(x, y));

		os << "\n";
	}
}

inline bool operator==(const Table& lhs, const Table& rhs)
{
	return std::memcmp(lhs.cells.data(), rhs.cells.data(),
					   sizeof(*lhs.cells.data()) * lhs.cells.size()) == 0;
}
}  // namespace RushHourSolver

inline size_t std::hash<RushHourSolver::Table>::operator()(
	const RushHourSolver::Table& key) const
{
	std::hash<uint16_t> hasher;
	size_t result = 0;
	for (uint8_t i = 0; i < 20; ++i)
	{
		result =
			(result << 1) ^
			hasher(uint16_t(RushHourSolver::cellTypeToKind(key.cells[i])));
	}
	return result;
}

#endif	// RushHourSolver_Table_INL
