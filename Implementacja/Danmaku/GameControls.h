#pragma once

/// <summary>
/// Rodzaje mo�liwych do kontrolek gry.
/// </summary>
enum class GameControl {
	UP				= 0x00,
	DOWN			= 0x01,
	LEFT			= 0x02,
	RIGHT			= 0x03,
	SHOOT			= 0x04,
	BOMB			= 0x05,
	FOCUS			= 0x06,
	ER				= 0x07
};

/// <summary>
/// Konwersja rodzaju bonusu na jego reprezentacj� w postaci stringu.
/// Je�li nie istnieje, to zwraca komunikat o b��dzie
/// </summary>
/// <param name="option">Typ kontrolki.</param>
/// <returns></returns>
inline std::string GameControl2String(GameControl option)
{
	switch(option)
    {
    case GameControl::UP:			return "UP";
    case GameControl::DOWN:			return "DOWN";
    case GameControl::LEFT:			return "LEFT";
	case GameControl::RIGHT:		return "RIGHT";
	case GameControl::SHOOT:		return "SHOOT";
	case GameControl::BOMB:			return "BOMB";
	case GameControl::FOCUS:		return "FOCUS";
	case GameControl::ER:			return "ERROR";
    }
};
/// <summary>
/// Konwersja stringu do rodzaju kontrolki.
/// </summary>
/// <param name="str">tre�� napisu.</param>
/// <returns>Kontrolk�, je�li nie istnieje, to zwraca komunikat o b��dzie</returns>
inline GameControl String2GameControl(std::string const & str)
{
	if (str.compare("UP") == 0)
		return GameControl::UP;
	else if (str.compare("DOWN") == 0)
		return GameControl::DOWN;
	else if (str.compare("LEFT") == 0)
		return GameControl::LEFT;
	else if (str.compare("RIGHT") == 0)
		return GameControl::RIGHT;
	else if (str.compare("SHOOT") == 0)
		return GameControl::SHOOT;
	else if (str.compare("BOMB") == 0)
		return GameControl::BOMB;
	else if (str.compare("FOCUS") == 0)
		return GameControl::FOCUS;
	else{
		return GameControl::ER;
	}
};