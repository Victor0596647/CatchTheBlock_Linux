#include "Game.h"

using namespace sf;

Game::Game()
{
    initWin();
    initGame();
    run();
}

Game::~Game()
{
    //dtor
}

void Game::initGame(){
    this->game = new CatchTheBlock;
}

void Game::initWin(){
    this->app = new RenderWindow (VideoMode(1280, 720), "Catch The Block", Style::Close);
    this->app->setKeyRepeatEnabled(false);
    this->app->setFramerateLimit(frameLimit);
}

void Game::run(){
    while(this->app->isOpen()){
        updatePollEvents();
        render();
    }
}

void Game::update(){
    this->game->update(*app);
}

void Game::render(){
    this->app->clear();
    this->game->render(*app);
    this->app->display();
}

void Game::updatePollEvents(){
    Event event;
    while(this->app->pollEvent(event)){
        switch (event.type){
            case Event::Closed:
                this->app->close();
                break;
            case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
                this->app->close();
            }
            //Pausing game
            if(Keyboard::isKeyPressed(Keyboard::Key::P) && !this->game->getGamePause() && !this->game->getGameWin() && !this->game->getGameLose()){
                this->game->setGamePause(true);
            }else if(Keyboard::isKeyPressed(Keyboard::Key::P) && this->game->getGamePause() == true){
                this->game->setGamePause(false);
            }
        }
    }
    update();
}
