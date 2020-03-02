#ifndef RushHourSolver_Solver_INL
#define RushHourSolver_Solver_INL

namespace RushHourSolver
{
inline Solver::Solver() : g(std::mt19937(rd())) {}

inline Solver::Movement::Movement(const IPiece& mp, Direction md)
	: movedPiece(mp), movingDirection(md)
{
}

inline Solver::Branch::Branch(const IPiece& mp,
							  Direction md,
							  Table t,
							  std::vector<Movement> p)
	: movement(mp, md), table(t), parents(std::move(p))
{
}
inline Solver::Branch::Branch(const IPiece& mp, Direction md, Table t)
	: Branch(mp, md, t, {})
{
}

inline void Solver::Branch::retrace() const
{
	Table t = Table();
	t.printSelf();

	for (const auto& parent : parents)
	{
		std::cout << '\n';
		parent.movedPiece.get().move(t, parent.movingDirection);
		t.printSelf();
	}
}

inline bool Solver::solutionFound(const Table& table) const
{
	return table.boundedAt(1, 4) == CellType::BigBotLeft;
}

inline void Solver::solve(
	std::array<std::reference_wrapper<IPiece>, 10>& pieces,
	std::array<Direction, 4>& directions)
{
	std::unordered_set<Table> visitedTables;

	std::stack<std::shared_ptr<Branch>> branches;

	auto makeBranches = [&](std::shared_ptr<Branch> branch) {
		if (branch->parents.size() > MAX_DEPTH)
			return false;

		std::shuffle(pieces.begin(), pieces.end(), g);

		for (IPiece& piece : pieces)
		{
			std::shuffle(directions.begin(), directions.end(), g);

			for (Direction direction : directions)
			{
				if (piece.canMove(branch->table, direction))
				{
					Table testTable = branch->table;
					piece.move(testTable, direction);

					if (solutionFound(testTable))
					{
						std::lock_guard<std::mutex> lock(solutionMutex);

						if (solution == nullptr ||
							branch->parents.size() < solution->parents.size())
						{
							solution = std::make_shared<Branch>(
								piece, direction, testTable, branch->parents);
							solution->parents.push_back({piece, direction});
							return true;
						}
					}

					auto found = visitedTables.find(testTable);

					if (found == visitedTables.end())
					{
						auto newBranch = std::make_shared<Branch>(
							piece, direction, testTable, branch->parents);
						newBranch->parents.push_back({piece, direction});

						branches.push(newBranch);
						visitedTables.insert(testTable);
					}
				}
			}
		}

		return false;
	};

	auto initialBranch =
		std::make_shared<Branch>(hLong, Direction::Right, Table());

	makeBranches(initialBranch);

	while (!branches.empty())
	{
		auto branch = branches.top();

		branches.pop();

		if (makeBranches(branch))
		{
			std::lock_guard<std::mutex> lock(solutionMutex);

			std::cout << "solution found in " << solution->parents.size()
					  << " moves" << std::endl;
		}
	}
}

inline void Solver::threadFunc()
{
	std::array<std::reference_wrapper<IPiece>, 10> pieces{
		big,	hLong,	vLong1, vLong2, vLong3,
		vLong4, small1, small2, small3, small4,
	};

	std::array<Direction, 4> directions{
		Direction::Up,
		Direction::Down,
		Direction::Left,
		Direction::Right,
	};

	for (int i = 0; i < THREAD_LOOP_COUNT; i++)
	{
		std::shuffle(pieces.begin(), pieces.end(), g);
		std::shuffle(directions.begin(), directions.end(), g);

		solve(pieces, directions);
	}
}

inline void Solver::solve()
{
	std::thread t0(std::bind(&Solver::threadFunc, this));
	std::thread t1(std::bind(&Solver::threadFunc, this));
	std::thread t2(std::bind(&Solver::threadFunc, this));
	std::thread t3(std::bind(&Solver::threadFunc, this));
	std::thread t4(std::bind(&Solver::threadFunc, this));
	std::thread t5(std::bind(&Solver::threadFunc, this));
	std::thread t6(std::bind(&Solver::threadFunc, this));
	std::thread t7(std::bind(&Solver::threadFunc, this));
	std::thread t8(std::bind(&Solver::threadFunc, this));
	std::thread t9(std::bind(&Solver::threadFunc, this));
	std::thread t10(std::bind(&Solver::threadFunc, this));
	std::thread t11(std::bind(&Solver::threadFunc, this));
	std::thread t12(std::bind(&Solver::threadFunc, this));
	std::thread t13(std::bind(&Solver::threadFunc, this));
	std::thread t14(std::bind(&Solver::threadFunc, this));
	std::thread t15(std::bind(&Solver::threadFunc, this));

	t0.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
}
}  // namespace RushHourSolver

#endif	// RushHourSolver_Solver_INL
