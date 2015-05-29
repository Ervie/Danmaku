#include "Application.h"

unsigned int Application::m_FPS = 60;


Application::Application(HINSTANCE hInstance, int const nShowCmd)
{
	LPCSTR const className = "danmakuWindow";
	this->windowTitle = "Danmaku";
	this->hWnd = NULL;

	// inicjalizacja okna
	this->window = new GameWindow(hInstance, nShowCmd, className, this->windowTitle.c_str(), WIDTH, HEIGHT, hWnd);
	this->gDevice = new GraphicsDevice();
	this->timer = new Timer();
	this->endStageInfo = new EndStageInfo();
	this->endStageInfo->numberOfStage = 1;
};


Application::~Application()
{
	if (window) delete window;
	if (gDevice) delete gDevice;
	if (timer) delete timer;
	if (field) delete field;
};

void Application::Initialize()
{
	if ( !gDevice->Initialize(hWnd, true )) // przekazanie okna
	{
		throw new Direct3DInitializationFailedException();
	}
	this->field = new TitleScreen( gDevice, endStageInfo );
	this->mode = ScreenMode::TITLE;
	this->timer->Start();
};


void Application::Run()
{
	//bool game = false;
	if (field->Initialize())
	{
		// p�tla g��wna, rysuje i aktualizuje
		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));
		while (true)
		{
			if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
			{
				if (msg.message == WM_QUIT) break;
				TranslateMessage(&msg);	
				DispatchMessage(&msg);
			}
			else
			{
				timer->Update();
				CalculateFPS( timer->elapsedTime );
				/* ===== SUPER ZABEZPIECZENIE WSZYSTKIEGO PRZED LAGAMI!! ====== */
				//// Je�eli otrzymany czas przekracza 1 klatk�, NIC SI� NIE DZIEJE!!
				if ( m_FPS * timer->elapsedTime > 1.75f )
					continue;
				//// ^Kwiat mojej kaiery programistycznej.
				//// Sasuga ore.
				field->Run( timer->elapsedTime );


				// prze��czenie screen�w
				if (field->isEnded() && field->NextMode() != ScreenMode::NONE)
				{
					mode = field->NextMode();

					endStageInfo = field->ReturnInformation();

					delete field;

					switch (mode)
					{
						case(ScreenMode::GAME):
							field = new Game(gDevice, endStageInfo);
							break;

						case(ScreenMode::TITLE):
							field = new TitleScreen(gDevice, endStageInfo);
							break;

						case(ScreenMode::SCORE_COUNT):
							field = new ScoreCountScreen(gDevice, endStageInfo);
							break;

					}
					field->Initialize();

				}

			}
		}
	}
};


void Application::CalculateFPS( float const dt )
{
	static int frameCount;
	static float elapsedTime;

	frameCount++;
	elapsedTime += dt;

	if ( elapsedTime >= 1.0000000f )
	{
		m_FPS = frameCount;
		std::stringstream ss;
		ss << windowTitle << " FPS: " << frameCount;
		SetWindowText( hWnd, ss.str().c_str() );
		frameCount = 0;
		elapsedTime = 0.0f;
	}
};