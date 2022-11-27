#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("duration (tid har samme værdi som alarm)"){

	Duration d;

	//Tester om time er lig 0 når programmet starter.
	REQUIRE(d.getDuration() == 0);
	//Tilføjer værdi til time
	d.setDuration(69);
	//Tjekker om værdien er tilføjet
	REQUIRE(d.getDuration() == 69);
	d.setDuration(420);
	REQUIRE(d.getDuration() == 420);
	//ticker time med en
	d.tick();
	//Tjekker om tick virker
	REQUIRE(d.getDuration() == 421);
	//Ticker time med 8574
	d.set_tick(8573);
	//Tjekker om set_time virker
	REQUIRE(d.getDuration() == 8994);
	//Sætter alarm til
	d.setAlarm(9000);
	//Tjekker om alarm er false hvis time er mindre end alarm
	REQUIRE(d.tick() == false);
	d.set_tick(4);
	//Tjekker om alarm er true hvis time er lig med alarm
	REQUIRE(d.tick() == true);
	d.set_tick(42);
	//Tjekker om tick er falske, for at se om AlarmHasBeenSet er blevet sat til false
	REQUIRE(d.tick() == false);
}

TEST_CASE("duration (tid er større end alarms værdi)"){

	Duration d;

	REQUIRE(d.getDuration() == 0);
	d.setDuration(69);
	REQUIRE(d.getDuration() == 69);
	d.setDuration(420);
	REQUIRE(d.getDuration() == 420);
	d.tick();
	REQUIRE(d.getDuration() == 421);
	d.set_tick(8573);
	REQUIRE(d.getDuration() == 8994);
	d.setAlarm(9050);
	REQUIRE(d.tick() == false);
	REQUIRE(d.set_tick(500) == true);
}


