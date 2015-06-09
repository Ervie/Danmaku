/* ======================================================== *\
 *  @IException.h
 *  @Opis: Interfejs dla wyjątków
 *  @Utworzona: 21.03.2015 19:02
 *  @Autor: Mateusz Forczmański
\* ======================================================== */

#ifndef EX_H
#define EX_H

#include <string>
#include <Windows.h>

class IException
{
public:
	virtual ~IException() = 0 {};

	// zwrócenie komunikatu
	virtual std::string ToString() const = 0;

	// pokazanie message boxa
	virtual void ToMessageBox() = 0;
};

#endif