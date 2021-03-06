/********************************
                   *  		mm_soundmanager.h
                   *		Matthew Mills
           ********************************/




#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <QList>
#include <QString>
#include <QMediaPlayer>
#include "hh_main_player.h"
#include "mm_resourcemanager.h"

class SoundManager: public ResourceManager
{
private:

    //These are the paths to the sound files in the resource folder

    QString background_path = "qrc:/sounds/background.mp3";
    QString bump_path = "qrc:/sounds/bump.mp3";
    QString chomp_path = "qrc:/sounds/chomp.mp3";
    QString die_path = "qrc:/sounds/die.mp3";
    QString eat_path = "qrc:/sounds/eat.mp3";
    QString end_path = "qrc:/sounds/end.mp3";
    QString hit_path = "qrc:/sounds/hit.mp3";
    QString levelup_path = "qrc:/sounds/levelup.mp3";
    QString pickup_path = "qrc:/sounds/pickup.mp3";
    QString start_path = "qrc:/sounds/start.mp3";
    QString steam_path = "qrc:/sounds/steam.mp3";
    QString throw_path = "qrc:/sounds/throw.mp3";

    QMediaPlayer *background_music;
    QMediaPlayer *bump_music;
    QMediaPlayer *chomp_music;
    QMediaPlayer *die_music;
    QMediaPlayer *eat_music;
    QMediaPlayer *end_music;
    QMediaPlayer *hit_music;
    QMediaPlayer *levelup_music;
    QMediaPlayer *pickup_music;
    QMediaPlayer *start_music;
    QMediaPlayer *steam_music;
    QMediaPlayer *throw_music;


public:

    //These are the member functions and the class constructor

    SoundManager();

    void adjust_volume(QMediaPlayer *music, int volume);

    void play_background();

    void play_bump();

    void play_chomp();

    void play_die();

    void play_eat();

    void play_end();

    void play_hit();

    void play_levelup();

    void play_pickup();

    void play_start();

    void play_steam();

    void play_throw();


    void stop_background();

    void stop_bump();

    void stop_chomp();

    void stop_die();

    void stop_eat();

    void stop_end();

    void stop_hit();

    void stop_levelup();

    void stop_pickup();

    void stop_start();

    void stop_steam();

    void stop_throw();

};

#endif // SOUNDMANAGER_H
