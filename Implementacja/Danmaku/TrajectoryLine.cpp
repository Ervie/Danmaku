#include "TrajectoryLine.h"

TrajectoryLine::TrajectoryLine( D3DXVECTOR2 const & startPoint, float const angle, float const length )
	: length((short)length)
{
	/* Wartosci vectora s� w przedziale [0, 1] */
	D3DXVECTOR2 dv;
	dv.x = std::cos( angle );
	dv.y = -std::sin( angle );
	this->SetDirection( dv );
	this->SetStartPoint( startPoint );
};


TrajectoryLine::~TrajectoryLine()
{
};


void TrajectoryLine::SetDirection( D3DXVECTOR2 const & direction )
{
	this->direction = direction;
};


D3DXVECTOR2 TrajectoryLine::GetPosition( float const distance )
{
	D3DXVECTOR2 position;
	if (length != 0)
		position = startPoint + direction * (float) fmod(distance, length);
	else
		position = startPoint + direction * distance;
	return position;
};


void TrajectoryLine::Translate( D3DXVECTOR2 const & translate )
{
	this->startPoint += translate;
};


void TrajectoryLine::Scale( float const scale )
{
	this->direction *= scale;
};


void TrajectoryLine::Rotate( float const theta )
{
	// TODO
};

void TrajectoryLine::SetTrajectoryTowardsPlayer(D3DXVECTOR2 const & myPosition, D3DXVECTOR2 const & playerPosition)
{
	this->SetStartPoint( myPosition );
	float newAngle = Vector::Angle(myPosition, playerPosition);
	float x = myPosition.x - playerPosition.x;
	float y = myPosition.y - playerPosition.y;
	if ( x <= 0 && y >= 0)
	{
		this->direction.x = +std::cos(newAngle);
		this->direction.y = -std::sin(newAngle);
	}
	else if ( x > 0 && y >= 0)
	{
		this->direction.x = -std::cos(newAngle);
		this->direction.y = -std::sin(newAngle);
	}
	else
	{
		this->direction.x = std::cos(newAngle);
		this->direction.y = std::sin(newAngle);
	}
};