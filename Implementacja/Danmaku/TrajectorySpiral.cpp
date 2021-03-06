#include "TrajectorySpiral.h"


TrajectorySpiral::TrajectorySpiral( D3DXVECTOR2 const & center, float const a, float const b )
{
	this->SetParameters( a, b );
	// punktem pocz�tkowym jest �r�d�o spirali
	this->SetCenterPoint( center );
	this->SetStartPoint( center );
};


TrajectorySpiral::~TrajectorySpiral()
{
};



void TrajectorySpiral::SetParameters( float const a, float const b )
{
	this->a = a;
	this->b = b;
};


void TrajectorySpiral::SetCenterPoint( D3DXVECTOR2 const & center )
{
	this->center = center;
};


void TrajectorySpiral::Translate( D3DXVECTOR2 const & translate )
{
	startPoint += translate;
};


void TrajectorySpiral::Scale( float const scale )
{
	this->b *= scale;
};


void TrajectorySpiral::Rotate( float const theta )
{
	this->theta += theta;
};
