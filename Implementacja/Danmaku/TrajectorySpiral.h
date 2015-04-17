#pragma once

#include "Trajectory.h"
#include "Vector.h"

class TrajectorySpiral : public Trajectory
{
	/* wsp�czynnik obrotu spirali */
	float a;

	/* odleg�o�� mi�dzy kolejnymi obrotami */
	float b;

public:
	TrajectorySpiral( D3DXVECTOR2 const & center, float const & a, float const & b );
	virtual ~TrajectorySpiral();

private:
	void SetParameters( float const & a, float const & b );

public:
	/* ==== Przeci��one interfejsy ==== */
	D3DXVECTOR2 GetPosition( float const & theta ) const override;
	void Translate( D3DXVECTOR2 const & translate ) override;
	void Scale( float const & scale ) override;
	void Rotate( float const & theta ) override;
};