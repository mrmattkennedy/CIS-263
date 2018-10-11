#include <string>
#include "Celebrity.h"

Celebrity::Celebrity() {}

Celebrity::~Celebrity() {}

Celebrity::Celebrity(std::string name,
				int meet_rating,
				bool met) {
	this->name = name;
	this->meet_rating = meet_rating;
	this->met = met;
}

Celebrity::Celebrity(std::string name,
				int meet_rating,
				std::string area,
				bool met) {
	this->name = name;
	this->meet_rating = meet_rating;
	this->area = area;
	this->met = met;
}
		
std::string Celebrity::get_name()	const {return this->name;}
int Celebrity::get_meet_rating()	const {return this->meet_rating;}
std::string Celebrity::get_area()	const {return this->area;}
bool Celebrity::get_met()		const {return this->met;}

void Celebrity::set_name(std::string name) 	{this->name = name;}
void Celebrity::set_meet_rating(int meet_rating){this->meet_rating = meet_rating;}
void Celebrity::set_area(std::string area) 	{this->area = area;}
void Celebrity::set_met(bool met) 		{this->met = met;}


bool operator< (const Celebrity & c1, const Celebrity & c2)
{ 
	if (c1.get_meet_rating() < c2.get_meet_rating())
		return true;
	else if (!c1.get_met() && c2.get_met())
		return true;
	else
		return c1.get_name().compare(c2.get_name());
	return false;
}


bool operator<= (const Celebrity & c1, const Celebrity & c2) 
{

	if (c1.get_meet_rating() <= c2.get_meet_rating())
		return true;
	else if ((!c1.get_met() && c2.get_met()) || (c1.get_met() == c2.get_met()))
		return true;
	else
		return c1.get_name().compare(c2.get_name());
	return false;
}
/*
bool Celebrity::operator< (Celebrity & c) {

	if (this->get_meet_rating() < c.get_meet_rating())
		return true;
	return false;
	else if (!c1.get_met() && c2.get_met())
		return true;
	else
		return c1.get_name().compare(c2.get_name());
	return false;
}

bool Celebrity::operator<= (Celebrity & c) {

	if (this->get_meet_rating() <= c.get_meet_rating())
		return true;
	return false;
	else if ((!c1.get_met() && c2.get_met()) || (c1.get_met() == c2.get_met()))
		return true;
	else
		return c1.get_name().compare(c2.get_name());
	return false;

}
	*/

