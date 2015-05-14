#include "BonusFactory.h"

BonusFactory * BonusFactory::pInstance_ = 0;

BonusFactory & BonusFactory::Instance()
{
	if (!pInstance_)
	{
		pInstance_ = new BonusFactory();
	}
	return *pInstance_;
};

Bonus * const BonusFactory::CreateBonus( Bonuses const bonus, D3DXVECTOR2 const & position, float const value, float const speed )
{
	CallbackMap::const_iterator it = callbacks_.find( bonus );
	if ( it == callbacks_.end())
	{
		throw std::runtime_error("Nieznany identyfikator bonusu.");
	}
	return (it->second)(position, value, speed);
};

bool BonusFactory::RegisterBonus( Bonuses const bonus, CreateBonusCallback createFn )
{
	return this->callbacks_.insert( CallbackMap::value_type( bonus, createFn )).second;
};


bool BonusFactory::UnregisterBonus( Bonuses const bonus )
{
	return this->callbacks_.erase( bonus ) == 1;
};