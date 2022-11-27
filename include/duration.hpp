#ifndef DURATION_H_
#define __DURATION_H_

class Duration{
	private:
		int time;
		int alarm;
		bool alarmHasBeenSet;
		bool checkAndUpdateAlarm();
	public:
		Duration();
		int getDuration();
		void setDuration(int t);
		bool tick();
		bool set_tick(int dt);
		void setAlarm(int t);
		bool checkAlarm();
		~Duration();
};

#endif //DURATION_H_
