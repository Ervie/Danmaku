#pragma once

#include "CPattern.h"
#include "EnemyBullet.h"
#include "TrajectoryFactory.h"

class Pattern02 : public CPattern
{
	//// STA�E
	static const unsigned short BULLET_NUMBER_S	= 1000;

	//// TORY
	TrajectoryPtr traj1, traj2;

	float scaleTime;

public:
	Pattern02();
	void Initialize(LPDIRECT3DDEVICE9 device, D3DXVECTOR2 const & position) override;
	void Update(float const time) override;

	void Add();

};