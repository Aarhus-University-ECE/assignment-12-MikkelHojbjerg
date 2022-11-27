#include "duration.hpp"
#include <assert.h>
#include <iostream>

int Duration::getDuration(){
	return time;
}

Duration::Duration(){
	time = 0;
	alarm = 0;
	alarmHasBeenSet = false;
}

void Duration::setDuration(int t){
	assert(t >= 0);
	time = t;
}

bool Duration::tick(){
	time++;
	return checkAndUpdateAlarm();
}

bool Duration::set_tick(int dt){
	//Fejl med hasAlarmBeenSet bliver til falsk er her
	assert(dt >= 0);
	time += dt;
	return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t){
	assert(t >= 0 && t > time);
	alarm = t;
	alarmHasBeenSet = true;
}

bool Duration::checkAlarm(){
	return alarmHasBeenSet;
}

bool Duration::checkAndUpdateAlarm(){

	if(time >= alarm && alarmHasBeenSet == true){
		alarmHasBeenSet = false;
		return true;
	}else{
		return false;
	}

}

Duration::~Duration(){}
