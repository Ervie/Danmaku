#include "PlayerPattern04.h"

/// <summary>
/// Tworzy now� instacj� klasy <see cref="PlayerPattern04"/>.
/// </summary>
PlayerPattern04::PlayerPattern04(void)
{
	leftShift = D3DXVECTOR2(20,15);
	rightShift = D3DXVECTOR2(-20,15);
}

/// <summary>
/// Niszczy instancj� klasy <see cref="PlayerPattern04"/>.
/// </summary>
PlayerPattern04::~PlayerPattern04(void)
{
}

/// <summary>
/// Aktualizuje stan.
/// </summary>
/// <param name="time">Pr�bka czasu.</param>
void PlayerPattern04::Update(float const time)
{
	if (this->elapsedTime >= 0.07000f)
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
void PlayerPattern04::AddBullet()
{
	for (int i = 0; i < 2; i++ )
	{
		PlayerBullet * newBullet;
		PlayerBullet * newBullet2;

		newBullet = new PlayerBullet( 1000.0f, 100 );
		newBullet2 = new PlayerBullet( 800.0f, 50 );

		newBullet->SetSprite ( templateSprite );
		newBullet2->SetSprite ( templateSprite2 );
		
		newBullet->InitializeHitbox( Hitbox::Shape::CIRCLE, Hitbox::Size::HALF_LENGTH );
		newBullet2->InitializeHitbox( Hitbox::Shape::CIRCLE, Hitbox::Size::HALF_LENGTH );

		switch (i % 2)
		{
			case 0:
				newBullet->SetTrajectory( TrajectoryPtr(TrajectoryFactory::Instance().CreateTrajectory( Road::LINE, *position - leftShift, D3DXToRadian(90) ) ) );
				newBullet2->SetTrajectory( TrajectoryPtr(TrajectoryFactory::Instance().CreateTrajectory( Road::LINE, *position - rightShift, D3DXToRadian(85) ) ) );
				break;
			case 1:
				newBullet->SetTrajectory( TrajectoryPtr(TrajectoryFactory::Instance().CreateTrajectory( Road::LINE, *position - rightShift, D3DXToRadian(90) ) ) );
				newBullet2->SetTrajectory( TrajectoryPtr(TrajectoryFactory::Instance().CreateTrajectory( Road::LINE, *position - leftShift, D3DXToRadian(95) ) ) );
				break;

			default:
				break;
		}
		this->bullet.push_back( newBullet );
		this->bullet.push_back( newBullet2 );
	}
}

/// <summary>
/// Za�adowanie sprajt�w dla pocisk�w.
/// </summary>
/// <param name="pbsResource">�r�d�o sprajt�w pocisk�w.</param>
void PlayerPattern04::LoadSprite(PlayerBulletSpriteResource & pbsResource)
{
	this->LoadBulletType(templateSprite, "PlayerBullet1", pbsResource);
	this->LoadBulletType(templateSprite2, "PlayerBullet2", pbsResource);
};
