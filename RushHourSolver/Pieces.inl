#ifndef RushHourSolver_Pieces_INL
#define RushHourSolver_Pieces_INL

namespace RushHourSolver
{
inline void SmallPiece::moveUp(Table& table) const
{
	assert(canMoveUp(table));

	auto [x, y] = table.findCell(cells[0]);

	if (table.swapUp(x, y) == false)
		assert(false);
}

inline void SmallPiece::moveDown(Table& table) const
{
	assert(canMoveDown(table));

	auto [x, y] = table.findCell(cells[0]);

	if (table.swapDown(x, y) == false)
		assert(false);
}

inline void SmallPiece::moveLeft(Table& table) const
{
	assert(canMoveLeft(table));

	auto [x, y] = table.findCell(cells[0]);

	if (table.swapLeft(x, y) == false)
		assert(false);
}

inline void SmallPiece::moveRight(Table& table) const
{
	assert(canMoveRight(table));

	auto [x, y] = table.findCell(cells[0]);

	if (table.swapRight(x, y) == false)
		assert(false);
}

inline void VLongPiece::moveUp(Table& table) const
{
	assert(canMoveUp(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapUp(x1, y1) == false)
		assert(false);
	if (table.swapUp(x2, y2) == false)
		assert(false);
}

inline void VLongPiece::moveDown(Table& table) const
{
	assert(canMoveDown(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapDown(x2, y2) == false)
		assert(false);
	if (table.swapDown(x1, y1) == false)
		assert(false);
}

inline void VLongPiece::moveLeft(Table& table) const
{
	assert(canMoveLeft(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapLeft(x1, y1) == false)
		assert(false);
	if (table.swapLeft(x2, y2) == false)
		assert(false);
}

inline void VLongPiece::moveRight(Table& table) const
{
	assert(canMoveRight(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapRight(x1, y1) == false)
		assert(false);
	if (table.swapRight(x2, y2) == false)
		assert(false);
}

inline void HLongPiece::moveUp(Table& table) const
{
	assert(canMoveUp(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapUp(x1, y1) == false)
		assert(false);
	if (table.swapUp(x2, y2) == false)
		assert(false);
}

inline void HLongPiece::moveDown(Table& table) const
{
	assert(canMoveDown(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapDown(x1, y1) == false)
		assert(false);
	if (table.swapDown(x2, y2) == false)
		assert(false);
}

inline void HLongPiece::moveLeft(Table& table) const
{
	assert(canMoveLeft(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapLeft(x1, y1) == false)
		assert(false);
	if (table.swapLeft(x2, y2) == false)
		assert(false);
}

inline void HLongPiece::moveRight(Table& table) const
{
	assert(canMoveRight(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);

	if (table.swapRight(x2, y2) == false)
		assert(false);
	if (table.swapRight(x1, y1) == false)
		assert(false);
}

inline void BigPiece::moveUp(Table& table) const
{
	assert(canMoveUp(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);
	auto [x3, y3] = table.findCell(cells[2]);
	auto [x4, y4] = table.findCell(cells[3]);

	if (table.swapUp(x1, y1) == false)
		assert(false);
	if (table.swapUp(x2, y2) == false)
		assert(false);
	if (table.swapUp(x3, y3) == false)
		assert(false);
	if (table.swapUp(x4, y4) == false)
		assert(false);
}

inline void BigPiece::moveDown(Table& table) const
{
	assert(canMoveDown(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);
	auto [x3, y3] = table.findCell(cells[2]);
	auto [x4, y4] = table.findCell(cells[3]);

	if (table.swapDown(x3, y3) == false)
		assert(false);
	if (table.swapDown(x4, y4) == false)
		assert(false);
	if (table.swapDown(x1, y1) == false)
		assert(false);
	if (table.swapDown(x2, y2) == false)
		assert(false);
}

inline void BigPiece::moveLeft(Table& table) const
{
	assert(canMoveLeft(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);
	auto [x3, y3] = table.findCell(cells[2]);
	auto [x4, y4] = table.findCell(cells[3]);

	if (table.swapLeft(x1, y1) == false)
		assert(false);
	if (table.swapLeft(x3, y3) == false)
		assert(false);
	if (table.swapLeft(x2, y2) == false)
		assert(false);
	if (table.swapLeft(x4, y4) == false)
		assert(false);
}

inline void BigPiece::moveRight(Table& table) const
{
	assert(canMoveRight(table));

	auto [x1, y1] = table.findCell(cells[0]);
	auto [x2, y2] = table.findCell(cells[1]);
	auto [x3, y3] = table.findCell(cells[2]);
	auto [x4, y4] = table.findCell(cells[3]);

	if (table.swapRight(x2, y2) == false)
		assert(false);
	if (table.swapRight(x4, y4) == false)
		assert(false);
	if (table.swapRight(x1, y1) == false)
		assert(false);
	if (table.swapRight(x3, y3) == false)
		assert(false);
}
}  // namespace RushHourSolver

#endif	// RushHourSolver_Pieces_INL
