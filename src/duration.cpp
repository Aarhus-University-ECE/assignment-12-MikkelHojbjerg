#include "duration.hpp"
#include <assert.h>
#include <iostream>

//HEnter værdien af time
int Duration::getDuration(){
	return time;
}

//Initializer Duration
Duration::Duration(){
	time = 0;
	alarm = 0;
	alarmHasBeenSet = false;
}
//Til at sætte time
void Duration::setDuration(int t){
	//Time skal være større end 0
	assert(t >= 0);
	//Time får den tildelte værdi
	time = t;
}

//Til at tilføjle en værdi af 1 til time
bool Duration::tick(){
	//Ticker time op med en
	time++;
	//Tjekker om alarm er gået over tid
	return checkAndUpdateAlarm();
}

//Til at tilføjle en vilkårlig integer til tid
bool Duration::set_tick(int dt){
	//Tjekker om dt er større end 0
	assert(dt >= 0);
	//Ligger dt til time
	time += dt;
	//Tjekker om alarm er gået over tid
	return checkAndUpdateAlarm();
}

//Til at sætte alarm
void Duration::setAlarm(int t){
	//alarm skal være større end nul og større end time
	assert(t >= 0 && t > time);
	//alarm får den tildelte værdi
	alarm = t;
	//alarm bliver sat til true
	alarmHasBeenSet = true;
}

//Til at tjekke alarm
bool Duration::checkAlarm(){
	//Tjekker om alarm er blevet sat
	return alarmHasBeenSet;
}

//Til at tjekke om alarm er gået over tid og om alarm er blevet sat
bool Duration::checkAndUpdateAlarm(){
	//Tjekker om alarm er det samme eller gået over tiden og om alarm er blevet sat
	if(time >= alarm && alarmHasBeenSet == true){
		//Hvis ja, bliver alarm sat til falsk
		alarmHasBeenSet = false;
		return true;
	}else{
		//Ellers er alarm ikke blevet triggert
		return false;
	}

}

//Freeer/deleter Duration
Duration::~Duration(){}
