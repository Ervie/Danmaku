#ifndef EX_DIRECT3D_INIT_FAILED_H
#define EX_DIRECT3D_INIT_FAILED_H

#include "IException.h"

class Direct3DInitializationFailedException: public IException
{
public:
	// zwr�cenie komunikatu
	std::string ToString() const override;

	// pokazanie message boxa
	void ToMessageBox() override;
};


#endif