#pragma once

#include "IPattern.h"
#include "EnemyBullet.h"

//// konkretna klasa ka�dego Patternu
class EPattern : public IPattern
{
protected:
	/// Definicja kolejki wrogich pocisk�w
	typedef std::deque<EnemyBullet*> EBulletQue;

	//// POCISKI
	EBulletQue bullet;

	// definicja wsp�lnego wska�nika na tor
	typedef std::shared_ptr<Trajectory> TrajectoryPtr;

	// Kontrola czasowa
	float elapsedTime;

	// uchyt do diwajsa, dla generacji nowych pocisk�w w czasie
	LPDIRECT3DDEVICE9 device;

	// pozycja wzoru
	D3DXVECTOR2 position;

public:
	EPattern();
	virtual ~EPattern();
	
	// przekazanie uchwytu
	virtual void Initialize(LPDIRECT3DDEVICE9 device, D3DXVECTOR2 const & position );

	virtual void SetPosition(D3DXVECTOR2 const & pos);

	// narysowanie wszystkich pocisk�w
	void Draw(RECT const & rect) override;

	inline EBulletQue const & GetBullets() const
	{
		return bullet;
	};

};
