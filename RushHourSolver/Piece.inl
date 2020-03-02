#ifndef RushHourSolver_Printing_INL
#define RushHourSolver_Printing_INL

namespace RushHourSolver
{
template <size_t N>
bool IPiece::canMove(const Table& table,
					 Direction direction,
					 const std::array<CellType, N>& cells) const
{
	switch (direction)
	{
	case Direction::Up:
		return canMoveUp(table, cells);
	case Direction::Down:
		return canMoveDown(table, cells);
	case Direction::Left:
		return canMoveLeft(table, cells);
	case Direction::Right:
		return canMoveRight(table, cells);
	}
}

template <size_t N>
bool IPiece::canMoveUp(const Table& table,
					   const std::array<CellType, N>& cells) const
{
	for (auto cell : cells)
	{
		if (cell == CellType::VLong1Bot || cell == CellType::VLong2Bot ||
			cell == CellType::VLong3Bot || cell == CellType::VLong4Bot ||
			cell == CellType::BigBotLeft || cell == CellType::BigBotRight)
			continue;

		auto [x, y] = table.findCell(cell);

		const CellType* upCell = table.at(x, y - 1);

		if (!upCell)  // is a wall
			return false;
		else if (*upCell != CellType::Empty)
			return false;
	}

	return true;
}

template <size_t N>
bool IPiece::canMoveDown(const Table& table,
						 const std::array<CellType, N>& cells) const
{
	for (auto cell : cells)
	{
		if (cell == CellType::VLong1Top || cell == CellType::VLong2Top ||
			cell == CellType::VLong3Top || cell == CellType::VLong4Top ||
			cell == CellType::BigTopLeft || cell == CellType::BigTopRight)
			continue;

		auto [x, y] = table.findCell(cell);

		const CellType* downCell = table.at(x, y + 1);

		if (!downCell)
			return false;
		else if (*downCell != CellType::Empty)
			return false;
	}

	return true;
}

template <size_t N>
bool IPiece::canMoveLeft(const Table& table,
						 const std::array<CellType, N>& cells) const
{
	for (auto cell : cells)
	{
		if (cell == CellType::HLongRight || cell == CellType::BigTopRight ||
			cell == CellType::BigBotRight)
			continue;

		auto [x, y] = table.findCell(cell);

		const CellType* leftCell = table.at(x - 1, y);

		if (!leftCell)
			return false;
		else if (*leftCell != CellType::Empty)
			return false;
	}

	return true;
}

template <size_t N>
bool IPiece::canMoveRight(const Table& table,
						  const std::array<CellType, N>& cells) const
{
	for (auto cell : cells)
	{
		if (cell == CellType::HLongLeft || cell == CellType::BigTopLeft ||
			cell == CellType::BigBotLeft)
			continue;

		auto [x, y] = table.findCell(cell);

		const CellType* rightCell = table.at(x + 1, y);

		if (!rightCell)
			return false;
		else if (*rightCell != CellType::Empty)
			return false;
	}

	return true;
}

inline void IPiece::move(Table& table, Direction direction) const
{
	switch (direction)
	{
	case Direction::Up:
		return moveUp(table);
	case Direction::Down:
		return moveDown(table);
	case Direction::Left:
		return moveLeft(table);
	case Direction::Right:
		return moveRight(table);
	}
}

template <size_t N>
TPiece<N>::TPiece(std::array<CellType, N> cs) : cells{cs}
{
}

template <size_t N>
bool TPiece<N>::canMove(const Table& table, Direction direction) const
{
	return IPiece::canMove(table, direction, cells);
}

template <size_t N>
bool TPiece<N>::canMoveUp(const Table& table) const
{
	return IPiece::canMoveUp(table, cells);
}

template <size_t N>
bool TPiece<N>::canMoveDown(const Table& table) const
{
	return IPiece::canMoveDown(table, cells);
}

template <size_t N>
bool TPiece<N>::canMoveLeft(const Table& table) const
{
	return IPiece::canMoveLeft(table, cells);
}

template <size_t N>
bool TPiece<N>::canMoveRight(const Table& table) const
{
	return IPiece::canMoveRight(table, cells);
}
}  // namespace RushHourSolver

#endif	// RushHourSolver_Printing_INL
