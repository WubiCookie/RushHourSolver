#ifndef RushHourSolver_Solver_HPP
#define RushHourSolver_Solver_HPP

#include "Enums.hpp"
#include "Piece.hpp"
#include "Pieces.hpp"
#include "Printing.hpp"
#include "Table.hpp"

#include <atomic>
#include <functional>
#include <memory>
#include <mutex>
#include <random>
#include <stack>
#include <unordered_set>

namespace RushHourSolver
{
struct Solver
{
	static inline size_t MAX_DEPTH = 200;
	static inline size_t THREAD_LOOP_COUNT = 3;

	SmallPiece small1{{CellType::Small1}};
	SmallPiece small2{{CellType::Small2}};
	SmallPiece small3{{CellType::Small3}};
	SmallPiece small4{{CellType::Small4}};

	VLongPiece vLong1{{CellType::VLong1Top, CellType::VLong1Bot}};
	VLongPiece vLong2{{CellType::VLong2Top, CellType::VLong2Bot}};
	VLongPiece vLong3{{CellType::VLong3Top, CellType::VLong3Bot}};
	VLongPiece vLong4{{CellType::VLong4Top, CellType::VLong4Bot}};

	HLongPiece hLong{{CellType::HLongLeft, CellType::HLongRight}};

	BigPiece big{{CellType::BigTopLeft, CellType::BigTopRight,
				  CellType::BigBotLeft, CellType::BigBotRight}};

	std::random_device rd;
	std::mt19937 g;

	inline Solver();

	struct Movement
	{
		const std::reference_wrapper<const IPiece> movedPiece;
		const Direction movingDirection;

		inline Movement(const IPiece& mp, Direction md);
	};

	struct Branch
	{
		const Movement movement;
		const Table table;

		std::vector<Movement> parents;

		inline Branch(const IPiece& mp,
					  Direction md,
					  Table t,
					  std::vector<Movement> p);
		inline Branch(const IPiece& mp, Direction md, Table t);

		inline void retrace() const;
	};

	std::mutex solutionMutex;
	std::shared_ptr<Branch> solution;

	inline bool solutionFound(const Table& table) const;

	inline void solve(std::array<std::reference_wrapper<IPiece>, 10>& pieces,
					  std::array<Direction, 4>& directions);

	inline void threadFunc();

	inline void solve();
};
}  // namespace RushHourSolver

#include "Solver.inl"

#endif	// RushHourSolver_Solver_HPP
