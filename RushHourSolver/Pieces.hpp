#ifndef RushHourSolver_Pieces_HPP
#define RushHourSolver_Pieces_HPP

#include "Piece.hpp"
#include "Table.hpp"

#include <cassert>

namespace RushHourSolver
{
struct SmallPiece final : TPiece<1>
{
	using TPiece::TPiece;

	inline void moveUp(Table& table) const override;
	inline void moveDown(Table& table) const override;
	inline void moveLeft(Table& table) const override;
	inline void moveRight(Table& table) const override;
};

struct VLongPiece final : TPiece<2>
{
	using TPiece::TPiece;

	inline void moveUp(Table& table) const override;
	inline void moveDown(Table& table) const override;
	inline void moveLeft(Table& table) const override;
	inline void moveRight(Table& table) const override;
};

struct HLongPiece final : TPiece<2>
{
	using TPiece::TPiece;

	inline void moveUp(Table& table) const override;
	inline void moveDown(Table& table) const override;
	inline void moveLeft(Table& table) const override;
	inline void moveRight(Table& table) const override;
};

struct BigPiece final : TPiece<4>
{
	using TPiece::TPiece;

	inline void moveUp(Table& table) const override;
	inline void moveDown(Table& table) const override;
	inline void moveLeft(Table& table) const override;
	inline void moveRight(Table& table) const override;
};
}  // namespace RushHourSolver

#include "Pieces.inl"

#endif	// RushHourSolver_Pieces_HPP
