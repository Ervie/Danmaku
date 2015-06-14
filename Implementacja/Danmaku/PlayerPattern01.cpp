#include "PlayerPattern01.h"


/// <summary>
/// Tworzy now� instacj� klasy <see cref="PlayerPattern01"/>.
/// </summary>
PlayerPattern01::PlayerPattern01(void)
{
}

/// <summary>
/// Niszczy instancj� klasy <see cref="PlayerPattern01"/>.
/// </summary>
PlayerPattern01::~PlayerPattern01(void)
{
}

/// <summary>
/// Aktualizuje stan.
/// </summary>
/// <param name="time">Pr�bka czasu.</param>
void PlayerPattern01::Update(float const time)
{
	if (this->elapsedTime >= 0.10000f)
	{
		if (this->isKeyPressed)
			AddBullet();
		this->elapsedTime = 0;
	}
	this->elapsedTime += time;
	
	for ( PBulletQue::const_iterator it = bullet.begin(); it != bullet.end(); it++ )
	{
		(*it)->Update(time);
	}
}

/// <summary>
/// Dodanie nowego pocisku.
/// </summary>
void PlayerPattern01::AddBullet()
{
	PlayerBullet * newBullet;
	newBullet = new PlayerBullet( 800.0f, 50 );
	newBullet->SetSprite ( templateSprite );
	newBullet->InitializeHitbox( Hitbox::Shape::CIRCLE, Hitbox::Size::HALF_LENGTH );
	newBullet->SetDistance( D3DXToRadian( 45.0f ) );
	newBullet->SetTrajectory( TrajectoryPtr(TrajectoryFactory::Instance().CreateTrajectory( Road::LINE, *position, D3DXToRadian(90) ) ) );
	this->bullet.push_back( newBullet );
}

/// <summary>
/// Za�adowanie sprajt�w dla pocisk�w.
/// </summary>
/// <param name="pbsResource">�r�d�o sprajt�w pocisk�w.</param>
void PlayerPattern01::LoadSprite(PlayerBulletSpriteResource & pbsResource)
{
	this->LoadBulletType(templateSprite, "PlayerBullet1", pbsResource);
};
