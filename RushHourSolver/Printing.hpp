#ifndef RushHourSolver_Printing_HPP
#define RushHourSolver_Printing_HPP

#include "Enums.hpp"

#include <iostream>

namespace RushHourSolver
{
inline std::ostream& printRow1(CellType cellType, std::ostream& os = std::cout)
{
	switch (cellTypeToKind(cellType))
	{
	case CellKind::Empty:
		return os << char(176) << char(176);

	case CellKind::VLongTop:
		return os << char(201) << char(187);

	case CellKind::VLongBot:
		return os << char(186) << char(186);

	case CellKind::HLongLeft:
		return os << char(201) << char(205);
	case CellKind::HLongRight:
		return os << char(205) << char(187);

	case CellKind::Small:
		return os << char(201) << char(187);

	case CellKind::BigTopLeft:
		return os << char(201) << char(205);
	case CellKind::BigTopRight:
		return os << char(205) << char(187);
	case CellKind::BigBotLeft:
		return os << char(186) << ' ';
	case CellKind::BigBotRight:
		return os << ' ' << char(186);
	}
}

inline std::ostream& printRow2(CellType cellType, std::ostream& os = std::cout)
{
	switch (cellTypeToKind(cellType))
	{
	case CellKind::Empty:
		return os << char(176) << char(176);

	case CellKind::VLongTop:
		return os << char(186) << char(186);

	case CellKind::VLongBot:
		return os << char(200) << char(188);

	case CellKind::HLongLeft:
		return os << char(200) << char(205);
	case CellKind::HLongRight:
		return os << char(205) << char(188);

	case CellKind::Small:
		return os << char(200) << char(188);

	case CellKind::BigTopLeft:
		return os << char(186) << ' ';
	case CellKind::BigTopRight:
		return os << ' ' << char(186);
	case CellKind::BigBotLeft:
		return os << char(200) << char(205);
	case CellKind::BigBotRight:
		return os << char(205) << char(188);
	}
}

inline std::ostream& operator<<(std::ostream& os, CellType cellType)
{
	switch (cellType)
	{
	case CellType::Empty:
		return os << ' ';

	case CellType::VLong1Top:
	case CellType::VLong2Top:
	case CellType::VLong3Top:
	case CellType::VLong4Top:
		return os << '^';

	case CellType::VLong1Bot:
	case CellType::VLong2Bot:
	case CellType::VLong3Bot:
	case CellType::VLong4Bot:
		return os << 'v';

	case CellType::HLongLeft:
		return os << '<';
	case CellType::HLongRight:
		return os << '>';

	case CellType::Small1:
	case CellType::Small2:
	case CellType::Small3:
	case CellType::Small4:
		return os << char(254);

	case CellType::BigTopLeft:
		return os << char(201);
	case CellType::BigTopRight:
		return os << char(187);
	case CellType::BigBotLeft:
		return os << char(200);
	case CellType::BigBotRight:
		return os << char(188);
	}
}

inline std::ostream& operator<<(std::ostream& os, Direction direction)
{
	switch (direction)
	{
	case Direction::Up:
		return os << "Up";
	case Direction::Down:
		return os << "Down";
	case Direction::Left:
		return os << "Left";
	case Direction::Right:
		return os << "Right";
	}
}
}  // namespace RushHourSolver

#endif	// RushHourSolver_Printing_HPP
