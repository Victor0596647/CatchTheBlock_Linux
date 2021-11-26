#ifndef CATCHTHEBLOCK_H
#define CATCHTHEBLOCK_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class CatchTheBlock
{
    public:
        CatchTheBlock();
        virtual ~CatchTheBlock();
        void render(RenderTarget& target);
        void update(Window& target);
        void setGamePause(bool Apause){ setPause = Apause;}
        void setGameWin(bool Awin){ win = Awin;}
        void setGameLose(bool Alose){ Lost = Alose;}
        bool getGamePause(){return setPause;}
        bool getGameWin(){return win;}
        bool getGameLose(){return Lost;}
        sf::RectangleShape square;
        sf::RectangleShape square2;

    private:
        float currentSpeed = 0.520;
        const float speed = 0.520;
        int level = 1;
        int catchCount = 0;
        bool setPause = 0;
        bool Lost = 0;
        bool win = false;
        void initSprite();
        void initText();
        void initAudio();
        std::string audioFile2 = "res/Ring_Victor059.wav";
        std::string audioFile1 = "res/Generic-Beep_Victor059.wav";
        std::string audioFile3 = "res/Ring-Deep_Victor059.wav";

        //Variables
        Font pix;
        Text resultWL;
        Text Catch;
        Text CatchT;
        Text Speed;
        Text SpeedT;
        Text Level;
        Text LevelT;
        Text Score;
        Text ScoreT;
        Text statusPause;
        Sound beep1;
        Sound levl;
        Sound lose;
        SoundBuffer buffer1;
        SoundBuffer buffer2;
        SoundBuffer buffer3;
        Clock clock;
        Time time;
};

#endif // CATCHTHEBLOCK_H
