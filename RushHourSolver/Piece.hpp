#ifndef RushHourSolver_Piece_HPP
#define RushHourSolver_Piece_HPP

#include "Enums.hpp"
#include "Table.hpp"

#include <array>

namespace RushHourSolver
{
struct IPiece
{
	template <size_t N>
	bool canMove(const Table& table,
				 Direction direction,
				 const std::array<CellType, N>& cells) const;

	template <size_t N>
	bool canMoveUp(const Table& table,
				   const std::array<CellType, N>& cells) const;

	template <size_t N>
	bool canMoveDown(const Table& table,
					 const std::array<CellType, N>& cells) const;

	template <size_t N>
	bool canMoveLeft(const Table& table,
					 const std::array<CellType, N>& cells) const;

	template <size_t N>
	bool canMoveRight(const Table& table,
					  const std::array<CellType, N>& cells) const;

	virtual bool canMove(const Table& table, Direction direction) const = 0;

	virtual bool canMoveUp(const Table& table) const = 0;
	virtual bool canMoveDown(const Table& table) const = 0;
	virtual bool canMoveLeft(const Table& table) const = 0;
	virtual bool canMoveRight(const Table& table) const = 0;

	inline void move(Table& table, Direction direction) const;

	virtual void moveUp(Table& table) const = 0;
	virtual void moveDown(Table& table) const = 0;
	virtual void moveLeft(Table& table) const = 0;
	virtual void moveRight(Table& table) const = 0;
};

template <size_t N>
struct TPiece : IPiece
{
	std::array<CellType, N> cells;

	TPiece(std::array<CellType, N> cs);

	bool canMove(const Table& table, Direction direction) const override;

	bool canMoveUp(const Table& table) const override;
	bool canMoveDown(const Table& table) const override;
	bool canMoveLeft(const Table& table) const override;
	bool canMoveRight(const Table& table) const override;
};
}  // namespace RushHourSolver

#include "Piece.inl"

#endif	// RushHourSolver_Piece_HPP
