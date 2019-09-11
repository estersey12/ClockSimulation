//Emmanuelle Esters
//Lab5out
//Clock simulation


#include <iostream>
#include <cmath>
#include "graph1.h"

using namespace std;

class Clock
{
private:
	int hour;
	int min;
	int sec;


public:
	Clock();
	bool setHour(int hour);
	bool setMin(int min);
	bool setSec(int sec);
	int getHour();
	int getMin();
	int getSec();
	void draw();
};

Clock::Clock()
{
	//Set private data fields to default values
	hour = 0;
	min = 0;
	sec = 0;
}

bool Clock::setHour(int hour)
{
	bool result = false;

	//Implement rules for hour when out of range  
	if (hour >= 0 && hour <=11)
	{
		this->hour = hour;
		result = true;
	}
	else if (hour > 11)
	{
		this->hour = 11;
		result = true;
	}
	else if (hour < 0)
	{
		this->hour = 0;
		result = true;
	}
	return result;
}

bool Clock::setMin(int min)
{
	bool result = false;

	//Implement rules for hour when out of range  
	if (min >= 0 && min <= 59)
	{
		this->min = min;
		result = true;
	}
	else if (min > 59)
	{
		this->min = 59;
		result = true;
	}
	else if (min < 0)
	{
		this->min = 0;
		result = true;
	}
	return result;
}

bool Clock::setSec(int sec)
{
	bool result = false;

	//Implement rules for hour when out of range  
	if (sec >= 0 && sec <= 59)
	{
		this -> sec = sec;
		result = true;
	}
	else if (sec > 59)
	{
		this -> sec = 59;
		result = true;
	}
	else if (sec < 0)
	{
		this -> sec = 0;
		result = true;
	};
	return result;
}

int Clock::getHour()
{
	return hour;
}

int Clock::getMin()
{
	return min;
}

int Clock::getSec()
{
	return sec;
}

void Clock::draw()
{
	int alpha = 0;
	double const PI = 3.141593;
	int center_x = 400;
	int center_y = 400;
	int length_of_hand = 0;
	int end_x = 20;
	int end_y = 20;
	int sec_hand = 0;
	int min_hand = 0;
	int hour_hand = 0;

	getHour();

	drawRect(0, 0, 640, 480);
	displayPNG("clock_face.png", 123, 50);

	//Second hand
	alpha = sec * 6;
	length_of_hand = 150;

		//Second Endpoints
	if (alpha >= 0 && alpha < 90)
	{
		end_x = center_x + (cos((90 - alpha)*PI / 180.0))*length_of_hand;
		end_y = center_y - (sin((90 - alpha)*PI / 180.0))* length_of_hand;
	}
	else if (alpha >= 90 && alpha < 180)
	{
		end_x = center_x + (cos((alpha - 90)*PI / 180.0))* length_of_hand;
		end_y = center_y + (sin((alpha - 90)*PI / 180.0))*length_of_hand;

	}
	else if (alpha >= 180 && alpha < 270)
	{
		end_x = center_x - (cos((270 - alpha)*PI / 180.0))*length_of_hand;
		end_y = center_y + (sin((270 - alpha)*PI / 180.0))*length_of_hand;



	}
	else if (alpha >= 270 && alpha < 360)
	{
		end_x = center_x - (cos((alpha - 270)*PI / 180.0))*length_of_hand;
		end_y = center_y - (sin((alpha - 270)*PI / 180.0))*length_of_hand;


	}

	//Draw Sec hand
	sec_hand = drawLine(197, 189, end_x, end_y, 5);
	setColor(sec_hand, 255, 0, 0);
	
	//Minute hand
	alpha = min * 6 + (sec / 60.0) * 6;
	length_of_hand = 180;


		//Min Endpoints
	if (alpha >= 0 && alpha < 90)
	{
		end_x = center_x + (cos((90 - alpha)*PI / 180.0))*length_of_hand;
		end_y = center_y - (sin((90 - alpha)*PI / 180.0))* length_of_hand;
	}
	else if (alpha >= 90 && alpha < 180)
	{
		end_x = center_x + (cos((alpha - 90)*PI / 180.0))* length_of_hand;
		end_y = center_y + (sin((alpha - 90)*PI / 180.0))*length_of_hand;

	}
	else if (alpha >= 180 && alpha < 270)
	{
		end_x = center_x - (cos((270 - alpha)*PI / 180.0))*length_of_hand;
		end_y = center_y + (sin((270 - alpha)*PI / 180.0))*length_of_hand;



	}
	else if (alpha >= 270 && alpha < 360)
	{
		end_x = center_x - (cos((alpha - 270)*PI / 180.0))*length_of_hand;
		end_y = center_y - (sin((alpha - 270)*PI / 180.0))*length_of_hand;


	}


		//Draw min hand
	min_hand = drawLine(197, 189, end_x, end_y, 5);
	setColor(min_hand, 0, 0, 0);

	//Hour hand
	alpha = hour * 30 + (min / 60.0) * 30;
	length_of_hand = 133;


		//hour Endpoints
	if (alpha >= 0 && alpha < 90)
	{
		end_x = center_x + (cos((90 - alpha)*PI / 180.0))*length_of_hand;
		end_y = center_y - (sin((90 - alpha)*PI / 180.0))* length_of_hand;
	}
	else if (alpha >= 90 && alpha < 180)
	{
		end_x = center_x + (cos((alpha - 90)*PI / 180.0))* length_of_hand;
		end_y = center_y + (sin((alpha - 90)*PI / 180.0))*length_of_hand;

	}
	else if (alpha >= 180 && alpha < 270)
	{
		end_x = center_x - (cos((270 - alpha)*PI / 180.0))*length_of_hand;
		end_y = center_y + (sin((270 - alpha)*PI / 180.0))*length_of_hand;



	}
	else if (alpha >= 270 && alpha < 360)
	{
		end_x = center_x - (cos((alpha - 270)*PI / 180.0))*length_of_hand;
		end_y = center_y - (sin((alpha - 270)*PI / 180.0))*length_of_hand;


	}


	//draw hour hand
	hour_hand = drawLine(197, 189, end_x, end_y, 5);
	setColor(hour_hand, 0, 0, 0);
}

int main()
{
	//Variable Declaration/Initialization
	int hour = 0;
	int min = 0;
	int sec = 0;
	bool result;

	Clock clock1;

	char repeat;

	//Display the Graphics
	displayGraphics();

	do
	{
		//Prompt for seconds
		cout << "Enter the number of seconds: ";
		cin >> sec;

		//Prompt for minutes
		cout << "Enter the number of minutes: ";
		cin >> min;

		//Prompt for hours
		cout << "Enter the number of hours: ";
		cin >> hour;

		//set hour for clock1 -- display message
		result = clock1.setHour(hour);
		if (result == false)
		{
			cout << "Your hour value was incorrect" << endl;
		}

		//set minute for clock1 -- display message
		result = clock1.setMin(min);
		if (result == false)
		{
			cout << "Your minute value was incorrect" << endl;
		}

		//set second for clock1 -- display message
		result = clock1.setSec(sec);
		if (result == false)
		{
			cout << "Your second value was incorrect" << endl;

		}


		//Draw the clock
		clock1.draw();

		//Display Digital Time
		gout << setPos(280, 440) << "Time: " << hour << ":" << min << ":" << sec << endg;

		//Return statement
		cout << "\nWould you like to repeat? (y/n): ";
		cin >> repeat;

		//Clear graphics/console
		system("cls");
		clearGraphics();


	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}
