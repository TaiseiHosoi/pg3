#include <stdio.h>
#include <list>
#include <iostream>



int main() {

    std::list<const char*> YamanoteLine;
    YamanoteLine.push_back("Toukyou");
    YamanoteLine.push_back("Yurakucho");
    YamanoteLine.push_back("Shimbashi");
    YamanoteLine.push_back("Hamamatsucho");
    YamanoteLine.push_back("Tamachi");
    YamanoteLine.push_back("Shinagawa");
    YamanoteLine.push_back("Osaki");
    YamanoteLine.push_back("Gotanda");
    YamanoteLine.push_back("Meguro");
    YamanoteLine.push_back("Ebisu");
    YamanoteLine.push_back("Shibuya");
    YamanoteLine.push_back("Harajuku");
    YamanoteLine.push_back("Yoyogi");
    YamanoteLine.push_back("Shinjuku");
    YamanoteLine.push_back("Shin-Okubo");
    YamanoteLine.push_back("Takadanobaba");
    YamanoteLine.push_back("Mejiro");
    YamanoteLine.push_back("Ikebukuro");
    YamanoteLine.push_back("Otsuka");
    YamanoteLine.push_back("Sugamo");
    YamanoteLine.push_back("Komagome");
    YamanoteLine.push_back("Tabata");
    YamanoteLine.push_back("Nippori");
    YamanoteLine.push_back("Uguisudani");
    YamanoteLine.push_back("Ueno");
    YamanoteLine.push_back("Okachimachi");
    YamanoteLine.push_back("Akihabara");
    YamanoteLine.push_back("Kanda");

    std::list<const char*>::iterator itr;
    for (itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {//初期段階
        std::cout << *itr << "\n";
    }

    std::cout << "\n";

    //西日暮里を入れる
    for (itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
        if (*itr == "Nippori") {
            itr = YamanoteLine.insert(itr, "NishiniNippori");
            break;
        }
    }

    for (itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
        std::cout << *itr << "\n";
    }

    //高輪ゲートウェイを入れる
    for (itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
        if (*itr == "Shinagawa") {
            itr = YamanoteLine.insert(itr, "TakanawaGateway");
            break;
        }
    }

    for (itr = YamanoteLine.begin(); itr != YamanoteLine.end(); ++itr) {
        std::cout << *itr << "\n";
    }

 
	

	return 0;
}